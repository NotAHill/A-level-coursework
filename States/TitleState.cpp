#include "TitleState.h"
#include "MenuState.h"
#include "../Game.h"

#include <iostream>

TitleState::TitleState(Game& game) :
	BaseState(game),
	text(),
	timer(sf::Time::Zero),
	showText(true)
{
	backgroundSprite.setTexture(ResourceManager::get().textures.get("background"));

	// Set the sprite to screen size
	backgroundSprite.setScale(
		gamePtr->getWindow().getSize().x / backgroundSprite.getLocalBounds().width,
		gamePtr->getWindow().getSize().y / backgroundSprite.getLocalBounds().height);

	text.setFont(ResourceManager::get().fonts.get("Fixedsys"));
	text.setString("Press any key to start");
	text.setFillColor(sf::Color::White);
	text.setOutlineColor(sf::Color::Black);
	text.setOutlineThickness(3.0f);
	text.setCharacterSize(48u);

	text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
	text.setPosition(sf::Vector2f(gamePtr->getWindow().getSize() / 2u));
	
	std::cout << "Currently in TITLE state" << std::endl;
}

bool TitleState::update(sf::Time deltaTime)
{
	timer += deltaTime;

	if (timer >= sf::seconds(0.5f))
	{
		showText = !showText;
		timer = sf::Time::Zero;
	}
	return true;
}

bool TitleState::render(RenderMaster& renderer)
{
	renderer.drawSFML(backgroundSprite);

	if (showText)
		renderer.drawSFML(text);

	// bottom of stack - irrelevant
	return true;
}

bool TitleState::fixedUpdate(sf::Time deltaTime)
{
	return false;
}

bool TitleState::handleEvent(sf::Event& event)
{
	// If any key is pressed move to the next screen
	if (event.type == sf::Event::KeyReleased)
	{
		gamePtr->getStack().popState();
		gamePtr->getStack().pushState<MenuState>(*gamePtr);
	}

	return true;
}
