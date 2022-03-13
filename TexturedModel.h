#pragma once
#ifndef TEXTURED_MODEL
#define TEXTURED_MODEL

#include "Model.h"
#include "Mesh.h"
#include "Texture.h"

class TexturedModel : public Model
{
public:
	TexturedModel();
	TexturedModel(const std::string& mesh, const std::string& texture);
	void addData(const std::vector<float>& vertexPositions, const std::vector<float>& textureCoords, const std::vector<float>& normalDirections, const std::vector<unsigned int>& indices);
	void addData(const Mesh& mesh);
	void bindTexture() const;
	void addTexture(const std::string& name);
	const unsigned int& getID() const;

private:
	unsigned int ID;
};



#endif // !TEXTURED_MODEL
