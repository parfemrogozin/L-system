#include "turtle.h"
#include "pos_stack.h"

static struct Stack pos_stack;

int init_stack(int maxsize)
{
  int ret;
  pos_stack.size = maxsize;
  pos_stack.top = -1;
  pos_stack.stack = malloc(sizeof(struct Turtle) * pos_stack.size);
  if (pos_stack.stack == NULL)
  {
    ret = EXIT_FAILURE;
  }
  else
  {
    ret = EXIT_SUCCESS;
  }
  return ret;
}

static int isempty(void)
{
   if(pos_stack.top == -1)
      return 1;
   else
      return 0;
}

static int isfull(void)
{
   if(pos_stack.top == pos_stack.size)
      return 1;
   else
      return 0;
}

struct Turtle pop(void)
{
   struct Turtle data;

   if(!isempty())
   {
      data = pos_stack.stack[pos_stack.top];
      pos_stack.top = pos_stack.top - 1;
      return data;
   }
   else
   {
      SDL_Log("Could not retrieve data, Stack is empty.\n");
   }
   return (struct Turtle) {.coord.x = 0, .coord.y = 0, .angle = 0, .distance = 0};
}

int push(struct Turtle data)
{
  int ret;
  if( !isfull() )
  {
    pos_stack.top = pos_stack.top + 1;
    pos_stack.stack[pos_stack.top] = data;
    ret = EXIT_SUCCESS;
  }
  else
  {
    SDL_Log("Could not insert data, Stack is full.\n");
    ret = EXIT_FAILURE;
  }
  return ret;
}

void destroy_stack(void)
{
  free(pos_stack.stack);
}
