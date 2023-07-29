#include "../include/log.h"

// MARK: PUBLIC MEMBER METHODS PROTOTYPES
void display_console_error(const char* message, const char* file,
    const int line, const char* func);
void display_console_message(const char* message, const char* file,
    const int line, const char* func);
void display_console_warning(const char* message, const char* file,
    const int line, const char* func);
void write_to_file(const char* message, const char* file,
    const int line, const char* func);

// MARK: CONSTRUCTOR & DESTRUCTOR DEFINITIONS

// The constructor should be used to create a new instance
struct KClog* new_log() {
  // create a KClog instance to be returned
  struct KClog* new_log = malloc(sizeof(struct KClog));

  // confirm that there is memory to allocate
  if (new_log == NULL) {
    display_console_error("The memory could not be allocated!",
        __FILE__, __LINE__, __func__);
    return NULL;
  }

  // assign the public member methods
  new_log->log_error = display_console_error;
  new_log->log_message = display_console_message;
  new_log->log_warning = display_console_warning;
  new_log->log_to_file = write_to_file;

  return new_log;
}

// The destructor should be used to destroy an existing instance
void destroy_log(struct KClog* log) {
  // free the memory only if the log is not null reference
  if (log == NULL) {
    display_console_warning("Dereferenced object!",
        __FILE__, __LINE__, __func__);
    return;
  }

  free(log);
}

// MARK: PUBLIC MEMBER METHODS DEFINITIONS

// This function will display a red error message on the screen.
void display_console_error(const char* message, const char* file,
    const int line, const char* func) {
  // use the \033[31m ANSI escape code for red color
  printf("\n");
  printf("\033[31m%s: in function ‘%s’ \033[0m \n", file, func);
  printf("\033[31m%s:%d error: %s \033[0m \n", file, line, message);
  printf("\n");
}

// This function will display a simple message on the screen.
void display_console_message(const char* message, const char* file,
    const int line, const char* func) {
  printf("\n");
  printf("%s: in function ‘%s’ \n", file, func);
  printf("%s:%d message: %s \n", file, line, message);
  printf("\n");
}

// This function will display a yellow error message on the screen.
void display_console_warning(const char* message, const char* file,
    const int line, const char* func) {
  // use the \033[33m ANSI escape code for yellow color
  printf("\n");
  printf("\033[33m%s: in function ‘%s’ \033[0m \n", file, func);
  printf("\033[33m%s:%d warning: %s \033[0m \n", file, line, message);
  printf("\n");
}

// This function will write a message to a specified file.
void write_to_file(const char* message, const char* file,
    const int line, const char* func) {
}
