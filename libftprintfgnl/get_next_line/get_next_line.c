/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aproust <aproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:18:38 by aproust           #+#    #+#             */
/*   Updated: 2023/01/31 14:18:39 by aproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*res_line(char *line)
{
	char	*res;
	size_t	i;

	i = -1;
	if (!line[0])
		return (NULL);
	while (line[++i] && line[i] != '\n')
		;
	if (line[i] == '\n')
		i++;
	res = ft_calloc(sizeof(char), i + 1);
	if (!res)
		return (NULL);
	i = -1;
	while (line[++i] && line[i] != '\n')
		res[i] = line[i];
	if (line[i] == '\n')
		res[i++] = '\n';
	res[i] = 0;
	return (res);
}

char	*supp_line(char *str)
{
	char	*res;
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	if (!str[0])
	{
		free(str);
		return (NULL);
	}
	while (str[++i] && str[i] != '\n')
		;
	res = ft_calloc(sizeof(char), (ft_strlen(str) - i + 1));
	if (!res)
		return (NULL);
	if (str[i] == '\n')
		i++;
	while (str[i])
		res[j++] = str[i++];
	free(str);
	return (res);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	int			ret;
	static char	*line[4096];
	char		*res;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, NULL, 0) < 0)
		return (NULL);
	buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	ret = 1;
	while (ret && !ft_strchr(buffer, '\n'))
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret < 0)
			return (free(line[fd]), NULL);
		buffer[ret] = '\0';
		line[fd] = ft_strjoin(line[fd], buffer);
	}
	res = res_line(line[fd]);
	line[fd] = supp_line(line[fd]);
	free(buffer);
	return (res);
}

// int main(void)
// {
//     int        fd1 = open("mathieu", O_RDONLY);
//     // int        fd2 = ope+n()
//     char *str;

//     str = get_next_line(fd1);
//     printf("%s", str);
//     free(str);
//     // while ((str = get_next_line(fd)))
//     // {
//     //     printf("%s", str);
//     //     free
// 	// }
// }
