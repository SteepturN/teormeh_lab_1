#include <SFML/Graphics.hpp>
#include "../header/CoordinateSystem.hpp"
#include "../header/Vector2p.hpp"
CoordinateSystem::CoordinateSystem(const float& x, const float& y,
                                   const float& rotation_angle/* = 0 */)
	: x(x), y(y), rotation_angle(rotation_angle) {}
void CoordinateSystem::draw(sf::RenderWindow& window) {
	Vector2p(COORDINATESYSTEM_LENGTH).rotate(rotation_angle + 90.0f)
		.setPosition(x, y).draw(window);
	Vector2p(COORDINATESYSTEM_LENGTH).rotate(rotation_angle)
		.setPosition(x, y).draw(window);
}
