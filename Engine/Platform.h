#pragma once

#include "Vec2.h"
#include "Rect.h"

class Platform
{
public:
	Platform( const Vei2& pos );

	void Draw( class Graphics& gfx ) const;

	const Rect& GetRect() const;
public:
	static constexpr int Size = 32;
private:
	const Vei2 pos;
	const Rect hitbox;
};