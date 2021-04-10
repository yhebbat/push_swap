#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

typedef struct s_stack
{
    int value;
    struct s_stack *suivant;
}t_stack;

typedef struct s_list
{
    struct s_stack *header;
}t_list;

