#ifndef __CLOTH_POINT_H__
#define __CLOTH_POINT_H__

#include <Cloth/Vector.h>

namespace Cloth {

	class Point {
	public:
		Point();
		Point(const Cloth::Vector3&);
		Point(float, float, float);
		~Point();

		Cloth::Vector3& pos();
		const Cloth::Vector3& pos() const;

		bool fixed() const;
		void setFixed(bool);

		float x() const;
		float y() const;
		float z() const;

		void tick(const Cloth::Vector3& gravity);

	private:
		Cloth::Vector3		_pos;
		Cloth::Vector3		_oldPos;
		bool				_fixed;
	};

}

#endif //__CLOTH_POINT_H__