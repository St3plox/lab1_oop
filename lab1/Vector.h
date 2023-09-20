#pragma once

namespace VectorNamespace {

    class Vector {
    private:
        double x;
        double y;
        double z;

    public:
        Vector();
        Vector(double x, double y, double z);
        ~Vector();
        Vector(const Vector& other);
        Vector(Vector&& other)noexcept;

        double module();
        void copyOf(Vector vector);
        void multByScal(double a);
        void normalize();
        void printXYZ();

        double getX();
        double getY();
        double getZ();

        void setX(double x);
        void setY(double y);
        void setZ(double z);
    };
    Vector sumVector(Vector v1, VectorNamespace::Vector v2);

    Vector substractVector(Vector v1, Vector v2);

    Vector multVector(Vector v1, Vector v2);

    double scalMultVector(Vector v1, Vector v2);

    double cosineAngle(Vector v1, Vector v2);

    double sinAngle(Vector v1, Vector v2);

    double angleInDegrees(Vector v1, Vector v2);
}