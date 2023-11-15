// This file is part of libkc_logger
// ==================================
//
// console_log.c
//
// Copyright (c) 2023 Daniel Tanase
// SPDX-License-Identifier: MIT License

#include "../include/console_log.h"

//--- MARK: PRIVATE MEMBER METHODS PROTOTYPES -------------------------------//
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

//--- MARK: PUBLIC MEMBER METHODS PROTOTYPES --------------------------------//
void log_debug(const char* title, const char* description,
    const char* file, const int line, const char* func);
void log_error(const char* exception, const char* description,
    const char* file, const int line, const char* func);
void log_fatal(const char* exception, const char* description,
    const char* file, const int line, const char* func);
void log_info(const char* title, const char* description,
    const char* file, const int line, const char* func);
void log_warning(const char* warning, const char* description,
    const char* file, const int line, const char* func);

//---------------------------------------------------------------------------//

struct ConsoleLog* new_console_log(const char** exceptions,
    const char** descriptions, const char* file)
{
  // create a ConsoleLog instance to be returned
  struct ConsoleLog* new_log = malloc(sizeof(struct ConsoleLog));

  // confirm that there is memory to allocate
  if (new_log == NULL)
  {
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
  new_log->info = display_info_message;
  new_log->warning = display_warning_message;

  return new_log;
}

//---------------------------------------------------------------------------//

void destroy_console_log(struct ConsoleLog* log)
{
  // free the memory only if the log is not null reference
  if (log == NULL)
  {
    log_warning("NULL_REFERENCE", "Attempting to use a reference "
        "or pointer that points to NULL, or is uninitialized.",
        __FILE__, __LINE__, __func__);
    return;
  }

  free(log);
}

//---------------------------------------------------------------------------//

static void display_debug_message(struct ConsoleLog* self,
    const int index, const int line, const char* func)
{
  log_debug(self->exceptions[index],
      self->descriptions[index], self->file, line, func);
}

//---------------------------------------------------------------------------//

static void display_error_message(struct ConsoleLog* self,
    const int index, const int line, const char* func)
{
  log_error(self->exceptions[index],
      self->descriptions[index], self->file, line, func);
}

//---------------------------------------------------------------------------//

static void display_fatal_message(struct ConsoleLog* self,
    const int index, const int line, const char* func)
{
  log_fatal(self->exceptions[index],
      self->descriptions[index], self->file, line, func);
}

//---------------------------------------------------------------------------//

static void display_info_message(struct ConsoleLog* self,
    const int index, const int line, const char* func)
{
  log_info(self->exceptions[index],
      self->descriptions[index], self->file, line, func);
}

//---------------------------------------------------------------------------//

static void display_warning_message(struct ConsoleLog* self,
    const int index, const int line, const char* func)
{
  log_warning(self->exceptions[index],
      self->descriptions[index], self->file, line, func);
}

//---------------------------------------------------------------------------//

void log_debug(const char* title, const char* description,
    const char* file, const int line, const char* func)
{
  printf("\n");
  printf("[DEBUG] %s:%d in function ‘%s’ \n", file, line, func);
  printf("[%s] %s\n", title, description);
  printf("\n");
}

//---------------------------------------------------------------------------//

void log_error(const char* exception, const char* description,
    const char* file, const int line, const char* func)
{
  // use the \033[31m ANSI escape code for red color
  printf("\n");
  printf("\033[31m[ERROR] %s:%d in function ‘%s’ \033[0m \n", file, line, func);
  printf("\033[31m[%s] %s \033[0m \n", exception, description);
  printf("\n");
}

//---------------------------------------------------------------------------//

void log_fatal(const char* exception, const char* description,
    const char* file, const int line, const char* func)
{
  // use the \033[31m ANSI escape code for red color
  printf("\n");
  printf("\033[31m[FATAL] %s:%d in function ‘%s’ \033[0m \n", file, line, func);
  printf("\033[31m[%s] %s \033[0m \n", exception, description);
  printf("\n");
  exit(1);
}

//---------------------------------------------------------------------------//

void log_info(const char* title, const char* description,
    const char* file, const int line, const char* func)
{
  printf("\n");
  printf("[INFO] %s:%d in function ‘%s’ \n", file, line, func);
  printf("[%s] %s\n", title, description);
  printf("\n");
}

//---------------------------------------------------------------------------//

void log_warning(const char* warning, const char* description,
    const char* file, const int line, const char* func)
{
  // use the \033[33m ANSI escape code for yellow color
  printf("\n");
  printf("\033[33m[WARNING] %s:%d in function ‘%s’ \033[0m \n", file, line, func);
  printf("\033[33m[%s] %s \033[0m \n", warning, description);
  printf("\n");
}

//---------------------------------------------------------------------------//

