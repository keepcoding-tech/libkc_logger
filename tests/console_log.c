#include "../include/console_log.h"

#include <assert.h>
#include <string.h>

// Test the creation and destruction of an instance.
void test_creation_and_destruction() {
  struct ConsoleLog* log = new_console_log();
  destroy_console_log(log);
}

// Test case for the log_error() method.
void test_log_error() {
  struct ConsoleLog* log = new_console_log();

  // log the error to the console
  log->log_error("THIS IS JUST A TEST!!!", "This is a test description! XD",
      __FILE__, __LINE__, __func__);

  destroy_console_log(log);
}

// Test case for the log_message() method.
void test_log_message() {
  struct ConsoleLog* log = new_console_log();

  // log the message to the console
  log->log_message("THIS IS JUST A TEST!!!", "If you see this message, don't "
      "worry, this is just a test. :D \nActually, seeing this means the test "
      "is working as it should.",
      __FILE__, __LINE__, __func__);

  destroy_console_log(log);
}

// Test case for the log_warning() method.
void test_log_warning() {
  struct ConsoleLog* log = new_console_log();

  // log the warning to the console
  log->log_warning("THIS IS JUST A TEST!!!", "This is a test description! XD",
      __FILE__, __LINE__, __func__);

  destroy_console_log(log);
}

int main() {
  test_creation_and_destruction();
  test_log_error();
  test_log_message();
  test_log_warning();
  return 0;
}
