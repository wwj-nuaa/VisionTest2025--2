#include "robot.hpp"
robot::robot(int id, double x, double y, double direction,
          ObjectColor color, double length, double width,
          bool movable)
    : object(id, 0, 0, 0, true), coloredobject(color),
      length(length), width(width) {
}

