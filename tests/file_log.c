// This file is part of libkc_logger
// ==================================
//
// file_log.c
//
// Copyright (c) 2024 Daniel Tanase
// SPDX-License-Identifier: MIT License

#define _CRT_SECURE_NO_WARNINGS

#include "../include/file_log.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

// Test the creation and destruction of an instance.
void test_creation_and_destruction() {
  struct FileLog* log = new_file_log();
  destroy_file_log(log);
}

// Test case for the log_to_file() method.
void test_log_to_file() {
  struct FileLog* log = new_file_log();

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

  char* test = __FILE__ ": in function ‘test_log_to_file’";
  for (int i = 0; i < strlen(test) - 1; ++i) {
    printf("%c == %c \n", read_line[i], test[i]);
    assert(read_line[i] == test[i]);
  }

  fgets(read_line, sizeof(read_line), read_file);
  test = __FILE__ ":32 message: THIS IS JUST A TEST!!!";
  for (int i = 0; i < strlen(test) - 1; ++i) {
    assert(read_line[i] == test[i]);
  }

  fgets(read_line, sizeof(read_line), read_file);
  test = "  This is a test description! XD";
  for (int i = 0; i < strlen(test) - 1; ++i) {
    assert(read_line[i] == test[i]);
  }

  destroy_file_log(log);
}

int main() {
  test_creation_and_destruction();
  test_log_to_file();
  return 0;
}
