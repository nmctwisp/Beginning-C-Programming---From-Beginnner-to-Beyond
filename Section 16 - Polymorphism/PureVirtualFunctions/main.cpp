#include <iostream>
#include <vector>

class Shape {	//Shape is the Abstract Base Class (ABC)
private:
	// attributes common to all shapes
public:
	virtual void draw() = 0;		// pure virtual function
	virtual void rotate() = 0;		// pure virtual function
	virtual ~Shape() {};
};

class Open_Shape : public Shape { // Abstract Class
public:
	virtual ~Open_Shape() {};
};

class Closed_Shape : public Shape { // Abstract Class
public:
	virtual ~Closed_Shape() {};
};

class Line : public Open_Shape { // Concrete Class
public:
	virtual void draw() override {
		std::cout << "Drawing a Line" << std::endl;
	};
	virtual void rotate() override {
		std::cout << "Rotating a Line" << std::endl;
	}
	virtual ~Line() {};
};

class Circle : public Closed_Shape { // Concrete Class
public:
	virtual void draw() override {
		std::cout << "Drawing a Circle" << std::endl;
	};
	virtual void rotate() override {
		std::cout << "Rotating a Circle" << std::endl;
	};
	virtual ~Circle() {};
};

class Square : public Closed_Shape { // Concrete Class
public:
	virtual void draw() override {
		std::cout << "Drawing a Square" << std::endl;
	};
	virtual void rotate() override {
		std::cout << "Rotating a Square" << std::endl;
	}
	virtual ~Square() {};
};

void screen_refresh(const std::vector<Shape*> &shapes) {
	std::cout << "Refreshing..." << std::endl;
	for (const auto p : shapes)
		p->draw();
}

int main() {
	//    Shape s;
	//    Shape *p = new Shape();

	//        Circle c;
	//        c.draw();

	//    Shape *ptr = new Circle();
	//    ptr->draw();
	//    ptr->rotate();

	Shape *s1 = new Circle();
	Shape *s2 = new Line();
	Shape *s3 = new Square();

	std::vector<Shape *> shapes{ s1,s2,s3 };

	//    for (const auto p: shapes) 
	//        p->draw();

	screen_refresh(shapes);

	delete s1;
	delete s2;
	delete s3;

	return 0;
}
