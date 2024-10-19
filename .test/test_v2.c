#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

static size_t g_test_counter = 1;
const char *g_test_cases[] =  {
	"v2_create",
	"v2_zero",
	"v2_add",
	"v2_add_scalar",
	"v2_sub",
	"v2_sub_scalar",
	"v2_mult",
	"v2_mult_scalar",
	"v2_div",
	"v2_div_scalar",
};

#define TEST_CASE_LIMIT (sizeof(g_test_cases) / sizeof(g_test_cases[0]))

#define TEST_PASSED() \
do \
{ \
	if (g_test_counter > TEST_CASE_LIMIT) \
	{ \
		fprintf(stderr, "Test %zu is not covered yet, there are only %zu tests\n", g_test_counter, TEST_CASE_LIMIT); \
		exit(1); \
	} \
	printf("Test %zu passed (%s)\n", g_test_counter, g_test_cases[g_test_counter - 1]); \
	++g_test_counter; \
} while (0);

#define TEST_FAILED() \
do \
{ \
	fprintf(stderr, "Test %zu failed (%s) %s:%d\n", g_test_counter, g_test_cases[g_test_counter - 1], __FILE__, __LINE__); \
	exit (1); \
} while (0);

void	test_v2_create(void)
{
	t_v2 vec1 = v2_create(25, 5);
	float expected_x = 25;
	float expected_y = 5;
	if (vec1.x != expected_x) TEST_FAILED();
	if (vec1.y != expected_y) TEST_FAILED();
	TEST_PASSED();
}

void	test_v2_zero(void)
{
	t_v2 vec1 = v2_zero();
	float expected_x = 0;
	float expected_y = 0;
	if (vec1.x != expected_x) TEST_FAILED();
	if (vec1.y != expected_y) TEST_FAILED();
	TEST_PASSED();
}

void	test_v2_add(void)
{
	t_v2 vec1 = {5, 25};
	t_v2 vec2 = {20, 30};
	t_v2 vec3 = v2_add(&vec1, &vec2);
	float expected_x = 25;
	float expected_y = 55;
	if (vec3.x != expected_x) TEST_FAILED();
	if (vec3.y != expected_y) TEST_FAILED();
	TEST_PASSED();
}

void	test_v2_add_scalar(void)
{
	t_v2 vec1 = {5, 25};
	t_v2 vec3 = v2_add_scalar(&vec1, 25);
	float expected_x = 30;
	float expected_y = 50;
	if (vec3.x != expected_x) TEST_FAILED();
	if (vec3.y != expected_y) TEST_FAILED();
	TEST_PASSED();
}

void	test_v2_sub(void)
{
	t_v2 vec1 = {5, 25};
	t_v2 vec2 = {20, 30};
	t_v2 vec3 = v2_sub(&vec1, &vec2);
	float expected_x = -15;
	float expected_y = -5;
	if (vec3.x != expected_x) TEST_FAILED();
	if (vec3.y != expected_y) TEST_FAILED();
	TEST_PASSED();
}

void	test_v2_sub_scalar(void)
{
	t_v2 vec1 = {5, 25};
	t_v2 vec3 = v2_sub_scalar(&vec1, 25);
	float expected_x = -20;
	float expected_y = 0;
	if (vec3.x != expected_x) TEST_FAILED();
	if (vec3.y != expected_y) TEST_FAILED();
	TEST_PASSED();
}

void	test_v2_mult(void)
{
	t_v2 vec1 = {5, 25};
	t_v2 vec2 = {20, 30};
	t_v2 vec3 = v2_mult(&vec1, &vec2);
	float expected_x = 100;
	float expected_y = 750;
	if (vec3.x != expected_x) TEST_FAILED();
	if (vec3.y != expected_y) TEST_FAILED();
	TEST_PASSED();
}

void	test_v2_mult_scalar(void)
{
	t_v2 vec1 = {5, 25};
	t_v2 vec3 = v2_mult_scalar(&vec1, 3);
	float expected_x = 15;
	float expected_y = 75;
	if (vec3.x != expected_x) TEST_FAILED();
	if (vec3.y != expected_y) TEST_FAILED();
	TEST_PASSED();
}

void	test_v2_div(void)
{
	t_v2 vec1 = {5, 25};
	t_v2 vec2 = {100, 5};
	t_v2 vec3 = v2_div(&vec1, &vec2);
	float expected_x = 5/100.0;
	float expected_y = 25/5.0;
	if (vec3.x != expected_x) TEST_FAILED();
	if (vec3.y != expected_y) TEST_FAILED();
	TEST_PASSED();
}

void	test_v2_div_scalar(void)
{
	t_v2 vec1 = {5, 25};
	t_v2 vec3 = v2_div_scalar(&vec1, 5);
	float expected_x = 5/5.0;
	float expected_y = 25/5.0;
	if (vec3.x != expected_x) TEST_FAILED();
	if (vec3.y != expected_y) TEST_FAILED();
	TEST_PASSED();
}

int	main(void)
{
	test_v2_create();
	test_v2_zero();
	test_v2_add();
	test_v2_add_scalar();
	test_v2_sub();
	test_v2_sub_scalar();
	test_v2_mult();
	test_v2_mult_scalar();
	test_v2_div();
	test_v2_div_scalar();
	printf("All tested passed!\n");
	return (0);
}
