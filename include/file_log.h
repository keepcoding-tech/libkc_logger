// This file is part of libkc_logger
// ==================================
//
// file_log.h
//
// Copyright (c) 2023 Daniel Tanase
// SPDX-License-Identifier: MIT License

/*
 * The FileLog structure provides a logging mechanism to write log messages
 * to specified files.
 *
 * The FileLg structure offers a flexible and reusable logging solution,
 * allowing developers to customize log output to specific files based on their
 * requirements. It is designed to enhance debugging, error reporting, and
 * information gathering in C applications.
 */

#ifndef FILE_LOG_H
#define FILE_LOG_H

#include <stdio.h>
#include <stdlib.h>

struct FileLog
{
  // will write a message to a specified file
  void (*log_to_file)(const char* file_path, const char* log,
      const char* message, const char* file, const int line, const char* func);
};

//---------------------------------------------------------------------------//

// the constructor should be used to create a new instance
struct FileLog* new_file_log();

// the destructor should be used to destroy an existing instance
void destroy_file_log(struct FileLog* log);

#endif /* FILE_LOG_H */
