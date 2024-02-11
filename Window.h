#pragma once
#include <SDL2/SDL.h>
#include <stdlib.h>
namespace cube
{
    class Window
    {
    private:
        SDL_Window *m_window;
        SDL_Renderer *m_renderer;
        SDL_Texture *m_texture;
        Uint32 *m_buffer;
        Uint32 *m_bufferBlur;

    public:
        const static int WINDOW_WIDTH = 800;
        const static int WINDOW_HEIGHT = 800;
        Window();
        bool Init();
        bool processEvents();
        void setPixels(int x, int y, Uint8 r, Uint8 g, Uint8 b);
        void drawLine(int x1, int y1, int x2, int y2, Uint8 r, Uint8 g, Uint8 b);
        void clearPixels();
        void screenBlur();
        void screenUpdate();
        void screenClose();
    };
} // namespace cube
