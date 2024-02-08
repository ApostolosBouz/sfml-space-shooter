
#include "core/actor.hpp"
#include <iostream>

namespace game
{
	Actor::Actor()
	{
        std::cout << " " << typeid(*this).name() << " ";
	}

	void Actor::draw(sf::RenderWindow& window)
	{
		if(!window.isOpen()) return;
	}

	Actor::~Actor()
	{
        std::cout << " " << typeid(*this).name() << " ";
	}
}