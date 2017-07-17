#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdlib.h>

#include <life/grid.h>

int main();

void loop(uint16_t generation);

void render(grid_t *grid, uint16_t generation);

void setup();

void tearDown();

#endif
