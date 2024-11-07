#include <fcntl.h>
#include "minunit.h"

#include "tests_gnl_mandatory.c"
#include "tests_gnl_bonus.c"

int	main(void)
{
	MU_RUN_SUITE(get_next_line_test_suite);
	MU_RUN_SUITE(get_next_line_bonus_test_suite);

	MU_REPORT();
	return MU_EXIT_CODE;
}
