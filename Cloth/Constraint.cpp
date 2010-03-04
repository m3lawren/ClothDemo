#include "Constraint.h"

#include "Point.h"

namespace Cloth {

	Constraint::Constraint(Point& a, Point& b, float len) : _a(a), _b(b), _len(len) {
	}

	Constraint::~Constraint() {
	}

	void Constraint::enforce() {
		Vector3 delta = _a.pos() - _b.pos();
		float diff = (delta.mag() - _len) / 2.0f;
		delta = normalize(delta);

		_a.pos() -= diff * delta;
		_b.pos() += diff * delta;
	}

}