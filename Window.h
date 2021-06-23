#pragma once
#include <SDL2/SDL.h>

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

	void init(const char* title, int xpos, int ypos, bool fullscreen);
	void handleEvents();
	void handleKeyDown(SDL_KeyboardEvent& key);
	void handleKeyUp(SDL_KeyboardEvent& key);
	static SDL_Renderer* rend;
	const static int HEIGHT = 800;
	const static int WIDTH = 800;
private:
	bool isRunning;
	SDL_Window* window;
	bool frozen;

};
