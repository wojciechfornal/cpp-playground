#include "solution.h"
#include "result.h"
#include <algorithm>

Result Solution::max_area(const std::vector<int>& heights) {

    if (heights.size() < 2) {
        return Result{};
    }

    Result result{};

    int l_cursor = 0;
    int r_cursor = static_cast<int>(heights.size()) - 1;
    int max = 0;

    while (l_cursor < r_cursor) {

        int width = r_cursor - l_cursor;
        int height = std::min(heights[l_cursor], heights[r_cursor]);
        int area = width * height;
        
        if (area > max) {
            max = area;
            result = Result{area, heights[l_cursor], heights[r_cursor], width};
        }

        if (heights[l_cursor] < heights[r_cursor]) {
            l_cursor++;
        } else {
            r_cursor--;
        }
    }
    
    return result;

}