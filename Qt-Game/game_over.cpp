#include "game_over.h"
#include "static_game.h"

void Game_over::End_game()
{
Static_game::instance().getGame()->close();
}
