#include "Fruits.h"

void Fruits::updateFruit(Fruits& fruit, BaseGrid& grid) {
    fruit.coords.X = rand() % grid.getWidth();
    fruit.coords.Y = rand() % grid.getHeight();
    fruit.symbol = (rand() % 2 == 0) ? 42 : 43;
}
