LIBS= -lm -lSDL2
EXECUTABLE = tree



$(EXECUTABLE): main.c lsystem.c turtle.c pos_stack.c
	gcc -g -o $@ $^ -std=gnu18 -pedantic -Wall -Wextra -Wno-missing-field-initializers $(LIBS)

clean:
	$(RM) $(EXECUTABLE)
