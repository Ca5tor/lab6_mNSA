#include <iostream>
#include <iomanip>

double f(double x, double y) { // F'(L)
	return ((36*x*x-36*x+4*y*y+4*y+10) / (216*x*x-216*x+8*y*y+8*y+56));
}

double gx(double x) {return (6 * x - 3);} // df/dx

double gy(double y) {return (2 * y + 1);} // df/dy

void NSA(double x, double y, double E) {
	double xmin, ymin, L;
	int k = 0;

	std::cout << "k\tx\t\ty\t      gx\t    gy" << std::endl;
	std::cout << k << std::setw(9)  << x << std::setw(15) << y << std::setw(15) <<
		 gx(x) << std::setw(15) << gy(y) << std::endl;

	k = 1;

	while (std::abs(gx(x)) > E && std::abs(gy(y)) >= E ) {
		 L = f(x, y);
		 x = x - L * gx(x);
		 y = y - L * gy(y);
	
		 std::cout << std::setprecision(4) << k     << std::setw(9)  <<
			     x << std::setw(15)        << y     << std::setw(15) <<
			 gx(x) << std::setw(15)        << gy(y) << std::endl;

		 k++;
	}
	xmin = x;
	ymin = y;
	std::cout << "\n\tXmin= " << x << "\tYmin= " << y << std::endl;
}

void main() {
	double a = 1.f, b = -1.f, E = 0.0001f;
	NSA(a, b, E);
	std::cin.get();
}