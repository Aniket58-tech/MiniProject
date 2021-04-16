#include "unity.h"
#include "snake.h"
#include <stdbool.h>
#include <conio.h>
/* required by the unity test framework */
void setUp(){}
/* required by the unity test framework */
void tearDown(){}

void test_result1(void)
{
	TEST_ASSERT_EQUAL(10,check_result1(10));     // function test case pass only if snake eats a fruit one time and gets a score as 10
}
void test_result2(void)
{
	TEST_ASSERT_EQUAL(50,check_result2(50));     // function test case pass only if snake eats a fruit five times and gets a score as 50
}
void test_result3(void)
{
	TEST_ASSERT_EQUAL(100,check_result3(100));     // function test case pass only if snake eats a fruit ten times and gets a score as 100
}
int main()
{
    setup();
	while(!gameover)							// runs until gameover has true value 
	{
		/**
		 * @brief Construct a new draw object
		 * draw() function is used to draw rectangle within which the snake can move
		 */
		draw();
		/**
		 * @brief Construct a new input object
		 * input() function is used to move snake in different directions
		 */
		input();
		/**
		 * @brief Construct a new logic object
		 * logic() function is used when we want to perform a task when player moves the snake to different directions
		 */
		logic();
	}
    /* Initialize the Unity Test Framework */
    UNITY_BEGIN();

    /* Run Test functions */
	RUN_TEST(test_result1);					// 1st test case will get execute
	RUN_TEST(test_result2);					// 2nd test case will get execute
	RUN_TEST(test_result3);					// 3rd test case will get execute

    /* CLose the Unity Test Framework */
	return UNITY_END();
}