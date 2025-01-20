#include "LearnVulkan/Application.hpp"

namespace lvk 
{
    Application::Application()
    {
        while (window.isOpen()) 
        {
            window.pollEvent();
        }
    }

    Application::~Application()
    {

    }
}