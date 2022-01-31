#include <SFML/Graphics.hpp>
#include "../header/Movement.hpp"
#include "../header/CoordinateSystem.hpp"
#include "../header/Vector2p.hpp"
#include <cmath>
#include <iostream>
#define VISUAL_KOEFF 10
#define VISUAL_OFFCET 100
float sqrt_sum(float a, float b) {
	return sqrt(pow(a, 2)+pow(b,2));
}
Movement::Movement(float velocity, float radius, int x, int y)
	: _velocity(velocity), _radius(radius), _coord(x, y) {}

sf::Vector2f Movement::point_current_position(float time) {
	float x_coord = _velocity * time +
		_radius * sin((_velocity * time) / _radius);
	float y_coord = _radius * (1 + cos((_velocity * time) / _radius)) + VISUAL_OFFCET;
	return sf::Vector2f(x_coord, y_coord);
}
void Movement::draw_coordinate_system(sf::RenderWindow& window) {
	_coord.draw(window);
}
void Movement::draw_point_velocity(float time, sf::RenderWindow& window, sf::Color c) {
	sf::Vector2f velocity = this->pvelocity(time);
	sf::Vector2f cur_pos = point_current_position(time);
	Vector2p velocity_vector(cur_pos, cur_pos+velocity);
	velocity_vector.draw(window, c);
}

sf::Vector2f Movement::pvelocity(float time) {
	float fi = (_velocity * time ) / _radius;
	float x_coord = _velocity * ( 1 + cos(fi));
	float y_coord = - _velocity * sin(fi);
	return sf::Vector2f(x_coord, y_coord);
}
void Movement::draw_point_acceleration_t_n_velocity(float time,
                                                    sf::RenderWindow& window) {
	float fi = _velocity * time / _radius;
	sf::Vector2f velocity = this->pvelocity(time);
	float acceler_tan = -pow(_velocity, 2) * sin(fi) /
		( _radius * sqrt(2 + 2 * cos(fi)));
	float acceler_norm = sqrt(pow(pow(_velocity, 2) / _radius, 2) -
	                          pow(acceler_tan, 2));
	auto point_cur_pos = point_current_position(time);
	velocity.x *= VISUAL_KOEFF;
	velocity.y *= VISUAL_KOEFF;
	acceler_tan *= VISUAL_KOEFF*3;
	acceler_norm *= VISUAL_KOEFF*3;
	Vector2p(point_cur_pos, velocity+point_cur_pos).
		draw(window, sf::Color::Red);
	Vector2p acceler_tan_v(velocity, acceler_tan);
	acceler_tan_v.setPosition(point_cur_pos);
	acceler_tan_v.draw(window, sf::Color::Green);

	Vector2p acceler_norm_v(sf::Vector2f(velocity.y, -velocity.x),
	                        acceler_norm);
	acceler_norm_v.setPosition(point_cur_pos);
	acceler_norm_v.draw(window, sf::Color::Blue);
}
