#include "Player.h"

Player::Player( const Vei2& pos )
	:
	pos( Vec2( pos ) )
{
}

void Player::Update( const Keyboard& kbd,float dt )
{
	if( kbd.KeyIsPressed( 'A' ) )
	{
		vel -= speed;
	}
	else if( kbd.KeyIsPressed( 'D' ) )
	{
		vel += speed;
	}
	else if( abs( vel ) < 0.3 ) vel = 0.0;

	if( vel > maxSpeed ) vel = maxSpeed;
	if( vel < -maxSpeed ) vel = -maxSpeed;

	pos.x += vel * dt;

	vel *= slowdownFactor;

	grav += gravAcc * dt;
	pos.y += grav * dt;

	if( kbd.KeyIsPressed( 'W' ) && canJump )
	{
		jumping = true;
		canJump = false;
	}

	if( jumping )
	{
		pos.y -= float( jumpPower ) * dt;
	}
}

void Player::Draw( Graphics& gfx ) const
{
	gfx.DrawRect( int( pos.x ),int( pos.y ),
		size,size,Colors::Red );
}

bool Player::CheckHit( const Rect& rect )
{
	bool hasHit = false;
	if( HitTestBot( rect ) )
	{
		pos.y = rect.top - size;
		Land();
		hasHit = true;
	}
	if( HitTestTop( rect ) )
	{
		pos.y = rect.bottom;
		Fall();
		hasHit = true;
	}

	if( HitTestLeft( rect ) )
	{
		pos.x = rect.right;
		hasHit = true;
	}

	if( HitTestRight( rect ) )
	{
		pos.x = rect.left - size;
		hasHit = true;
	}

	return hasHit;
}

void Player::Land()
{
	grav = 0.0f;
	jumping = false;
	canJump = true;
}

void Player::Fall()
{
	jumping = false;
	grav = 0.0f;
}

bool Player::HitTestTop( const Rect& rect ) const
{
	if( pos.x + offset < rect.right &&
		pos.x + size - offset > rect.left &&
		pos.y < rect.bottom &&
		pos.y + offset > rect.top )
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Player::HitTestBot( const Rect& rect ) const
{
	if( pos.x + offset < rect.right &&
		pos.x + size - offset > rect.left &&
		pos.y + size - offset < rect.bottom &&
		pos.y + size > rect.top )
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Player::HitTestLeft( const Rect& rect ) const
{
	if( pos.x < rect.right &&
		pos.x + offset > rect.left &&
		pos.y + offset < rect.bottom &&
		pos.y + size - offset > rect.top )
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Player::HitTestRight( const Rect& rect ) const
{
	if( pos.x + size - offset < rect.right &&
		pos.x + size > rect.left &&
		pos.y + offset < rect.bottom &&
		pos.y + size - offset > rect.top )
	{
		return true;
	}
	else
	{
		return false;
	}
}
