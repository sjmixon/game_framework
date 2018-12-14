
#ifndef VECTOR_H
#define VECTOR_H

class Vector
{
    public :
        Vector(float, float);

        float operator[](int) const;
        float& operator[](int);
        bool operator==(const Vector&) const;
        bool operator!=(const Vector&) const;
        Vector operator-() const;
        Vector operator+(const Vector&) const;
        Vector operator-(const Vector&) const;
        Vector operator*(float) const;
        Vector operator/(float) const;
        Vector& operator+=(const Vector&);
        Vector& operator-=(const Vector&);
        Vector& operator*=(float);
        Vector& operator/=(float);
        Vector& operator=(const Vector&);

        float magnitude() const;
        Vector normalize() const;
        float dot(const Vector&) const;

    private :
        float v[2];
};

#endif

