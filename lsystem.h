#ifndef lsytem_h
#define lsytem_h
  #define INPUT_FILE "input.txt"
  #define OUTPUT_FILE "output.txt"
#endif

struct Rule
{
  char predecessor;
  char successor[32];
};

void apply_rule(FILE * prev_gen, struct Rule * rule, FILE * next_gen);
void write_axiom(char * axiom);
void create_instrustions(char * axiom, struct Rule * rule, int generations);


