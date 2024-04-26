/*
** EPITECH PROJECT, 2024
** Game-of-life
** File description:
** Helper
*/

#pragma once

#include <iostream>
#include <tuple>

class Helper {
  public:
    Helper(int argc, const char *argv[]);
    ~Helper();
    void usage();
    void version();
    std::tuple<int, int> getDimensions();

  protected:
    int _height;
    int _width;
};
