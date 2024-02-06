
#include "game/intro.hpp"
#include <iostream>
#include <variant>

namespace game
{
	Intro::Intro()
	{
		intro_title_visible_ = false;
		intro_subtitle_visible_ = false;

		if (!intro_font_.loadFromFile("assets/fonts/UbuntuCond.ttf"))
		{
			// TODO: Handle font loading error
		}
		std::cout << "Intro Loaded." << std::endl;

		intro_title_.setFont(intro_font_);
		intro_title_.setString("SPACE SHOOTER");
		intro_title_.setCharacterSize(52);
		intro_title_.setFillColor(sf::Color::Transparent); // Initially transparent
		intro_title_.setPosition(100, 200); // Adjust position as needed

		intro_subtitle_.setFont(intro_font_);
		intro_subtitle_.setString("- Coming soon -");
		intro_subtitle_.setCharacterSize(24);
		intro_subtitle_.setFillColor(sf::Color::Transparent); // Initially transparent
		intro_subtitle_.setPosition(100, 300); // Adjust position as needed
	}

	void Intro::update()
	{
		// Fade in the first text box over 3 seconds
		if (show_texts_timer_.getElapsedTime().asSeconds() <= 3.0f
			&& !intro_title_visible_)
		{
			float alpha = 255 * (show_texts_timer_.getElapsedTime().asSeconds() / 3.0f);
			intro_title_.setFillColor(sf::Color(255, 255, 255, static_cast<sf::Uint8>(alpha)));
			intro_title_visible_ = true;
		}

		// Fade in the second text box after the first one over 3 seconds
		if (show_texts_timer_.getElapsedTime().asSeconds() > 3.0f
			&& show_texts_timer_.getElapsedTime().asSeconds() <= 6.0f
			&& !intro_subtitle_visible_)
		{
			float alpha = 255 * ((show_texts_timer_.getElapsedTime().asSeconds() - 3.0f) / 3.0f);
			intro_subtitle_.setFillColor(sf::Color(255, 255, 255, static_cast<sf::Uint8>(alpha)));
			intro_subtitle_visible_ = true;
		}
	}

	void Intro::draw(sf::RenderWindow& window)
	{
		window.draw(intro_title_);
		window.draw(intro_subtitle_);
	}

	Intro::~Intro()
	{
		std::cout << "Unloading Intro." << std::endl;
	}
}
