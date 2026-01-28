#ifndef TARGET_HPP
#define TARGET_HPP


#include"object.hpp"
#include <string>
#include <vector>

struct point {
    double x, y;
};
class target:public object{
    protected:
        double width;//宽度
    public:
        target(double _width);

        virtual ~target()= default;
        virtual std::vector<point> GetBounds() const = 0;
        virtual std::string describe() const = 0;

        double getwidth() const { return width; }

};



#endif