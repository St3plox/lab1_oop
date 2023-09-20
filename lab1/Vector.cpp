#include <iostream>
#include <math.h>
#include "Vector.h"
using namespace VectorNamespace;
#define M_PI 3.14159265358979323846


	double x;
	double y;
	double z;

	Vector::Vector() {

		x = 0;
		y = 0;
		z = 0;

		std::cout << "Null-vector has been created" << std::endl;
	}

	Vector::Vector(double x, double y, double z) {

		this->x = x;

		this->y = y;

		this->z = z;

		std::cout << "Vector has been created" << std::endl;
	}


	Vector::~Vector() {
		std::cout << "Vector has been deleted" << std::endl;
	}

	Vector::Vector(const Vector& other) {
		x = other.x;
		y = other.y;
		z = other.z;
		std::cout << "Copy constructor called" << std::endl;
	}

	Vector::Vector(Vector&& other) noexcept {
		x = std::move(other.x); 
		y = std::move(other.y);
		z = std::move(other.z);
		std::cout << "Move constructor called" << std::endl;
	}

	double Vector::module() {

		return sqrt(pow(x, 2)
			+ pow(y, 2)
			+ pow(z, 2));
	}

	void Vector::copyOf(VectorNamespace::Vector vector) {

		x = vector.getX();
		y = vector.getY();
		z = vector.getZ();

	}

	void Vector::multByScal(double a) {
		
		x *= a;
		y *= a;
		z *= a;
	}

	void VectorNamespace::Vector::normalize() {

		double module = this->module();

		x /= module;
		y /= module;
		z /= module;
	}

	void Vector::printXYZ() {

		std::cout << "X is "<< x << std::endl;
		std::cout << "Y is " << y << std::endl;
		std::cout << "Z is " << x << std::endl;
	}

	double Vector::getX() {
		return x;
	}

	double Vector::getY() {
		return y;
	}

	double Vector::getZ() {
		return z;
	}

	void Vector::setX(double x) {
		this->x = x;
	}

	void Vector::setY(double y) {
		this->y = y;
	}

	void Vector::setZ(double z) {
		this->z = z;
	}

	Vector sumVector(Vector v1, Vector v2) {
	
	return Vector(v1.getX() + v2.getX(),
		v1.getY() + v2.getY(),
		v1.getZ() + v2.getZ());
}

Vector substractVector(Vector v1, Vector v2) {

	return Vector(v1.getX() - v2.getX(),
		v1.getY() - v2.getY(),
		v1.getZ() - v2.getZ());
}

Vector multVector(Vector v1, Vector v2) {
	
	return Vector(v1.getY() * v2.getZ() - v1.getX() * v2.getY(),
			v1.getZ() *  - v2.getX() * v2.getZ(),
			v1.getX() * v2.getY() - v1.getY() * v2.getX());

}
double scalMultVector(Vector v1, Vector v2) {
	return v1.getX()*v2.getY() + v1.getY() + v2.getY() + v1.getZ() + v2.getZ();
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