#include "emeraldpch.h"
#include "Vector3.h"

namespace Emerald {
	/*
	================================================
	Vector3 Constructor - No Arguments
	================================================
	*/
	Vector3::Vector3() {
		Vector3(0.0, 0.0, 0.0);
	}


	/*
	================================================
	Vector3 Constructor - All Arguments
	================================================
	*/
	Vector3::Vector3(const float xAssign, const float yAssign, const float zAssign) {
		x = xAssign;
		y = yAssign;
		z = zAssign;
	}

	Vector3 Vector3::operator+(const Vector3& v) {
		return Vector3(x + v.x, y + v.y, z + v.z);
	}

	Vector3 Vector3::operator-(const Vector3& v) {
		return Vector3(x - v.x, y - v.y, z - v.z);
	}

	Vector3& Vector3::operator+=(const Vector3& v) {
		x += v.x;
		y += v.y;
		z += v.z;
		return (*this);
	}

	Vector3& Vector3::operator-=(const Vector3& v) {
		x -= v.x;
		y -= v.y;
		z -= v.z;
		return (*this);
	}


	Vector3 Vector3::operator*(const float scalar) {
		return Vector3(x * scalar, y * scalar, z * scalar);
	}

	Vector3 Vector3::operator/(float scalar) {
		scalar = 1.0f / scalar;
		return Vector3(x * scalar, y * scalar, z * scalar);
	}

	Vector3& Vector3::operator*=(const float scalar) {
		x *= scalar;
		y *= scalar;
		z *= scalar;
		return (*this);
	}

	Vector3& Vector3::operator/=(float scalar) {
		scalar = 1.0f / scalar;
		x *= scalar;
		y *= scalar;
		z *= scalar;
		return (*this);
	}

	/*
	=======================================================
	Vector3::Dot - Calculates and returns the dot product
				   between this vector and another passed
				   as a paramter.
	=======================================================
	*/
	float Vector3::Dot(const Vector3& in) const {
		return x * in.x + y * in.y + z * in.z;
	}


	/*
	=======================================================
	Vector3::Cross - Calculates the cross product of two
					 vectors passed as parameters "in" and
					 "out". The result is assigned to the
					 out parameter.
	=======================================================
	*/
	void Vector3::Cross(const Vector3& in, Vector3& out) {
		out = Vector3(y * in.z - z * in.y, z * in.x - x * in.z, x * in.y - y * in.x);
	}


	/*
	===========================================================
	Vector3::Normalize - Converts this vector to a unit
						 vector and returns it as a reference.
	===========================================================
	*/
	Vector3& Vector3::Normalize() {
		const float inverseMagnitude = 1.0f / Magnitude();
		x *= inverseMagnitude;
		y *= inverseMagnitude;
		z *= inverseMagnitude;
		return (*this);
	}

	/*
	=======================================================
	Vector3::Magnitude - Returns the length of the vector.
	=======================================================
	*/
	float Vector3::Magnitude() const {
		return sqrtf((x * x) + (y * y) + (z * z));
	}


	/*
	=================================================================
	Vector3::Distance - Calculates the distance between two vectors.
	=================================================================
	*/
	float Vector3::Distance(const Vector3& other) {
		float distanceX = x - other.x;
		float distanceY = y - other.y;
		float distanceZ = z - other.z;
		return sqrtf((distanceX * distanceX) + (distanceY * distanceY) + (distanceZ * distanceZ));
	}


	/*
	===========================================================
	Vector3::AreParallelOrAntiparallel

	Compares two input Vector3 parameters and returns true if
	they are parallel or anti-parallel to each other.
	False otherwise.
	===========================================================
	*/
	bool Vector3::AreParallelOrAntiparallel(const Vector3& otherVec) {
		float magnitudeProduct = Magnitude() * otherVec.Magnitude();
		float dotProduct = Dot(otherVec);
		if ((magnitudeProduct == dotProduct) || (magnitudeProduct == (dotProduct * -1.0f))) {
			return true;
		}
		return false;
	}


	/*
	===========================================================
	Vector3::Equals - Takes another Vector3 object as a
						parameter and returns true if each
						element between the vectors are equal.
						False otherwise.
	===========================================================
	*/
	bool Vector3::Equals(const Vector3& other) {
		return ((x == other.x) && (y == other.y) && (z == other.z));
	}


	std::string Vector3::ToString() {
		std::string vectorString = std::string("<") + std::to_string(x)
									+ ", " + std::to_string(y) +
									", " + std::to_string(z) + ">";
		return vectorString;
	}
}