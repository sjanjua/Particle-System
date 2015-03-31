#include "ParticleSystem.hpp"

ParticleSystem::ParticleSystem( int particles )
	: m_numParticles( particles )
	, m_vertexArray( sf::Points, m_numParticles )
	, m_particles( m_numParticles )
	, m_emitter( 0.0f, 0.0f )
	, m_lifetime( sf::seconds( 3.0f ) )
{

}

void ParticleSystem::update( sf::Time dt )
{
	for ( int i = 0; i < m_particles.size(); i++ )
	{
		Particle& p = m_particles[ i ];

		p.lifetime -= dt;

		if ( p.lifetime <= sf::Time::Zero )
		{
			reset( i );
		}

		else
		{
			m_vertexArray[ i ].position += ( p.velocity * dt.asSeconds() );

			m_vertexArray[ i ].color = sf::Color( 0, 215, 255 );

			float ratio = p.lifetime.asSeconds() / m_lifetime.asSeconds();

			m_vertexArray[ i ].color.a = ratio * 255;
		}
	}
}

void ParticleSystem::reset( int i )
{
	m_vertexArray[ i ].position = m_emitter;

	float speed = ( std::rand() % 50 ) + 50;
	float angle = ( std::rand() % 360 ) * 3.14 / 180;

	m_particles[ i ].velocity = sf::Vector2f( std::cos( angle ) * speed, std::sin( angle ) * speed );
	m_particles[ i ].lifetime = sf::milliseconds( ( std::rand() % 2000 ) + 1000 );
}