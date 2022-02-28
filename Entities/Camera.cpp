#include "Camera.h"

#include "../Maths/Matrix.h"

/*
rotation x = pitch
rotation y = yaw
rotation z = roll
*/

Camera::Camera()
{
	projectionMatrix = makeProjectionMatrix(45.0f);
	position = { 0, 0, -3.5f };
	rotation = { 0, 0, 0 };
	displacement = { 0, 2.0f, -3.5f };
}

void Camera::update()
{
	if (entity != nullptr)
	{
		position = entity->position + displacement; // Displacement for 3rd person only
		rotation = entity->rotation;
	}

	viewMatrix = makeViewMatrix(*this);
}

void Camera::hookEntity(const Entity& _entity)
{
	entity = &_entity;
}

const glm::vec3& Camera::getPosition() const
{
	return position;
}

const glm::mat4 Camera::getViewMatrix() const
{
	return viewMatrix;
}

const glm::mat4 Camera::getProjectionMatrix() const
{
	return projectionMatrix;
}
