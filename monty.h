#ifndef MONTY_H
#define MONTY_H
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
		int n;
		struct stack_s *prev;
		struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
		char *opcode;
		void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct driver_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * Description: carries values through the program
 */
typedef struct driver_s
{
	char *arg;
	FILE *file;
	char *content;
}  driver_t;
extern driver_t drivers;
stack_t *add_dnodeint(stack_t **head, const int n);
int assign(stack_t **stack, unsigned int counter);
void set_content(char *con);
void set_arg(char *_arg);
void set_file(FILE *f);
void f_push(stack_t **head, unsigned int counter);
void f_pall(stack_t **head, unsigned int counter);
void free_stack(stack_t *head);
#endif
