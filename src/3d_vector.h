#ifndef VECTOR_3D_H
#define VECTOR_3D_H

typedef struct {
    double x;
    double y;
    double z;
} Vector3D;


Vector3D vec_create(double x, double y, double z);
Vector3D vec_sum(Vector3D v1, Vector3D v2);
Vector3D vec_sub(Vector3D v1, Vector3D v2);
double vec_dot(Vector3D v1, Vector3D v2);
Vector3D vec_cross(Vector3D v1, Vector3D v2);

#endif
