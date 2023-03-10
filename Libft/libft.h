#ifndef LIBFT
#define LIBFT LIBFT

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>


void ft_putchar(char c);
size_t ft_strlen(char *str);
void ft_putstr(const char *str);
void ft_putnbr(int nb);
int ft_atoi(char *str);
char *ft_itoa(int n);
char *ft_unsigned_itoa(unsigned int n);
int ft_octal(int nb);
void ft_printf(char *str, ...);

#endif