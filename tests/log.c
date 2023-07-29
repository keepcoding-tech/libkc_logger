#include "../include/log.h"

// Test the creation and destruction of an instance.
void test_creation_and_destruction() {
  struct KClog* log = new_log();
  destroy_log(log);
}

// Test case for the log_error() method.
void test_log_error() {
  struct KClog* log = new_log();
  log->log_error("THIS IS JUST A TEST!!!", __FILE__, __LINE__, __func__);
  destroy_log(log);
}

// Test case for the log_message() method.
void test_log_message() {
  struct KClog* log = new_log();
  log->log_message("If you see this message, don't worry, this is just a test. :D \n"
      "  Actually, seeing this means the test is working as it should.",
      __FILE__, __LINE__, __func__);
  destroy_log(log);
}

// Test case for the log_warning() method.
void test_log_warning() {
  struct KClog* log = new_log();
  log->log_warning("THIS IS JUST A TEST!!!", __FILE__, __LINE__, __func__);
  destroy_log(log);
}

int main() {
  test_creation_and_destruction();
  test_log_error();
  test_log_message();
  test_log_warning();
  return 0;
}
