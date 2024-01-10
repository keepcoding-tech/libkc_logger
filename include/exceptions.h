// This file is part of libkc_logger
// ==================================
//
// exceptions.h
//
// Copyright (c) 2024 Daniel Tanase
// SPDX-License-Identifier: MIT License

/*
 * This header file provides an exception handling framework through
 * enumerations and corresponding arrays of exception descriptions. It
 * encapsulates various types of exceptions that can occur during program
 * execution. Developers can use this framework to handle and report errors in
 * a structured manner.
 *
 * The EXCEPTION enumeration lists common exception types, and the exception and
 * log_exception arrays provide string representations and detailed descriptions
 * for each exception type, aiding in better error reporting and debugging.
 */

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

enum EXCEPTIONS
{
  KC_EMPTY_STRUCTURE,
  KC_INDEX_OUT_OF_BOUNDS,
  KC_NULL_REFERENCE,
  KC_OUT_OF_MEMORY,
  KC_UNDERFLOW,
  KC_OVERFLOW,
  KC_DIVISION_BY_ZERO,
  KC_INVALID_ARGUMENT,
  KC_FILE_NOT_FOUND,
  KC_PERMISSION_DENIED,
  KC_IO_ERROR,
  KC_INTERRUPTED_OPERATION,
  KC_TIMEOUT,
  KC_NETWORK_ERROR,
  KC_INVALID_OPERATION,
  KC_FORMAT_ERROR,
  KC_PARSE_ERROR,
  KC_UNSUPPORTED_FEATURE,
  KC_DATA_CORRUPTION,
  KC_RESOURCE_UNAVAILABLE,
  KC_CONFIGURATION_ERROR,
  KC_HARDWARE_FAILURE,
  KC_SYSTEM_ERROR,
  KC_DEADLOCK,
  KC_UNHANDLED_EXCEPTION,
  KC_UNDEFINED_BEHAVIOR,
  KC_BUFFER_OVERFLOW,
  KC_BUFFER_UNDERFLOW,
  KC_THREAD_ERROR,
  KC_CONCURRENT_ACCESS,
  KC_LOST_CONNECTION,
  KC_PROTOCOL_ERROR,
  KC_SECURITY_ERROR,
  KC_COMPILATION_ERROR,
  KC_DEBUGGING_ERROR,
  KC_LOGGING_ERROR,
  KC_RECOVERABLE_ERROR,
  KC_UNRECOVERABLE_ERROR,
  KC_FATAL_ERROR,
  KC_UNKNOWN_ERROR
};

extern const char* err[];
extern const char* log_err[];

#endif /* EXCEPTIONS_H */