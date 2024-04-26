/*
** EPITECH PROJECT, 2024
** Game-of-life
** File description:
** Logger
*/

#pragma once

#include <iostream>
#include <stdarg.h>

class Logger
{
public:
  Logger(std::string name);
  ~Logger();
  void debug(std::string message, ...);
  void debug(std::string message, va_list args);
  void error(std::string message, ...);
  void error(std::string message, va_list args);
  void info(std::string message, ...);
  void info(std::string message, va_list args);
  void warn(std::string message, ...);
  void warn(std::string message, va_list args);

protected:
  std::string getCurrentDatetime();

private:
  std::string _name;
};
