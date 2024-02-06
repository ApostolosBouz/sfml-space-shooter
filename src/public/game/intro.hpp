#ifndef INTRO_HPP
#define INTRO_HPP

#include <SFML/Graphics.hpp>
#include <vector>

namespace game
{
	class Intro
	{
	public:
		Intro(sf::RenderWindow& window);
		void update();
		void draw(sf::RenderWindow& window);
		~Intro();

	private:
		void centerTextOnScreen(sf::Text& text, sf::RenderWindow& window, float vert_center_offset);

		// Intro members
		sf::Clock intro_timer_;
		float intro_elapsed_;

		sf::Font intro_font_;
		sf::Text intro_title_;	
		sf::Text intro_subtitle_;
	};
}

#endif