#include "RenderMaster.h"

RenderMaster::RenderMaster(Game& game) :
	quadRenderer(game)
{
}

void RenderMaster::drawQuad(const Vector3& pos)
{
	quadRenderer.add(pos);
}

void RenderMaster::drawSFML(const sf::Drawable& drawable)
{
	sfmlRenderer.add(drawable);
}

void RenderMaster::finishRender(sf::RenderWindow& window)
{
	glClearColor(0.1f, 0.5f, 1.0f, 1.0f);
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);

	quadRenderer.render();

	sfmlRenderer.render(window);

	window.display();
}