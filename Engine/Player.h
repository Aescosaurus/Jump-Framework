#pragma once

#include "Graphics.h"
#include "Vec2.h"
#include "Keyboard.h"
#include "Rect.h"
#include "Platform.h"

class Player
{
public:
	Player( const Vei2& pos );

	void Update( const Keyboard& kbd,float dt );
	void Draw( Graphics& gfx ) const;

	// Call once for everything you want to collide with.
	bool CheckHit( const Rect& rect );
	// Call with a vector of items to collide with.
	template<typename T>
	bool CheckHits( const std::vector<T>& items )
	{
		bool hasHit = false;

		for( const T& item : items )
		{
			if( CheckHit( item.GetRect() ) ) hasHit = true;
		}

		return hasHit;
	}
private:
	void Land();
	void Fall();

	bool HitTestTop( const Rect& rect ) const;
	bool HitTestBot( const Rect& rect ) const;
	bool HitTestLeft( const Rect& rect ) const;
	bool HitTestRight( const Rect& rect ) const;
private:
	Vec2 pos;
	static constexpr int size = 32;
	// For hit test math.
	static constexpr int offset = size / 4;

	float vel = 0.0f;
	static constexpr float speed = 50.0f;
	static constexpr float maxSpeed = speed * 2.5f;
	static constexpr float slowdownFactor = 0.96f;

	static constexpr float gravAcc = 6.9f / 0.05f;
	float grav = 0.0f;
	static constexpr int jumpPower = 202;
	bool jumping = false;
	bool canJump = false;
};