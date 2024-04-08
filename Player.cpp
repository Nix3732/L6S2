#include "Player.h"

namespace ez
{
	sf::Sprite sprite_player;

	Player::Player(float x, float y, float vx, float vy, sf::Texture player, bool OnGround, float jump_high)
	{
		Setup(x, y, vx, vy, player, OnGround, jump_high);
	}

	void Player::Setup(float x, float y, float vx, float vy, sf::Texture player, bool OnGround, float jump_high)
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

	sf::Sprite Player::Get()
	{
		return sprite_player;
	}

	void Player::setVelocityX(float dv)
	{
		p_x += dv;
	}
	void Player::setVelocityY(float dv)
	{
		p_y += dv;
	}
	float Player::X()
	{
		return p_x;
	}
	float Player::Y()
	{
		return p_y;
	}
	float Player::P_vx()
	{
		return p_vx;
	}
	float Player::P_vy()
	{
		return p_vy;
	}
	void Player::P_vx(float vx)
	{
		p_vx = vx;
	}
	void Player::P_vy(float vy)
	{
		p_vy = vy;
	}
	bool Player::OnGround()
	{
		return p_OnGround;
	}
	void Player::OnGround(bool OnGround)
	{
		p_OnGround = OnGround;
	}
	float Player::Jump_High()
	{
		return p_jump_high;
	}
	void Player::Move()
	{
		sprite_player.setPosition(p_x, p_y);
	}
	void Player::anim(int p1x, int p1y, int p2x, int p2y)
	{
		sprite_player.setTextureRect(sf::IntRect(p1x, p1y, p2x, p2y));
	}
}