#ifndef ARMORPLATE_HPP
#define ARMORPLATE_HPP

#include"exprtk.hpp"
#include"target.hpp"
#include"enum.hpp"
#include<memory>

#include "robot.hpp"


class Robot;

class ArmorPlate: public target{
    private:
        ObjectColor color;
        int bianhao;
        ArmorSide side;
        std::weak_ptr<Robot> hostRobot;
        bool ishitable;
    public:
    ArmorPlate(int id, int bianhao, ArmorSide side,
           ObjectColor color, std::shared_ptr<Robot> host);
    void update_from_host();
    void canhitable();//判断外法向量点积<0
};

#endif