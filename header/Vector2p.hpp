#ifndef VECTOR2P_H_
#define VECTOR2P_H_
#include <SFML/Graphics.hpp>

struct Vector2p;
Vector2p& upsidedown(Vector2p& vect, sf::RenderWindow& window);

struct Vector2p {
	Vector2p(const float x1, const float y1,
			 const float x2, const float y2);
	Vector2p(const sf::Vector2f& begin, const sf::Vector2f& end);
	Vector2p(const float length);
	Vector2p(const sf::Vector2f& vector, const float length);
	Vector2p& setPosition(const sf::Vector2f&);

	Vector2p& rotate(const float angle);
	Vector2p& setPosition(const float x, const float y);
	void draw(sf::RenderWindow& window, sf::Color = sf::Color::Black);
	friend Vector2p& upsidedown(Vector2p& vect, sf::RenderWindow& window);
private:
	sf::Vector2f v1;
	sf::Vector2f v2;
	float add_angle;
};
#endif // VECTOR2P_H_
