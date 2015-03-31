#ifndef PARTICLE_SYSTEM_HPP
#define PARTICLE_SYSTEM_HPP

#include <SFML/Graphics.hpp>
#include <vector>

class ParticleSystem
{
public:

	ParticleSystem( int particles );

	void update( sf::Time dt );
	void reset( int i );

	void             setEmitter( float x, float y ) { m_emitter = sf::Vector2f( x, y ); }
	sf::VertexArray& getVArray()                    { return m_vertexArray; }

private:

	struct Particle
	{
		sf::Vector2f velocity;
		sf::Time     lifetime;
	};

	int                     m_numParticles;

	sf::VertexArray         m_vertexArray;
	std::vector< Particle > m_particles;

	sf::Vector2f            m_emitter;

	sf::Time                m_lifetime;
};

#endif // PARTICLE_SySTEM_HPP