#pragma once

#include <vector>

#include <SDL2/SDL.h>

class Window
{
public:
	//void update();
	//void handleEvents();
	void clean();
	void render();
	bool running();

	//void calculateInitialWindowDimensions();

	void init(const char* title, int xpos, int ypos);
	//void handleKeyDown(SDL_KeyboardEvent& key);
	//void handleKeyUp(SDL_KeyboardEvent& key);
	static SDL_Renderer* rend;
	static int HEIGHT = WIDTH = 800;

private:
	bool isRunning;
	SDL_Window* window;
};
