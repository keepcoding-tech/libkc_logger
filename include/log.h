// open source c library
// ==================================
//
// log.h
//
// Daniel Tanase
// 29/07/23

/*
 * The KClog structure, provides a generic logging mechanism with various
 * functionalities. It allows users to log messages with additional contextual
 * information such as file name, line number, and function name. The structure
 * contains function pointers for different logging operations.
 *
 * It is designed to enhance debugging and error reporting by providing
 * context-specific information for each logged message.
 */

#ifndef LOG_H
#define LOG_H

#include <stdio.h>
#include <stdlib.h>

struct KClog {
  // will display a red error message on the screen
  void (*log_error)(const char* error, const char* description,
      const char* file, const int line, const char* func);

  // will display a simple message on the screen
  void (*log_message)(const char* title, const char* message,
      const char* file, const int line, const char* func);

  // will display a yellow error message on the screen
  void (*log_warning)(const char* warning, const char* description,
      const char* file, const int line, const char* func);

  // will write a message to a specified file
  void (*log_to_file)(const char* log, const char* message,
      const char* file, const int line, const char* func);
};

// the constructor should be used to create a new instance
struct KClog* new_log();

// the destructor should be used to destroy an existing instance
void destroy_log(struct KClog* log);

#endif /* LOG_H */
