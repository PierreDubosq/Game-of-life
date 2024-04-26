/*
** EPITECH PROJECT, 2024
** Game-of-life
** File description:
** Helper
*/

#include "Helper.hpp"

Helper::Helper(int argc, const char *argv[])
{
  if (argc == 1)
  {
    throw std::runtime_error("No arguments provided");
  }
  for (int i = 1; i < argc; i++)
  {
    std::string arg = argv[i];

    if (arg == "-h" || arg == "--help")
    {
      usage();
    }
    else if (arg == "-v" || arg == "--version")
    {
      version();
    }
    else if (arg.find("-w=") == 0 || arg.find("--width=") == 0)
    {
      std::string width = arg.substr(arg.find("=") + 1);
      _width = std::stoi(width);
    }
    else if (arg.find("-h=") == 0 || arg.find("--height=") == 0)
    {
      std::string height = arg.substr(arg.find("=") + 1);
      _height = std::stoi(height);
    }
    else
    {
      throw std::runtime_error("Invalid argument: " + arg);
    }
  }
}

Helper::~Helper()
{
}

void Helper::usage()
{
  std::string usage = "Usage: ./game-of-life [OPTIONS]\n"
                      "Options:\n"
                      "  -h, --help\t\t\tDisplay this help message\n"
                      "  -w, --width\t\t\tSet the width of the window\n"
                      "  -h, --height\t\t\tSet the height of the window\n"
                      "  -w, --width\t\t\tSet the width of the window\n"
                      "Example:\n"
                      "  ./game-of-life -w=250 -h=250\n";

  std::cout << usage;
}

void Helper::version()
{
  std::cout << "Game of life v1.0.0\n";
}

std::tuple<int, int> Helper::getDimensions()
{
  return std::make_tuple(_width, _height);
}