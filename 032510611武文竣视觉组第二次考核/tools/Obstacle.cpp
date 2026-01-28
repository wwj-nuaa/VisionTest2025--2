#include "Obstacle.hpp"
#include <cmath>
#include <iostream>

Obstacle::Obstacle(int id, double x, double y, double direction,
             double width, double height,
             Material _ob,
             bool _destractable)
    : target(0),
        height(height),
        ob(_ob),
        destractable(_destractable) {
}