/*********************************************

CIS330: Lab 3

Implementation file for the error reporting system

*********************************************/

#include <ohno.h>

// Might fix with library?
#include <stdlib.h>
#include <string.h>

static struct ohno_state *state;

/*
 * Initialize the ohno error system with the given file stream and application name.
 *
 * This should allocate and populate the state structure.
 * Make sure to make a copy of `app_name` as we'll need to use this string later when `ohno()` is called.
 *
 * Feel free to return non-zero if anything went wrong (like not having sufficient memory).
 */
int
ohno_init(FILE* where_to, const char* app_name)
{
  state = (struct ohno_state*)malloc(sizeof(struct ohno_state)); 
  if (state == NULL)
    return 1;
  state->name = (char *)malloc(sizeof(char) * strlen(app_name) + 1);
  if (state->name == NULL) {
    free(state);
    return 1;
  }
  state->out = where_to;
  state->error_number = 0;

  strcpy(state->name, app_name);
  return 0;
}

/*
 * Free any memory allocated to the ohno error system.
 *
 * You allocated memory in `ohno_init()`, now you must give it back.
 */
void
ohno_free()
{
  free(state->name);
  free(state);
}

/*
 * Report an error or warning given the current ohno error system settings (from ohno_init())
 *
 * This function should format `message` and `severity` along with the `app_name` string copied in `ohno_init()`
 * and write (print) a nice message on the saved `FILE *`.
 * The particular formating is up to you. Get creative if your like and feel free to add useful information
 * (e.g. error number or timestamp) to your report.
 */
void
ohno(const char* message, ohno_severity_t severity)
{
  switch(severity) {
    case OHNO_WARNING :
    fprintf(state->out, "ERROR WARNING: %s\n", message);
    break;

    case OHNO_SERIOUS :
    fprintf(state->out, "ERROR SERIOUS: %s\n", message);
    break;

    case OHNO_FATAL :
    fprintf(state->out, "ERROR OHNO_FATAL: %s\n", message);
    break;

    default :
    fprintf(state->out, "ERROR UNKNOWN: %s\n", message);
  }
}
