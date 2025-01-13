#pragma once

namespace Emerald {

	/*
	=========================================================================================
	Vector2 - Represents a basic 2-dimensional vector that can be used in a virtual space.
			The x-axis points to the right and the y axis points up.
	=========================================================================================
	*/
	class EMERALD_API Vector2 {
	public:
		Vector2();
		Vector2(const float xAssign, const float yAssign);

		Vector2		operator+(const Vector2& v);
		Vector2		operator-(const Vector2& v);
		Vector2&	operator+=(const Vector2& v);
		Vector2&	operator-=(const Vector2& v);
		Vector2		operator*(const float scalar);
		Vector2		operator/(float scalar);
		Vector2&	operator*=(const float scalar);
		Vector2&	operator/=(float scalar);
		float		Dot(const Vector2& in) const;
		Vector2&	Normalize();
		float		Magnitude() const;
		float		Distance(const Vector2& other);
		bool		AreParallelOrAntiparallel(const Vector2& otherVec);
		bool		Equals(const Vector2& other);
		std::string	ToString();

	public:
		float		x;			// Vector X Component.
		float		y;			// Vector Y Component.
	};
}