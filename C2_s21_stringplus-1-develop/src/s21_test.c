#include "s21_test.h"

void print_info(Suite *suite) {
  SRunner *srunner = srunner_create(suite);
  srunner_run_all(srunner, CK_NORMAL);
  int failed_count = srunner_ntests_failed(srunner);
  srunner_free(srunner);

  if (failed_count != 0) {
    printf("FAILED\n");
  } else {
    printf("SUCCESS\n");
  }
}

int main() {
  Suite *suites[] = {test_memchr(),
                     test_memcmp(),
                     test_memcpy(),
                     test_memset(),
                     test_strncat(),
                     test_strchr(),
                     test_strncmp(),
                     test_strncpy(),
                     test_strcspn(),
                     test_strerror(),
                     test_strlen(),
                     test_strpbrk(),
                     test_strrchr(),
                     test_strstr(),
                     test_sscanf(),
                     test_strtok(),
                     test_sprintf(),
                     test_insert(),
                     test_to_upper(),
                     test_to_lower(),
                     test_trim(),

                     NULL};

  for (int i = 0; suites[i] != NULL; i++) {
    print_info(suites[i]);
  }

  return 0;
}
