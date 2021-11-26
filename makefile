yes:
	g++ -g -Wall -pedantic source/CoordinateSystem.cpp source/Movement.cpp source/Vector2p.cpp source/main.cpp source/UpsideDown.cpp -lsfml-graphics -lsfml-window -lsfml-system -o main

try: source/CoordinateSystem.o source/Movement.cpp source/Vector2p.cpp main.cpp source/UpsideDown.cpp
	g++ -g -Wall -pedantic source/CoordinateSystem.cpp source/Movement.cpp source/Vector2p.cpp main.cpp source/UpsideDown.cpp -lsfml-graphics -lsfml-window -lsfml-system -o try
