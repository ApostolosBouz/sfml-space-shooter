#ifndef APP_HPP
#define APP_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

namespace game
{
	class IntroPhase;

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

		std::unique_ptr<IntroPhase> intro_ = nullptr;
	};
}

#endif