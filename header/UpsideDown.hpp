#ifndef UPSIDEDOWN_H_
#define UPSIDEDOWN_H_
#include <SFML/Graphics.hpp>
#include "../header/Movement.hpp"
#include "../header/Vector2p.hpp"

sf::Vertex&& upsidedown(sf::Vertex&& vert, sf::RenderWindow& window);
sf::Vertex& upsidedown(sf::Vertex&, sf::RenderWindow&);
Vector2p& upsidedown(Vector2p&, sf::RenderWindow&);

#endif // UPSIDEDOWN_H_
