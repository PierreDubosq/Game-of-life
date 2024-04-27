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

  logger.info("Game created with screen size: " + std::to_string(GetScreenWidth()) + "x" + std::to_string(GetScreenHeight()));
}

Game::~Game()
{
  logger.info("Game destroyed");
}

void Game::newGrid()
{
  grid = std::vector(GetScreenWidth(), std::vector<bool>(GetScreenHeight(), false));

  for (int i = 0; i < (GetScreenWidth() * GetScreenHeight()) / 10; i++)
  {
    grid[rand() % GetScreenWidth()][rand() % GetScreenHeight()] = true;
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
  std::vector<std::vector<bool>> newGrid(GetScreenWidth(), std::vector<bool>(GetScreenHeight(), false));

  for (int y = 0; y < GetScreenHeight(); y++)
  {
    for (int x = 0; x < GetScreenWidth(); x++)
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

          if (nx < 0 || nx >= GetScreenWidth() || ny < 0 || ny >= GetScreenHeight())
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
  if (history.size() > 1)
  {
    bool end = true;

    for (int y = 0; y < GetScreenHeight(); y++)
    {
      for (int x = 0; x < GetScreenWidth(); x++)
      {
        if (grid[x][y] != history[history.size() - 1][x][y])
        {
          end = false;
          break;
        }
      }
    }

    if (end)
    {
      logger.info("Game ended");
      CloseWindow();
    }
  }

  if (history.size() > 2)
  {
    bool end = true;

    for (int y = 0; y < GetScreenHeight(); y++)
    {
      for (int x = 0; x < GetScreenWidth(); x++)
      {
        if (grid[x][y] != history[history.size() - 2][x][y])
        {
          end = false;
          break;
        }
      }
    }

    if (end)
    {
      logger.info("Game ended");
      CloseWindow();
    }
  }

  if (history.size() > 3)
  {
    bool end = true;

    for (int y = 0; y < GetScreenHeight(); y++)
    {
      for (int x = 0; x < GetScreenWidth(); x++)
      {
        if (grid[x][y] != history[history.size() - 3][x][y])
        {
          end = false;
          break;
        }
      }
    }

    if (end)
    {
      logger.info("Game ended");
      CloseWindow();
    }
  }
}