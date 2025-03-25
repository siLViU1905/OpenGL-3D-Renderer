#pragma once

class vec3
{
    public:
 float x,y,z;
  vec3();
  vec3(float x,float y,float z);
};

vec3 operator+(const vec3& v1,const vec3& v2);

vec3& operator+=(vec3& v1,const vec3& v2);

vec3 operator-(const vec3& v1,const vec3& v2);

vec3& operator-=(vec3& v1,const vec3& v2);

vec3 operator+(const vec3& v,float val);

vec3& operator+=(vec3& v,float val);

vec3 operator-(const vec3& v,float val);

vec3& operator-=(vec3& v,float val);

vec3 operator*(const vec3& v,float val);

vec3& operator*=(vec3& v,float val);

vec3 operator/(const vec3& v,float val);

vec3& operator/=(vec3& v,float val);