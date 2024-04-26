/*
** EPITECH PROJECT, 2024
** Game-of-life
** File description:
** Raylib
*/

#pragma once

#include "Logger.hpp"
#include "raylib.h"

class Raylib
{
public:
  Raylib(int height, int width, std::string title, int fps);
  ~Raylib();
  static void traceLog(int logLevel, const char *text, va_list args);

private:
  Logger logger;
};
