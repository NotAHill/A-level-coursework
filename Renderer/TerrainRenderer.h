#pragma once
#ifndef TERRAINRENDERER_H
#define TERRAINRENDERER_H


#include "../Model.h"
#include "../Util/Shader.h"
#include "../Camera.h"

#include <vector>
#include <SFML/Graphics/Image.hpp>

class Game;
class Model;

class TerrainRenderer
{
public:
	TerrainRenderer();
	void add(const Vector3& position);
	void render(const Camera& camera);

private:
	float getHeight(const unsigned int& u, const unsigned int& v, const sf::Image& image);

	std::vector<Vector3> terrainList;
	Model terrainModel;
	
	float size;
	float maxHeight;
};



#endif // !TERRAINRENDERER_H
