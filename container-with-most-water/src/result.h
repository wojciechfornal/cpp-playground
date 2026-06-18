#pragma once

struct Result {

    int area = 0;
    int l_side = 0;
    int r_side = 0;
    int width = 0;
    bool error = true;

    Result() = default;

    Result(int area, int l_side, int r_side, int width, bool error = false)
        : area(area), l_side(l_side), r_side(r_side), width(width), error(error) {}

};