#ifndef INTRO_PHASE_HPP
#define INTRO_PHASE_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include "core/phase.hpp"

namespace game
{
	class IntroPhase : public Phase
	{
	public:
		IntroPhase(sf::RenderWindow& window);
		void update() override;
		void draw(sf::RenderWindow& window) override;
		~IntroPhase();

	private:
		void centerTextOnScreen(sf::Text& text, sf::RenderWindow& window, float vert_center_offset);

		sf::Font intro_font_;
		sf::Text intro_title_;	
		sf::Text intro_subtitle_;
	};
}

#endif