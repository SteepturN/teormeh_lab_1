#ifndef MOVEMENT_H_
#define MOVEMENT_H_
#include <SFML/Graphics.hpp>
#include "../header/CoordinateSystem.hpp"
class Movement {
public: //wheel
	Movement(float velocity, float radius, int x, int y);
	sf::Vector2f point_current_position(float time);
	CoordinateSystem coordinate_system();
	void draw_coordinate_system(sf::RenderWindow&);
	void draw_point_velocity(float time, sf::RenderWindow&, sf::Color);
	void draw_point_acceleration_t_n_velocity(float time, sf::RenderWindow&);
	sf::Vector2f pvelocity(float time);
private:
	float _velocity;
	float _radius;
	CoordinateSystem _coord;

};
#endif // MOVEMENT_H_
