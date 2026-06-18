#include "Game.hpp"
#include <iostream>

Game::Game()
    : m_grid(80, 60) {}

Game::~Game() {

    if (m_renderer) {
        SDL_DestroyRenderer(m_renderer);
    }

    if (m_window) {
        SDL_DestroyWindow(m_window);
    }

    SDL_Quit();

}

bool Game::init(const char* title, int width, int height) {

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        std::cerr << "SDL_Init error: " << SDL_GetError() << std::endl;
        return false;
    }

    m_window = SDL_CreateWindow(title, width, height, 0);
    if (!m_window) {
        std::cerr << "SDL_CreateWindow error: " << SDL_GetError() << std::endl;
        return false;
    }

    m_renderer = SDL_CreateRenderer(m_window, nullptr);
    if (!m_renderer) {
        std::cerr << "SDL_CreateRenderer error: " << SDL_GetError() << std::endl;
        return false;
    }

    int gridWidth = width / m_cellSize;
    int gridHeight = height / m_cellSize;
    m_grid = Grid(gridWidth, gridHeight);
    m_grid.randomize(0.2f);

    m_isRunning = true;
    m_lastUpdateTime = SDL_GetTicks();

    return true;

}

void Game::run() {

    while (m_isRunning) {
        handleEvents();
        update();
        render();
        SDL_Delay(8);
    }

}

void Game::handleEvents() {

    SDL_Event event;
    
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_QUIT) {
            m_isRunning = false;
        } else if (event.type == SDL_EVENT_KEY_DOWN) {
            switch (event.key.key) {
                case SDLK_ESCAPE:
                    m_isRunning = false;
                    break;
                case SDLK_SPACE:
                    m_isPaused = !m_isPaused;
                    break;
                case SDLK_R:
                    m_grid.randomize(0.2f);
                    break;
                case SDLK_C:
                    m_grid.clear();
                    break;
                default:
                    break;
            }
        } else if (event.type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
            if (event.button.button == SDL_BUTTON_LEFT) {
                int gridX = static_cast<int>(event.button.x) / m_cellSize;
                int gridY = static_cast<int>(event.button.y) / m_cellSize;
                m_grid.toggleCell(gridX, gridY);
            }
        } else if (event.type == SDL_EVENT_MOUSE_MOTION) {
            if (event.motion.state & SDL_BUTTON_MASK(SDL_BUTTON_LEFT)) {
                int gridX = static_cast<int>(event.motion.x) / m_cellSize;
                int gridY = static_cast<int>(event.motion.y) / m_cellSize;
                if (gridX >= 0 && gridX < m_grid.getWidth() && gridY >= 0 && gridY < m_grid.getHeight()) {
                    
                }
            }
        }
    }

}

void Game::update() {
    
    if (m_isPaused) {
        return;
    }

    Uint64 currentTime = SDL_GetTicks();
    if (currentTime - m_lastUpdateTime >= m_updateIntervalMs) {
        m_grid.update();
        m_lastUpdateTime = currentTime;
    }

}

void Game::render() {

    SDL_SetRenderDrawColor(m_renderer, 23, 23, 30, 255);
    SDL_RenderClear(m_renderer);
    drawGrid();
    SDL_RenderPresent(m_renderer);

}

void Game::drawGrid() {

    int width = m_grid.getWidth();
    int height = m_grid.getHeight();

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            SDL_FRect cellRect = {
                static_cast<float>(x * m_cellSize),
                static_cast<float>(y * m_cellSize),
                static_cast<float>(m_cellSize),
                static_cast<float>(m_cellSize)
            };
            if (m_grid.isAlive(x, y)) {
                SDL_SetRenderDrawColor(m_renderer, 16, 185, 129, 255);
                SDL_RenderFillRect(m_renderer, &cellRect);
                SDL_SetRenderDrawColor(m_renderer, 5, 150, 105, 255);
                SDL_RenderRect(m_renderer, &cellRect);
            } else {
                SDL_SetRenderDrawColor(m_renderer, 30, 30, 40, 255);
                SDL_RenderRect(m_renderer, &cellRect);
            }
        }
    }

}