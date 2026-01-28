#include"object.hpp"
#include<iostream>
#include"mathtool.hpp"


object::object(int _id, double _x, double _y, double _dir, bool _movable)
    : id(_id), x(_x), y(_y), dir(_dir), movable(_movable) {
    

}

//设置运动规则
void object::setMovementExpressions(const std::string& x_expr,const std::string& y_expr,const std::string& dir_expr){
    expr_x_str = x_expr;
    expr_y_str = y_expr;
    expr_dir_str = dir_expr;
}

//驱动运动的核心逻辑
void object::update(double deltaTime) {
    //判断能否移动
    if (!movable) {
        return; 
    }

    // 设置t为exprtk变量
    symbol_table.add_variable("t", t);
    //启用数字常量和函数
    symbol_table.add_constants();

    // 准备接受运动公式
    expr_x.register_symbol_table(symbol_table);
    expr_y.register_symbol_table(symbol_table);
    expr_dir.register_symbol_table(symbol_table);
    //变量t
    t += deltaTime;

    // 计算x,y,dir
    if (!expr_x_str.empty()) {
        x = expr_x.value();  
    }
    if (!expr_y_str.empty()) {
        y = expr_y.value();  
    }
    if (!expr_dir_str.empty()) {
        dir = expr_dir.value(); 
        // 归一化
        normalize_angle(dir);
    }
}