g++ *.cpp -I SDL2\include -I SDL2_image\include -L SDL2\lib -L SDL2_image\lib -w -Wl,-subsystem,windows -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -o run_test