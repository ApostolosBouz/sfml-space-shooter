#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

namespace game
{
	class Intro;

	class App
	{
	public:
		App();
		void start();
		~App();

	private:
		sf::RenderWindow window_;
		sf::ContextSettings context_settings_;

		void processWindowEvents();
		void update();

		bool running_;

		std::unique_ptr<Intro> intro_ = nullptr;
	};
}

#endif