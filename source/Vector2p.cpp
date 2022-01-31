#include "../header/Vector2p.hpp"
#define VECTOR_WIDTH 2
#define ARROW_LENGTH 10
#include <cmath>
#include "../header/UpsideDown.hpp"
float sqrt_s(float a, float b) {
	return sqrt(pow(a, 2)+pow(b,2));
}
Vector2p::Vector2p(const float x1, const float y1,
                   const float x2, const float y2)
	: v1(x1, y1), v2(x2, y2), add_angle(0.0f) {}
Vector2p::Vector2p(const sf::Vector2f& v1, const sf::Vector2f& v2)
	: v1(v1), v2(v2), add_angle(0.0f) {}
Vector2p::Vector2p(const float length)
	: v1(0, 0), v2(0, length) {}
Vector2p::Vector2p(const sf::Vector2f& vector, const float length)
	: v1(0, 0), v2(vector.x*length/sqrt_s(vector.x, vector.y),
	               vector.y*length/sqrt_s(vector.x, vector.y)) {}
Vector2p& Vector2p::setPosition(const sf::Vector2f& v) {
	v2.x = v2.x - v1.x + v.x;
	v2.y = v2.y - v1.y + v.y;
	v1 = v;
	return *this;
}
Vector2p& Vector2p::rotate(const float _angle) {
	add_angle+=_angle; //rotates clockwise
	return *this;
}
Vector2p& Vector2p::setPosition(const float x, const float y) {
	v2.x = v2.x - v1.x + x;
	v2.y = v2.y - v1.y + y;
	v1.x = x;
	v1.y = y;
	return *this;
}
void Vector2p::draw(sf::RenderWindow& window, sf::Color c /* = Black */) {
	upsidedown(*this, window);
	float v_rotation = (atan2((v2.y-v1.y), (v2.x-v1.x)) * 180 / M_PI
	                    + add_angle);
	float v_length = sqrt_s(v1.x-v2.x, v1.y-v2.y);
	sf::RectangleShape vector(
		sf::Vector2f(VECTOR_WIDTH, v_length));
	vector.setRotation(-90/* allign with OX */+v_rotation);
	vector.setPosition(v1);
	vector.setFillColor(c);
	window.draw(vector);
	sf::RectangleShape arrow[2] {
		sf::RectangleShape(sf::Vector2f(VECTOR_WIDTH, ARROW_LENGTH)),
		sf::RectangleShape(sf::Vector2f(VECTOR_WIDTH, ARROW_LENGTH)),
	};
	sf::Vector2f arr_pos =
		v1 + sf::Vector2f(v_length * cos(v_rotation*M_PI/180 - 0.012f),
		                  v_length * sin(v_rotation*M_PI/180 - 0.012f));
	float arr_rotation = -90 + v_rotation + 180;
	for(int i = 0; i < 2; i++) {
		arrow[i].setFillColor(c);
		arrow[i].setPosition(arr_pos);
		arrow[i].rotate(30*(1-i*2) + arr_rotation);
		window.draw(arrow[i]);
	}
}
