/*
** EPITECH PROJECT, 2024
** Game-of-life
** File description:
** Console
*/

#include "Console.hpp"

std::string Console::color(Console::Formattings formatting,
                           Console::ForegroundColors foregroundColor,
                           Console::BackgroundColors backgroundColor)
{
  std::string result = "\033[";

  result += std::to_string(formatting) + ";";
  result += std::to_string(foregroundColor) + ";";
  result += std::to_string(backgroundColor) + "m";
  return result;
}

std::string Console::color()
{
  return Console::color(Console::Formattings::RESET,
                        Console::ForegroundColors::FG_DEFAULT,
                        Console::BackgroundColors::BG_DEFAULT);
}