#include <iostream>
#include "Window.h"
// #include "Particle.h"
#include "Cube.h"
#include <math.h>

using namespace cube;
// using namespace particles;

struct Vector
{
    double x;
    double y;
    double z;
};

int main()
{
    Window window;

    Cube cube;
    cube.update();
    cube.getRelations();
    if (!window.Init())
    {
        std::cout << "Error Initialiaing SDL" << std::endl;
    }
    window.clearPixels();

    bool runing = true;
    SDL_Event event;
    int x_rot = 0;
    int y_rot = 0;
    while (runing)
    {

        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_KEYDOWN)
            {
                if (event.type == SDL_KEYDOWN)
                {
                    if (event.key.keysym.sym == SDLK_w)
                    {
                        cube.y_pos = cube.y_pos - 3;
                        cube.update();
                        cube.getRelations();
                    }
                    else if (event.key.keysym.sym == SDLK_s)
                    {
                        cube.y_pos = cube.y_pos + 3;
                        cube.update();
                        cube.getRelations();
                    }
                    else if (event.key.keysym.sym == SDLK_a)
                    {
                        cube.x_pos = cube.x_pos + 3;
                        cube.update();
                        cube.getRelations();
                    }
                    else if (event.key.keysym.sym == SDLK_d)
                    {
                        cube.x_pos = cube.x_pos - 3;
                        cube.update();
                        cube.getRelations();
                    }
                    else if (event.key.keysym.sym == SDLK_LEFT)
                    {
                        x_rot = x_rot + 1;

                        cube.rotateX(x_rot, y_rot);
                        cube.update();
                        //
                        cube.getRelations();
                    }
                    else if (event.key.keysym.sym == SDLK_RIGHT)
                    {
                        x_rot = x_rot - 1;

                        cube.rotateX(x_rot, y_rot);
                        cube.update();
                        //
                        cube.getRelations();
                    }
                    else if (event.key.keysym.sym == SDLK_UP)
                    {
                        y_rot = y_rot + 1;

                        cube.rotateX(x_rot, y_rot);
                        cube.update();
                        //
                        cube.getRelations();
                    }
                    else if (event.key.keysym.sym == SDLK_DOWN)
                    {
                        y_rot = y_rot - 1;

                        cube.rotateX(x_rot, y_rot);
                        cube.update();
                        //
                        cube.getRelations();
                    }
                    else
                    {
                    }
                }
            }
            else if (event.type == SDL_QUIT)
            {
                runing = false;
            }
        }

        SDL_Delay(5);

        int elapsed = SDL_GetTicks();

        for (size_t i = 0; i < 12; i++)
        {
            int x1 = cube.rel[i][0][0];
            int y1 = cube.rel[i][0][1];
            int x2 = cube.rel[i][1][0];
            int y2 = cube.rel[i][1][1];

            // printf("%d %d %d %d \n", x1, y1, x2, y2);
            window.drawLine(x1, y1, x2, y2, 255, 255, 255);
        }
        window.screenUpdate();
        window.clearPixels();

        // window.drawLine(x1, y1, 100, y, 0, 0, 0);
        // window.clearPixels();

        // if (!window.processEvents())
        // {
        //     runing = false;
        // }
    }
}