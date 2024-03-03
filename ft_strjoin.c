/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguemazi <aguemazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:56:48 by aguemazi          #+#    #+#             */
/*   Updated: 2022/11/02 13:36:19 by aguemazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		counter;
	int		curs;

	if (!s1)
		return ((char *)s2);
	else if (!s2)
		return ((char *)s1);
	result = (char *)malloc((ft_strlen(s1) + (ft_strlen(s2) + 1)));
	if (!result)
		return (NULL);
	counter = 0;
	curs = 0;
	while (s1[counter])
		result[curs++] = s1[counter++];
	counter = 0;
	while (s2[counter])
		result[curs++] = s2[counter++];
	result[curs] = '\0';
	return (result);
}
