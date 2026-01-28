#ifndef MATHTOOL_HPP
#define MATHTOOL_HPP

#include <cmath>

#ifndef M_PI
constexpr double M_PI = 3.1415926535;
#endif

constexpr double EPS = 1e-9;

// 1. 角度归一化：映射到 [-π, π)

inline double normalize_angle(double angle) {
    while (angle > M_PI) angle -= 2.0 * M_PI;
    while (angle <= -M_PI) angle += 2.0 * M_PI;
    return angle;
}

// 2. 距离计算

inline double distance(double x1, double y1, double x2, double y2) {
    double dx = x2 - x1, dy = y2 - y1;
    return std::sqrt(dx * dx + dy * dy);
}

inline double distance_sq(double x1, double y1, double x2, double y2) {
    double dx = x2 - x1, dy = y2 - y1;
    return dx * dx + dy * dy;
}

// 3. 旋转（绕原点）
// 输入：局部点 (lx, ly)，旋转角 theta（弧度）
// 输出：通过引用返回世界坐标 (wx, wy)

inline void rotate_point(double lx, double ly, double theta,
                         double& wx, double& wy) {
    double c = std::cos(theta);
    double s = std::sin(theta);
    wx = lx * c - ly * s;  // x' = x·cosθ - y·sinθ
    wy = lx * s + ly * c;  // y' = x·sinθ + y·cosθ
}

// 4. 射线-线段相交检测
// 射线：起点 (rx, ry)，方向 (rdx, rdy) —— 不要求单位向量
// 线段：端点 A(ax, ay) 到 B(bx, by)
// 返回 true 并填充 out_t（射线参数 ≥0）和 out_u（线段参数 ∈ [0,1]）

inline bool ray_intersects_segment(
    double rx, double ry, double rdx, double rdy,
    double ax, double ay, double bx, double by,
    double& out_t, double& out_u) {

    double seg_dx = bx - ax;
    double seg_dy = by - ay;

    double det = rdx * (-seg_dy) - rdy * (-seg_dx); // = -(rdx*seg_dy - rdy*seg_dx)

    if (std::abs(det) < EPS) return false; // 平行或共线

    double inv_det = 1.0 / det;
    double t = ((ax - rx) * (-seg_dy) - (ay - ry) * (-seg_dx)) * inv_det;
    double u = ((ay - ry) * rdx - (ax - rx) * rdy) * inv_det;

    if (t >= 0.0 && u >= 0.0 && u <= 1.0) {
        out_t = t;
        out_u = u;
        return true;
    }
    return false;
}

// 重载：仅判断是否相交
inline bool ray_intersects_segment(
    double rx, double ry, double rdx, double rdy,
    double ax, double ay, double bx, double by) {
    double t, u;
    return ray_intersects_segment(rx, ry, rdx, rdy, ax, ay, bx, by, t, u);
}

// 5. 朝向换算（关键！适配 +Y 为前）
// 从朝向角 theta → 前向单位向量 (fx, fy)
// theta = 0 → (0, 1)

inline void forward_vector(double theta, double& fx, double& fy) {
    fx = std::sin(theta);  // x = sin(θ)
    fy = std::cos(theta);  // y = cos(θ)
}

// 从两点计算朝向角（from → to）
// 结果 ∈ [-π, π)
inline double direction_from_to(double from_x, double from_y,
                                double to_x, double to_y) {
    double dx = to_x - from_x;
    double dy = to_y - from_y;
    return normalize_angle(std::atan2(dx, dy)); // ← 注意：dx, dy 顺序！
}

#endif //MATHTOOL_HPP