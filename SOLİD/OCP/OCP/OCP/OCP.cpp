#include <iostream>
#include <vector>

class Shape {
public:
    virtual double area() = 0;
};

class Rectangle : public Shape {
public:
    Rectangle(double width, double height) : width_(width), height_(height) {}
    double area() override {
        return width_ * height_;
    }
private:
    double width_;
    double height_;
};

class Circle : public Shape {
public:
    Circle(double radius) : radius_(radius) {}
    double area() override {
        return 3.14 * radius_ * radius_;
    }
private:
    double radius_;
};

class AreaCalculator {
public:
    double calculateArea(std::vector<Shape*> shapes) {
        double totalArea = 0;
        for (auto shape : shapes) {
            totalArea += shape->area();
        }
        return totalArea;
    }
};

int main() {
    Rectangle r(2, 4);
    Circle c(5);
    AreaCalculator calc;
    std::vector<Shape*> shapes = { &r, &c };
    double totalArea = calc.calculateArea(shapes);
    std::cout << "Total area = " << totalArea << std::endl;
    return 0;
}
