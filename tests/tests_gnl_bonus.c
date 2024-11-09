#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include "minunit.h"
#include "../src/get_next_line_bonus.h"

MU_TEST(test_gnl_bonus_normal_file)
{
	// ARRANGE
	int	fd = open("test_files/test1.txt", O_RDONLY);
	mu_check(fd != -1);

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
		char	*actual_result = get_next_line(fd);

		// ASSERT
		mu_assert_string_eq(expected_lines[i], actual_result);

		// FREE MEMORY
		free(actual_result);
	}
	// CLEANUP
	close(fd);
}

MU_TEST(test_gnl_bonus_empty_file)
{
	// ARRANGE
	int	fd = open("test_files/empty.txt", O_RDONLY);
	mu_check(fd != -1);

	// ACT
	char	*actual_result = get_next_line(fd);

	// ASSERT
	mu_assert_string_eq(actual_result, NULL); 

	// CLEANUP
	free(actual_result);
	close(fd);
}

MU_TEST(test_gnl_bonus_single_line_no_newline)
{
	// ARRANGE
	int	fd = open("test_files/single_line_no_newline.txt", O_RDONLY);
	mu_check(fd != -1);

	const char	*expected_result = "Single line without newline";

	// ACT
	char	*actual_result = get_next_line(fd);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result); 
	free(actual_result);

	// Verify that the next call returns NULL
	actual_result = get_next_line(fd);
	mu_assert_string_eq(actual_result, NULL); 

	// CLEANUP
	free(actual_result);
	close(fd);
}

MU_TEST_SUITE(get_next_line_bonus_test_suite)
{
	MU_RUN_TEST(test_gnl_bonus_normal_file);
	MU_RUN_TEST(test_gnl_bonus_empty_file);
	MU_RUN_TEST(test_gnl_bonus_single_line_no_newline);
}

int	main(void)
{
//	MU_RUN_SUITE(get_next_line_bonus_test_suite);

	MU_REPORT();
	return MU_EXIT_CODE;
}
