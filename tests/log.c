#include "../include/log.h"

#include <assert.h>
#include <string.h>

// Test the creation and destruction of an instance.
void test_creation_and_destruction() {
  struct KClog* log = new_log();
  destroy_log(log);
}

// Test case for the log_error() method.
void test_log_error() {
  struct KClog* log = new_log();

  // log the error to the console
  log->log_error("THIS IS JUST A TEST!!!", "This is a test description! XD",
      __FILE__, __LINE__, __func__);

  destroy_log(log);
}

// Test case for the log_message() method.
void test_log_message() {
  struct KClog* log = new_log();

  // log the message to the console
  log->log_message("THIS IS JUST A TEST!!!", "If you see this message, don't "
      "worry, this is just a test. :D \nActually, seeing this means the test "
      "is working as it should.",
      __FILE__, __LINE__, __func__);

  destroy_log(log);
}

// Test case for the log_warning() method.
void test_log_warning() {
  struct KClog* log = new_log();

  // log the warning to the console
  log->log_warning("THIS IS JUST A TEST!!!", "This is a test description! XD",
      __FILE__, __LINE__, __func__);

  destroy_log(log);
}

// Test case for the log_to_file() method.
void test_log_to_file() {
  struct KClog* log = new_log();

  const char* filename = "build/bin/test/test.log";

  // write the log to the file
  log->log_to_file(filename, "THIS IS JUST A TEST!!!",
      "This is a test description! XD",
      __FILE__, __LINE__, __func__); // DO NOT MOVE THIS LINE!!!

  // check if the log was printed correctely
  FILE *read_file = fopen(filename, "r");
  char read_line[100];

  // skip the next two lines
  fgets(read_line, sizeof(read_line), read_file);
  fgets(read_line, sizeof(read_line), read_file);

  fgets(read_line, sizeof(read_line), read_file);
  char* test = "tests/log.c: in function ‘test_log_to_file’";
  for (int i = 0; i < strlen(read_line) - 1; ++i) {
    assert(read_line[i] == test[i]);
  }

  fgets(read_line, sizeof(read_line), read_file);
  test = "tests/log.c:56 message: THIS IS JUST A TEST!!!";
  for (int i = 0; i < strlen(read_line) - 1; ++i) {
    assert(read_line[i] == test[i]);
  }

  fgets(read_line, sizeof(read_line), read_file);
  test = "  This is a test description! XD";
  for (int i = 0; i < strlen(read_line) - 1; ++i) {
    assert(read_line[i] == test[i]);
  }

  destroy_log(log);
}

int main() {
  test_creation_and_destruction();
  test_log_error();
  test_log_message();
  test_log_warning();
  test_log_to_file();
  return 0;
}
