#include "monty.h"
driver_t drivers = {NULL, NULL, NULL};
/**
* set_arg - sets the global variable
* @_arg: char pointer to arguements
* Return: no return
*/
void set_arg(char *_arg)
{
	drivers.arg = _arg;
}
/**
* set_file - sets the global variable
* @f: file pointer
* Return: no return
*/
void set_file(FILE *f)
{
	drivers.file = f;
}
/**
* set_content - sets the global variable
* @con: char pointer to content
* Return: no return
*/
void set_content(char *con)
{
	drivers.content = con;
}
