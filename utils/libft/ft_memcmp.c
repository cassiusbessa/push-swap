/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caqueiro <caqueiro@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:20:31 by caqueiro          #+#    #+#             */
/*   Updated: 2023/11/01 15:20:33 by caqueiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char		*str1;
	const unsigned char		*str2;
	size_t					i;

	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)str1[i] != (unsigned char)str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return (0);
}

/*int	main(void)
{
	char	s1[]  = "nos somos iguais";
	char	s2[]  = "nos somos iguais";
	
	char	s3[]  = "bhh";
	char	s4[]  = "bcc";

	char s5[] = "abcd";
	char s6[] = "def";
	printf("%d", memcmp(s1,s2, 8) == ft_memcmp(s1,s2, 8));
	printf("%d", memcmp(s3,s4, 8) == ft_memcmp(s3,s4, 8));
	printf("%d", memcmp(s5,s6, 2) == ft_memcmp(s5,s6, 2));
}*/
