#ifndef ENERGYMECHANISM_HPP
#define ENERGYMECHANISM_HPP

#include "target.hpp"

class EnergyMechanism :public target{
public:
    struct config {
        double moren_boost = 1.5;      // 全局默认伤害倍数
        double moren_duration = 30;   // 全局默认持续时间（秒）
    };
private:
    static config moren_config; // 全局默认配置
    bool isactive=false;//是否激活
    double activetime=-1;//激活时间
    double configured_boost;//伤害加成
    double configured_duration;//持续时间
public:
    EnergyMechanism(int id,
                    double _x, double _y,
                    double _configured_boost,
                    double _configured_duration);
    void activate();//激活函数

    bool getisactive(){return isactive;}
};

#endif //ENERGYMECHANISM_HPP