#include "SFML/Graphics.hpp"
#include <iostream>
using namespace std;

int main()
{
	sf::RenderWindow window( sf::VideoMode( 600, 600 ), "drrp" );

	sf::Texture texture;

	if (!texture.loadFromFile("lib/initial.png", sf::IntRect(7,3,15,15)))
	{
		std::cout << "Error loading paddle texture :(" << std::endl;
	}

	//sf::Sprite sprite(texture);

	// or

	sf::Sprite sprite;
	sprite.setTexture(texture);

  sprite.move(sf::Vector2f(300, 300));

  double dx;
  double dy;
  double spd = 0.25;


	while ( window.isOpen( ) )
	{
		sf::Event event;

		while ( window.pollEvent( event ) )
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

    dx = 0;
    dy = 0;
    //   RIGHT
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
      dx += spd;
    }
    //  UP
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
      dy -= spd;
    }
    // LEFT
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
      dx -= spd;
    }
    // DOWN
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
      dy += spd;
    }
    sprite.move(sf::Vector2f(dx, dy));

		window.clear( );

		window.draw(sprite);

		window.display( );
	}
}
