struct Stack
{
  int size;
  int top;
  struct Turtle * stack;
};

int init_stack(int maxsize);
struct Turtle pop(void);
int push(struct Turtle data);
void destroy_stack(void);
