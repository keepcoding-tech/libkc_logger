/* open source c library
 * ==================================
 *
 * log.h
 *
 * Daniel Tanase
 * 29/07/23
 *
 */

#ifndef LOG_H
#define LOG_H

#include <stdio.h>
#include <stdlib.h>

struct KClog {
  /* will display a red error message on the screen */
  void (*log_error)(char* message);

  /* will display a simple message on the screen */
  void (*log_message)(char* message);

  /* will display a yellow error message on the screen */
  void (*log_warning)(char* message);

  /* will write a message to a specified file */
  void (*log_to_file)(char* message);
};

/* the constructor should be used to create a new instance */
struct KClog* new_log();

/* the destructor should be used to destroy an existing instance */
void destroy_log(struct KClog* log);

#endif /* LOG_H */
