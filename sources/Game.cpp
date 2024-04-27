/*
** EPITECH PROJECT, 2024
** Game-of-life
** File description:
** Game
*/

#include "Game.hpp"

Game::Game(int height, int width) : logger("Game"), raylib(width, height, "Game of life", 60)
{
  newGrid();

  logger.info("Game created with screen size: " + std::to_string(width) + "x" + std::to_string(height));
}

Game::~Game()
{
  logger.info("Game destroyed");
}

void Game::newGrid()
{
  int width = GetScreenWidth();
  int height = GetScreenHeight();

  grid = std::vector(width, std::vector<bool>(height, false));

  for (int i = 0; i < (width * height) / 10; i++)
  {
    grid[rand() % width][rand() % height] = true;
  }
}

void Game::run()
{
  while (!WindowShouldClose())
  {
    BeginDrawing();
    ClearBackground(WHITE);
    DrawFPS(10, 10);
    update();
    draw();
    EndDrawing();
    checkEnd();
  }
}

void Game::update()
{
  int width = GetScreenWidth();
  int height = GetScreenHeight();

  static std::vector<std::vector<bool>> newGrid(
      width, std::vector<bool>(height, false));

  for (int y = 0; y < height; y++)
  {
    for (int x = 0; x < width; x++)
    {
      int neighbors = 0;

      for (int i = -1; i <= 1; i++)
      {
        for (int j = -1; j <= 1; j++)
        {
          if (i == 0 && j == 0)
          {
            continue;
          }

          int nx = x + i;
          int ny = y + j;

          if (nx < 0 || nx >= width || ny < 0 || ny >= height)
          {
            continue;
          }

          if (grid[nx][ny])
          {
            neighbors++;
          }
        }
      }

      if (grid[x][y])
      {
        if (neighbors < 2 || neighbors > 3)
        {
          newGrid[x][y] = false;
        }
        else
        {
          newGrid[x][y] = true;
        }
      }
      else
      {
        if (neighbors == 3)
        {
          newGrid[x][y] = true;
        }
      }
    }
  }

  history.push_back(grid);
  if (history.size() > 3)
  {
    history.erase(history.begin());
  }
  grid = newGrid;
}

void Game::draw()
{
  for (int y = 0; y < GetScreenHeight(); y++)
  {
    for (int x = 0; x < GetScreenWidth(); x++)
    {
      if (grid[x][y])
      {
        DrawPixel(x, y, BLACK);
      }
    }
  }
}

void Game::checkEvents()
{
  if (IsKeyPressed(KEY_SPACE))
  {
    newGrid();
  }
}

void Game::checkEnd()
{
  int historySize = history.size();
  int screenHeight = GetScreenHeight();
  int screenWidth = GetScreenWidth();

  for (int i = 1; i <= 3 && i <= historySize; i++)
  {
    bool end = true;

    for (int y = 0; y < screenHeight; y++)
    {
      for (int x = 0; x < screenWidth; x++)
      {
        if (grid[x][y] != history[historySize - i][x][y])
        {
          end = false;
          break;
        }
      }
      if (!end)
      {
        break;
      }
    }

    if (end)
    {
      logger.info("Game ended");
      CloseWindow();
      return;
    }
  }
}
