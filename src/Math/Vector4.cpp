#include "Vector4.hpp"

float Vector4::operator*(const Vector4& sec)
{
	return x * sec.x + y * sec.y + z * sec.z + w * sec.w;
}

Vector4 Vector4::operator*(const float& scalar)
{
	return Vector4(x * scalar, y * scalar, z * scalar, w * scalar);
}

Vector4 Vector4::operator+(const Vector4& sec)
{
	return Vector4(x + sec.x, y + sec.y, z + sec.z, w + sec.w);
}

Vector4& Vector4::operator+=(const Vector4& sec)
{
	Vector4 tmp(this->x + sec.x, this->y + sec.y, this->z + sec.z, this->w + sec.w);
	return tmp;
}


Vector4 Vector4::operator-()
{
	return Vector4(-x, -y, -z, -w);
}

Vector4 Vector4::operator-(const Vector4& sub)
{
	return Vector4(this->x - sub.x, this->y - sub.y, this->z - sub.z, this->w - sub.w );
}

Vector4& Vector4::operator=(const Vector4& sec)
{
	this->x = sec.x;
	this->y = sec.y;
	this->z = sec.z;
	this->w = sec.w;

	Scalar = sqrMagnitude();
	return *this;
}

Vector4& Vector4::operator=(const float*& array)
{
	this->x = array[0];
	this->y = array[1];
	this->z = array[2];
	this->w = array[3];

	Scalar = sqrMagnitude();

	return *this;
}

Vector4 Vector4::operator/(const float& scalar)
{
	return Vector4(this->x / scalar, this->y / scalar, this->z / scalar, this->w / scalar);
}

float& Vector4::operator[] (const int& position) 
{
	
	switch (position)
	{
	case 0:
		return x;
	case 1:
		return y;
	case 2:
		return z;
	case 3:
		return w;
	default:
		throw (position);
		break;
	}
}

bool Vector4::operator== (const Vector4& sec) { return (x == sec.x && y == sec.y && z == sec.z && w == sec.w) ? true  : false; }
bool Vector4::operator!= (const Vector4& sec)  { return (x == sec.x && y == sec.y && z == sec.z && w == sec.w) ? false :  true; }

Vector4 Vector4::normalized()
{
	float nMagnitude = this->sqrMagnitude();
	return Vector4(this->x / nMagnitude, this->y / nMagnitude, this->z / nMagnitude, this->w / nMagnitude);
}

float Vector4::magnitude()
{
	return (std::powf(this->x, 2) + std::powf(this->y, 2) + std::powf(this->z, 2) + std::powf(this->w, 2));
}

float Vector4::sqrMagnitude()
{
	return std::sqrtf(this->magnitude());
}

Vector4 Vector4::identity()
{
	return Vector4(1.f, 1.f, 1.f, 1.f);
}

float& Vector4::at(const int& position)
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
		case 3:
			return (w);
		default:
			throw (position);
			break;
		}
	}
	catch (const int error)
	{
		std::cerr << std::this_thread::get_id() << "Vector4. Out of Bounds of method .at() ... Index = " << error << std::endl;
	}

}

std::string Vector4::toString()
{
	return std::to_string(x) + " " + std::to_string(y) + " " + std::to_string(z) + " " + std::to_string(w) + "\n";
}

Vector4::~Vector4()
{
	x = 0;
	y = 0;
	z = 0;
	w = 0;
	Scalar = 0;
}