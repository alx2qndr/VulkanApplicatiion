#pragma once

#include "LearnVulkan/Window.hpp"

namespace lvk 
{
    class Application
    {
    public:
        Application();
        ~Application();

    private:
        Window window{640, 480, "Hello World!"};
    };
}