#include "../include/log.h"

/* MARK: PUBLIC MEMBER METHODS PROTOTYPES */
void display_console_error(char* message);
void display_console_message(char* message);
void display_console_warning(char* message);
void write_to_file(char* message);

/* MARK: CONSTRUCTOR & DESTRUCTOR DEFINITIONS */

/* The constructor should be used to create a new instance */
struct KClog* new_log() {
  /* create a KClog instance to be returned */
  struct KClog* new_log = malloc(sizeof(struct KClog));

  /* confirm that there is memory to allocate */
  if (new_log == NULL) {
    display_console_error("The memory could not be allocated!");
    return NULL;
  }

  /* assign the public member methods */
  new_log->log_error = display_console_error;
  new_log->log_message = display_console_message;
  new_log->log_warning = display_console_warning;
  new_log->log_to_file = write_to_file;

  return new_log;
}

/* The destructor should be used to destroy an existing instance */
void destroy_log(struct KClog* log) {
  /* free the memory only if the log is not null reference */
  if (log == NULL) {
    return;
  }

  free(log);
}

/* MARK: PUBLIC MEMBER METHODS DEFINITIONS */

/* This function will display a red error message on the screen. */
void display_console_error(char* message) {
  printf("\033[31mTHIS IS AN ERROR: %s\033[0m\n", message);
}

/* This function will display a simple message on the screen. */
void display_console_message(char* message) {
  printf("THIS IS A MESSAGE: %s\n", message);
}

/* This function will display a yellow error message on the screen. */
void display_console_warning(char* message) {
  printf("\033[33mTHIS IS A WARNING: %s\033[0m\n", message);
}

/* This function will write a message to a specified file. */
void write_to_file(char* message) {
  printf("THIS IS A MESSAGE: %s\n", message);
}
