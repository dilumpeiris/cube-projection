#include <iostream>
#include <math.h>
#include "Window.h"
#include "Cube.h"

using namespace cube;

int main()
{
    bool runing = true;

    Window window;
    if (!window.Init())
    {
        std::cout << "Error Initialiaing SDL" << std::endl;
    }
    window.clearPixels();

    Cube cube;
    cube.update();
    cube.getRelations();

    int t_speed = 10;
    int r_speed = 3;
    while (runing)
    {

        int elapsed = SDL_GetTicks();
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_KEYDOWN)
            {
                if (event.type == SDL_KEYDOWN)
                {
                    if (event.key.keysym.sym == SDLK_w)
                    {
                        cube.y_pos = cube.y_pos + t_speed;
                        cube.update();
                        cube.getRelations();
                    }
                    else if (event.key.keysym.sym == SDLK_s)
                    {
                        cube.y_pos = cube.y_pos - t_speed;
                        cube.update();
                        cube.getRelations();
                    }
                    else if (event.key.keysym.sym == SDLK_a)
                    {
                        cube.x_pos = cube.x_pos - t_speed;
                        cube.update();
                        cube.getRelations();
                    }
                    else if (event.key.keysym.sym == SDLK_d)
                    {
                        cube.x_pos = cube.x_pos + t_speed;
                        cube.update();
                        cube.getRelations();
                    }
                    else if (event.key.keysym.sym == SDLK_UP)
                    {
                        cube.x_rot = cube.x_rot + r_speed;

                        cube.rotate();
                        cube.update();
                        cube.getRelations();
                    }
                    else if (event.key.keysym.sym == SDLK_DOWN)
                    {
                        cube.x_rot = cube.x_rot - r_speed;

                        cube.rotate();
                        cube.update();
                        cube.getRelations();
                    }
                    else if (event.key.keysym.sym == SDLK_RIGHT)
                    {
                        cube.y_rot = cube.y_rot + r_speed;

                        cube.rotate();
                        cube.update();
                        cube.getRelations();
                    }
                    else if (event.key.keysym.sym == SDLK_LEFT)
                    {
                        cube.y_rot = cube.y_rot - r_speed;

                        cube.rotate();
                        cube.update();
                        cube.getRelations();
                    }
                }
            }
            else if (event.type == SDL_QUIT)
            {
                runing = false;
            }
        }

        SDL_Delay(5);

        for (size_t i = 0; i < 12; i++)
        {
            int x1 = cube.rel[i][0][0];
            int y1 = cube.rel[i][0][1];
            int x2 = cube.rel[i][1][0];
            int y2 = cube.rel[i][1][1];

            window.drawLine(x1, y1, x2, y2, 255, 255, 255);
        }
        window.screenUpdate();
        window.clearPixels();
    }
}