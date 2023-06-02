// PolimorphismVirtualFunction.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

class Shape {
public:
	virtual double getArea()const;
	virtual double getVolume()const;
	virtual std::string getName()const = 0;
	virtual void print()const = 0;
};

class Point : public Shape {
public:
	Point(int = 0, int = 0);
	void setX(int);
	int getX()const;
	void setY(int);
	int getY()const;
	virtual std::string getName()const;
	virtual void print()const;

private:
	int x;
	int y;

};


class Circle : public Point {
public:
	Circle(int = 0, int = 0, double = 0.0);
	void setRadius(double);
	double getRadius()const;
	double getDiameter()const;
	double getCircumference()const;
	virtual double getArea()const;
	virtual double getVolume()const;
	virtual std::string getName()const;
	virtual void print()const;

private:
	double radius;
};


class Cylinder : public Circle {
public:
	Cylinder(int = 0, int = 0, double = 0.0, double = 0.0);
	void setHeight(double);
	double getHeight()const;
	virtual double getArea()const;
	virtual double getVolume()const;
	virtual std::string getName()const;
	virtual void print()const;

private:
	double height;
};

double Shape::getArea()const
{
	return 0.0;
}

double Shape::getVolume()const
{
	return 0.0;
}

Point::Point(int xValue, int yValue) :x(xValue), y(yValue)
{

}

void Point::setX(int xValue)
{
	x = xValue;
}

int Point::getX()const {
	return x;
}


void Point::setY(int yValue)
{
	y = yValue;
}

int Point::getY()const {
	return y;
}

std::string Point::getName() const
{
	return "Point";
}

void Point::print()const
{
	std::cout << "[" << getX() << ", " << getY() << ']';
}

Circle::Circle(int xValue, int yValue, double radiusValue)
	:Point(xValue, yValue)
{
	setRadius(radiusValue);
}

void Circle::setRadius(double radiusValue)
{
	radius = (radiusValue < 0.0 ? 0.0 : radiusValue);
}

double Circle::getRadius()const
{
	return radius;
}

double Circle::getDiameter()const
{
	return 2 * getRadius();
}

double Circle::getCircumference()const
{
	return 3.14159 * getDiameter();
}

double Circle::getArea()const
{
	return 3.14159 * getRadius() * getRadius();
}

std::string Circle::getName() const
{
	return "Circle";
}

void Circle::print() const
{
	std::cout << "center is ";
	Point::print();
	std::cout << "; radius is " << getRadius();
}

Cylinder::Cylinder(int xValue, int yValue, double radiusValue, double heightValue) 
	:Circle(xValue, yValue, radiusValue) {
	setHeight(heightValue);
}

void Cylinder::setHeight(double heightValue)
{
	height = (height < 0.0 ? 0.0 : heightValue);
}

double Cylinder::getHeight()const
{
	return height;
}

double Cylinder::getArea()const
{
	return 2 * Circle::getArea() + getCircumference()*getHeight();
}

double Cylinder::getVolume()const
{
	return Circle::getArea() * getHeight();
}

std::string Cylinder::getName()const
{
	return "Cylinder";
}

void Cylinder::print()const
{
	Circle::print();
	std::cout << ", heinght is " << getHeight();
}

void virtualViaPointer(const Shape*);
void virtualViaReference(const Shape&);

int main()
{
	Point p(7, 11);
	Circle circle(22, 8, 3.5);
	Cylinder cylinder(10, 10, 3.3, 10);
	Shape* shape;
	Shape* shapeCircle;
	Shape* shapeCylinder;
	shape = &p;
	shapeCircle = &circle;
	shapeCylinder = &cylinder;
	
	virtualViaPointer(shape); 
	virtualViaReference(*shape);
	virtualViaPointer(shapeCircle);
	virtualViaReference(*shapeCircle);
	virtualViaPointer(shapeCylinder);
	virtualViaReference(*shapeCylinder);
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
