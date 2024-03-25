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
		Game(int wd, int hg, std::string name)
		{
			w_wd = wd;
			w_hg = hg;
			w_name = name;
		}

		void set()
		{
			w_window.create(sf::VideoMode(w_wd, w_hg), w_name);
			w_window.setTitle(w_name);

			//иконка
			icon.loadFromFile("assets\\icon.png");
			w_window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
			
			//задний фон
			texture_background.loadFromFile("assets\\back.jpg");
			sprite_background.setTexture(texture_background);

			//картинка на игроке
			texture_player.loadFromFile("assets\\player.png");

			//задание игрока
			int x = 100;
			int y = 765;
			int vx = 500;
			int vy = 50;
			bool OnGround = true;
			int jump_high = 8000;
			int gravity = jump_high / 10;
			pl.Setup(x, y, vx, vy, texture_player, OnGround, jump_high);
		}

		//жизнь))
		void life()
		{
			std::vector<int> run_framex1;
			std::vector<int> run_framex2;
			run_framex1.push_back(323);
			run_framex2.push_back(289);
			run_framex1.push_back(635);
			run_framex2.push_back(193);
			run_framex1.push_back(875);
			run_framex2.push_back(253);
			float jump_high = pl.Jump_High();

			float fps = 100;

			while(w_window.isOpen())
			{
				sf::Event event;
				while(w_window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
					{
						w_window.close();
					}
				}

				float dt = clock.getElapsedTime().asSeconds();
				if (1 / fps > dt)
				{
					sf::Time t = sf::seconds(1 / fps - dt);
					sf::sleep(t);
				}
				dt = clock.getElapsedTime().asSeconds();
				clock.restart();


				pl.anim(48, 0, 252, 350);

				w_window.clear();

				float x = pl.X();
				float y = pl.Y();
				float vx = pl.P_vx();
				bool OnGround = pl.OnGround();

				if (y < 765)
				{
					pl.setVelocityY((pow(10, 2)/2)*dt);
					pl.OnGround(false);
				}
				else
				{
					pl.OnGround(true);
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				{
					CurrentFrame += 7 * dt;
					if (CurrentFrame > 3)
					{
						CurrentFrame -= 3;
					}
					pl.setVelocityX(vx*dt);
					pl.anim(run_framex1[int(CurrentFrame)], 0, run_framex2[int(CurrentFrame)], 350);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				{
					CurrentFrame += 7 * dt;
					if (CurrentFrame > 3)
					{
						CurrentFrame -= 3;
					}
					pl.setVelocityX(-vx*dt);
					pl.anim(run_framex1[int(CurrentFrame)] + run_framex2[int(CurrentFrame)], 0, -run_framex2[int(CurrentFrame)], 350);
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && (OnGround))
				{
					pl.setVelocityY(-jump_high*dt);
					pl.OnGround(false);
				}

				if ((sf::Keyboard::isKeyPressed(sf::Keyboard::D)) && (sf::Keyboard::isKeyPressed(sf::Keyboard::A)))
				{
					pl.anim(48, 0, 252, 350);
				}


				std::cout << y << std::endl;
				pl.Move();

				w_window.draw(sprite_background);

				w_window.draw(pl.Get());

				w_window.display();
			}
		}
	};
}