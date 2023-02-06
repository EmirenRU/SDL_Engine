#include "Matrix4x4.hpp"
#include <iostream>

Matrix4x4::Matrix4x4()
{
	v1 = { 0, 0, 0, 0 };
	v2 = { 0, 0, 0, 0 };
	v3 = { 0, 0, 0, 0 };
	v4 = { 0, 0, 0, 0 };
	Determinant = 0;
}

Matrix4x4::Matrix4x4(const Vector4 &_v1, const Vector4 &_v2, const Vector4 &_v3, const Vector4 &_v4)
{
	this->v1 = _v1;
	this->v2 = _v2;
	this->v3 = _v3;
	this->v4 = _v4;
	Determinant = getDeterminant();
}
Vector4& Matrix4x4::at(const int& position)
{
	try {
		switch (position)
		{
		case 0:
			return v1;
		case 1:
			return v2;
		case 2:
			return v3;
		case 3:
			return v4;
		default:
			throw position;
			break;
		}
	}
	catch (const int error)
	{
		std::cerr << std::this_thread::get_id() << "Matrix4x4. Out of Bounds of operator[] ... Index = " << error << std::endl;
	}
	Vector4 *tmp = nullptr;
	return *tmp;
}

std::string Matrix4x4::toString()
{
	return std::to_string(v1[0]) + " " + std::to_string(v1[1]) + " " + std::to_string(v1[2]) + " " + std::to_string(v1[3]) + "\n" + \
		std::to_string(v1[1]) + " " + std::to_string(v2[1]) + " " + std::to_string(v2[2]) + " " + std::to_string(v2[3]) + "\n" + \
		std::to_string(v1[2]) + " " + std::to_string(v3[1]) + " " + std::to_string(v3[2]) + " " + std::to_string(v3[3]) + "\n" + \
		std::to_string(v1[3]) + " " + std::to_string(v4[1]) + " " + std::to_string(v4[2]) + " " + std::to_string(v4[3]) + "\n";
}

Matrix4x4::~Matrix4x4()
{
	v1.~Vector4();
	v2.~Vector4();
	v3.~Vector4();
	v4.~Vector4();
	Determinant = 0;
}

Vector4& Matrix4x4::operator[] (const int& position)
{
	if (position == 0)
		return v1;
	if (position == 1)
		return v2;
	if (position == 2)
		return v3;
	if (position == 3)
		return v4;
}

bool Matrix4x4::operator==(const Matrix4x4& sub)
{
	return (this->v1 == sub.v1 && this->v2 == sub.v2 && this->v3 == sub.v3 && this->v4 == sub.v4) ? true : false;
}

bool Matrix4x4::operator!=(const Matrix4x4& sub)
{
	return (this->v1 == sub.v1 && this->v2 == sub.v2 && this->v3 == sub.v3 && this->v4 == sub.v4) ? false : true;
}

Matrix4x4& Matrix4x4::operator=(const Matrix4x4& sub) 
{
	this->v1 = sub.v1;
	this->v2 = sub.v2;
	this->v3 = sub.v3;
	this->v4 = sub.v4;
	Determinant = sub.Determinant;
	return *this;
}

Matrix4x4 Matrix4x4::operator-() 
{	
	return Matrix4x4(-this->v1, -this->v2, -this->v3, -this->v4);
}

Matrix4x4 Matrix4x4::operator-(const Matrix4x4& sub) 
{
	return Matrix4x4(this->v1 - sub.v1, this->v2 - sub.v2, this->v3 - sub.v3, this->v4 - sub.v4);
}

Matrix4x4 Matrix4x4::operator+(const Matrix4x4& sub) 
{
	return Matrix4x4(this->v1 + sub.v1, this->v2 + sub.v2, this->v3 + sub.v3, this->v4 + sub.v4);
}

Matrix4x4& Matrix4x4::operator*(Matrix4x4& sub) 
{
	Matrix4x4 tmp;

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			tmp[i][j] = 0;
			for (int k = 0; k < 4; ++k)
			{
				tmp[i][j] += (this->at(i)[k] * sub[k][j]);
			}
		}
	}

	return tmp;
}

float Matrix4x4::getDeterminant() 
{
	Determinant = v1[0] * v2[1] * v3[2] * v4[3] + v1[1] * v2[2] * v3[3] * v4[0] + v1[2] * v2[3] * v3[0] * v4[1] + v1[3] * v2[0] * v3[1] * v4[2] - \
				  v1[3] * v2[2] * v3[1] * v4[0] - v1[2] * v2[1] * v3[0] * v4[3] - v1[1] * v2[0] * v3[4] * v4[3] - v1[0] * v2[4] * v3[3] * v4[2];
	return Determinant;
}


Matrix4x4* Matrix4x4::zeroes()
{
	const Vector4 v1 = { 0, 0, 0, 0};
	const Vector4 v2 = { 0, 0, 0, 0};
	const Vector4 v3 = { 0, 0, 0, 0};
	const Vector4 v4 = { 0, 0, 0, 0};
	Matrix4x4* tmp = new Matrix4x4(v1, v2, v3, v4);
	return tmp;
}

bool Matrix4x4::isIdentity() 
// An identity matrix contains 1.0 in the main diagonal, and 0.0 for every other elements.
{
	const Vector4 v1 = { 1,0,0,0 };
	const Vector4 v2 = { 0,1,0,0 };
	const Vector4 v3 = { 0,0,1,0 };
	const Vector4 v4 = { 0,0,0,1 };

	return (this->v1 == v1 && this->v2 == v2 && this->v3 == v3 && this->v4 == v4) ? true : false;

}

Matrix4x4* Matrix4x4::identity()
// This is a matrix that effectively does nothing when applied. It has 1s in the main diagonal and 0s in all other elements:
// 1.00000 0.00000 0.00000 0.00000
// 0.00000 1.00000 0.00000 0.00000
// 0.00000 0.00000 1.00000 0.00000
// 0.00000 0.00000 0.00000 1.00000
{
	const Vector4 v1 = { 1,0,0,0 };
	const Vector4 v2 = { 0,1,0,0 };
	const Vector4 v3 = { 0,0,1,0 };
	const Vector4 v4 = { 0,0,0,1 };

	Matrix4x4 *tmp = new Matrix4x4(v1, v2, v3, v4);
	return tmp;
}