#ifndef ENUM_HPP
#define ENUM_HPP

#include <string>

//枚举定义
enum class ObjectColor {
    RED,
    BLUE
};

enum class ArmorSide {
    FRONT,
    BACK,
    LEFT,
    RIGHT
};

enum class AmmoType {
    SMALL_BULLET,
    BIG_BULLET
};

enum class Material {
    WOOD,
    METAL,
    CONCRETE,
    PLASTIC
};

class coloredobject{
    ObjectColor color;
    public:

    coloredobject(ObjectColor color) {};

    virtual ~coloredobject();
};
//字符串转换函数（声明） 
std::string toString(ObjectColor color);
std::string toString(ArmorSide side);
std::string toString(AmmoType type);

#endif