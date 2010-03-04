#include "Output.h"

#include <sstream>

std::ostream& operator<<(std::ostream& s, const Cloth::Vector3& v) {
	std::ostringstream ss;
	ss.precision(3);
	ss.setf(std::ios::fixed, std::ios::floatfield);
	ss << '(' << v.x() << ", " << v.y() << ", " << v.z() << ')';

	return s << ss.str();
}