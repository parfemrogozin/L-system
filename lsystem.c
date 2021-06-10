#include <stdio.h>
#include "lsystem.h"

void write_axiom(char * axiom)
{
  FILE * prev_gen;
  prev_gen = fopen(INPUT_FILE, "w");
  fputs(axiom, prev_gen);
  fclose(prev_gen);
}


void apply_rule(FILE * prev_gen, struct Rule * rule, FILE * next_gen)
{
  int found;

  int ch = getc(prev_gen);
  while (ch != EOF)
  {
    found = 0;
    for (int i = 0; i < 2; i++)
    {
      if (ch == rule[i].predecessor)
      {
        fputs(rule[i].successor, next_gen);
        found = 1;
        break;
      }
    }
    if (! found)
    {
      fputc(ch, next_gen);
    }
    ch = getc(prev_gen);
  }
}

void create_instrustions(char * axiom, struct Rule * rule, int generations)
{
  FILE * prev_gen, * next_gen;

  write_axiom(axiom);

  while (generations > 0)
  {
    prev_gen = fopen(INPUT_FILE, "r");
    next_gen = fopen(OUTPUT_FILE, "w");
    apply_rule(prev_gen, rule, next_gen);
    fclose(prev_gen);
    fclose(next_gen);
    rename(OUTPUT_FILE, INPUT_FILE);
    generations--;
  }

}
