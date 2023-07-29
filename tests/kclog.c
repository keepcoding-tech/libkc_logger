#include "../include/kclog.h"

int main() {
  struct KClog* log = new_log();
  log->log_error("Just testing");
  log->log_warning("Just testing");
  log->log_message("Just testing");
  free(log);
  return 0;
}
