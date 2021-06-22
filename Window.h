#pragma once
#include <SDL2/SDL.h>

#undef main

#include <vector>

class Window
{
public:
	//void update(float deltaTime);
	//void handleEvents();
	void clean();
	void render();
	bool running();

	Window();
	~Window();
	//void calculateInitialWindowDimensions();

	void init(const char* title, int xpos, int ypos, bool fullscreen);
	//void handleKeyDown(SDL_KeyboardEvent& key);
	//void handleKeyUp(SDL_KeyboardEvent& key);
	//void resizeWindow(int windowWidth, int windowHeight);
	static SDL_Renderer* rend;
	//static int screenHeight;
	//static int screenWidth;
private:
	bool isRunning;
	SDL_Window* window;
	bool frozen;

};
