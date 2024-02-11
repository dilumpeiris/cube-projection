#include "Window.h"
using namespace std;
namespace cube
{
    Window::Window() : m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer(NULL)
    {
    }
    bool Window::Init()
    {
        if (SDL_Init(SDL_INIT_VIDEO) < 0)
        {
            return 0;
        }

        m_window = SDL_CreateWindow("Cube Rotate", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
        if (m_window == NULL)
        {
            SDL_Quit();
            return 0;
        }

        m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
        m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, WINDOW_WIDTH, WINDOW_HEIGHT);

        if (m_renderer == NULL or m_texture == NULL)
        {
            SDL_DestroyRenderer(m_renderer);
            SDL_DestroyTexture(m_texture);
            SDL_DestroyWindow(m_window);
            SDL_Quit();
            return 0;
        }

        m_buffer = new Uint32[WINDOW_HEIGHT * WINDOW_WIDTH];
        m_bufferBlur = new Uint32[WINDOW_HEIGHT * WINDOW_WIDTH];

        memset(m_buffer, 255, WINDOW_HEIGHT * WINDOW_WIDTH * sizeof(Uint32));
        screenUpdate();
        return true;
    }
    bool Window::processEvents()
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                return false;
            }
        }
        return true;
    }

    void Window::setPixels(int x, int y, Uint8 r, Uint8 g, Uint8 b)
    {

        Uint32 color = 0;

        color += r;
        color <<= 8;
        color += g;
        color <<= 8;
        color += b;
        color <<= 8;
        color += 0xFF;

        int pixel = ((WINDOW_WIDTH / 2 - y) * WINDOW_WIDTH + (WINDOW_WIDTH / 2 + x));
        m_buffer[pixel] = color;
    }

    void Window::drawLine(int x1, int y1, int x2, int y2, Uint8 r, Uint8 g, Uint8 b)
    {
        double x = x2 - x1;
        double y = y2 - y1;

        double len = sqrt((x * x) + (y * y));

        double ax = x / len;
        double ay = y / len;

        x = x1;
        y = y1;
        for (size_t i = 0; i < len; i++)
        {
            if (abs(x) < WINDOW_WIDTH / 2 & abs(y) < WINDOW_HEIGHT / 2)
            {
                setPixels((int)x, (int)y, r, g, b);
            }
            x += ax;
            y += ay;
        }
    }

    void Window::screenBlur()
    {
        Uint32 *temp = m_buffer;
        m_buffer = m_bufferBlur;
        m_bufferBlur = temp;

        for (int y = 0; y < WINDOW_HEIGHT; y++)
        {
            for (int x = 0; x < WINDOW_WIDTH; x++)
            {
                int redTotal = 0;
                int greenTotal = 0;
                int blueTotal = 0;
                for (int row = -1; row <= 1; row++)
                {
                    for (int col = -1; col <= 1; col++)
                    {
                        int currentY = y + row;
                        int currentX = x + col;

                        if (currentX >= 0 && currentX < WINDOW_WIDTH && currentY >= 0 && currentY < WINDOW_HEIGHT)
                        {
                            Uint32 color = m_bufferBlur[currentY * WINDOW_WIDTH + currentX];

                            Uint8 red = color >> 24;
                            Uint8 green = color >> 16;
                            Uint8 blue = color >> 8;

                            redTotal += red;
                            greenTotal += green;
                            blueTotal += blue;
                        }
                    }
                }
                Uint8 red = redTotal / 9;
                Uint8 green = greenTotal / 9;
                Uint8 blue = blueTotal / 9;
                Uint32 color = 0;

                color += red;
                color <<= 8;
                color += green;
                color <<= 8;
                color += blue;
                color <<= 8;
                color += 0xFF;

                m_buffer[y * WINDOW_WIDTH + x] = color;
            }
        }
    }
    void Window::screenUpdate()
    {
        SDL_RenderClear(m_renderer);
        SDL_UpdateTexture(m_texture, NULL, m_buffer, WINDOW_WIDTH * sizeof(Uint32));
        SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
        SDL_RenderPresent(m_renderer);
    }

    void Window::clearPixels()
    {
        memset(m_buffer, 0, WINDOW_HEIGHT * WINDOW_WIDTH * sizeof(Uint32));
        screenUpdate();
    }

    void Window::screenClose()
    {
        delete[] m_buffer;
        SDL_DestroyRenderer(m_renderer);
        SDL_DestroyTexture(m_texture);
        SDL_DestroyWindow(m_window);
        SDL_Quit();
    }
}
