#pragma once

#include "Vec2.h"
#include "Rect.h"
#include "Graphics.h"

class Platform
{
public:
	Platform( const Vei2& pos );

	void Draw( Graphics& gfx ) const;

	const Rect& GetRect() const;
private:
	const Vei2 pos;
	static constexpr int size = 64;
	const Rect hitbox;
};