/*
** EPITECH PROJECT, 2024
** Game-of-life
** File description:
** main
*/

#include "Game.hpp"
#include "Helper.hpp"
#include "Logger.hpp"

#include <exception>

int main(int argc, const char *argv[])
{
  Logger logger("Main");

  try
  {
    Helper helper(argc, argv);
    std::tuple<int, int> dimensions = helper.getDimensions();
    Game game(std::get<0>(dimensions), std::get<1>(dimensions));

    game.run();
  }
  catch (const std::exception &e)
  {
    logger.error(e.what());
  }

  return 0;
}