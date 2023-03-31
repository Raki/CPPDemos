#include <fmt/format.h>
#include <vector>
#include <chrono>
#include <future>


class Point
{
private:
	static size_t cCount; //This is just declaration
public:
	float x, y, z;
	Point(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		cCount++;
	}
	Point(const Point& p)
	{
		x = p.x;
		y = p.y;
		z = p.z;
		fmt::print("copy constructor called\n");
	}
	void operator=(const Point &p)
	{
		this->x = p.x;
		this->y = p.y;
		fmt::print("assignment operator called\n");
	}
};

size_t Point::cCount; //This is the defintion

Point add(Point& a, Point& b)
{
	return Point(a.x + b.x, a.y + b.y, a.z + b.z);
}

int main()
{
	
	Point p(0,0,0);
	Point p2 = p; // copy construct
	              /*
				  * A copy constructor is used to initialize a previously uninitialized object from some other object's data.
				  */
	Point p3(p2); // copy construct
	Point p4(1, 2, 3);
	
	p = add(p, p4); // assignment operator
					/*
					* An assignment operator is used to replace the data of a previously initialized object with some other object's data.
					*/
	p.x += 1;
	return EXIT_SUCCESS;
}


