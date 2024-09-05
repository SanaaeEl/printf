#ifndef MAIN_H
#define MAIN_H


#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>



/**
 * struct specifierss - handles char & string types
 * @specifier: specifier
 * @handler: pointer to the char & string handling functions
 */

typedef struct specifierss
{
	char specifier;
	int (*handler)(va_list *arg);
} sp_map;



int _printf(const char *format, ...);
int _printch(char c);
int _printstr(char *str);
int print_int(int nb);

int handle_char(va_list *arg);
int handle_string(va_list *arg);
int handle_percent(va_list *arg);
int handle_int(va_list *arg);
int (*get_specifier(char spec))(va_list *);




#endif  /* MAIN_H */
