#include "EnemyRobot.hpp"
#include <sstream>

EnemyRobot::EnemyRobot(int id, double x, double y, double direction,
               ObjectColor color, double length, double width,
               double _hp, double _maxhp)
    : robot(id, x, y, 0, color, length, width),
      hp(_hp),
      maxhp(_maxhp){
}
