#include "Constraint.h"

#include "Point.h"

#include <cmath>

#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))

namespace Cloth {

	Constraint::Constraint(Point& a, Point& b, float len) : _a(a), _b(b), _len(len) {
		_len = (_a.pos() - _b.pos()).mag();
	}

	Constraint::~Constraint() {
	}

	void Constraint::enforce() {	
		if (_a.fixed() && _b.fixed()) return;

		Vector3 delta = _a.pos() - _b.pos();
		float diff = (delta.mag() - _len) / delta.mag();		

		if		(_a.fixed()) _b.pos() += diff * delta;
		else if (_b.fixed()) _a.pos() -= diff * delta;
		else {
			_a.pos() -= diff * delta / 2.0f;
			_b.pos() += diff * delta / 2.0f;
		}

		float foo = (_a.pos() - _b.pos()).mag();
	}

	float Constraint::error() const {
		return fabs((_a.pos() - _b.pos()).mag() - _len);
	}

	const Point& Constraint::a() const {
		return _a;
	}

	const Point& Constraint::b() const {
		return _b;
	}

	BoundsConstraint::BoundsConstraint() : _x1(0.0f), _y1(0.0f), _z1(0.0f), _x2(0.0f), _y2(0.0f), _z2(0.0f) {		
	}

	BoundsConstraint::~BoundsConstraint() {
	}

	void BoundsConstraint::init(float x1, float y1, float z1, float x2, float y2, float z2) {
		_x1 = MIN(x1, x2);
		_x2 = MAX(x1, x2);

		_y1 = MIN(y1, y2);
		_y2 = MAX(y1, y2);

		_z1 = MIN(z1, z2);
		_z2 = MAX(z1, z2);
	}

	void BoundsConstraint::enforceOn(Cloth::Point& p) const {
		Cloth::Vector3& v = p.pos();
		
		if		(_x1 == _x2)    ; 
		else if (v.x() < _x1)	v.setX(_x1);
		else if (v.x() > _x2)	v.setX(_x2);

		if		(_y1 == _y2)    ;
		else if (v.y() < _y1)	v.setY(_y1);
		else if (v.y() > _y2)	v.setY(_y2);

		if		(_z1 == _z2)	;
		else if (v.z() < _z1)	v.setZ(_z1);
		else if (v.z() > _z2)	v.setZ(_z2);
	}

}