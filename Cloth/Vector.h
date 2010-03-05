#ifndef __CLOTH_VECTOR_H__
#define __CLOTH_VECTOR_H__

namespace Cloth {

	class Vector3 {
	public:
		Vector3();
		Vector3(float, float, float);
		~Vector3();

		float mag() const;

		float x() const;
		float y() const;
		float z() const;
		void setX(float);
		void setY(float);
		void setZ(float);

		Vector3& operator+=(const Vector3&);
		Vector3& operator-=(const Vector3&);
		Vector3& operator*=(float);
		Vector3& operator/=(float);

	private:
		float _x, _y, _z;
	};

	Vector3 operator+(const Vector3&, const Vector3&);
	Vector3 operator-(const Vector3&, const Vector3&);
	Vector3 operator*(const Vector3&, float);
	Vector3 operator*(float, const Vector3&);
	Vector3 operator/(const Vector3&, float);

	float dotProduct(const Vector3&, const Vector3&);
	Vector3 normalize(const Vector3&);

}

#endif //__CLOTH_VECTOR_H__