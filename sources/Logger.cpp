/*
** EPITECH PROJECT, 2024
** Game-of-life
** File description:
** Logger
*/

#include "Console.hpp"
#include "Logger.hpp"

Logger::Logger(std::string name)
    : _name(name)
{
}

Logger::~Logger()
{
}

void Logger::debug(std::string message, ...)
{
  va_list args;

  va_start(args, message);
  this->debug(message, args);
  va_end(args);
}

void Logger::debug(std::string message, va_list args)
{
  std::string content;

  content = Console::color(
                Console::Formattings::BOLD,
                Console::ForegroundColors::FG_LIGHT_BLUE,
                Console::BackgroundColors::BG_DEFAULT) +
            this->getCurrentDatetime() + Console::color(Console::Formattings::BOLD, Console::ForegroundColors::FG_LIGHT_MAGENTA, Console::BackgroundColors::BG_DEFAULT) + " [" + _name + "] " + Console::color(Console::Formattings::BOLD, Console::ForegroundColors::FG_LIGHT_BLUE, Console::BackgroundColors::BG_DEFAULT) + message + Console::color() + "\n";
  vprintf(content.c_str(), args);
}

void Logger::error(std::string message, ...)
{
  va_list args;

  va_start(args, message);
  this->error(message, args);
  va_end(args);
}

void Logger::error(std::string message, va_list args)
{
  std::string content;

  content = Console::color(
                Console::Formattings::BOLD,
                Console::ForegroundColors::FG_LIGHT_RED,
                Console::BackgroundColors::BG_DEFAULT) +
            this->getCurrentDatetime() + Console::color(Console::Formattings::BOLD, Console::ForegroundColors::FG_LIGHT_MAGENTA, Console::BackgroundColors::BG_DEFAULT) + " [" + _name + "] " + Console::color(Console::Formattings::BOLD, Console::ForegroundColors::FG_LIGHT_RED, Console::BackgroundColors::BG_DEFAULT) + message + Console::color() + "\n";
  vprintf(content.c_str(), args);
}

void Logger::info(std::string message, ...)
{
  va_list args;

  va_start(args, message);
  this->info(message, args);
  va_end(args);
}

void Logger::info(std::string message, va_list args)
{
  std::string content;

  content = Console::color(
                Console::Formattings::BOLD,
                Console::ForegroundColors::FG_LIGHT_GREEN,
                Console::BackgroundColors::BG_DEFAULT) +
            this->getCurrentDatetime() + Console::color(Console::Formattings::BOLD, Console::ForegroundColors::FG_LIGHT_MAGENTA, Console::BackgroundColors::BG_DEFAULT) + " [" + _name + "] " + Console::color(Console::Formattings::BOLD, Console::ForegroundColors::FG_LIGHT_GREEN, Console::BackgroundColors::BG_DEFAULT) + message + Console::color() + "\n";
  vprintf(content.c_str(), args);
}

void Logger::warn(std::string message, ...)
{
  va_list args;

  va_start(args, message);
  this->warn(message, args);
  va_end(args);
}

void Logger::warn(std::string message, va_list args)
{
  std::string content;

  content = Console::color(
                Console::Formattings::BOLD,
                Console::ForegroundColors::FG_LIGHT_YELLOW,
                Console::BackgroundColors::BG_DEFAULT) +
            this->getCurrentDatetime() + Console::color(Console::Formattings::BOLD, Console::ForegroundColors::FG_LIGHT_MAGENTA, Console::BackgroundColors::BG_DEFAULT) + " [" + _name + "] " + Console::color(Console::Formattings::BOLD, Console::ForegroundColors::FG_LIGHT_YELLOW, Console::BackgroundColors::BG_DEFAULT) + message + Console::color() + "\n";
  vprintf(content.c_str(), args);
}

std::string Logger::getCurrentDatetime()
{
  std::string datetime;
  time_t now = time(0);
  struct tm tstruct;

  tstruct = *localtime(&now);
  datetime += std::to_string(tstruct.tm_year + 1900) + "-";
  datetime += (tstruct.tm_mon + 1 < 10 ? "0" : "") + std::to_string(tstruct.tm_mon + 1) + "-";
  datetime += (tstruct.tm_mday < 10 ? "0" : "") + std::to_string(tstruct.tm_mday) + " ";
  datetime += (tstruct.tm_hour < 10 ? "0" : "") + std::to_string(tstruct.tm_hour) + ":";
  datetime += (tstruct.tm_min < 10 ? "0" : "") + std::to_string(tstruct.tm_min) + ":";
  datetime += (tstruct.tm_sec < 10 ? "0" : "") + std::to_string(tstruct.tm_sec);
  return datetime;
}