#include "../include/console_log.h"
#include "../include/file_log.h"

#include <time.h>

// MARK: PUBLIC MEMBER METHODS PROTOTYPES
void write_to_file(const char* file_path, const char* log, const char* message,
    const char* file, const int line, const char* func);

// MARK: CONSTRUCTOR & DESTRUCTOR DEFINITIONS

// The constructor should be used to create a new instance
struct FileLog* new_file_log() {
  // create a KClog instance to be returned
  struct FileLog* new_log = malloc(sizeof(struct FileLog));

  // confirm that there is memory to allocate
  if (new_log == NULL) {
    struct ConsoleLog* log = new_console_log();
    log->log_error("OUT_OF_MEMORY", "Failing to allocate memory "
        "dynamically (using 'malloc') due to insufficient memory in the heap.",
        __FILE__, __LINE__, __func__);
    return NULL;
  }

  // assign the public member methods
  new_log->log_to_file = write_to_file;

  return new_log;
}

// The destructor should be used to destroy an existing instance
void destroy_file_log(struct FileLog* log) {
  // free the memory only if the log is not null reference
  if (log == NULL) {
    struct ConsoleLog* log = new_console_log();
    log->log_warning("NULL_REFERENCE", "Attempting to use a reference "
        "or pointer that points to NULL, or is uninitialized.",
        __FILE__, __LINE__, __func__);
    return;
  }

  free(log);
}

// MARK: PUBLIC MEMBER METHODS DEFINITIONS

// This function will write a message to a specified file.
void write_to_file(const char* filename, const char* log, const char* message,
    const char* file, const int line, const char* func) {
  // open the file in append mode (creates a new file if it doesn't exist)
  FILE *write_file = fopen(filename, "a");

  // print an error and exit the program
  if (write_file == NULL) {
    struct ConsoleLog* log = new_console_log();
    char error_description[256];
    sprintf(error_description, "Failed to open the specified file: %s", filename);
    log->log_error("CANNOT_OPEN_FILE", error_description,
        __FILE__, __LINE__, __func__);

    // exit the program
    exit(1);
  }

  // get the current timestamp
  time_t now;
  struct tm *tm_info;
  char time_buffer[30];
  time(&now);

  // convert the timestamp to a human-readable string
  tm_info = localtime(&now);
  strftime(time_buffer, sizeof(time_buffer), "%Y-%m-%d %H:%M:%S", tm_info);

  // writing data the log to the file
  fprintf(write_file, "\n");
  fprintf(write_file, "[%s]\n", time_buffer);
  fprintf(write_file, "%s: in function ‘%s’\n", file, func);
  fprintf(write_file, "%s:%d message: %s\n", file, line, log);
  fprintf(write_file, "  %s\n", message);

  // close the file
  fclose(write_file);
}
