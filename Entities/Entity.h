#pragma once
#ifndef ENTITY_H
#define ENTITY_H

// Temporary
#include <glm/glm.hpp>

class Entity
{
public:
	glm::vec3 position = { 0, 0, 0 };
	glm::vec3 rotation = { 0, 0, 0 };
	glm::vec3 velocity = { 0, 0, 0 };
	float scale = 1.0f;
};

#endif // !ENTITY_H


