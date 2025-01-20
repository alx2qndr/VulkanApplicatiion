#pragma once

#include <string>
#include <memory>

#include <SDL3/SDL.h>
#include <SDL3/SDL_vulkan.h>

namespace lvk 
{
    class Window
    {
    public:
        Window(int width, int height, const std::string& title); 
        ~Window();

        SDL_Window* getWindow() const;

        bool isOpen() const;

        void pollEvent();

    private:
        std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> window;

        const int width;
        const int height;
    
        const std::string title;

        bool running;
    };
}
