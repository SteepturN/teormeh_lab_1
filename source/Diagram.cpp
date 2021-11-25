#include <SFML/Graphics.hpp>
#include <cmath>
#include "Movement.cpp"
#include "Curve.cpp"

class Diagram
{

	public:

	Diagram(int height, int width)
	:	height(height), width(width), window(sf::VideoMode(width, height), "C++"),
	 	OX_coord_shift(width/2.0), OY_coord_shift(height/2.0), OX_right_shift(10), OY_upper_shift(10);
	{
		window.clear(sf::Color::White);
	}
	const int height;
	const int width;
	sf::RenderWindow window;
	void draw(Curve* c, const int volume)
	{
		sf::VertexArray line(sf::PrimitiveType::LineStrip);
		for(int i = 0; i < volume; i++)
			line.append(sf::Vertex(sf::Vector2f(c[i].x+OX_coord_shift,(-1)*(c[i].y+OY_coord_shift)), sf::Color::Black));
		window.draw(line);
	}
	void draw(const Vector_draw &v)
	{
		sf::VertexArray line(sf::PrimitiveType::Lines);
		line.append(sf::Vertex(sf::Vector2f(v0.x, v0.y), sf::Color::Red));
		line.append(sf::Vertex(sf::Vector2f(v0.x+v1.x, v0.y+v1.y), sf::Color::Red));
		window.draw(line);
	
		sf::VertexArray arrow(sf::PrimitiveType::LineStrip);
		sf::Vector2f f(signbit(v1.x)*(-2)+1, signbit(v1.y)*(-2)+1);

		float fi = M_PI/6.0f;
		float length = sqrt(pow(v1.x, 2)+pow(v2.x, 2));

		arrow.append(sf::Vertex(sf::Vector2f((-v1.x*cos(fi)-v1.y*sin(fi))/length+v0.x+v1.x, ((v1.x*sin(fi)-v1.x*cos(fi))/length+v0.y+v1.y), sf::Color::Red));
		arrow.append(sf::Vertex(sf::Vector2f(v0.x+v1.x, v0.y+v1.y), sf::Color::Red));
		arrow.append(sf::Vertex(sf::Vector2f((-v1.x*cos(fi)+v1.y*sin(fi))/length+v0.x+v1.x, ((-v1.x*sin(fi)-v1.x*cos(fi))/length+v0.y+v1.y), sf::Color::Red));
		window.draw(arrow);
	} //добавить возможность выбора цвета, рисовать прямоугольниками
	void draw(const Coordinate_system& c)
	{
		//c.x c.y c.можно добавить возможность указания, куда смотрят координаты
		this->draw(Vector2f(0, (-1)(c.y+OX_y_coord_shift)), Vector2f(width-OX_right_shift, (-1)(c.y+OY_y_coord_shift))); //OX
		this->draw(Vector2f(c.x+OY_coord_shift, -height), Vector2f(c.x+OY_coord_shift, (-1)(OY_upper_shift)));
	}

	private:

	const float OX_coord_shift;
	const float OY_coord_shift;
	const float OX_right_shift;
	const float OY_upper_shift;

};
