#include <iostream>
#include "backend/petridish.hpp"
#include "frontend/ascii_renderer.hpp"
#include <windows.h>

int main(int argc, char *argv[]) {
	std::cout << *argv << std::endl;
	int width, height;
	std::cout << "Enter <width height>:";
	std::cin >> width >> height;
	
	Petridish p(width, height);
	p.InitializeRandomCulture();
	while (true) {
		system("cls");
		ASCII_RENDERER_H::Render(width, height, p.GetCulture());
		p.Update();
		p.ApplyBuffer();
		Sleep(200);
	}
	std::cin.ignore();
	std::cin.get();

	return 0;
}