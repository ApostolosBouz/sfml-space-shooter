
#include "game/intro_phase.hpp"
#include <iostream>
#include <variant>

namespace game
{
	IntroPhase::IntroPhase(sf::RenderWindow& window)
	{
		std::cout << " " << typeid(*this).name() << std::endl;

		if (!intro_font_.loadFromFile("assets/fonts/Orbitron-Bold.ttf"))
		{
			// TODO: Handle font loading error
		}

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
	}

	void IntroPhase::update()
	{
		Phase::update();

		// Fade in the first text box over 5 seconds
		if (getPhaseElapsedSecs() <= 5.0f)
		{
			float alpha = 255 * (getPhaseElapsedSecs() / 5.0f);
			intro_title_.setFillColor(sf::Color(255, 255, 255, static_cast<sf::Uint8>(alpha)));
		}
		// Fade in the second text box after the first one over 2 seconds
		else if (getPhaseElapsedSecs() > 5.0f && getPhaseElapsedSecs() <= 7.0f)
		{
			float alpha = 255 * ((getPhaseElapsedSecs() - 5) / 2.0f);
			intro_subtitle_.setFillColor(sf::Color(255, 255, 255, static_cast<sf::Uint8>(alpha)));
		}
	}

	void IntroPhase::draw(sf::RenderWindow& window)
	{
		Phase::draw(window);

		window.draw(intro_title_);
		window.draw(intro_subtitle_);
	}

	void IntroPhase::centerTextOnScreen(sf::Text& text, sf::RenderWindow& window, float vert_center_offset)
	{
		float centerX = (window.getSize().x - text.getLocalBounds().width) / 2.0f ;
		float centerY = (window.getSize().y - text.getLocalBounds().height) / (2.0f + vert_center_offset);
		text.setPosition(centerX, centerY);
	}

	IntroPhase::~IntroPhase()
	{
		std::cout << id_ << " Destroying " << typeid(*this).name() << " ";
	}
}
