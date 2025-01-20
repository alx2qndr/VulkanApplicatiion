#include "LearnVulkan/Application.hpp"

#include <iostream>
#include <exception>
#include <memory>

int main(int argc, char** argv)
{
    try 
    {
        auto app = std::make_unique<lvk::Application>();
    } 
    catch (std::exception& e) 
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}