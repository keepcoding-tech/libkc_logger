// This file is part of libkc_logger
// ==================================
//
// console_log.c
//
// Copyright (c) 2024 Daniel Tanase
// SPDX-License-Identifier: MIT License

#include "../include/console_log.h"

#include <assert.h>
#include <string.h>

enum {
  TEST_DEBUG,
  TEST_ERROR,
  TEST_INFO,
  TEST_WARNING,
  TEST_FATAL
};

const char* ex[] = {
  "TEST_DEBUG",
  "TEST_ERROR",
  "TEST_INFO",
  "TEST_WARNING",
  "TEST_FATAL"
};

const char* log_ex[] = {
  "This is just a test description for debug! XD",
  "This is just a test description for error! XD",
  "This is just a test description for info! XD",
  "This is just a test description for warning! XD",
  "This is just a test description for fatal! XD\n"
    "After this test, the program will exit with a status code of 1."
    "This is GOOD!!",
};

// Test the creation and destruction of an instance.
void test_creation_and_destruction() {
  struct ConsoleLog* log = new_console_log(ex, log_ex, __FILE__);
  destroy_console_log(log);
}

// Test case for the debug() method.
void test_debug() {
  struct ConsoleLog* log = new_console_log(ex, log_ex, __FILE__);

  // log the debug to the console
  log->debug(log, TEST_DEBUG, __LINE__, __func__);
  destroy_console_log(log);
}

// Test case for the error() method.
void test_error() {
  struct ConsoleLog* log = new_console_log(ex, log_ex, __FILE__);

  // log the error to the console
  log->error(log, TEST_ERROR, __LINE__, __func__);
  destroy_console_log(log);
}

// Test case for the info() method.
void test_info() {
  struct ConsoleLog* log = new_console_log(ex, log_ex, __FILE__);

  // log the message to the console
  log->info(log, TEST_INFO, __LINE__, __func__);
  destroy_console_log(log);
}

// Test case for the warning() method.
void test_warning() {
  struct ConsoleLog* log = new_console_log(ex, log_ex, __FILE__);

  // log the warning to the console
  log->warning(log, TEST_WARNING, __LINE__, __func__);
  destroy_console_log(log);
}

// Test case for the fatal() method.
void test_fatal() {
  struct ConsoleLog* log = new_console_log(ex, log_ex, __FILE__);

  // log the fatal to the console
  log->fatal(log, TEST_FATAL, __LINE__, __func__);
  destroy_console_log(log);
}

int main() {
  test_creation_and_destruction();
  test_debug();
  test_error();
  test_info();
  test_warning();
  test_fatal();
  return 0;
}
