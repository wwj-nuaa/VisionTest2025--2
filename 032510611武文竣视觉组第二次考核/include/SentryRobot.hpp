#ifndef SENTRYROBOT_HPP
#define SENTRYROBOT_HPP

#include "robot.hpp"
#include "enum.hpp"

class SentryRobot:public robot {
private:
    AmmoType type;
public:

    ~SentryRobot();

    SentryRobot(int id, double x, double y, double dir,AmmoType type,
            ObjectColor color, double length, double width);

    //重载
    void fire();
    void fire(AmmoType type);

    void move(double length, double direction);
    void changeDirection(double deltaRad);

    //静态成员
    static int instanceCount_;               // 创建的哨兵总数
    static long long totalTargetsDetected_;  // 哨兵累计探测目标数

    //友元
    friend std::ostream& operator<<(std::ostream& os, const SentryRobot& sentry);
};

#endif //SENTRYROBOT_HPP