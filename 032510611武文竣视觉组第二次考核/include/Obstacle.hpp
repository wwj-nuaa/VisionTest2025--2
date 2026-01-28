#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "target.hpp"
#include "enum.hpp"
#include <string>
#include <vector>
#include <memory>

class Obstacle:public target{
private:
    Material ob;
    bool destractable;
    double height;
public:
    Obstacle(int id, double x, double y, double direction,
             double width, double height = 0.0,
             Material _ob = Material::METAL,
             bool _destractable=false);
    virtual ~Obstacle() = default;
};

#endif //OBSTACLE_H