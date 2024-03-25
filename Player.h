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

		Player(float x, float y, float vx, float vy, sf::Texture player, bool OnGround, float jump_high)
		{
			Setup(x, y, vx, vy, player, OnGround, jump_high);
		}


		void Setup(float x, float y, float vx, float vy, sf::Texture player, bool OnGround, float jump_high)
		{
			p_x = x;
			p_y = y;
			p_vx = vx;
			p_vy = vy;
			p_OnGround = OnGround;
			p_jump_high = jump_high;
			texture_player = player;
			sprite_player.setTexture(texture_player);
			sprite_player.setPosition(p_x, p_y);
			sprite_player.setScale(0.5f, 0.5f);
			
		}

		sf::Sprite Get()
		{
			return sprite_player;
		}
		void setVelocityX(float dv)
		{
			p_x += dv;
		}
		void setVelocityY(float dv)
		{
			p_y += dv;
		}
		float X()
		{
			return p_x;
		}
		float Y()
		{
			return p_y;
		}
		float P_vx()
		{
			return p_vx;
		}
		float P_vy()
		{
			return p_vy;
		}
		void P_vx(float vx)
		{
			p_vx = vx;
		}
		void P_vy(float vy)
		{
			p_vy = vy;
		}
		bool OnGround()
		{
			return p_OnGround;
		}
		void OnGround(bool OnGround)
		{
			p_OnGround = OnGround;
		}
		float Jump_High()
		{
			return p_jump_high;
		}
		void Move()
		{
			sprite_player.setPosition(p_x, p_y);
		}
		void anim(int p1x, int p1y, int p2x, int p2y)
		{
			sprite_player.setTextureRect(sf::IntRect(p1x, p1y, p2x, p2y));
		}
	};
}