#include <SFML/Graphics.hpp>
#include "ParticleSystem.hpp"

int main()
{
	sf::RenderWindow window( sf::VideoMode( 800, 600 ), "Particle System" );

	sf::Event ev;

	ParticleSystem particles( 10000 );

	sf::Clock clock;

	while ( window.isOpen() )
	{
		while ( window.pollEvent( ev ) )
		{
			if ( ev.type == sf::Event::Closed || sf::Keyboard::isKeyPressed( sf::Keyboard::Escape ) )
			{
				window.close();
			}
		}

		particles.setEmitter( sf::Mouse::getPosition( window ).x, sf::Mouse::getPosition( window ).y );

		sf::Time elapsed = clock.restart();

		particles.update( elapsed );

		window.clear();
		window.draw( particles.getVArray() );
		window.display();
	}

	return 0;
}