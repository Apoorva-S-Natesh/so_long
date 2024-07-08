/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asomanah <asomanah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:11:34 by asomanah          #+#    #+#             */
/*   Updated: 2024/06/12 17:24:57 by asomanah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buff;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buff)
		buff = ft_calloc(1, 1);
	if (!buff)
	{
		free(buff);
		return (NULL);
	}
	buff = ft_read_file(fd, buff);
	if (!buff)
		return (NULL);
	line = ft_get_line(buff);
	buff = ft_nextline(buff);
	return (line);
}

char	*ft_read_file(int fd, char *result)
{
	int		bytes_read;
	char	*buff;

	bytes_read = 1;
	buff = NULL;
	buff = allocate(buff, result);
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buff);
			free(result);
			return (NULL);
		}
		buff[bytes_read] = '\0';
		result = ft_str_join(result, buff);
		if (ft_strchr(result, '\n'))
			break ;
	}
	free (buff);
	return (result);
}

char	*ft_get_line(char *buff)
{
	char	*line;
	int		i;

	i = 0;
	if (!buff[i])
		return (NULL);
	while (buff[i] && buff[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		line[i] = buff[i];
		i++;
	}
	if (buff[i] && buff[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*ft_nextline(char *buff)
{
	char	*next;
	int		i;
	int		a;

	i = 0;
	a = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (!buff[i])
	{
		free(buff);
		return (NULL);
	}
	next = ft_calloc(((ft_strlen(buff)) - i + 1), sizeof(char));
	i++;
	while (buff[i])
	{
		next[a] = buff[i];
		i++;
		a++;
	}
	free (buff);
	return (next);
}

char	*allocate(char *buff, char *result)
{
	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buff)
	{
		free(buff);
		free(result);
		return (NULL);
	}
	return (buff);
}
