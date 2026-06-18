#pragma once
#include <vector>

/**
 * @brief Tracks cell states using standard dynamic arrays and handles Conway's rules.
 */
class Grid {

    public:

        Grid(int width, int height);

        void randomize(float probability = 0.2f);
        void update();
        void clear();
        void toggleCell(int x, int y);

        bool isAlive(int x, int y) const;

        int getWidth() const {
            return m_width;
        }
        
        int getHeight() const {
            return m_height;
        }

    private:

        int m_width;
        int m_height;

        int countNeighbors(int x, int y) const;
        int getIndex(int x, int y) const;        

        std::vector<bool> m_cells;

};