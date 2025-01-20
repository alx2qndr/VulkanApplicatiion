#include "LearnVulkan/Window.hpp"
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_video.h>
#include <stdexcept>

namespace lvk 
{
    Window::Window(int width, int height, const std::string& title) 
        : width(width), height(height), title(title), window(nullptr, SDL_DestroyWindow)
    {
        if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) == false) 
        {
            throw std::runtime_error("SDL could not initialize! SDL_Error: " + std::string(SDL_GetError()));
        }

        window.reset(SDL_CreateWindow(title.c_str(), width, height, SDL_WINDOW_VULKAN | SDL_WINDOW_RESIZABLE));
        if (!window) 
        {
            throw std::runtime_error("Window could not be created! SDL_Error: " + std::string(SDL_GetError()));
        }

        running = true;
    }

    Window::~Window()
    {
        SDL_Quit();
    }

    SDL_Window* Window::getWindow() const
    {
        return window.get();
    }
    
    bool Window::isOpen() const
    {
        return running;
    }

    void Window::pollEvent()
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type) 
            {
                case SDL_EVENT_QUIT:
                    running = false;
                    break;
                default:
                    break;
            }
        }
    }
}
