#include "emeraldpch.h"
#include "Vector4.h"

namespace Emerald {

	/*
	================================================
	Vector4 Constructor - No Arguments
	================================================
	*/
	Vector4::Vector4() {
		Vector4(0.0, 0.0, 0.0, 0.0);
	}


	/*
	================================================
	Vector4 Constructor - All Arguments
	================================================
	*/
	Vector4::Vector4(const float xAssign, const float yAssign, const float zAssign, const float wAssign) {
		x = xAssign;
		y = yAssign;
		z = zAssign;
		w = wAssign;
	}


	/*
	==================================================
	Vector4 operator overload functions for addition
	and subtraction between vectors, as well as
	multiplication and division between vectors and
	a scalar.
	==================================================
	*/
	

	Vector4 Vector4::operator+(const Vector4& v) {
		return Vector4(x + v.x, y + v.y, z + v.z, w + v.w);
	}

	Vector4 Vector4::operator-(const Vector4& v) {
		return Vector4(x - v.x, y - v.y, z - v.z, w - v.w);
	}

	Vector4& Vector4::operator+=(const Vector4& v) {
		x += v.x;
		y += v.y;
		z += v.z;
		w += v.w;
		return (*this);
	}

	Vector4& Vector4::operator-=(const Vector4& v) {
		x -= v.x;
		y -= v.y;
		z -= v.z;
		w -= v.w;
		return (*this);
	}

	Vector4 Vector4::operator*(const float scalar) {
		return Vector4(x * scalar, y * scalar, z * scalar, w * scalar);
	}

	Vector4 Vector4::operator/(float scalar) {
		scalar = 1.0f / scalar;
		return Vector4(x * scalar, y * scalar, z * scalar, w * scalar);
	}

	Vector4& Vector4::operator*=(const float scalar) {
		x *= scalar;
		y *= scalar;
		z *= scalar;
		w *= scalar;
		return (*this);
	}

	Vector4& Vector4::operator/=(float scalar) {
		scalar = 1.0f / scalar;
		x *= scalar;
		y *= scalar;
		z *= scalar;
		w *= scalar;
		return (*this);
	}


	/*
	=======================================================
	Vector4::Dot - Calculates and returns the dot product
				   between this vector and another passed
				   as a paramter.
	=======================================================
	*/
	float Vector4::Dot(const Vector4& in) const {
		return (x * in.x + y * in.y + z * in.z + w * in.w);
	}


	/*
	===========================================================
	Vector4::Normalize - Converts this vector to a unit
						 vector and returns it as a reference.
	===========================================================
	*/
	Vector4& Vector4::Normalize() {
		const float inverseMagnitude = 1.0f / Magnitude();
		x *= inverseMagnitude;
		y *= inverseMagnitude;
		z *= inverseMagnitude;
		w *= inverseMagnitude;
		return (*this);
	}


	/*
	=======================================================
	Vector4::Magnitude - Returns the length of the vector.
	=======================================================
	*/
	float Vector4::Magnitude() const {
		return sqrtf((x * x) + (y * y) + (z * z) + (w * w));
	}


	/*
	===========================================================
	Vector4::Equals - Takes another Vector4 object as a
						parameter and returns true if each
						element between the vectors are equal.
						False otherwise.
	===========================================================
	*/
	bool Vector4::Equals(const Vector4& other) {
		return ((x == other.x) && (y == other.y) && (z == other.z) && (w == other.w));
	}


	/*
	===========================================================
	Vector4::ToString - Writes the vector into std::string
						format and returns the value.
	===========================================================
	*/
	std::string Vector4::ToString() {
		std::string vectorString = std::string("<") + std::to_string(x)
			+ ", " + std::to_string(y)
			+ ", " + std::to_string(z)
			+ ", " + std::to_string(w) + ">";
		return vectorString;
	}
}