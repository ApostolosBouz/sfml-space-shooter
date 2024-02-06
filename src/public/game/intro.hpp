#ifndef INTRO_HPP
#define INTRO_HPP

#include <SFML/Graphics.hpp>
#include <vector>

namespace game
{
	class Intro
	{
	public:
		Intro();
		void update();
		void draw(sf::RenderWindow& window);
		~Intro();

	private:

		// Intro members
		sf::Font intro_font_;
		sf::Clock show_texts_timer_;

		sf::Text intro_title_;
		bool intro_title_visible_;
		
		sf::Text intro_subtitle_;
		bool intro_subtitle_visible_;

		std::vector<sf::Text> active_texts_;
	};
}

#endif