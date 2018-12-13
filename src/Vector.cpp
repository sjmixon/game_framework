
#include "Vector.h"

Vector::Vector(float x, float y)
{
    v[0] = x;
    v[1] = y;
}

Vector& Vector::operator=(const Vector& rhs)
{
    v[0] = rhs[0];
    v[1] = rhs[1];
    return (*this);
}

float Vector::operator[](int index) const
{
    return (v[index]);
}

float& Vector::operator[](int index)
{
    return (v[index]);
}

Vector Vector::operator*(float scale) const
{
    return (Vector(v[0] * scale, v[1] * scale));
}

Vector Vector::operator/(float scale) const
{
    return (Vector(v[0] / scale, v[1] / scale));
}

Vector Vector::operator+(const Vector& other) const
{
    return (Vector(v[0] + other.v[0], v[1] + other.v[1]));
}

Vector Vector::operator-(const Vector& other) const
{
    return (Vector(v[0] - other.v[0], v[1] - other.v[1]));
}

Vector Vector::operator-() const
{
    return (Vector(-v[0], -v[1]));
}

Vector& Vector::operator*=(float scale)
{
    v[0] *= scale;
    v[1] *= scale;
    return (*this);
}

Vector& Vector::operator/=(float scale)
{
    v[0] /= scale;
    v[1] /= scale;
    return (*this);
}

Vector& Vector::operator+=(const Vector& other)
{
    v[0] += other.v[0];
    v[1] += other.v[1];
    return (*this);
}

Vector& Vector::operator-=(const Vector& other)
{
    v[0] -= other.v[0];
    v[1] -= other.v[1];
    return (*this);
}

float Vector::magnitude() const
{
    return (std::sqrt((v[0] * v[0]) + (v[1] + v[1])));
}

Vector Vector::normalize() const
{
    float m = this->magnitude();
    return (Vector(v[0] / m, v[1] / m));
}

float Vector::dot(const Vector& other) const
{
    return ((v[0] * other.v[0]) + (v[1] * other.v[1]));
}

