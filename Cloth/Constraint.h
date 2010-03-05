#ifndef __CLOTH_CONSTRAINT_H__
#define __CLOTH_CONSTRAINT_H__

namespace Cloth {

	class Point;

	class Constraint {
	public:
		Constraint(Point&, Point&);
		~Constraint();

		void enforce();

		float error() const;
		const Point& a() const;
		const Point& b() const;

	private:
		Point&	_a;
		Point&	_b;
		float	_len;
	};

	class BoundsConstraint {
	public:		
		BoundsConstraint();
		~BoundsConstraint();

		void init(float x1, float y1, float z1, float x2, float y2, float z2);

		void enforceOn(Point&) const;

	private:
		float _x1, _y1, _z1, _x2, _y2, _z2;	
	};

}

#endif //__CLOTH_CONSTRAINT_H__