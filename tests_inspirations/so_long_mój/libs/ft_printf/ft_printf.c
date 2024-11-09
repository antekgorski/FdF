/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prutkows <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:45:11 by prutkows          #+#    #+#             */
/*   Updated: 2024/04/19 15:45:12 by prutkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_parse_format(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (c == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		count += ft_putunbr(va_arg(args, unsigned int));
	else if (c == 'x')
		count += ft_puthex_lower(va_arg(args, unsigned int));
	else if (c == 'X')
		count += ft_puthex_upper(va_arg(args, unsigned int));
	else if (c == 'p')
		count += ft_putptr((unsigned long)va_arg(args, void *));
	else if (c == '%')
	{
		write(1, "%", 1);
		count++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	unsigned int	count;
	va_list			args;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			count++;
		}
		else
		{
			format++;
			count += ft_parse_format(*format, args);
		}
		format++;
		va_end(args);
	}
	return (count);
}

// int	main(void)
// {
// 	char c = 'A';
// 	char *s = "Hello, World!";
// 	int d = -123;
// 	int i = 456;
// 	unsigned int u = 789;
// 	unsigned int x = 0xabc;
// 	unsigned int X = 0xDEF;
// 	unsigned long p = (unsigned long)&d;
// 	int a;

// 	ft_printf("Testing ft_printf:\n");
// 	a = ft_printf("Character: %c\n", c);
// 	printf("%d\n", a);
// 	a = ft_printf("String: %s\n", s);
// 	printf("%d\n", a);
// 	a = ft_printf("Signed decimal integer: %d\n", d);
// 	printf("%d\n", a);
// 	a = ft_printf("Signed decimal integer: %i\n", i);
// 	printf("%d\n", a);
// 	a = ft_printf("Unsigned decimal integer: %u\n", u);
// 	printf("%d\n", a);
// 	a = ft_printf("Unsigned hexadecimal integer (lowercase): %x\n", x);
// 	printf("%d\n", a);
// 	a = ft_printf("Unsigned hexadecimal integer (uppercase): %X\n", X);
// 	printf("%d\n", a);
// 	a = ft_printf("Pointer: %p\n", (void *)p);
// 	printf("%d\n", a);
// 	a = ft_printf("Percent sign: %%\n");
// 	printf("%d\n", a);

// 	printf("Testing printf:\n");
// 	a = printf("Character: %c\n", c);
// 	printf("%d\n", a);
// 	a = printf("String: %s\n", s);
// 	printf("%d\n", a);
// 	a = printf("Signed decimal integer: %d\n", d);
// 	printf("%d\n", a);
// 	a = printf("Signed decimal integer: %i\n", i);
// 	printf("%d\n", a);
// 	a = printf("Unsigned decimal integer: %u\n", u);
// 	printf("%d\n", a);
// 	a = printf("Unsigned hexadecimal integer (lowercase): %x\n", x);
// 	printf("%d\n", a);
// 	a = printf("Unsigned hexadecimal integer (uppercase): %X\n", X);
// 	printf("%d\n", a);
// 	a = printf("Pointer: %p\n", (void *)p);
// 	printf("%d\n", a);
// 	a = printf("Percent sign: %%\n");
// 	printf("%d\n", a);

// 	char *str = NULL;
// 	printf("%s\n", str);

// 	ft_printf("%s\n", str);

// 	return (0);
// }