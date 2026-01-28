#include "enum.hpp"
#include <stdexcept> 

std::string toString(ObjectColor color) {
    switch (color) {
        case ObjectColor::RED:  return "RED";
        case ObjectColor::BLUE: return "BLUE";
        default: return "UNKNOWN_COLOR";
    }
}

std::string toString(ArmorSide side) {
    switch (side) {
        case ArmorSide::FRONT: return "FRONT";
        case ArmorSide::BACK:  return "BACK";
        case ArmorSide::LEFT:  return "LEFT";
        case ArmorSide::RIGHT: return "RIGHT";
        default: return "UNKNOWN_SIDE";
    }
}

std::string toString(AmmoType type) {
    switch (type) {
        case AmmoType::SMALL_BULLET: return "SMALL_BULLET";
        case AmmoType::BIG_BULLET:   return "BIG_BULLET";
        default: return "UNKNOWN_AMMO";
    }
}