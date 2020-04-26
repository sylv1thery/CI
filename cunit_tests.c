#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <CUnit/Basic.h>
#include <CUnit/Console.h>
#include <CUnit/CUnit.h>

#include "circle.h"


static const double epsilon = 0.000000001;

void test_point_self(void)
{
  Point A = {1,1};
  Point B = {1,1};
  Point C = {-1,-1};
  
  double epsilon = 0.000000001;
  CU_ASSERT_DOUBLE_EQUAL(distance2(&A,&A),0,epsilon );
  CU_ASSERT_DOUBLE_EQUAL_FATAL(distance2(&A,&B),0,epsilon );
  CU_ASSERT_DOUBLE_NOT_EQUAL(distance2(&A,&C),0,epsilon );
}

void test_point_symetry(void)
{
  Point A = {1,1};
  Point B = {2,2};
  Point C = {-1,-1};
  Point D = {1,3};

  double epsilon = 0.000000001;
  CU_ASSERT_DOUBLE_EQUAL(distance2(&A,&B),distance2(&B,&A),epsilon );
  CU_ASSERT_DOUBLE_NOT_EQUAL(distance2(&A,&B),distance2(&B,&B),epsilon );
}


void test_point_value(void)
{
  Point A = {1,1};
  Point B = {2,2};
  Point C = {-1,-1};
  Point D = {1,3};

  CU_ASSERT_DOUBLE_EQUAL(distance2(&A,&B),2.0,epsilon );
  CU_ASSERT_DOUBLE_EQUAL(distance2(&A,&C),8.0,epsilon );
  CU_ASSERT_DOUBLE_EQUAL(distance2(&A,&D),4.0,epsilon );
}



void test_circle_1(void)
{
  Point A = {0,0};
  Circle C1 = {A,2};
  Point B = {1,1};
  Point C = {2,0};
  Point D = {3,0};
  CU_ASSERT_TRUE(is_inside(&A,&C1));
  CU_ASSERT_TRUE(is_inside(&B,&C1));
  CU_ASSERT_TRUE(is_inside(&C,&C1));
  CU_ASSERT_FALSE(is_inside(&D,&C1));
}

int main()
{
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();
    
    CU_pSuite pS1 = CU_add_suite("Testing Points", NULL, NULL);
    CU_ADD_TEST(pS1, test_point_self);
    CU_ADD_TEST(pS1, test_point_symetry);
    CU_ADD_TEST(pS1, test_point_value);

    CU_pSuite pS2 = CU_add_suite("Testing Circles", NULL, NULL);
    CU_ADD_TEST(pS2, test_circle_1);
    
    CU_basic_set_mode(CU_BRM_NORMAL);
    CU_basic_run_tests();
    return CU_get_number_of_failures();
}