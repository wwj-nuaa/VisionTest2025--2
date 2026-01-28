#ifndef OBJECT_HPP
#define OBJECT_HPP

#include"exprtk.hpp"

class object{
    private:
        int id;
        double x,y,dir;
        bool movable;

        double t=0.0;//exprtk引入需要时间变量

        //存储用户输入的表达式字符串
        std::string expr_x_str;
        std::string expr_y_str;
        std::string expr_dir_str;

        //使用exprtk
        exprtk::symbol_table<double> symbol_table;
        exprtk::expression<double> expr_x;
        exprtk::expression<double> expr_y;
        exprtk::expression<double> expr_dir;
        exprtk::parser<double> parser;

        //确保x,y,dir编译成功
        bool valid_x = false;
        bool valid_y = false;
        bool valid_dir = false;
    
    public:
        //构造函数
        object(int _id, double _x, double _y, double _dir, bool _movable = false);

        //访问数据
        int getId() { return id; }
        double getX() { return x; }
        double getY() { return y; }
        double getDir() { return dir; }
        bool isMovable() { return movable; }
        //输入数据
        void getId(int _id) { id=_id; }
        void getX(double _x){ x=_x; }
        void getY(double _y) { y=_y; }
        void getDir(double _dir) {dir=_dir; }
        void isMovable(bool _movable) { movable=_movable; }

        //设置运动规则
        void setMovementExpressions(const std::string& x_expr,
                                    const std::string& y_expr,
                                    const std::string& dir_expr);

        //更新x,y,dir值
        void update(double deltaTime);
};




#endif