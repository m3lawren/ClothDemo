#ifndef __CLOTH_CONSTRAINT_H__
#define __CLOTH_CONSTRAINT_H__

namespace Cloth {

	class Point;

	class Constraint {
	public:
		Constraint(Point&, Point&, float len);
		~Constraint();

		void enforce();

	private:
		Point&	_a;
		Point&	_b;
		float	_len;
	};

}

#endif //__CLOTH_CONSTRAINT_H__