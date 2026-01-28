// SentryRobot.cpp
#include "SentryRobot.hpp"
#include "mathtool.hpp" // normalize_angle
#include "EnergyMechanism.hpp"
#include <cmath>

// 定义静态成员
int SentryRobot::instanceCount_ = 0;
long long SentryRobot::totalTargetsDetected_ = 0;

SentryRobot::SentryRobot(int id,double x, double y, double dir,AmmoType type,
                         ObjectColor color,double length, double width)
    : robot(id, x, y, dir, ObjectColor::RED, length, width) ,type(AmmoType::SMALL_BULLET){
    ++instanceCount_;
}


void SentryRobot::fire() {
    fire(AmmoType::SMALL_BULLET);
}

void SentryRobot::fire(AmmoType /*type*/) {
}

void SentryRobot::move(double length, double direction) {
    // direction 是世界坐标系角度（如 0 = +Y 方向）
    getX(length * std::sin(direction));
    getY(length * std::cos(direction));
}

void SentryRobot::changeDirection(double changedRad) {
    getDir(normalize_angle(getDir() + changedRad))  ;
}


std::ostream operator<<(const std::ostream & lhs, AmmoType rhs);

// 友元 operator<< 实现
std::ostream& operator<<(std::ostream& os, const SentryRobot& sentry) {
    os << "[Sentry #" << sentry.type << "] ";
    return os;
}