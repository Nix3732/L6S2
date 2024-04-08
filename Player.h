#pragma once
#include <SFML/Graphics.hpp>

namespace ez
{
	const float pi = acos(-1);

	class Player
	{
		float p_x, p_y;
		float p_vx, p_vy;
		float p_jump_high;
		sf::Texture texture_player;
		sf::Sprite sprite_player;
		bool p_OnGround;


	public:
		Player() = default;

		Player(float x, float y, float vx, float vy, sf::Texture player, bool OnGround, float jump_high);

		void Setup(float x, float y, float vx, float vy, sf::Texture player, bool OnGround, float jump_high);

		sf::Sprite Get();

		void setVelocityX(float dv);
		void setVelocityY(float dv);
		float X();
		float Y();
		float P_vx();
		float P_vy();
		void P_vx(float vx);
		void P_vy(float vy);
		bool OnGround();
		void OnGround(bool OnGround);
		float Jump_High();
		void Move();
		void anim(int p1x, int p1y, int p2x, int p2y);
	};
}