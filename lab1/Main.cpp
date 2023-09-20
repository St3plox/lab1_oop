#include <iostream>
#include "Vector.h"
using namespace VectorNamespace;


int main() { 


	Vector nullVector;
	Vector vector(1.0, 5.0, 7.0);


	std::cout << "null vector x:" << nullVector.getX() << std::endl;

	std::cout << "vector moudle:" << vector.module() << std::endl;

	nullVector.copyOf(vector);
	std::cout << "vector moudle:" << nullVector.module() << std::endl;

	nullVector.multByScal(3.0);
	std::cout << "null vector x:" << nullVector.getX() << std::endl;

	vector.normalize();
	std::cout << "vector x:" << vector.getX() << std::endl;

	vector.printXYZ();
	nullVector.printXYZ();


	Vector v1(1.0, 5.0, 7.0);
	Vector v2(-1.0, 15.0, -7.0);


	std::cout << "vector sum result: " << std::endl;
	sumVector(v1, v2).printXYZ();

	std::cout << "vector substraction result: " << std::endl;
	substractVector(v1, v2).printXYZ();

	std::cout << "vector multiplication result: " << std::endl;
	multVector(v1, v2).printXYZ();


	std::cout << "vector scal multiplication result: " << scalMultVector(v1, v2) << std::endl;

	std::cout << "cos between vectors: " << cosineAngle(v1, v2) << std::endl;

	std::cout << "sin between vectors: " << sinAngle(v1, v2) << std::endl;

	std::cout << "Angele in degrees between vectors: " << angleInDegrees(v1, v2) << std::endl;

	return 0;
}