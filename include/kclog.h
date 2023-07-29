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
  /* will display on the screen an error message */
  void (*log_error)(char* message);

  /* will display on the screen a simple message */
  void (*log_message)(char* message);

  /* will display on the screen a warning message */
  void (*log_warning)(char* message);

};

struct KClog* new_log();

#endif /* LOG_H */
