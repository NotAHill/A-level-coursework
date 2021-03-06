#pragma once
#ifndef OBJECT_H
#define OBJECT_H

#include "Entity.h"
#include "../Model/TexturedModel.h"
#include "../Maths/CollisionBox.h"

#include <SFML/Graphics/Texture.hpp>

class Object : public Entity
{
public:
	Object(TexturedModel& _model, glm::vec3 _position, glm::vec3 _rotation, float _scale);
	virtual ~Object() {}

	TexturedModel* getModel() const;
	CollisionBox box;
	
private:
	// make unique ptr instead
	TexturedModel* model;
	
};



#endif // !OBJECT_H

