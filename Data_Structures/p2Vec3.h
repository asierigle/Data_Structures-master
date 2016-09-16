#ifndef __P2VEC3_H__
#define __P2VEC3_H__

#include "p2Defs.h"
#include <math.h>

template<class TYPE> class Vec3
{
public:
	TYPE x, y, z;
	Vec3() : x(0.0f), y(0.0f), z(0.0f){}
	
	Vec3(TYPE _x, TYPE _y, TYPE _z) {
		x = _x;
		y = _y;
		z = _y;
	}

	void SetZero() {
		x = y = z = 0.0f;
	}
	
	bool IsZero() {
		return(x == 0.0f && y == 0.0f && z == 0.0f);
	}

	Vec3 DistanceTo(Vec3 a) {
		TYPE distance, dx, dy, dz;

		dx = a.x - x;
		dy = a.y - y;
		dz = a.z - z;

		distance = sqrt((TYPE)dx*dx + dy*dy + dz*dz);
		return(distance);
	}

	Vec3 operator+ (const Vec3& a)const {
		Vec3 tmp;
		tmp.x = a.x + x;
		tmp.y = a.y + y;
		tmp.z = a.z + z;

		return(tmp);
	}

	Vec3 operator- (const Vec3& a)const {
		Vec3 tmp;
		tmp.x = x + a.x;
		tmp.y = y + a.y;
		tmp.z = z + a.z;

		return(tmp);
	}

	Vec3 operator+= (const Vec3& a)const {
		x += a.x;
		y += a.y;
		z += a.z;

		return(*this);
	}

	Vec3 operator-= (const Vec3& a)const {
		x -= a.x;
		y -= a.y;
		z -= a.z;

		return(*this);
	}

	bool operator== (const Vec3& a)const {
		
		return(x == a.x && y == a.y && z == a.z);

	}

	bool operator!= (const Vec3& a)const {

		return(x != a.x || y != a.y || z != a.z);

	}
};


#endif // !__P2VEC3_H__
