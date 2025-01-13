#pragma once

namespace Emerald {

	/*
	=========================================================================================
	Vector4 - Represents a basic 4-dimensional vector that can also be used as a quaternion
			  for engine programming and gameplay programming.
	=========================================================================================
	*/
	class EMERALD_API Vector4 {
	public:
		Vector4();
		Vector4(const float xAssign, const float yAssign, const float zAssign, const float wAssign);

		Vector4		operator+(const Vector4& v);
		Vector4		operator-(const Vector4& v);
		Vector4&	operator+=(const Vector4& v);
		Vector4&	operator-=(const Vector4& v);
		Vector4		operator*(const float scalar);
		Vector4		operator/(float scalar);
		Vector4&	operator*=(const float scalar);
		Vector4&	operator/=(float scalar);
		float		Dot(const Vector4& in) const;
		Vector4&	Normalize();
		float		Magnitude() const;
		bool		Equals(const Vector4& other);
		std::string	ToString();

	public:
		float		x;			// Vector X Component.
		float		y;			// Vector Y Component.
		float		z;			// Vector Z Component.
		float		w;			// Vector W Component.
	};
}