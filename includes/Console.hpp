/*
** EPITECH PROJECT, 2024
** Game-of-life
** File description:
** Console
*/

#pragma once

#include <iostream>

class Console
{
public:
  enum Formattings
  {
    RESET = 0,
    BOLD = 1,
    DIM = 2,
    UNDERLINED = 4,
    BLINK = 5,
    REVERSE = 7,
    HIDDEN = 8
  };
};
