#ifndef _VECTOR2_
#define _VECTOR2_

#include "../EngineUnits/Engine.hpp"

class Vector2 {
public:

	Vector2 ()                   { x = y = 0; Scalar = sqrMagnitude(); }
	Vector2 (float _x, float _y) { x = _x; y = _y; Scalar = sqrMagnitude(); }

	void set_X (float _X) { x = _X; Scalar = sqrMagnitude(); }
	void set_Y (float _Y) { y = _Y; Scalar = sqrMagnitude(); }

	Vector2 normalized  ();
	float   magnitude   ();
	float   sqrMagnitude();
	Vector2 identity    ();
	std::string toString();
	std::ostream& operator<<(std::ostream& strm);

	Vector2 operator+  (Vector2 sec );
	Vector2 operator*  (float scalar);
	Vector2 operator/  (float scalar);
	Vector2 operator-  (            );
	float   operator*  (Vector2 sec );
	void    operator=  (Vector2 sec );
	void    operator=  (float*  arr );
	bool    operator== (Vector2 sec );
	bool    operator!= (Vector2 sec );
	float   operator[] (int position);

	~Vector2();

	float x;
	float y;
	float Scalar;
};

#endif //_VECTOR2_