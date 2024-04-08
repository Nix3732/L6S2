#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Player.h"
#include <vector>


namespace ez
{
	class Game
	{
		int w_wd;
		int w_hg;
		std::string w_name;
		sf::RenderWindow w_window;
		ez::Player pl;

		sf::Texture texture_background;
		sf::Sprite sprite_background;

		sf::Texture texture_player;

		sf::Image icon;

		float CurrentFrame = 0;
		sf::Clock clock;

	public:
		Game(int wd, int hg, std::string name);

		void set();

		//жизнь))
		void life();
	};
}