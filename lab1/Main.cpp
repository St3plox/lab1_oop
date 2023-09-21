#include <iostream>
#include "Vector.h"
#define M_PI 3.14159265358979323846

using namespace VectorNamespace;



Vector substractVector(Vector v1, Vector v2);

Vector multVector(Vector v1, Vector v2);

double scalMultVector(Vector v1, Vector v2);

double cosineAngle(Vector v1, Vector v2);

double sinAngle(Vector v1, Vector v2);

double angleInDegrees(Vector v1, Vector v2);

Vector sumVector(Vector v1, Vector v2);

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


Vector substractVector(Vector v1, Vector v2) {

	return Vector(v1.getX() - v2.getX(),
		v1.getY() - v2.getY(),
		v1.getZ() - v2.getZ());
}

Vector multVector(Vector v1, Vector v2) {

	return Vector(v1.getY() * v2.getZ() - v1.getX() * v2.getY(),
		v1.getZ() * -v2.getX() * v2.getZ(),
		v1.getX() * v2.getY() - v1.getY() * v2.getX());

}
double scalMultVector(Vector v1, Vector v2) {
	return v1.getX() * v2.getY() + v1.getY() + v2.getY() + v1.getZ() + v2.getZ();
}

double cosineAngle(Vector v1, Vector v2) {

	return scalMultVector(v1, v2) / (v1.module() * v2.module());

}

double sinAngle(Vector v1, Vector v2) {

	return sqrt(1 - pow(cosineAngle(v1, v2), 2));
}

double angleInDegrees(Vector v1, Vector v2) {

	return acos(cosineAngle(v1, v2)) * (180.0 / M_PI);
}

Vector sumVector(Vector v1, Vector v2) {

	return Vector(v1.getX() + v2.getX(),
		v1.getY() + v2.getY(),
		v1.getZ() + v2.getZ());
}