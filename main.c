#include <stdio.h>
#include <SDL2/SDL.h>
#include "lsystem.h"
#include "turtle.h"

int generations;

SDL_bool process_events(void)
{
  SDL_Event event;
  while(SDL_PollEvent(&event))
  {

    switch(event.type)
    {

      case SDL_WINDOWEVENT_CLOSE:
        return SDL_TRUE;

      case SDL_QUIT:
        return SDL_TRUE;

      default:
        return SDL_FALSE;

    }
  }
  return SDL_FALSE;
}

void render(SDL_Renderer * renderer, void (*draw)())
{
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_RenderClear(renderer);
  draw(renderer);
  SDL_RenderPresent(renderer);
}

int main(int argc, char **argv)
{
  SDL_Window *window = NULL;
  SDL_Renderer *renderer = NULL;

  if (argc == 2)
  {
    sscanf( argv[1], "%d", &generations);
  }
  else
  {
    printf("%s\n", "usage: tree <number of generations>");
    exit(EXIT_FAILURE);
  }
  char * axiom = "0";
  struct Rule rule[] =
  {
      [0].predecessor = '1',
      [0].successor = "11",
      [1].predecessor = '0',
      [1].successor = "1[0]0",

  };

  create_instrustions(axiom, rule, generations);
  SDL_Log("Number of trunk segements: %d\n", (int) pow(2,generations - 1) + 1);

  window = SDL_CreateWindow(
    "Tree",
    SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED,
    WINDOW_WIDTH,
    WINDOW_HEIGHT,
    SDL_WINDOW_OPENGL);

  renderer = SDL_CreateRenderer(
    window,
    -1,
   SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

  render(renderer, draw_tree);
  while(!process_events())
  {
    SDL_Delay(10);
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return EXIT_SUCCESS;
}

