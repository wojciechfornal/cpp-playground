#include "Grid.hpp"
#include <random>
#include <algorithm>

Grid::Grid(int width, int height)
    : m_width(width), m_height(height), m_cells(width * height, false) {}

void Grid::randomize(float probability) {

    // The seed, the engine, and the distribution
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dis(0.0f, 1.0f);

    for (int i = 0; i < m_width * m_height; ++i) {
        m_cells[i] = (dis(gen) < probability);
    }

}

void Grid::clear() {
    std::fill(m_cells.begin(), m_cells.end(), false);
}

void Grid::toggleCell(int x, int y) {
    if (x >= 0 && x < m_width && y >= 0 && y < m_height) {
        int index = getIndex(x, y);
        m_cells[index] = !m_cells[index];
    }
}

bool Grid::isAlive(int x, int y) const {
    if (x >= 0 && x < m_width && y >= 0 && y < m_height) {
        int index = getIndex(x, y);
        return m_cells[index];
    }
    return false;
}

int Grid::getIndex(int x, int y) const {
    return y * m_width + x;
}

int Grid::countNeighbors(int x, int y) const {
    int count = 0;
    for (int dy = -1; dy <= 1; ++dy) {
        for (int dx = -1; dx <= 1; ++dx) {
            if (dx == 0 && dy == 0) continue;
            // Let's just not crash because of out of bounds error
            int nx = (x + dx + m_width) % m_width;
            int ny = (y + dy + m_height) % m_height;
            if (m_cells[getIndex(nx, ny)]) {
                count++;
            }
        }
    }
    return count;
}

void Grid::update() {

    std::vector<bool> nextCells(m_width * m_height, false);

    // The vicious circle of life
    for (int y = 0; y < m_height; ++y) {
        for (int x = 0; x < m_width; ++x) {
            int neighbors = countNeighbors(x, y);
            int index = getIndex(x, y);
            bool alive = isAlive(x, y);
            if (alive) {
                nextCells[index] = (neighbors == 2 || neighbors == 3);
            } else {
                nextCells[index] = (neighbors == 3);
            }
        }
    }

    m_cells = std::move(nextCells);

}