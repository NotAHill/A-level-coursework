#pragma once
#ifndef CAMERA_H
#define CAMERA_H

#include "Entity.h"

// Temporary
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera : public Entity
{
public:
	Camera();

	void update();
	void hookEntity(const Entity& _entity);
	
	const glm::vec3& getPosition() const;

	const glm::mat4 getViewMatrix() const;
	const glm::mat4 getProjectionMatrix() const;	
	
private:
	const Entity* entity;

	glm::mat4 projectionMatrix;
	glm::mat4 viewMatrix;
	glm::vec3 displacement;
};


#endif // !CAMERA_H

