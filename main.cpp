#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <cmath>
#include "header/Vector2p.hpp"
#include "header/CoordinateSystem.hpp"
int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 500), "C++");
	sf::VertexArray line(sf::PrimitiveType::LineStrip);
	CoordinateSystem sys(100, 100, 0);
	//Vector2p v(sf::Vector2f(100, 100), -1000);
//	Vector2p v(100); v.setPosition(100,200); v.rotate(30);
	//v.rotate(-30);
	//v.rotate(180);
	window.isOpen();
		sf::Event event;
		window.clear(sf::Color::White);
//		v.draw(window);
		sys.draw(window);
		window.display();
		while (window.isOpen())
			while(window.pollEvent(event))
				if (event.type == sf::Event::Closed) window.close();
	return 0;
}
