#define WINDOW_SIZE 1500,500
#define MAX_TIME 150.0f
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../header/Movement.hpp"
#include "../header/UpsideDown.hpp"
//#include "../header/Diagram.hpp"

int main() {
	sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE), "Wheel");
	window.setFramerateLimit(200);
	window.clear(sf::Color::White);
	float radius = 100.0f, velocity = 10.0f, print_vectors_time = 10.0f;
	const float delta_time = 0.0001f;
	//std::cin >> radius >> velocity >> print_vectors_time;
	Movement wheel(velocity, radius, 10,10);
	sf::VertexArray cycloid(sf::PrimitiveType::LineStrip);
	//I shall draw movement of 1 point and few vectors of velocity and acceleration
	for(float time = 0; time < MAX_TIME; time+=delta_time) {
		cycloid.append(upsidedown(sf::Vertex(wheel.point_current_position(time), sf::Color::Black), window));
	}
	wheel.draw_coordinate_system(window);
	wheel.draw_point_acceleration_t_n_velocity(print_vectors_time, window);
	window.draw(cycloid);
	window.isOpen();
//	sf::Event event;
	float time = 0;
	window.display();
	while (window.isOpen()) {
//		while(window.pollEvent(event)) {
		time = (time + 0.4f);
			if(time > MAX_TIME) break;
			window.clear(sf::Color::White);
			wheel.draw_coordinate_system(window);
			wheel.draw_point_acceleration_t_n_velocity(time, window);
			window.draw(cycloid);
			window.display();
			//if (event.type == sf::Event::Closed) window.close();
//			getchar();
//		}
	}
	return 0;
}
