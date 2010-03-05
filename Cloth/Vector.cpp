#include "Vector.h"

#include <cmath>

namespace Cloth {
	Vector3::Vector3() : _x(0.0f), _y(0.0f), _z(0.0f) {
	}

	Vector3::Vector3(float x, float y, float z) : _x(x), _y(y), _z(z) {
	}

	Vector3::~Vector3() {
	}

	float Vector3::mag() const {
		return sqrt(_x*_x+_y*_y+_z*_z);
	}

	float Vector3::x() const {
		return _x;
	}

	float Vector3::y() const {
		return _y;
	}

	float Vector3::z() const {
		return _z;
	}

	void Vector3::setX(float x) {
		_x = x;
	}

	void Vector3::setY(float y) {
		_y = y;
	}

	void Vector3::setZ(float z) {
		_z = z;
	}

	Vector3& Vector3::operator+=(const Vector3& a) {
		_x += a._x;
		_y += a._y;
		_z += a._z;
		return *this;
	}

	Vector3& Vector3::operator-=(const Vector3& a) {
		_x -= a._x;
		_y -= a._y;
		_z -= a._z;
		return *this;
	}

	Vector3& Vector3::operator*=(float f) {
		_x *= f;
		_y *= f;
		_z *= f;
		return *this;
	}

	Vector3& Vector3::operator/=(float f) {
		_x /= f;
		_y /= f;
		_z /= f;
		return *this;
	}

	Vector3 operator+(const Vector3& a, const Vector3& b) {
		return Vector3(a) += b;
	}

	Vector3 operator-(const Vector3& a, const Vector3& b) {
		return Vector3(a) -= b;
	}

	Vector3 operator*(const Vector3& a, float f) {
		return Vector3(a) *= f;
	}

	Vector3 operator*(float f, const Vector3& a) {
		return Vector3(a) *= f;
	}

	Vector3 operator/(const Vector3& a, float f) {
		return Vector3(a) /= f;
	}

	float dotProduct(const Vector3& a, const Vector3& b) {
		return a.x() * b.x() + a.y() * b.y() + a.z() * b.z();
	}

	Vector3 normalize(const Vector3& a) {
		float l = a.mag();
		return a / l;
	}
}