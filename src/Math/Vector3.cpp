#include "Vector3.hpp"

float Vector3::operator*(Vector3 sec)
{
	return x * sec.x + y * sec.y + z * sec.z;
}

Vector3 Vector3::operator*(float scalar)
{
	return Vector3(x * scalar, y * scalar, z * scalar);
}

Vector3 Vector3::operator+(Vector3 sec)
{
	return Vector3(x + sec.x, y + sec.y, z + sec.z);
}

void Vector3::operator=(Vector3 sec)
{
	x = sec.x;
	y = sec.y;
	z = sec.z;

	Scalar = sqrMagnitude();
}

Vector3 Vector3::operator/(float scalar)
{
	return Vector3(this->x / scalar, this->y / scalar, this->z / scalar);
}

void Vector3::operator=(float* array)
{
	this->x = array[0];
	this->y = array[1];
	this->z = array[2];
}

Vector3 Vector3::normalized()
{
	return Vector3(this->x / Scalar, this->y / Scalar, this->z / Scalar);
}

float Vector3::magnitude()
{
	return (std::powf(this->x, 2) + std::powf(this->y, 2) + std::powf(this->z, 2));
}

float Vector3::sqrMagnitude()
{
	return std::sqrtf(this->magnitude());
}

Vector3 Vector3::identity()
{
	return Vector3(1.0f, 1.0f, 1.0f);
}

std::string Vector3::toString()
{
	return std::to_string(x) + " " + std::to_string(y) + " " + std::to_string(z) + "\n";
}

Vector3::~Vector3()
{
	x = 0;
	y = 0;
	z = 0;
	Scalar = 0;
}

bool Vector3::operator== (Vector3 sec) { return (x == sec.x && y == sec.y && z == sec.z ) ? true : false; }
bool Vector3::operator!= (Vector3 sec) { return (x == sec.x && y == sec.y && z == sec.z ) ? false : true; }

float Vector3::operator[](int position)
{
	try {
		switch (position)
		{
		case 0:
			return x;
		case 1:
			return y;
		case 2:
			return z;
		default:
			throw position;
			break;
		}
	}
	catch (const int error)
	{
		std::cerr << std::this_thread::get_id() << "Matrix4x4. Out of Bounds of operator[] ... Index = " << error << std::endl;
	}

	return INT_MAX;
}
