#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include "minunit.h"
#include "../src/get_next_line.h"

MU_TEST(gnl_mandatory_test)
{
	// ARRANGE
	int	fd1 = open("test_files/test1.txt", O_RDONLY);
	mu_check(fd1 != -1); // Assert that the file opened successfully

	const char	*expected_lines[] = 	
		{
			"Hello_Dolly.\n",
			"Goodbye.\n",
			"Hello_Dolly.\n",
			NULL,
		};

	// ACT
	for (int i = 0; expected_lines[i] != NULL; i++)
	{
		char	*actual_result = get_next_line(fd1);

		// ASSERT
		mu_assert_string_eq(expected_lines[i], actual_result);

		// FREE MEMORY
		free(actual_result);
	}	
	close(fd1);
}

MU_TEST_SUITE(get_next_line_test_suite)
{
	MU_RUN_TEST(gnl_mandatory_test);
}
