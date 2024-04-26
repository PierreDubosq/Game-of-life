/*
** EPITECH PROJECT, 2024
** Game-of-life
** File description:
** Raylib
*/

#include "Raylib.hpp"

Raylib::Raylib(int height, int width, std::string title, int fps): logger("Raylib")
{
  InitWindow(width, height, title.c_str());
  // SetTargetFPS(fps);
  (void)fps;
  SetTraceLogCallback(Raylib::traceLog);

  logger.debug("Raylib created");
}

Raylib::~Raylib()
{
  if (IsWindowReady()) {
    CloseWindow();
  }

  logger.debug("Raylib destroyed");
}

void Raylib::traceLog(int logLevel, const char *text, va_list args)
{
  static Logger logger("Raylib");

  switch (logLevel) {
    case LOG_NONE:
    case LOG_ALL:
    case LOG_TRACE:
    case LOG_DEBUG:
      logger.debug(text, args);
      break;
    case LOG_INFO:
      logger.info(text, args);
      break;
    case LOG_WARNING:
      logger.warn(text, args);
      break;
    case LOG_ERROR:
    case LOG_FATAL:
      logger.error(text, args);
      break;
  }
}
