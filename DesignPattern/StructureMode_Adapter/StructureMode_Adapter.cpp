// StructureMode_Adapter.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

struct Coord
{
    double x = 0;
};

struct Point
{
    double x = 0;
    double y = 0;

    Point(Coord _x, Coord _y)
    {
        x = _x.x;
        y = _y.x;
    }
};

class Manipulator {};

class Shape {
public:
    Shape() {}
    virtual void BoundingBox(Point& bottomLeft, Point& topRight)
    {

    }

    virtual Manipulator* CreateManipulator() const {
        return new Manipulator();
    }
};

class TextView {
public:
    TextView() {}
    void GetOrigin(Coord& x, Coord& y) const {

    }
    void GetExtent(Coord& width, Coord& height) const {

    }
    virtual bool IsEmpty() const {
        return false;
    }
};

// Adapter
class TextShape : public Shape, private TextView {
public:
    TextShape() {}
    virtual void BoundingBox(Point& bottomLeft, Point& topRight)
    {
        Coord bottom, left, width, height;
        
        GetOrigin(bottom, left);
        GetExtent(width, height);

        bottomLeft = Point(bottom, left);
        topRight = Point(bottom, left);
    }

    virtual bool IsEmpty() const {
        return TextView::IsEmpty();
    }

    virtual Manipulator* CreateManipulator() const {
        return new Manipulator();
    }

private:

};

int main()
{
    TextShape textShape;
}
