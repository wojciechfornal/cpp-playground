#pragma once
#include <SDL3/SDL.h>
#include "Grid.hpp"

class Game {

    public:

        Game();
        ~Game();

        bool init(const char* title, int width, int height);

        void run();

    private:

        int m_cellSize = 10;
        bool m_isPaused = true;
        bool m_isRunning = false;

        Uint64 m_lastUpdateTime = 0;
        Uint64 m_updateIntervalMs = 80;

        Grid m_grid;

        SDL_Window* m_window = nullptr;
        SDL_Renderer* m_renderer = nullptr;

        void drawGrid();
        void handleEvents();
        void update();
        void render();

};