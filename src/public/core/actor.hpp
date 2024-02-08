#ifndef ACTOR_HPP
#define ACTOR_HPP

#include <SFML/Graphics.hpp>
#include "core/object.hpp"

namespace game
{
	class Actor : public Object
	{
	public:
		Actor();
		void update() override {}
		virtual void draw(sf::RenderWindow& window);
		~Actor();
	};
}

#endif