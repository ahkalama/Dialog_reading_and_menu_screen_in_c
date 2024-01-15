/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkalama <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:23:33 by ahkalama          #+#    #+#             */
/*   Updated: 2023/01/04 15:27:54 by ahkalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_new_left_str(char *kalan)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (kalan[i] && kalan[i] != '\n')
		i++;
	if (!kalan[i])
	{
		free(kalan);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(kalan) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (kalan[i])
		str[j++] = kalan[i++];
	str[j] = '\0';
	free(kalan);
	return (str);
}

char	*ft_get_line(char *kalan)
{
	int		i;
	char	*str;

	i = 0;
	if (!kalan[i])
		return (NULL);
	while (kalan[i] && kalan[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (kalan[i] && kalan[i] != '\n')
	{
		str[i] = kalan[i];
		i++;
	}
	if (kalan[i] == '\n')
	{
		str[i] = kalan[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_read_to_left_str(int fd, char *kalan)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(kalan, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		kalan = ft_strjoin(kalan, buff);
	}
	free(buff);
	return (kalan);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*kalan;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	kalan = ft_read_to_left_str(fd, kalan);
	if (!kalan)
		return (NULL);
	str = ft_get_line(kalan);
	kalan = ft_new_left_str(kalan);
	return (str);
}

// int main()
// {
// 	int fd = open("test.txt", O_RDONLY);
// 	char *a;
// 	int i = 2;
// 	while(i--)
// 	{
// 		a = get_next_line(fd);
// 		printf("%s", a);
// 	}
// }
