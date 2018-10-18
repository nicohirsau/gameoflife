#ifndef ASCII_RENDERER_H
#define ASCII_RENDERER_H

#include <vector>
#include <string>
#include <iostream>

void Render(int width, int height, std::vector<bool> *culture);
void ClearScreen(int, int);

#endif