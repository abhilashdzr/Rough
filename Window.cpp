#include "Window.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
using namespace std;

SDL_Renderer* Window::rend = nullptr;
Window::Window() {
    frozen = true;
}

Window::~Window() {

}

/*void Window::update(float  deltaTime) {
    game->update();
}*/

void Window::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);


    switch (event.type) {
    case SDL_QUIT:
        isRunning = false;
        break;
    case SDL_KEYDOWN:
        handleKeyDown(event.key);
        break;
    case SDL_KEYUP:
        handleKeyUp(event.key);
        break;
    case SDL_WINDOWEVENT:
        if (event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED) {
            resizeWindow(event.window.data1, event.window.data2);
        }
        break;
    case SDL_MOUSEBUTTONDOWN:
        //game->handleMouseButtonDown(event.button);
        break;
    case SDL_MOUSEBUTTONUP:
        //game.handleMouseUp(event.button);
        break;
    }
}

void Window::handleKeyDown(SDL_KeyboardEvent& key) {

    switch (key.keysym.scancode) {
    case (21):
        game->reset();
        break;
    case 6:
        game->calculateBoardStates();
        break;
    case 19:                                                        //can do with tab
        game->togglePromotionOptions();
        break;
    case 53:
        game->makeRandomMove();
        break;
    case 29:
        game->unmakeMove();
        break;
    default:
        std::cout << "Scancode is:" << key.keysym.scancode << std::endl;
        break;
    }
}
void Window::handleKeyUp(SDL_KeyboardEvent& key) {

    switch (key.keysym.scancode) {


    default:
        //std::cout << "Scancode is:" << key.keysym.scancode << std::endl;
        break;
    }
}



void Window::clean() {
    //delete(game);

    SDL_DestroyRenderer(Window::rend);
    SDL_DestroyWindow(window);  //error here
    SDL_Quit();


    std::cout << "Succesfully cleaned!\n";
}

bool Window::running() {
    return isRunning;
}


void Window::render() {
    // load the image into memory using SDL_image library function
    SDL_Surface* board_img = IMG_Load("resources/board.jpg");

    SDL_Texture* board = SDL_CreateTextureFromSurface(Window::rend, board_img);
    SDL_FreeSurface(board_img);

    SDL_RenderClear(Window::rend);

    SDL_RenderCopy(Window::rend, board, NULL, NULL);

    // game->render();

    SDL_RenderPresent(Window::rend);
}


void Window::init(const char* title, int xpos, int ypos, bool fullscreen) {
    int flags = 0;
    Uint32 rend_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;

    flags = SDL_WINDOW_RESIZABLE;
    if (fullscreen) {
        flags = flags | SDL_WINDOW_FULLSCREEN;
    }

    // attempt to initialize SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        cout << "Can't initialize SDL: " << SDL_GetError() << "\n";
    }


    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {

        std::cout << "Subsystems Initialized!\n";

        //calculateInitialWindowDimensions();

        window = SDL_CreateWindow(title, xpos, ypos, 800, 800, rend_flags);
        if (window) {
            std::cout << "Window Created!\n";
            //SDL_SetWindowMinimumSize(window, MIN_WINDOW_WIDTH, MIN_WINDOW_HEIGHT);
        }


        Window::rend = SDL_CreateRenderer(window, -1, rend_flags);


        if (!Window::rend) {
            cout << "Could not initialize renderer, fuck off SDL" << endl;
        }

        SDL_Surface* img = IMG_Load("resources/board.jpg");

        SDL_Texture* board = SDL_CreateTextureFromSurface(rend, img);
        SDL_FreeSurface(img);

        // clear the window
        SDL_RenderClear(rend);
        // draw the board to the window
        SDL_RenderCopy(rend, board, NULL, NULL);

        SDL_RenderPresent(rend);


        SDL_DestroyTexture(board);
        isRunning = true;

        //game = new Game();
        //game->init();



    }

    else {
        isRunning = false;
        fprintf(stderr, "Something failed in SDL setup\n");
    }

}


//?????

//sets the initial height and width to be a square that is 80% of the smallest dimension.
// void Window::calculateInitialWindowDimensions() {
//     SDL_DisplayMode DM;
//     SDL_GetCurrentDisplayMode(0, &DM);
//     auto Width = DM.w;
//     auto Height = DM.h;


//     //If height is smaller.
//     int squareWidth;
//     if (Width > Height) {
//         squareWidth = .8 * Height;
//     }
//     else {
//         squareWidth = .8 * Width;
//     }
//     Window::screenHeight = Window::screenWidth = squareWidth;
// }
