#pragma once
#include <memory> 
#include "Resource.h"
#include <Texture.h>

typedef std::shared_ptr<Resource<aie::Texture>> TexturePtr;

class TempPlayer
{
public:
	TempPlayer(TexturePtr texture) : m_ship(texture) {};
	~TempPlayer() {};

private: 
	TexturePtr m_ship;
};