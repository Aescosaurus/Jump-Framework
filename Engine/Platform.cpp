#include "Platform.h"

Platform::Platform( const Vei2& pos )
	:
	pos( pos ),
	hitbox( pos,size,size )
{
}

void Platform::Draw( Graphics& gfx ) const
{
	gfx.DrawRect( pos.x,pos.y,size,size,Colors::Gray );

	// gfx.DrawHitbox( hitbox );
}

const Rect& Platform::GetRect() const
{
	return( hitbox );
}
