#include "ascii_renderer.hpp"

void Render(int width, int height, std::vector<bool> *culture) {
    for (int x = 0; x < width; x++) {
        std::string row = "";
        for (int y = 0; y < height; y++) {
            int d_dimension = width * (y % height) + (x % width);
            bool is_cell_living = culture->at(d_dimension);
            row += (is_cell_living) ? "#" : " ";
        }
        std::cout << row << std::endl;
    }
}

void ClearScreen(int width, int height) {
    for (int i = 0; i < width*height; i++)
        std::cout << '\b';
}