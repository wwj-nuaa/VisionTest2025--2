#include "EnergyMechanism.hpp"
#include <sstream>

EnergyMechanism::EnergyMechanism(int _id,
                    double _x, double _y,
                    double _configured_boost,
                    double _configured_duration)
    : target(0),
      configured_boost(_configured_boost),
      configured_duration(_configured_duration) {
    // 配置伤害加成倍数
    if (_configured_boost > 0) {
        configured_boost = _configured_boost;
    } else {
        configured_boost = 3;
    }

    // 配置持续时间
    if (_configured_duration > 0) {
        configured_duration = _configured_duration;
    } else {
        configured_duration = 30;
    }

    // 初始未激活
    isactive = false;
}

void EnergyMechanism::activate() {
    isactive = true;

}
