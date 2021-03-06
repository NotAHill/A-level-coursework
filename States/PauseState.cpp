#include "PauseState.h"

#include "GameState.h"
#include "MenuState.h"

#include "../Game.h"
#include "../GUI/Button.h"
#include "../GUI/Label.h"

#include <iostream>

PauseState::PauseState(Game& game) :
	BaseState(game),
	backgroundShape()
{
	std::cout << "Currently in PAUSE state" << std::endl;

	auto window = gamePtr->getWindow().getSize();

	backgroundShape.setFillColor({ 0, 0, 0, 150 });
	backgroundShape.setSize(sf::Vector2f(gamePtr->getWindow().getSize()));

	auto text = std::make_shared<Label>(true);
	text->text.setCharacterSize(50u);
	text->setText({ "Game Paused" });
	text->setPosition({ window.x / 2.0f, window.y / 2.0f - 150.0f });


	auto playButton = std::make_shared<Button>(ButtonSize::SMALL);
	playButton->setText("Resume");
	playButton->setPosition({ window.x / 2.0f, window.y / 2.0f - 50.0f });
	playButton->setCallback([&]()
		{
			gamePtr->getStack().popState();
		});

	auto menuButton = std::make_shared<Button>(ButtonSize::SMALL);
	menuButton->setText("Menu");
	menuButton->setPosition({ window.x / 2.0f, window.y / 2.0f + 50.0f });
	menuButton->setCallback([&]()
		{
			gamePtr->getStack().clearStates();
			gamePtr->getStack().pushState<MenuState>(*gamePtr);
		});

	auto quitButton = std::make_shared<Button>(ButtonSize::SMALL);
	quitButton->setText("Quit");
	quitButton->setPosition({ window.x / 2.0f, window.y / 2.0f + 150.0f });
	quitButton->setCallback([&]()
		{
			gamePtr->getStack().clearStates();
		});

	container.addComponent(text);
	container.addComponent(playButton);
	container.addComponent(menuButton);
	container.addComponent(quitButton);
}

bool PauseState::update(sf::Time deltaTime)
{
	// Return false so that all the states below it on the stack are not updated
	return false;
}

bool PauseState::render(RenderMaster& renderer)
{
	// Draw background first
	renderer.drawSFML(backgroundShape);

	container.render(renderer);

	return true;
}

bool PauseState::fixedUpdate(sf::Time deltaTime)
{
	return false;
}

bool PauseState::handleEvent(sf::Event& event)
{
	container.handleEvent(event, gamePtr->getWindow());

	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::BackSpace)
		{
			// Backspace pressed, remove itself to return to the game
			gamePtr->getStack().popState();
		}
	}

	return false;
}
