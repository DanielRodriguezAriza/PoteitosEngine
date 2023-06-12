#pragma once
#include <cmath>

template<typename T = float>
class Vector3Dx
{
public:

	Vector3Dx()
		:x{ 0 }, y{ 0 }, z{ 0 }
	{}

	Vector3Dx(T f1, T f2, T f3)
		:x{ f1 }, y{ f2 }, z{ f3 }
	{}

	Vector3Dx(Vector3Dx const& other)
		:x{ other.x }, y{ other.y }, z{ other.z }
	{}

	Vector3Dx(T f)
		:x{ f }, y{ f }, z{ f }
	{}

	inline void setX(T f) { this->x = f; }
	inline void setY(T f) { this->y = f; }
	inline void setZ(T f) { this->z = f; }

	inline T getX() const { return this->x; }
	inline T getY() const { return this->y; }
	inline T getZ() const { return this->z; }

	Vector3Dx operator+(Vector3Dx const& other) const
	{
		return Vector3Dx{ this->getX() + other.getX(), this->getY() + other.getY(), this->getZ() + other.getZ() };
	}

	Vector3Dx operator-(Vector3Dx const& other) const
	{
		return Vector3Dx{ this->getX() - other.getX(), this->getY() - other.getY(), this->getZ() - other.getZ() };
	}

	Vector3Dx operator*(T f) const
	{
		return Vector3Dx{ this->getX() * f,this->getY() * f,this->getZ() * f };
	}

	Vector3Dx operator/(T f) const
	{
		return Vector3Dx{ this->getX() / f,this->getY() / f,this->getZ() / f };
	}

	Vector3Dx& operator=(Vector3Dx const& other)
	{
		this->setX(other.getX());
		this->setY(other.getY());
		this->setZ(other.getZ());
		return *this;
	}

	Vector3Dx& operator+=(Vector3Dx const& other)
	{
		this->setX(this->getX() + other.getX());
		this->setY(this->getY() + other.getY());
		this->setZ(this->getZ() + other.getZ());
		return *this;
	}

	Vector3Dx& operator-=(Vector3Dx const& other)
	{
		this->setX(this->getX() - other.getX());
		this->setY(this->getY() - other.getY());
		this->setZ(this->getZ() - other.getZ());
		return *this;
	}

	Vector3Dx& operator*=(T f)
	{
		this->setX(this->getX() * f);
		this->setY(this->getY() * f);
		this->setZ(this->getZ() * f);
		return *this;
	}

	Vector3Dx& operator/=(T f)
	{
		this->setX(this->getX() / f);
		this->setY(this->getY() / f);
		this->setZ(this->getZ() / f);
		return *this;
	}

	T operator*(Vector3Dx const& other) const
	{
		return (this->getX() * other.getX() + this->getY() * other.getY() + this->getZ() * other.getZ());
	}


	T length() const
	{
		return std::sqrt(x * x + y * y + z * z);
	}

	Vector3Dx normalize()
	{
		T len = this->length();
		return *this / len;
	}

private:
	T x, y, z;
};




template<typename T>
Vector3Dx<T> operator*(T f, Vector3Dx<T> const& v)
{
	return Vector3Dx<T>{ v.getX() * f,v.getY() * f,v.getZ() * f };
}

template<typename T>
Vector3Dx<T> operator/(T f, Vector3Dx<T> const& v)
{
	return Vector3Dx<T>{ v.getX() / f,v.getY() / f,v.getZ() / f };
}


typedef Vector3Dx<float> Vector3D;
typedef Vector3Dx<float> Vector3Df;
typedef Vector3Dx<double> Vector3Dd;
typedef Vector3Dx<int> Vector3Di;