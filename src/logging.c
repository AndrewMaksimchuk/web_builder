#include "variables.h"
#include <string.h>

/* t - terminal */

/* Color default */
void tlog(char *data)
{
    printf("%s\n", data);
}

/* Color custom */
void tlog_color(int color_code, char *data)
{
    printf("\033[%dm%s\n\033[0m", color_code, data);
}

void tloge(size_t maxlen, char *format, char *data)
{
    char buffer[maxlen];
    snprintf(buffer, maxlen, format, data);
    printf("%s\n", buffer);
}

/* Color red */
void terror(size_t maxlen, char *format, char *data)
{
    char buffer[maxlen];
    snprintf(buffer, maxlen, format, data);
    printf("\033[31m%s\n\033[0m", buffer);
}

/* Color orange */
void twarn(size_t maxlen, char *format, char *data)
{
    char buffer[maxlen];
    snprintf(buffer, maxlen, format, data);
    printf("\033[33m%s\n\033[0m", buffer);
}

/* Color blue and icon */
void tinfo(size_t maxlen, char *format, char *data)
{
    char buffer[maxlen];
    snprintf(buffer, maxlen, format, data);
    printf("\033[34m%s\n\033[0m", buffer);
}

/* Color custom */
void tmessage(int color_code, size_t maxlen, char *format, char *data)
{
    char buffer[maxlen];
    snprintf(buffer, maxlen, format, data);
    printf("\033[%dm%s\n\033[0m", color_code, buffer);
}

void tmessage_number(int color_code, size_t maxlen, char *format, int data)
{
    char buffer[maxlen];
    snprintf(buffer, maxlen, format, data);
    printf("\033[%dm%s\n\033[0m", color_code, buffer);
}
