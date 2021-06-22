#include <iostream>
using namespace std;

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Window.h"

SDL_Renderer* Window::rend = nullptr;

// void Window::update() { game->update(); }

void Window::init(const char* title, int xpos, int ypos)
{
    uint32_t rend_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        //calculateInitialWindowDimensions();
        window = SDL_CreateWindow(title, xpos, ypos, Window::HEIGHT, Window::WIDTH, rend_flags);
        Window::rend = SDL_CreateRenderer(window, -1, rend_flags);

        SDL_Surface* board_img = IMG_Load("resources/board.jpg");
        SDL_Texture* board = SDL_CreateTextureFromSurface(rend, board_img);
        SDL_FreeSurface(board_img);

        // clear the window
        SDL_RenderClear(rend);
        // draw the board to the window
        SDL_RenderCopy(rend, board, NULL, NULL);
        SDL_RenderPresent(rend);

        //game = new Game();
        //game->init();
        
        SDL_DestroyTexture(board);
        isRunning = true;
    }
    else
        isRunning = false;
}

// void Window::handleEvents()
// {
//     SDL_Event event;
//     SDL_PollEvent(&event);

//     switch (event.type)
//     {
//         case SDL_QUIT:
//             isRunning = false;
//             break;
//         case SDL_KEYDOWN:
//             handleKeyDown(event.key);
//             break;
//         case SDL_KEYUP:
//             handleKeyUp(event.key);
//             break;
//         case SDL_WINDOWEVENT:
//             if (event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED)
//                 resizeWindow(event.window.data1, event.window.data2);
//             break;
//         case SDL_MOUSEBUTTONDOWN:
//             //game->handleMouseButtonDown(event.button);
//             break;
//         case SDL_MOUSEBUTTONUP:
//             //game.handleMouseUp(event.button);
//             break;
//     }
// }

void Window::handleKeyDown(SDL_KeyboardEvent& key)
{
    switch (key.keysym.scancode)
    {
        case SDLK_r: // r_key
            game->reset();
            break;
        case SDLK_TAB: // tab_key
            game->togglePromotionOptions();
            break;
        // case SDLK_RETURN: // enter_key
        //     game->calculateBoardStates();
        //     break;
        default:
            break;
    }
}

void Window::handleKeyUp(SDL_KeyboardEvent& key) {

    switch (key.keysym.scancode)
    {
        default:
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

void Window::render()
{
    SDL_Surface* board_img = IMG_Load("resources/board.jpg");
    SDL_Texture* board = SDL_CreateTextureFromSurface(rend, board_img);
    SDL_FreeSurface(board_img);

    // clear the window
    SDL_RenderClear(rend);
    // draw the board to the window
    SDL_RenderCopy(rend, board, NULL, NULL);

    // game->render();

    SDL_RenderPresent(Window::rend);
}
