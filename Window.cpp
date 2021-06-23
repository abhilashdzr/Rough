#include "Window.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
using namespace std;

SDL_Renderer* Window::rend = nullptr;                       //initializing the render window object

Window::Window() {
    frozen = true;
}

Window::~Window() {

}

/*void Window::update(float  deltaTime) {
    game->update();
}*/

void Window::init(const char* title, int xpos, int ypos, bool fullscreen) {

    Uint32 rend_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        window = SDL_CreateWindow(title, xpos, ypos,  Window::HEIGHT, Window::WIDTH, rend_flags);
        if (window)             std::cout << "Window Created!\n";
        Window::rend = SDL_CreateRenderer(window, -1, rend_flags);
        if (!Window::rend)      cout << "Could not initialize renderer, noob developers noted" << endl;

        isRunning = true;

        //game = new Game();
        //game->init();
    }
    else
        isRunning = false;
}


void Window::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type) {
    case SDL_QUIT:
        isRunning = false;
        break;
    // case SDL_KEYDOWN:
    //     handleKeyDown(event.key);
    //     break;
    case SDL_KEYUP:
        handleKeyUp(event.key);
        break;
        // case SDL_WINDOWEVENT:
        //     if (event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED) {
        //         resizeWindow(event.window.data1, event.window.data2);
        //     }
        //     break;
        // case SDL_MOUSEBUTTONDOWN:
        //     game->handleMouseButtonDown(event.button);
        //     break;
        // case SDL_MOUSEBUTTONUP:
        //     game.handleMouseUp(event.button);
        //     break;
    }
}


void Window::handleKeyDown(SDL_KeyboardEvent& key)
{
    switch (key.keysym.scancode)
    {
    case SDLK_r: // r_key
        //game->reset();
        break;
    case SDLK_TAB: // tab_key
        //game->togglePromotionOptions();
        break;
    // case SDLK_RETURN: // enter_key
    //     game->calculateBoardStates();
    //     break;
    default:
        break;
    }
}


void Window::handleKeyUp(SDL_KeyboardEvent& key)
{
    switch (key.keysym.scancode)
    {
    default:
        std::cout << "Scancode is:" << key.keysym.scancode << std::endl;
        break;
    }
}



void Window::clean()
{
    //delete(game);
    SDL_DestroyRenderer(Window::rend);
    SDL_DestroyWindow(window);  //error here
    SDL_Quit();
    std::cout << "Succesfully cleaned!\n";
}



bool Window::running() { return isRunning; }



void Window::render() {
    // load the image into memory using SDL_image library function
    SDL_Surface* board_img = IMG_Load("resources/board.jpg");

    SDL_Texture* board = SDL_CreateTextureFromSurface(Window::rend, board_img);
    SDL_FreeSurface(board_img);

    //clear the window
    SDL_RenderClear(Window::rend);
    //draw the window to the board
    SDL_RenderCopy(Window::rend, board, NULL, NULL);
    // game->render();
    SDL_RenderPresent(Window::rend);

    SDL_DestroyTexture(board);

}
