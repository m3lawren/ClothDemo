#ifndef __CLOTH_POINT_H__
#define __CLOTH_POINT_H__

#include <Cloth/Vector.h>

namespace Cloth {

	class Point {
	public:
		Point();
		Point(const Vector3&);
		Point(float, float, float);
		~Point();

		Vector3& pos();
		const Vector3& pos() const;

	private:
		Vector3		_pos;
		Vector3		_oldPos;
	};

}

#endif //__CLOTH_POINT_H__