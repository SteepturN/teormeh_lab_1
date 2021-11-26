#include <SFML/Graphics.hpp>
#include "../header/CoordinateSystem.hpp"
#include "../header/Vector2p.hpp"
CoordinateSystem::CoordinateSystem(const float& x, const float& y,
                                   const float& rotation_angle/* = 0 */)
	: x(x), y(y), rotation_angle(rotation_angle) {}
void CoordinateSystem::draw(sf::RenderWindow& window) {
	Vector2p vector(sf::Vector2f(1, 0), COORDINATESYSTEM_LENGTH);
	vector.setPosition(x, y);
	vector.draw(window);
	Vector2p vector_y(sf::Vector2f(0, 1), COORDINATESYSTEM_LENGTH);
	vector_y.setPosition(x, y);
	vector_y.draw(window);
}
