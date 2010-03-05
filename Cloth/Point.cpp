#include "Point.h"

namespace Cloth {

	Point::Point() {
	}

	Point::Point(const Vector3& p) : _pos(p), _oldPos(p), _fixed(false) {
	}

	Point::Point(float x, float y, float z) : _pos(x,y,z), _oldPos(_pos), _fixed(false) {
	}

	Point::~Point() {
	}

	Cloth::Vector3& Point::pos() {
		return _pos;
	}

	const Cloth::Vector3& Point::pos() const {
		return _pos;
	}

	bool Point::fixed() const {
		return _fixed;
	}

	void Point::setFixed(bool v) {
		_fixed = v;
	}

	float Point::x() const {
		return _pos.x();
	}

	float Point::y() const {
		return _pos.y();
	}

	float Point::z() const {
		return _pos.z();
	}

	void Point::tick(const Cloth::Vector3& gravity) {
		if (_fixed) return;
		Cloth::Vector3 npos = _pos + 0.995f * (_pos - _oldPos) + gravity;
		_oldPos = _pos;
		_pos = npos;

	}

}