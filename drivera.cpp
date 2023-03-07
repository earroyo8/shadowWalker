//Daniel Rivera
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "drivera.h"

typedef struct t_rat {
	int status;
	int pos[2];
} GRat;

struct Global {

    GRat rat;
} gr;
void initRat()
{
	gr.rat.status = 1;
	gr.rat.pos[0] = 25;
	gr.rat.pos[1] = 2;
}
