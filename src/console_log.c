#include "../include/console_log.h"

#include <time.h>

// MARK: PUBLIC MEMBER METHODS PROTOTYPES
void display_console_error(const char* error, const char* description,
    const char* file, const int line, const char* func);
void display_console_message(const char* title, const char* message,
    const char* file, const int line, const char* func);
void display_console_warning(const char* warning, const char* description,
    const char* file, const int line, const char* func);

// MARK: CONSTRUCTOR & DESTRUCTOR DEFINITIONS

// The constructor should be used to create a new instance
struct ConsoleLog* new_console_log() {
  // create a KClog instance to be returned
  struct ConsoleLog* new_log = malloc(sizeof(struct ConsoleLog));

  // confirm that there is memory to allocate
  if (new_log == NULL) {
    display_console_error("OUT_OF_MEMORY", "Failing to allocate memory "
        "dynamically (using 'malloc') due to insufficient memory in the heap.",
        __FILE__, __LINE__, __func__);
    return NULL;
  }

  // assign the public member methods
  new_log->log_error = display_console_error;
  new_log->log_message = display_console_message;
  new_log->log_warning = display_console_warning;

  return new_log;
}

// The destructor should be used to destroy an existing instance
void destroy_console_log(struct ConsoleLog* log) {
  // free the memory only if the log is not null reference
  if (log == NULL) {
    display_console_warning("NULL_REFERENCE", "Attempting to use a reference "
        "or pointer that points to NULL, or is uninitialized.",
        __FILE__, __LINE__, __func__);
    return;
  }

  free(log);
}

// MARK: PUBLIC MEMBER METHODS DEFINITIONS

// This function will display a red error message on the screen.
void display_console_error(const char* error, const char* description,
    const char* file, const int line, const char* func) {
  // use the \033[31m ANSI escape code for red color
  printf("\n");
  printf("\033[31m%s: in function ‘%s’ \033[0m \n", file, func);
  printf("\033[31m%s:%d error: %s \033[0m \n", file, line, error);
  printf("\033[31m  %s \033[0m \n", description);
}

// This function will display a simple message on the screen.
void display_console_message(const char* title, const char* message,
    const char* file, const int line, const char* func) {
  printf("\n");
  printf("%s: in function ‘%s’ \n", file, func);
  printf("%s:%d message: %s \n", file, line, title);
  printf("  %s\n", message);
}

// This function will display a yellow error message on the screen.
void display_console_warning(const char* warning, const char* description,
    const char* file, const int line, const char* func) {
  // use the \033[33m ANSI escape code for yellow color
  printf("\n");
  printf("\033[33m%s: in function ‘%s’ \033[0m \n", file, func);
  printf("\033[33m%s:%d warning: %s \033[0m \n", file, line, warning);
  printf("\033[33m  %s  \033[0m \n", description);
}
