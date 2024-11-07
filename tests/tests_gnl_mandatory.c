#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include "minunit.h"
#include "../src/get_next_line.h"

MU_TEST(gnl_mandatory_test)
{
	// ARRANGE
	int	fd1 = open("test_files/test1.txt", O_RDONLY);

	// ACT
	char	*actual_result = get_next_line(fd1);
	
	// ASSERT
}

MU_TEST_SUITE(get_next_line_test_suite)
{
	MU_RUN_TEST(gnl_mandatory_test);
}
