/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*   main.cpp                                              by CanTale_Games   */
/*                                                                            */
/*                                                                            */
/******************************************************************************/

#include "main.h"

void	init_everything(void)
{
	Game::init(GAME_NAME, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			WINDOW_WIDTH, WINDOW_HEIGHT, FULLSCREEN);
	Editor::init();
	Keys::init();
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	init_everything();
	while (Editor::isRunning())
	{
		Editor::handleEvents();
		Editor::update();
	}
	while(Game::isRunning())
	{
		Time::calculateDelta();
		Game::handleEvents();
		Game::update();
		SDL_Delay(1);
	}
	Game::clear();
	return (0);
}
