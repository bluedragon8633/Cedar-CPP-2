#include"Coords.h"

Coord::Coord(int nX, int nY) {
    x = nX; y = nY;
}
Coord::Coord() {
    x = 0; y = 0;
}

void Coord::set(int nX, int nY) {
    x = nX; y = nY;
}