// This file is part of libkc_logger
// ==================================
//
// exceptions.c
//
// Copyright (c) 2024 Daniel Tanase
// SPDX-License-Identifier: MIT License

const char* err[] =
{
  "EMPTY_STRUCTURE",
  "INDEX_OUT_OF_BOUNDS",
  "NULL_REFERENCE",
  "OUT_OF_MEMORY",
  "UNDERFLOW",
  "OVERFLOW",
  "DIVISION_BY_ZERO",
  "INVALID_ARGUMENT",
  "FILE_NOT_FOUND",
  "PERMISSION_DENIED",
  "IO_ERROR",
  "INTERRUPTED_OPERATION",
  "TIMEOUT",
  "NETWORK_ERROR",
  "INVALID_OPERATION",
  "FORMAT_ERROR",
  "PARSE_ERROR",
  "UNSUPPORTED_FEATURE",
  "DATA_CORRUPTION",
  "RESOURCE_UNAVAILABLE",
  "CONFIGURATION_ERROR",
  "HARDWARE_FAILURE",
  "SYSTEM_ERROR",
  "DEADLOCK",
  "UNHANDLED_EXCEPTION",
  "UNDEFINED_BEHAVIOR",
  "BUFFER_OVERFLOW",
  "BUFFER_UNDERFLOW",
  "THREAD_ERROR",
  "CONCURRENT_ACCESS",
  "LOST_CONNECTION",
  "PROTOCOL_ERROR",
  "SECURITY_ERROR",
  "COMPILATION_ERROR",
  "DEBUGGING_ERROR",
  "LOGGING_ERROR",
  "RECOVERABLE_ERROR",
  "UNRECOVERABLE_ERROR",
  "FATAL_ERROR",
  "UNKNOWN_ERROR"
};

const char* log_err[] =
{
  "You are attempting to perform operations on an empty data structure.",
  "You are trying to access an element at an invalid index in an array, list, "
    "or other indexed data structure.",
  "You are attempting to use a reference or pointer that points to null or is "
    "uninitialized.",
  "Failing to allocate memory dynamically (e.g., using malloc) due to "
    "insufficient memory in the heap.",
  "The data type's size goes below its minimum representable value.",
  "The data type's size exceeds its maximum representable value.",
  "Division operation attempted with a divisor of zero.",
  "A provided argument or parameter does not meet the expected conditions or "
    "constraints.",
  "The specified file or resource could not be found.",
  "The operation is not permitted due to insufficient permissions.",
  "An input/output operation failed or was not completed successfully.",
  "The operation was interrupted by an external event or signal.",
  "The operation exceeded the specified time limit.",
  "An error occurred in network communication or connectivity.",
  "The requested operation is not valid or supported in the current context.",
  "The data or input does not conform to the expected format.",
  "Error encountered while parsing or interpreting data or content.",
  "A feature or functionality is not supported or implemented.",
  "Data integrity is compromised or corrupted.",
  "The required resource is not available or accessible.",
  "An error occurred in the configuration or settings.",
  "A hardware component or device failure.",
  "An unexpected or system-level error occurred.",
  "A deadlock situation was encountered.",
  "An unhandled exception or error condition occurred.",
  "Undefined behavior was observed or encountered.",
  "Data buffer overflow occurred.",
  "Data buffer underflow occurred.",
  "Error related to thread management or execution.",
  "Concurrent access to a resource resulted in an error.",
  "Connection with a resource or service was lost.",
  "Error in protocol adherence or communication.",
  "Security-related error or violation.",
  "Error encountered during code compilation.",
  "Error occurred during debugging or debugging-related operation.",
  "Error related to logging or log management.",
  "A recoverable error occurred.",
  "An unrecoverable error occurred.",
  "A fatal error occurred.",
  "An unknown error occurred."
};

