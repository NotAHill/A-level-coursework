#pragma once
#ifndef RENDERMASTER_H
#define RENDERMASTER_H

#include "QuadRenderer.h"
#include "SFMLRenderer.h"

class Game;

class RenderMaster
{
public:
	RenderMaster(Game& game);

	void drawQuad(const Vector3& pos);
	void drawSFML(const sf::Drawable& drawable);
	void finishRender(sf::RenderWindow& window);

private:
	QuadRenderer quadRenderer;
	SFMLRenderer sfmlRenderer;
};



#endif // !RENDERMASTER_H