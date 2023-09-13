#include <iostream>
#include <math.h>

class Vector {
private:
	double beginX;

	double beginY;

	double beginZ;

	double endX;

	double endY;

	double endZ;

	double coordinates(double end, double begin) {
		return end - begin;
	}

public:
	Vector() {
		std::cout << "Null-vector has been created" << std::endl;
	}

	Vector(double beginX, double beginY, double beginZ,
		double endX, double endY, double endZ) {

		this->beginX = beginX;
		this->beginY = beginY;
		this->beginZ = beginZ;

		this->endX = endX;
		this->endY = endY;
		this->endZ = endZ;

		std::cout << "Vector has been created" << std::endl;
	}

	double module() {

		return sqrt(pow((endZ - beginZ), 2)
			+ pow((endY - beginY), 2)
			+ pow((endX - beginZ), 2));
	}

	void copyOf(Vector vector) {
		beginX = vector.getBeginX();
		beginY = vector.getBeginY();
		beginZ = vector.getBeginZ();

		endX = vector.getEndX();
		endY = vector.getEndY();
		endZ = vector.getEndZ();

	}

	void multByScal(double a) {
		beginX *= a;
		beginY *= a;
		beginZ *= a;

		endX *= a;
		endY *= a;
		endZ *= a;
	}

	void normalize() {
		double module = this->module();

		beginX /= module;
		beginY /= module;
		beginZ /= module;

		endX /= module;
		endY /= module;
		endZ /= module;
	}



	~Vector() {
		std::cout << "Vector has been deleted" << std::endl;
	}

	double getBeginX() {
		return beginX;
	}

	double getBeginY() {
		return beginY;
	}

	double getBeginZ() {
		return beginZ;
	}

	double getEndX() {
		return endX;
	}

	double getEndY() {
		return endY;
	}

	double getEndZ() {
		return endZ;
	}

	void setBeginX(double beginX) {
		this->beginX = beginX;
	}

	void setBeginY(double beginY) {
		this->beginY = beginY;
	}

	void setBeginZ(double beginY) {
		this->beginZ = beginZ;
	}

	void setEndX(double endX) {
		this->endX = endX;
	}

	void setEndY(double endY) {
		this->endY = endY;
	}

	void setEndZ(double endZ) {
		this->endZ = endZ;
	}
};

Vector sumVector(Vector v1, Vector v2) {
	Vector c(v1.getBeginX() + v2.getBeginX(),
		v1.getBeginY() + v2.getBeginY(),
		v1.getBeginZ() + v2.getBeginZ(),
		v1.getEndX() + v2.getEndX(),
		v1.getEndY() + v2.getEndY(),
		v1.getEndZ() + v2.getEndZ()
	);

	return c;
}
Vector substractVector(Vector v1, Vector v2) {
	Vector c(v1.getBeginX()  - v2.getBeginX(),
		v1.getBeginY() - v2.getBeginY(),
		v1.getBeginZ() - v2.getBeginZ(),
		v1.getEndX() - v2.getEndX(),
		v1.getEndY() - v2.getEndY(),
		v1.getEndZ() - v2.getEndZ()
	);

	return c;
}

double multVector(Vector v1, Vector v2) {
	
	double a1 = v1.getEndX() - v1.getBeginZ();
	double a2 = v1.getEndY() - v1.getBeginY();
	double a3 = v1.getEndZ() - v1.getBeginZ();

	double b1 = v2.getEndX() - v2.getBeginZ();
	double b2 = v2.getEndY() - v2.getBeginY();
	double b3 = v2.getEndZ() - v2.getBeginZ();


	return sqrt(pow((a2 * b3 - a3 * b2), 2)
			+ pow((a3 * b1 - a1 * b3), 2)
			+ pow((a1 * b2 - a2 * b1), 2));

}
double scalMultVector(Vector v1, Vector v2) {

}

int main() {
	Vector nullVector;
	Vector vector(1.0, 2.0, 3.0, 7.0, 8.0, 9.0);

	std::cout << "vector moudle:" << vector.module() << std::endl;
	nullVector.copyOf(vector);
	std::cout << "vector moudle:" << nullVector.module() << std::endl;

	nullVector.multByScal(3.0);
	std::cout << "null vector x:" << nullVector.getBeginX() << std::endl;
	
	vector.normalize();
	std::cout << "vector x:" << vector.getBeginX() << std::endl;



	return 0;
}