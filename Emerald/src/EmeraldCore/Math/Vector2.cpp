#include "emeraldpch.h"
#include "Vector2.h"

namespace Emerald {

	/*
	================================================
	Vector2 Constructor - No Arguments
	================================================
	*/
	Vector2::Vector2() {
		Vector2(0.0, 0.0);
	}


	/*
	================================================
	Vector2 Constructor - All Arguments
	================================================
	*/
	Vector2::Vector2(const float xAssign, const float yAssign) {
		x = xAssign;
		y = yAssign;
	}


	/*
	==================================================
	Vector2 operator overload functions for addition
	and subtraction between vectors, as well as
	multiplication and division between vectors and
	a scalar.
	==================================================
	*/
	Vector2 Vector2::operator+(const Vector2& v) {
		return Vector2(x + v.x, y + v.y);
	}

	Vector2 Vector2::operator-(const Vector2& v) {
		return Vector2(x - v.x, y - v.y);
	}

	Vector2& Vector2::operator+=(const Vector2& v) {
		x += v.x;
		y += v.y;
		return (*this);
	}

	Vector2& Vector2::operator-=(const Vector2& v) {
		x -= v.x;
		y -= v.y;
		return (*this);
	}

	Vector2 Vector2::operator*(const float scalar) {
		return Vector2(x * scalar, y * scalar);
	}

	Vector2 Vector2::operator/(float scalar) {
		scalar = 1.0f / scalar;
		return Vector2(x * scalar, y * scalar);
	}

	Vector2& Vector2::operator*=(const float scalar) {
		x *= scalar;
		y *= scalar;
		return (*this);
	}

	Vector2& Vector2::operator/=(float scalar) {
		scalar = 1.0f / scalar;
		x *= scalar;
		y *= scalar;
		return (*this);
	}


	/*
	=======================================================
	Vector2::Dot - Calculates and returns the dot product
				   between this vector and another passed
				   as a paramter.
	=======================================================
	*/
	float Vector2::Dot(const Vector2& in) const {
		return (x * in.x + y * in.y);
	}


	/*
	===========================================================
	Vector2::Normalize - Converts this vector to a unit
						 vector and returns it as a reference.
	===========================================================
	*/
	Vector2& Vector2::Normalize() {
		const float inverseMagnitude = 1.0f / Magnitude();
		x *= inverseMagnitude;
		y *= inverseMagnitude;
		return (*this);
	}


	/*
	=======================================================
	Vector2::Magnitude - Returns the length of the vector.
	=======================================================
	*/
	float Vector2::Magnitude() const {
		return sqrtf((x * x) + (y * y));
	}


	/*
	=================================================================
	Vector2::Distance - Calculates the distance between two vectors.
	=================================================================
	*/
	float Vector2::Distance(const Vector2& other) {
		float distanceX = x - other.x;
		float distanceY = y - other.y;
		return sqrtf((distanceX * distanceX) + (distanceY * distanceY));
	}


	/*
	===========================================================
	Vector2::AreParallelOrAntiparallel

	Compares two input Vector2 parameters and returns true if
	they are parallel or anti-parallel to each other.
	False otherwise.
	===========================================================
	*/
	bool Vector2::AreParallelOrAntiparallel(const Vector2& otherVec) {
		float magnitudeProduct = Magnitude() * otherVec.Magnitude();
		float dotProduct = Dot(otherVec);
		if ((magnitudeProduct == dotProduct) || (magnitudeProduct == (dotProduct * -1.0f))) {
			return true;
		}
		return false;
	}


	/*
	===========================================================
	Vector2::Equals - Takes another Vector2 object as a
						parameter and returns true if each
						element between the vectors are equal.
						False otherwise.
	===========================================================
	*/
	bool Vector2::Equals(const Vector2& other) {
		return ((x == other.x) && (y == other.y));
	}


	/*
	===========================================================
	Vector2::ToString - Writes the vector into std::string
						format and returns the value.
	===========================================================
	*/
	std::string Vector2::ToString() {
		std::string vectorString = std::string("<") + std::to_string(x)
			+ ", " + std::to_string(y) + ">";
		return vectorString;
	}
}