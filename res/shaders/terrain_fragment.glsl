#version 330 core

#define MAX_LIGHTS 4

out vec4 outColour;
in vec3 passColour;

// Phong Shading
struct Light
{
	vec3 direction;	
	vec3 bias;
	vec3 colour;
};

flat in vec3 passNormal;
in vec3 passFragPos;

uniform vec3 cameraPos;
uniform Light light[MAX_LIGHTS];

vec3 calculateLighting()
{
	vec3 normal = normalize(passNormal);
	vec3 viewDir = normalize(cameraPos - passFragPos);
	vec3 totalLight = vec3(0.0);

	for (int i = 0; i < MAX_LIGHTS; i++)
	{
		float brightness = max(dot(-light[i].direction, normal), 0.0);
		vec3 reflectDir = reflect(light[i].direction, normal);
		float shininess = pow(max(dot(viewDir, reflectDir), 0.0), 32);
		
		totalLight += (light[i].colour * light[i].bias.x) + (brightness * light[i].colour * light[i].bias.y) + (shininess * light[i].colour * light[i].bias.z);
	}

	return totalLight;
}

void main()
{
	vec3 lighting = calculateLighting();
	outColour = vec4(passColour * lighting, 1.0);
}

// Gouraud Shading
//void main()
//{
//	outColour = vec4(passColour, 1.0);
//}