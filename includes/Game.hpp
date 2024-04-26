/*
** EPITECH PROJECT, 2024
** Game-of-life
** File description:
** Game
*/

#pragma once

#include "Logger.hpp"
#include "Raylib.hpp"

#include <vector>

class Game
{
public:
  Game(int height, int width);
  ~Game();
  void newGrid();
  void run();
  void update();
  void draw();
  void checkEvents();
  void checkEnd();

protected:
  std::vector<std::vector<bool>> grid;
  std::vector<std::vector<std::vector<bool>>> history;

private:
  Logger logger;
  Raylib raylib;
};
