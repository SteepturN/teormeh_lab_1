#ifndef COORDINATESYSTEM_H_
#define COORDINATESYSTEM_H_
#include <SFML/Graphics.hpp>
#include "../header/CoordinateSystem.hpp"

#define COORDINATESYSTEM_LENGTH 500
struct CoordinateSystem {
	CoordinateSystem(const float& x, const float& y,
	                 const float& rotation_angle = 0);
	void draw(sf::RenderWindow&);
private:
	float x;
	float y;
	float rotation_angle;
};
#endif // COORDINATESYSTEM_H_
