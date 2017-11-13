#include <r_util.h>
#include "minunit.h"

static RNum *num;

bool test_r_num_minmax_swap_i() {
	int a = -1, b = 2;
	r_num_minmax_swap_i (&a, &b);
	mu_assert_eq (a == -1 && b == 2, 1, "a < b");
	a = 2, b = -1;
	r_num_minmax_swap_i (&a, &b);
	mu_assert_eq (a == -1 && b == 2, 1, "a < b");
	mu_end;
}

bool test_r_num_minmax_swap() {
	ut64 a = 1, b = 2;
	r_num_minmax_swap (&a, &b);
	mu_assert_eq (a == 1 && b == 2, 1, "minmax_swap, a < b -> a < b");
	a = 2, b = 1;
	r_num_minmax_swap (&a, &b);
	mu_assert_eq (a == 1 && b == 2, 1, "minmax_swap, b < a -> a < b");
	mu_end;
}

bool test_r_num_between() {
	mu_assert_eq (r_num_between (num, "1 2 3"), 1, "1 <= 2 <= 3");
	mu_assert_eq (r_num_between (num, "3 2 1"), 0, "3 <= 2 <= 1");
	mu_assert_eq (r_num_between (num, "1 1 1"), 1, "1 <= 1 <= 1");
	mu_assert_eq (r_num_between (num, "2 1 3"), 0, "2 <= 1 <= 3");
	mu_assert_eq (r_num_between (num, "1 2 (1+2)"), 1, "1 <= 2 <= (1+2)");
	mu_assert_eq (r_num_between (num, "2 3 (1+2+3)"), 1, "2 <= 3 <= (1+2+3)");
	mu_assert_eq (r_num_between (num, "(1+2) 2 (1+1)"), 0, "(1+2) <= 2 <= (1+1)");
	mu_end;
}

bool all_tests() {
	test_r_num_minmax_swap_i ();
	test_r_num_minmax_swap ();
	test_r_num_between ();
	return tests_passed != tests_run;
}

int main(int argc, char **argv) {
	num = r_num_new (NULL, NULL, NULL);
	return all_tests ();
}
