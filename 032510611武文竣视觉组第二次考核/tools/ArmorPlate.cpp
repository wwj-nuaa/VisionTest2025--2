#include"exprtk.hpp"
#include"ArmorPlate.hpp"
#include "target.hpp"
#include"enum.hpp"
#include<memory>


ArmorPlate::ArmorPlate(int id, int _bianhao, ArmorSide side,
                       ObjectColor color, std::shared_ptr<Robot> host)
    : target(0.15),
      bianhao(_bianhao),
      side(side),
      hostRobot(host) {
    update_from_host();
}



