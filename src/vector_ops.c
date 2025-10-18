#include "3d_vector.h"

Vector3D vec_create(double x, double y, double z) {
    Vector3D new_vec;
    new_vec.x = x;
    new_vec.y = y;
    new_vec.z = z;
    return new_vec;
}

Vector3D vec_sum(Vector3D v1, Vector3D v2) {
    return vec_create(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

Vector3D vec_sub(Vector3D v1, Vector3D v2) {
    return vec_create(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

double vec_dot(Vector3D v1, Vector3D v2) {
    return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
}

Vector3D vec_cross(Vector3D v1, Vector3D v2) {
    return vec_create(
        (v1.y * v2.z) - (v1.z * v2.y),
        (v1.z * v2.x) - (v1.x * v2.z),
        (v1.x * v2.y) - (v1.y * v2.x)
    );
}
