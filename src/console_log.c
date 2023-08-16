#include "../include/console_log.h"

/* MARK: PRIVATE MEMBER METHODS PROTOTYPES */
static void display_debug_message(struct ConsoleLog* self,
    const int index, const int line, const char* func);
static void display_error_message(struct ConsoleLog* self,
    const int index, const int line, const char* func);
static void display_fatal_message(struct ConsoleLog* self,
    const int index, const int line, const char* func);
static void display_info_message(struct ConsoleLog* self,
    const int index, const int line, const char* func);
static void display_warning_message(struct ConsoleLog* self,
    const int index, const int line, const char* func);

/* MARK: PUBLIC MEMBER METHODS PROTOTYPES */
void log_debug(const char* title, const char* description,
    const char* file, const int line, const char* func);
void log_error(const char* exception, const char* description,
    const char* file, const int line, const char* func);
void log_fatal(const char* exception, const char* description,
    const char* file, const int line, const char* func);
void log_message(const char* title, const char* description,
    const char* file, const int line, const char* func);
void log_warning(const char* warning, const char* description,
    const char* file, const int line, const char* func);

/* MARK: CONSTRUCTOR & DESTRUCTOR DEFINITIONS */

// The constructor should be used to create a new instance
struct ConsoleLog* new_console_log(const char** exceptions,
    const char** descriptions, const char* file) {
  // create a ConsoleLog instance to be returned
  struct ConsoleLog* new_log = malloc(sizeof(struct ConsoleLog));

  // confirm that there is memory to allocate
  if (new_log == NULL) {
    log_error("OUT_OF_MEMORY", "Failing to allocate memory "
        "dynamically (using 'malloc') due to insufficient memory in the heap.",
        __FILE__, __LINE__, __func__);
    return NULL;
  }

  // assign the exceptions and descriptions arrays
  new_log->exceptions = exceptions;
  new_log->descriptions = descriptions;
  new_log->file = file;

  // assign the public member methods
  new_log->debug = display_debug_message;
  new_log->error = display_error_message;
  new_log->fatal = display_fatal_message;
  new_log->message = display_info_message;
  new_log->warning = display_warning_message;

  return new_log;
}

// The destructor should be used to destroy an existing instance
void destroy_console_log(struct ConsoleLog* log) {
  // free the memory only if the log is not null reference
  if (log == NULL) {
    log_warning("NULL_REFERENCE", "Attempting to use a reference "
        "or pointer that points to NULL, or is uninitialized.",
        __FILE__, __LINE__, __func__);
    return;
  }

  free(log);
}

/* MARK: PRIVATE MEMBER METHODS DEFINITIONS */

// This function will simply call the public function with enforced parameters
static void display_debug_message(struct ConsoleLog* self,
    const int index, const int line, const char* func) {
  log_debug(self->exceptions[index],
      self->descriptions[index], self->file, line, func);
}

// This function will simply call the public function with enforced parameters
static void display_error_message(struct ConsoleLog* self,
    const int index, const int line, const char* func) {
  log_error(self->exceptions[index],
      self->descriptions[index], self->file, line, func);
}

// This function will simply call the public function with enforced parameters
static void display_fatal_message(struct ConsoleLog* self,
    const int index, const int line, const char* func) {
  log_fatal(self->exceptions[index],
      self->descriptions[index], self->file, line, func);
}

// This function will simply call the public function with enforced parameters
static void display_info_message(struct ConsoleLog* self,
    const int index, const int line, const char* func) {
  log_message(self->exceptions[index],
      self->descriptions[index], self->file, line, func);
}

// This function will simply call the public function with enforced parameters
static void display_warning_message(struct ConsoleLog* self,
    const int index, const int line, const char* func) {
  log_warning(self->exceptions[index],
      self->descriptions[index], self->file, line, func);
}

/* MARK: PUBLIC MEMBER METHODS DEFINITIONS */

// This function will display a white debug message on the screen.
void log_debug(const char* title, const char* description,
    const char* file, const int line, const char* func) {
  printf("\n");
  printf("%s: in function ‘%s’ \n", file, func);
  printf("%s:%d message: %s \n", file, line, title);
  printf("  %s\n", description);
}

// This function will display a red error message on the screen.
void log_error(const char* exception, const char* description,
    const char* file, const int line, const char* func) {
  // use the \033[31m ANSI escape code for red color
  printf("\n");
  printf("\033[31m%s: in function ‘%s’ \033[0m \n", file, func);
  printf("\033[31m%s:%d error: %s \033[0m \n", file, line, exception);
  printf("\033[31m  %s \033[0m \n", description);
}

// This function will display a red error message on the screen and exits.
void log_fatal(const char* exception, const char* description,
    const char* file, const int line, const char* func) {
  // use the \033[31m ANSI escape code for red color
  printf("\n");
  printf("\033[31m%s: in function ‘%s’ \033[0m \n", file, func);
  printf("\033[31m%s:%d error: %s \033[0m \n", file, line, exception);
  printf("\033[31m  %s \033[0m \n", description);
  exit(1);
}

// This function will display a simple message on the screen.
void log_message(const char* title, const char* description,
    const char* file, const int line, const char* func) {
  printf("\n");
  printf("%s: in function ‘%s’ \n", file, func);
  printf("%s:%d message: %s \n", file, line, title);
  printf("  %s\n", description);
}

// This function will display a yellow error message on the screen.
void log_warning(const char* warning, const char* description,
    const char* file, const int line, const char* func) {
  // use the \033[33m ANSI escape code for yellow color
  printf("\n");
  printf("\033[33m%s: in function ‘%s’ \033[0m \n", file, func);
  printf("\033[33m%s:%d warning: %s \033[0m \n", file, line, warning);
  printf("\033[33m  %s  \033[0m \n", description);
}

