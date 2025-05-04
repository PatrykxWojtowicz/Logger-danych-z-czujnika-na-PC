#include <iostream>
#include <cmath>

class Point {
private:
    double x, y;

public:
    Point() : x(0), y(0) {}

    Point(double xVal, double yVal) : x(xVal), y(yVal) {}

    void set(double newX, double newY) {
        x = newX;
        y = newY;
    }

    void print() const {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }

    double distanceTo(const Point& other) const {
        double dx = x - other.x;
        double dy = y - other.y;
        return std::sqrt(dx * dx + dy * dy);
    }

    void move(double dx, double dy) {
        x += dx;
        y += dy;
    }

    Point rotated(double angleRadians) const {
        double newX = x * std::cos(angleRadians) - y * std::sin(angleRadians);
        double newY = x * std::sin(angleRadians) + y * std::cos(angleRadians);
        return Point(newX, newY);
    }
};

int main() {
    Point p1;
    Point p2(3, 4);

    p1.set(0, 0);
    std::cout << "Point 1: "; p1.print();
    std::cout << "Point 2: "; p2.print();

    std::cout << "Distance between points: " << p1.distanceTo(p2) << std::endl;

    p1.move(2, 2);
    std::cout << "Point 1 after moving: "; p1.print();

    double angleDegrees = 90;
    double radians = angleDegrees * 3.14 / 180.0;

    Point p3 = p2.rotated(radians);

    std::cout << "Point 2 rotated by 90 degrees:" << std::endl;
    p3.print();

    return 0;
}
