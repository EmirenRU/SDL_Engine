#include "Vector2.hpp"

float Vector2::operator*(Vector2 sec)
{
	return x * sec.x + y * sec.y;
}

Vector2 Vector2::operator*(float scalar)
{
	return Vector2(x*scalar, y*scalar);
}

Vector2 Vector2::operator+(Vector2 sec)
{
	return Vector2(x + sec.x, y + sec.y);
}

Vector2 Vector2::operator/  (float scalar)
{
	return Vector2(this->x / scalar, this->y / scalar);
}

void Vector2::operator=(Vector2 sec)
{
	this->x = sec.x;
	this->y = sec.y;
	Scalar = sqrMagnitude();
}

Vector2 Vector2::operator-()
{
	return Vector2(-x, -y);
}

void Vector2::operator=(float* array)
{
	this->x = array[0];
	this->y = array[1];
}

float Vector2::operator[] (int position)
{
	try {
		switch (position)
		{
		case 0:
			return x;
		case 1:
			return y;
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

Vector2 Vector2::normalized()
{
	return Vector2(this->x / Scalar, this->y / Scalar);
}

float Vector2::magnitude()
{
	return (std::powf(this->x, 2) + std::powf(this->y, 2));
}

float Vector2::sqrMagnitude()
{
	Scalar = std::sqrtf(this->magnitude());
	return Scalar;
}

Vector2 Vector2::identity()
{
	return Vector2(1.0f, 1.0f);
}

std::string Vector2::toString()
{
	return std::to_string(x) + " " + std::to_string(y) + "\n";
}

std::ostream& Vector2::operator<<(std::ostream& strm)
{
	return strm << this->toString();
}


bool Vector2::operator== (Vector2 sec) { return (x == sec.x && y == sec.y ) ? true : false; }
bool Vector2::operator!= (Vector2 sec) { return (x == sec.x && y == sec.y ) ? false : true; }

Vector2::~Vector2()
{
	x = 0;
	y = 0;
	Scalar = 0;
}