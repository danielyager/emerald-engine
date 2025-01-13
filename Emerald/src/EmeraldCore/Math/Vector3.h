#pragma once

namespace Emerald {

	/*
	=========================================================================================
	Vector3 - Represents a basic 3-dimensional vector that can be used in a virtual space.
			This vector is right-handed with z axis pointing upwards, x pointing forwards,
			and y pointing to the left.
	=========================================================================================
	*/
	class EMERALD_API Vector3 {
	public:
		Vector3();
		Vector3(const float xAssign, const float yAssign, const float zAssign);

		Vector3		operator+(const Vector3& v);
		Vector3		operator-(const Vector3& v);
		Vector3&	operator+=(const Vector3& v);
		Vector3&	operator-=(const Vector3& v);
		Vector3		operator*(const float scalar);
		Vector3		operator/(float scalar);
		Vector3&	operator*=(const float scalar);
		Vector3&	operator/=(float scalar);
		float		Dot(const Vector3& in) const;
		void		Cross(const Vector3& in, Vector3& out);
		Vector3&	Normalize();
		float		Magnitude() const;
		float		Distance(const Vector3& other);
		bool		AreParallelOrAntiparallel(const Vector3& otherVec);
		bool		Equals(const Vector3& other);
		std::string	ToString();

	public:
		float		x;			// Vector X Component.
		float		y;			// Vector Y Component.
		float		z;			// Vector Z Component.
	};

}