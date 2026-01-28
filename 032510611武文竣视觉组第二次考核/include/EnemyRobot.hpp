#ifndef ENEMYROBOT_HPP
#define ENEMYROBOT_HPP

#include "robot.hpp"
#include "ArmorPlate.hpp"

class EnemyRobot:public robot {
private:
    double hp;
    const double maxhp;
    std::vector<std::shared_ptr<ArmorPlate>> armorPlates;
public:
    EnemyRobot(int id, double x, double y, double direction,
               ObjectColor color, double length, double width,
               double _hp, double _maxhp);
    virtual ~EnemyRobot() = default;

};

#endif //ENEMYROBOT_HPP