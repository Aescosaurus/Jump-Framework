#pragma once

#include <vector>
#include "Graphics.h"
#include <fstream>
#include <cassert>

class Map
{
public:
	static void Load( const std::string& filePath );
	static char Get( int x,int y );
	static char Get( int index );
public:
	static constexpr int Width = 1 + Graphics
		::ScreenWidth / 64;
	static constexpr int Height = 1 + Graphics
		::ScreenHeight / 64;
	static std::vector<char> Data;
};