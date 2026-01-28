#ifndef ROBOT_HPP
#define ROBOT_HPP


#include "ArmorPlate.hpp"
#include"object.hpp"
#include"enum.hpp"



class robot:public object,public coloredobject{
    private:
        double length,width,yuntai_dipan_angle=0.0;
    public:
    robot(int id, double x, double y, double dir,
      ObjectColor color, double length, double width,
      bool movable = true);
    ~robot();

    robot(const robot&) = delete;
    robot& operator=(const robot&) = delete;

    void dipantuoluo();

    void UpdateArmors();

};

#endif