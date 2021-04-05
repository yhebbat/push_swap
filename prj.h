#include <stdlib.h>
#include <unistd.h>

typedef struct s_stack
{
    int value;
    struct s_stack *preced;
    
}t_stack;

