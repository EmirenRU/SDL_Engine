#ifndef _VECTOR3_
#define _VECTOR3_

#include "../EngineUnits/Engine.hpp"

class Vector3 {
public:

	Vector3() { x = y = z = 0; Scalar = 0; }
	Vector3(float _x, float _y, float _z) { x = _x; y = _y; z = _z; Scalar = sqrMagnitude(); }


	void set_X(float _X) { x = _X; Scalar = sqrMagnitude(); }
	void set_Y(float _Y) { y = _Y; Scalar = sqrMagnitude(); }
	void set_Z(float _Z) { z = _Z; Scalar = sqrMagnitude(); }

	float   operator*  (Vector3 sec );
	Vector3 operator+  (Vector3 sec );
	Vector3 operator*  (float scalar);
	Vector3 operator/  (float scalar);
	void    operator=  (float* array);
	void    operator=  (Vector3 sec );
	bool	operator== (Vector3 sec );
	bool    operator!= (Vector3 sec );
	float   operator[] (int position);

	Vector3 normalized  ();
	float   magnitude   ();
	float   sqrMagnitude();
	Vector3 identity    ();
	std::string toString();

	~Vector3();

	float x, y, z;
	float Scalar;
};

#endif // _VECTOR3_