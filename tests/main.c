#include <check.h>
#include "../src/3d_vector.h"

START_TEST(test_vec_create)
{
    Vector3D v = vec_create(1.0, 2.0, 3.0);
    ck_assert_double_eq(v.x, 1.0);
    ck_assert_double_eq(v.y, 2.0);
    ck_assert_double_eq(v.z, 3.0);
}
END_TEST

START_TEST(test_vec_sum)
{
    Vector3D v1 = vec_create(1.0, 2.0, 3.0);
    Vector3D v2 = vec_create(4.0, 5.0, 6.0);
    Vector3D sum = vec_sum(v1, v2);
    ck_assert_double_eq(sum.x, 5.0);
    ck_assert_double_eq(sum.y, 7.0);
    ck_assert_double_eq(sum.z, 9.0);
}
END_TEST

START_TEST(test_vec_sub)
{
    Vector3D v1 = vec_create(10.0, 5.0, 2.0);
    Vector3D v2 = vec_create(4.0, 1.0, 1.0);
    Vector3D sub = vec_sub(v1, v2);
    ck_assert_double_eq(sub.x, 6.0);
    ck_assert_double_eq(sub.y, 4.0);
    ck_assert_double_eq(sub.z, 1.0);
}
END_TEST

START_TEST(test_vec_dot)
{
    Vector3D v1 = vec_create(1.0, 2.0, 3.0);
    Vector3D v2 = vec_create(4.0, 5.0, 6.0);
    double dot = vec_dot(v1, v2);
    ck_assert_double_eq(dot, 32.0);
}
END_TEST

START_TEST(test_vec_cross)
{
    Vector3D v1 = vec_create(1.0, 0.0, 0.0);
    Vector3D v2 = vec_create(0.0, 1.0, 0.0);
    Vector3D cross = vec_cross(v1, v2);
    ck_assert_double_eq(cross.x, 0.0);
    ck_assert_double_eq(cross.y, 0.0);
    ck_assert_double_eq(cross.z, 1.0);
}
END_TEST

Suite* vector_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("VectorMath");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_vec_create);
    tcase_add_test(tc_core, test_vec_sum);
    tcase_add_test(tc_core, test_vec_sub);
    tcase_add_test(tc_core, test_vec_dot);
    tcase_add_test(tc_core, test_vec_cross);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void)
{
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = vector_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? 0 : 1;
}
