#include <math.h>
#include <SDL2/SDL.h>
#include "lsystem.h"
#include "turtle.h"
#include "pos_stack.h"

extern int generations;

struct Turtle find_pos(struct Turtle old_pos)
{
  struct Turtle new_pos;
  new_pos.coord.x = old_pos.coord.x + sin(old_pos.angle) * old_pos.distance;
  new_pos.coord.y = old_pos.coord.y - cos(old_pos.angle) * old_pos.distance;
  return new_pos;
}

void draw_tree(SDL_Renderer *renderer)
{
  init_stack(generations);
  struct Turtle start_pos = (struct Turtle)
  {
    .coord.x = WINDOW_WIDTH/2,
    .coord.y = WINDOW_HEIGHT,
    .angle = 0,
    .distance = 50
  };
  struct Turtle end_pos;
  struct Turtle old_pos;
  int ch = 0;
  int draw = 0;
  FILE * lsystem_file = fopen(INPUT_FILE, "r");

  ch = getc(lsystem_file);
  while (ch != EOF)
  {
    switch(ch)
    {

      case '0':
        end_pos = find_pos(start_pos);
        end_pos.distance = start_pos.distance * 0.90;
        old_pos = start_pos;
        draw = 1;
        break;

      case '1':
        end_pos = find_pos(start_pos);
        end_pos.distance = start_pos.distance * 0.90;
        old_pos = end_pos;
        draw = 1;
        break;

      case '[':
        start_pos.angle = start_pos.angle - 0.785398163;
        push(start_pos);
        draw = 0;
        break;

      case ']':
        start_pos = pop();
        start_pos.angle = start_pos.angle + 1.57079633;
        draw = 0;
        break;

      default:
        break;

    }
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  /*SDL_Log("%c: %d,%d->%d,%d", ch, start_pos.coord.x, start_pos.coord.y, end_pos.coord.x, end_pos.coord.y);*/
  if (draw)
  {
    SDL_RenderDrawLine(renderer, start_pos.coord.x, start_pos.coord.y, end_pos.coord.x, end_pos.coord.y);
    start_pos.coord = old_pos.coord;
  }
  ch = getc(lsystem_file);
  }
  destroy_stack();
  fclose(lsystem_file);
}

