
#ifdef _WIN32
#include "platforms/win_reset.hpp"
#endif

#include <memory>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iostream>

#include "core/app.hpp"

namespace game
{
	App::App()
	{
		running_ = true;
		context_settings_.antialiasingLevel = 4;
		window_.create(sf::VideoMode(800, 600), "Space Shooter", sf::Style::Default, context_settings_);
		window_.setFramerateLimit(120);
	}

	void App::start()
	{
		while (running_)
		{
			processWindowEvents();

			// Render loop
			if (window_.isOpen())
			{
				window_.clear();
				// TODO: insert game drawings here
				window_.display();
			}
			else
			{
				running_ = false;
			}
		}
	}

	void App::processWindowEvents()
	{
		sf::Event event;
		while (window_.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window_.close();
			}
		}
	}

	App::~App()
	{
		std::cout<<"Game closed."<<std::endl;
	}
}