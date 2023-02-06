#ifndef _Vector4_
#define _Vector4_

#include "../EngineUnits/Engine.hpp"

class Vector4
{
public:
	Vector4() { x = y = z = w = 0; Scalar = 0; }
	Vector4(float _x, float _y, float _z, float _w) { x = _x; y = _y; z = _z; w = _w; Scalar = sqrMagnitude();}


	void set_X(float _X) { x = _X; Scalar = sqrMagnitude(); }
	void set_Y(float _Y) { y = _Y; Scalar = sqrMagnitude(); }
	void set_Z(float _Z) { z = _Z; Scalar = sqrMagnitude(); }

	float    operator*  (const Vector4& sec );
	Vector4  operator+  (const Vector4& sec );
	Vector4& operator+= (const Vector4& sec);
	Vector4  operator-  (            );
	Vector4  operator-  (const Vector4& sub );
	Vector4  operator*  (const float& scalar);
	Vector4  operator/  (const float& scalar);
	Vector4& operator=  (const Vector4& sec );
	Vector4& operator=  (const float*&  arr );
	bool	 operator== (const Vector4& sec );
	bool     operator!= (const Vector4& sec );
	float&   operator[] (const int& position);

	Vector4 normalized  ();
	float   magnitude   ();
	float   sqrMagnitude();
	Vector4 identity    ();
	float&   at          (const int& position);
	std::string toString();

	~Vector4();

	float x, y, z, w;
	float Scalar;
};

#endif //_Vector4_