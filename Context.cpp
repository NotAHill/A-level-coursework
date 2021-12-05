#include "Context.h"
#include <iostream>

Context::Context(sf::VideoMode size, sf::String title, bool fullscreen)
{
	// Configure OpenGL context settings
	sf::ContextSettings settings;
	settings.antialiasingLevel = 0;
	settings.majorVersion = 3;
	settings.minorVersion = 3;
	settings.depthBits = 24;
	settings.stencilBits = 8;

	// Create our window with specified context settings
	if (fullscreen)
		window.create(sf::VideoMode::getDesktopMode(), title, sf::Style::Fullscreen, settings);
	else
		window.create(size, title, sf::Style::Close | sf::Style::Titlebar, settings);

	// Load OpenGL function pointers
	//gladLoadGLLoader(reinterpret_cast<GLADloadproc>(sf::Context::getFunction))
	if (!gladLoadGL())
	{
		std::cerr << "Unable to load OpenGL functions\n";
		exit(-1);
	}

	// Create the OpenGL viewport
	glViewport(0, 0, window.getSize().x, window.getSize().y);
	window.setFramerateLimit(60);
}