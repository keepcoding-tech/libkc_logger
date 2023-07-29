#include "../include/kclog.h"

void log_error(char* message);
void log_message(char* message);
void log_warning(char* message);

struct KClog* new_log() {
  struct KClog* new_log = malloc(sizeof(struct KClog));

  if (new_log == NULL) {
    return NULL;
  }

  new_log->log_error = log_error;
  new_log->log_message = log_message;
  new_log->log_warning = log_warning;

  return new_log;
}

void log_error(char* message) {
  printf("\033[31mTHIS IS AN ERROR: %s\033[0m\n", message);
}

void log_message(char* message) {
  printf("THIS IS A MESSAGE: %s\n", message);
}

void log_warning(char* message) {
  printf("\033[33mTHIS IS A WARNING: %s\033[0m\n", message);
}
