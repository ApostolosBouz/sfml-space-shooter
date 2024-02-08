#ifndef PHASE_HPP
#define PHASE_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include "core/object.hpp"

namespace game
{
	class Actor;

	class Phase : public Object
	{
	public:
		Phase();

		void update() override;
		virtual void draw(sf::RenderWindow& window);

		void addActor(Actor& actor);
		const float getPhaseElapsedSecs() const;

		~Phase();

	protected:
		std::vector<Actor> phase_actors_;

	private:
		sf::Clock phase_timer_;
		float phase_elapsed_secs_;
	};
}

#endif