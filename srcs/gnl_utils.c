/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 17:29:29 by gde-alme          #+#    #+#             */
/*   Updated: 2022/09/12 17:01:43 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*ft_strchr(const char *s, int c)
{
	size_t		length;
	size_t		i;

	i = 0;
	length = ft_strlen(s) + 1;
	while (i < length)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
		{
			return (&((char *)s)[i]);
		}
		i++;
	}
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ss;
	size_t	strlen;

	if (!s)
		return (NULL);
	strlen = ft_strlen(s);
	if (start >= strlen)
		return (ft_strdup(""));
	if (len < strlen)
		ss = malloc (sizeof(char) * (len + 1));
	else
		ss = malloc (sizeof(char) * (len - start + 1));
	if (!ss)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		ss[i] = s[start + i];
		i++;
	}
	ss[i] = '\0';
	return (ss);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		length;
	size_t		i;
	char		*dest;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	length = ft_strlen(s1);
	length += ft_strlen(s2);
	dest = malloc(sizeof(char *) * (length));
	if (!dest)
		return (NULL);
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	while (i < length)
	{
		dest[i] = *s2++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *s1)
{
	char	*s2;
	char	*ptr;

	if (!s1)
		return (NULL);
	s2 = malloc (sizeof(char) * (ft_strlen(s1) + 1));
	if (!s2)
		return (NULL);
	ptr = s2;
	while (*s1)
		*ptr++ = *s1++;
	*ptr = *s1;
	return (s2);
}

int	ft_strlen(const char *s)
{
	int	i;

	if (*s == '\0')
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}
