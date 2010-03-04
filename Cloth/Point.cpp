#include "Point.h"

namespace Cloth {

	Point::Point() {
	}

	Point::Point(const Vector3& p) : _pos(p) {
	}

	Point::Point(float x, float y, float z) : _pos(x,y,z) {
	}

	Point::~Point() {
	}

	Vector3& Point::pos() {
		return _pos;
	}

	const Vector3& Point::pos() const {
		return _pos;
	}

}