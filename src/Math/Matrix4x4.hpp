#ifndef _MATRIX4x4_
#define _MATRIX4x4_

#include "Vector4.hpp"
#include "../EngineUnits/Engine.hpp"

/*

 | right | up    | fwd   | pos   |
x| 1     | 0     | 0     | 0     |
y| 0     | 1     | 0     | 0     |
z| 0     | 0     | 1     | 0     |
w| 0     | 0     | 0     | 1     |

*/

class Matrix4x4
{
public:
	Matrix4x4();
	Matrix4x4(const Vector4& _v1, const Vector4& _v2, const Vector4& _v3, const Vector4& _v4);

	bool       operator==  (const Matrix4x4& sub);
	bool       operator!=  (const Matrix4x4& sub);
	Matrix4x4& operator=   (const Matrix4x4& sub);
	Matrix4x4  operator-   (                    );
	Matrix4x4  operator-   (const Matrix4x4& sub);
	Matrix4x4  operator+   (const Matrix4x4& sub);
	Matrix4x4& operator*   (Matrix4x4& sub      );
	Vector4&   operator[]  (const int& position ) ;


	float       getDeterminant ();
	Matrix4x4*  zeroes         ();
	bool        isIdentity     ();
	Matrix4x4*  identity       ();
	Vector4&    at             (const int& position);
	std::string toString       ();

	~Matrix4x4();
	
	Vector4 v1;
	Vector4 v2;
	Vector4 v3;
	Vector4 v4;

	float Determinant;

	/*float M11, M12, M13, M14;
	float M21, M22, M23, M24;
	float M31, M32, M33, M34;
	float M41, M42, M43, M44;*/


};



#endif //_MATRIX4x4_