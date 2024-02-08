
#include "game/intro.hpp"
#include <iostream>
#include <variant>

namespace game
{
	Intro::Intro(sf::RenderWindow& window)
	{
		if (!intro_font_.loadFromFile("assets/fonts/Orbitron-Bold.ttf"))
		{
			// TODO: Handle font loading error
		}
		std::cout << "Intro Loaded." << std::endl;

		intro_title_.setFont(intro_font_);
		intro_title_.setString("SPACE SHOOTER");
		intro_title_.setCharacterSize(72);
		intro_title_.setFillColor(sf::Color::Transparent);
		centerTextOnScreen(intro_title_, window, 0.5f);

		intro_subtitle_.setFont(intro_font_);
		intro_subtitle_.setString("- Coming soon -");
		intro_subtitle_.setCharacterSize(24);
		intro_subtitle_.setFillColor(sf::Color::Transparent);
		centerTextOnScreen(intro_subtitle_, window, -0.5f);

		intro_elapsed_ = 0.0f;
	}

	void Intro::update()
	{
		intro_elapsed_ = intro_timer_.getElapsedTime().asSeconds();

		// Fade in the first text box over 3 seconds
		if (intro_elapsed_ <= 3.0f)
		{
			float alpha = 255 * (intro_elapsed_ / 3.0f);
			intro_title_.setFillColor(sf::Color(255, 255, 255, static_cast<sf::Uint8>(alpha)));
		}
		// Fade in the second text box after the first one over 3 seconds
		else if (intro_elapsed_ > 3.0f && intro_elapsed_ <= 6.0f)
		{
			float alpha = 255 * ((intro_elapsed_ - 3) / 3.0f);
			intro_subtitle_.setFillColor(sf::Color(255, 255, 255, static_cast<sf::Uint8>(alpha)));
		}
	}

	void Intro::draw(sf::RenderWindow& window)
	{
		window.draw(intro_title_);
		window.draw(intro_subtitle_);
	}

	void Intro::centerTextOnScreen(sf::Text& text, sf::RenderWindow& window, float vert_center_offset)
	{
		float centerX = (window.getSize().x - text.getLocalBounds().width) / 2.0f ;
		float centerY = (window.getSize().y - text.getLocalBounds().height) / (2.0f + vert_center_offset);
		text.setPosition(centerX, centerY);
	}

	Intro::~Intro()
	{
		std::cout << "Unloading Intro." << std::endl;
	}
}
