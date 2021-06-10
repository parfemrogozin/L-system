#include <SDL2/SDL.h>

#ifndef turtle_h
#define turtle_h
  #define WINDOW_WIDTH 1280
  #define WINDOW_HEIGHT 800
#endif

struct Turtle
{
  SDL_Point coord;
  double angle;
  int distance;
};

struct Turtle new_pos(struct Turtle old_pos);
void draw_tree(SDL_Renderer *renderer);

