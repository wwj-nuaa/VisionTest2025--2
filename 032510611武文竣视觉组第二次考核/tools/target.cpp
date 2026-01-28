#include"target.hpp"
#include<iostream>
#include<cmath>

target::target(double _width)
    : object('T', 0.0, 0.0, 0.0, false),  // 默认静态目标
      width(_width){
    if (width < 0) {
      
        width = 0.0;
    }
}