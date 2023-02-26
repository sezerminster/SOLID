#include <iostream>


class Shape {
public:
    virtual void draw() = 0;
    virtual int getArea() = 0;
};

class Rectangle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a rectangle..." << std::endl;
    }
    int getArea() override {
        return width * height;
    }
private:
    int width;
    int height;
};

class Square : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a square..." << std::endl;
    }
    int getArea() override {
        return side * side;
    }
private:
    int side;
};

void printArea(Shape* shape) {
    std::cout << "Area: " << shape->getArea() << std::endl;
}

int main() {
    Shape* shape1 = new Rectangle();
    Shape* shape2 = new Square();
    printArea(shape1);
    printArea(shape2);
    return 0;
}
