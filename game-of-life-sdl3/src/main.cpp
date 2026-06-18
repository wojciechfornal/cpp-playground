#include "Game.hpp"

int main(int argc, char* argv[]) {

    Game game;

    if (!game.init("The Vicious Cycle of Life", 800, 600)) {
        return -1;
    }

    game.run();
    
    return 0;

}
