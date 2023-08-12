// open source c library
// ==================================
//
// console_log.h
//
// Daniel Tanase
// 30/07/23

/*
 * The ConsoleLog structure, provides a generic logging mechanism with various
 * functionalities. It allows users to log messages with additional contextual
 * information such as file name, line number, and function name. The structure
 * contains function pointers for different logging operations.
 *
 * It is designed to enhance debugging and error reporting by providing
 * context-specific information for each logged message.
 */

#ifndef CONSOLE_LOG_H
#define CONSOLE_LOG_H

#include <stdio.h>
#include <stdlib.h>

struct ConsoleLog {
  // will display a white debug message on the screen
  void (*log_debug)(const char* debug, const char* description,
      const char* file, const int line, const char* func);

  // will display a red error message on the screen
  void (*log_error)(const char* error, const char* description,
      const char* file, const int line, const char* func);

  // will display a red error message on the screen and exit the program
  void (*log_fatal)(const char* error, const char* description,
      const char* file, const int line, const char* func);

  // will display a simple message on the screen
  void (*log_message)(const char* title, const char* message,
      const char* file, const int line, const char* func);

  // will display a yellow error message on the screen
  void (*log_warning)(const char* warning, const char* description,
      const char* file, const int line, const char* func);
};

// the constructor should be used to create a new instance
struct ConsoleLog* new_console_log();

// the destructor should be used to destroy an existing instance
void destroy_console_log(struct ConsoleLog* log);

#endif /* CONSOLE_LOG_H */
