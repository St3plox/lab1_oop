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
}