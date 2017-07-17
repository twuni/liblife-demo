#include <stdlib.h>
#include <stdio.h>

#include <life/grid.h>
#include <life/seeds/koks-galaxy.h>
#include <life/life.h>

#include <main.h>

grid_t *source;
grid_t *target;
grid_t *ephemeral;
uint16_t generation = 0;

int main() {
  setup();
  for (generation = 1; generation <= 8; generation++) {
    loop(generation);
  }
  tearDown();
  return 0;
}

void render(grid_t *grid, uint16_t generation) {
  printf("Generation %d\n", generation);
  for (uint16_t y = 0; y < grid->height; y++) {
    for (uint16_t x = 0; x < grid->width; x++) {
      printf("%d", Grid_getCellValue(grid, Grid_getCellIndex(grid, x, y)));
    }
    printf("\n");
  }
  printf("\n");
}

void setup() {
  source = Grid_new(16, 16);
  Grid_clear(source);
  KoksGalaxy_seed(source);
  target = Grid_new(16, 16);
  Grid_clear(target);
  render(source, 0);
}

void tearDown() {
  Grid_release(source);
  Grid_release(target);
}

void loop(uint16_t generation) {
  Life_tick(source, target);
  render(target, generation);
  ephemeral = source;
  source = target;
  target = ephemeral;
}
