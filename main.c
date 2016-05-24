/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 18:45:53 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/05/24 13:58:30 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

#include "wchar.h"
#include <stdio.h>
#include <locale.h>
#include <limits.h>

int main()
{
	int ft;
	int pf;
	wchar_t *truc2 = L"héllo∂";
	char *truc = "hello";

	setlocale(LC_ALL, "");
	/*pf = printf("% ");
	printf("\n");
	ft = ft_printf("% ");
	printf("\n");*/
	int i;
	//unsigned long l;
	char c;
	char **d;
	unsigned long l;
	int g;

	printf("printf    : ");
	pf = printf("%15.4S", L"我是一只猫。");
	printf("{%d}", ft_wstrlen(L"我是一只猫。"));
	printf("\n");
	ft_printf("ft_printf : ");
	ft = ft_printf("%15.4S", L"我是一只猫。");
	//ft = ft_printf("{%010d}", 42);
	ft_printf("\n");
	printf("printf    : %d\n", pf);
	printf("ft_printf : %d\n", ft);
	//printf("%s\n", ft_itoa(SHRT_MAX - 42));
	/*printf("%lu\n", ft_power(8, 21) * 1);
	printf("%lu\n", LONG_MIN);*/
	//l = &ft;
	//g = &ft;
	//ft_printf("long : %llx\n", l);
	//printf("int  : %llx", g);
	//pf = printf("ulltoa : %s", ft_ulltoa(ULONG_MAX));
	//printf("%d\n", ft_wstrlen(L"我是一只猫。"/*L"é"*/));
	/*printf("printf :    %hhd\n", (char)42);
	ft_printf("ft_printf : %x\n", LONG_MAX, 4);*/
	//pf = printf("%5%\n");
	//ft = ft_printf("%5%\n");
	//printf("printf :    %+D\n", 64);
	//ft_printf("ft_printf : %+o\n", 64);
	//ft_printf("ft_printf : %llx\n", LLONG_MIN);
	/*printf("printf :    %o\n", 64);
	ft_printf("printf :    %o\n", 64);*/
	//ft_printf("ft_printf : %llo\n", LLONG_MIN);
	//printf("long :    %d\n", sizeof(long));
	//printf("long :    %d\n", sizeof(long long));
	//ft_printf("ft_printf : %lld\n", (long long)-24145454564);
	//ft_printf("ft_printf : %lld\n", (long long)2414);
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
