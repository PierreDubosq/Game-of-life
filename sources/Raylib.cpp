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
  SetTargetFPS(fps);
  SetTraceLogCallback(Raylib::traceLog);

  logger.info("Raylib created");

  displayIntro();
}

Raylib::~Raylib()
{
  if (IsWindowReady()) {
    CloseWindow();
  }

  logger.info("Raylib destroyed");
}

void Raylib::displayIntro()
{
  Image logo = LoadImage("assets/images/raylib_logo.png");
  int size = GetScreenHeight() < GetScreenWidth() ? GetScreenHeight() : GetScreenWidth();
  ImageResize(&logo, size / 2, size / 2);
  Texture2D texture = LoadTextureFromImage(logo);

  double startTime = GetTime();
  while (!WindowShouldClose() && GetTime() - startTime < 2.0) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawTexture(texture, GetScreenWidth() / 2 - texture.width / 2,
        GetScreenHeight() / 2 - texture.height / 2, WHITE);
    EndDrawing();
  }

  UnloadTexture(texture);
  UnloadImage(logo);
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
