#include "../header/UpsideDown.hpp"
#include <SFML/Graphics.hpp>
#include "../header/Movement.hpp"
#include "../header/Vector2p.hpp"


sf::Vertex&& upsidedown(sf::Vertex&& vert, sf::RenderWindow& window) {
//	sf::Vertex needed_vert = vert;
	sf::Vector2u size = window.getSize();
	vert.position.y = size.y - vert.position.y;
	return std::move(vert);
}
sf::Vertex& upsidedown(sf::Vertex& vert, sf::RenderWindow& window) {
//	sf::Vertex needed_vert = vert;
	sf::Vector2u size = window.getSize();
	vert.position.y = size.y - vert.position.y;
	return vert;
}
Vector2p& upsidedown(Vector2p& vect, sf::RenderWindow& window) {
	sf::Vector2u size = window.getSize();
	vect.v1.y = size.y - vect.v1.y;
	vect.v2.y = size.y - vect.v2.y;
	return vect;
}
sf::Vector2f&& upsidedown(sf::Vector2f&& vect, sf::RenderWindow& window) {
	vect.y = window.getSize().y - vect.y;
	return std::move(vect);
}
