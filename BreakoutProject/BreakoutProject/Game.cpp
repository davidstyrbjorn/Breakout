#include"Game.h"
#include"Constants.h"

#include<iostream>

Game::~Game() {

}

Game::Game() {
	gameState = GameState::MENU;
}

int Game::run() {

	createWindow(); // Creates a new window

	sf::Clock clock; // Game Clock

	Scene mainScene; // The main scene of the game
	Menu mainMenu(renderWindow);

	while (isRunning) { // Main game loop is here
		sf::Event event;
		while (renderWindow.pollEvent(event)) { // Event loop starts here
			if (event.type == sf::Event::Closed)
				renderWindow.close();

			if(gameState == GameState::PLAYING)
				mainScene.onEvent(event); 
			if (gameState == GameState::MENU)
				mainMenu.onEvent(event,renderWindow);
		}
		// Draw stuff under here
		renderWindow.clear(sf::Color(6,6,6,255));

		/*
		* Changing game state logic
		*/
		if (mainMenu.getPlayTrigger()) {
			gameState = GameState::PLAYING;
			mainScene.newBoardSetup();

			mainMenu.setPlayTrigger(false);
		}
		if (mainScene.getGameOver()) {
			gameState = GameState::MENU;
			mainScene.setGameOver(false);
		}

		/*
		* Check what current state the game is in
		* to decide what scene we should update and draw
		*/
		
		if (gameState == GameState::MENU) {
			mainMenu.update(clock.restart().asSeconds());
			mainMenu.draw(renderWindow);
		}
		if (gameState == GameState::PLAYING) {
			mainScene.update(clock.restart().asSeconds());
			mainScene.draw(renderWindow);
		}

		renderWindow.display();
	}

	return 0;
}

void Game::createWindow() {
	if (renderWindow.isOpen())
		renderWindow.close();

	renderWindow.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
	renderWindow.setFramerateLimit(FPS);
}