#include "Game.h"
#include "IntroState.h"

int main(int argc, char* args[])
{
    // Create Game and States 
    std::unique_ptr<Game> game = std::make_unique<Game>();
    std::unique_ptr<IntroState> intro = std::make_unique<IntroState>(game.get());

    if (game->initialize() == false)
    {
        // TODO: Use SDL message boxes to display these errors
        // TODO: Create trace log
        printf("Failed to Initialize!");
        return 1;
    }

    game->change_state(intro.get());

    while (game->running())
    {
        game->handle_events();
        game->update();
        game->draw();

        // TODO: Control frame rate
    }

    return 0;
}
