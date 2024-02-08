
#include "core/phase.hpp"
#include "core/actor.hpp"
#include <iostream>
#include "core/phase.hpp"

namespace game
{
	Phase::Phase()
	{
		std::cout << " " << typeid(*this).name() << " ";
		phase_elapsed_secs_ = 0.0f;
	}

	void Phase::update()
	{
		phase_elapsed_secs_ = phase_timer_.getElapsedTime().asSeconds();

		if(!phase_actors_.empty())
		{
			for(auto& phase_actor : phase_actors_)
			{
				phase_actor.update();
			}
		}
	}

	void Phase::draw(sf::RenderWindow& window)
	{
		if(!window.isOpen()) return;
		
		if(!phase_actors_.empty())
		{
			for(auto& phase_actor : phase_actors_)
			{
				phase_actor.draw(window);
			}
		}	
	}

    void Phase::addActor(Actor &actor)
	{
		phase_actors_.push_back(actor);
	}
    
	const float Phase::getPhaseElapsedSecs() const
	{
        return phase_elapsed_secs_;
    }

    Phase::~Phase()
    {
		std::cout << " " << typeid(*this).name() << " ";
	}
}