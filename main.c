/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 18:45:53 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/05/03 20:18:19 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

#include "wchar.h"
#include <stdio.h>
#include <locale.h>
#include <limits.h>

int main()
{
	//printf("%llx\n", LONG_MAX);
	ft_printf("Long max : %llx\n", LONG_MAX);
}

/*
int	main()
{
	//unsigned int truc;
	//unsigned int t;
	//long t;
	wchar_t truc;
	wchar_t *truc2 = L"héllo∂";

	setlocale(LC_ALL, "");
	truc = L'é';
	//t = 4294967296; //limite unsigned int
	//t = 2147483647 + 2147483647 + 2;

	ft_printf("ft_printf :\n");
	//ft_printf("d : %d\n", t);
	//ft_printf("D : %D\n", t);
	//ft_printf("u : %u\n", t);
	//ft_printf("U : %U\n", t);
	//ft_printf("c : %c\n", 'e');
	//ft_printf("C : %C\n", truc);
	//ft_printf("s : %s\n", "mounir");
	ft_printf("S : %S\n", truc2);
	ft_printf("p : %p\n", truc2);
	//ft_printf("x : %x\n", t);
	//ft_printf("X : %X\n", (unsigned int)t);
	//ft_printf("b : %b\n", (unsigned int)t);
	printf("printf :\n");
	//printf("d : %d\n", t); // test octal et Octal
	//printf("i : %i\n", 0x45);
	//printf("D : %D\n", t);
	//printf("u : %u\n", t);
	//printf("U : %U\n", t);
	//printf("C : %C\n", truc);
	//printf("S : %S\n", truc2);
	//write(1, &truc, sizeof(wchar_t));
	printf("x : %x\n", (unsigned int)truc2);
	printf("p : %p\n", truc2);
	//printf("test : %p\n", truc);
	*/
	//color
	/*
	ft_printf("\033[36m");
	truc = "0";
	ft_printf("hey");
	ft_printf("\033[0m");
	*/
/*
}*/
