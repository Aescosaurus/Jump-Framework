#include "Platform.h"
#include "Graphics.h"

Platform::Platform( const Vei2& pos )
	:
	pos( pos ),
	hitbox( pos,float( Size ),float( Size ) )
{
}

void Platform::Draw( Graphics& gfx ) const
{
	gfx.DrawRect( pos.x,pos.y,Size,Size,Colors::Gray );

	// gfx.DrawHitbox( hitbox );
}

const Rect& Platform::GetRect() const
{
	return( hitbox );
}
