/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <engiacom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:33:21 by engiacom          #+#    #+#             */
/*   Updated: 2024/11/22 18:44:34 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read(char *s, int fd)
{
	char	*b;
	int		j;
	int		i;

	b = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (b == NULL)
		return (NULL);
	j = 1;
	i = 0;
	while (!ft_chr_c(s, '\n') && j != 0)
	{
		j = read(fd, b, BUFFER_SIZE);
		if (j == -1 || (j == 0 && i == 0 && s == NULL))
		{
			free (b);
			if (s)
				free (s);
			return (NULL);
		}
		b[j] = '\0';
		s = ft_strjoin(s, b);
		i++;
	}
	free (b);
	return (s);
}

char	*ft_newstash(char *s)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free (s);
		return (NULL);
	}
	str = ft_calloc((ft_strlen(s) - i), sizeof(char));
	if (str == NULL)
		return (NULL);
	i++;
	j = 0;
	while (s[i] != '\0')
		str[j++] = s[i++];
	free (s);
	return (str);
}

char	*ft_newline(char *s)
{
	int		i;
	char	*new;

	i = 0;
	if (!s[i])
		return (NULL);
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	new = (char *)malloc((i + 2) * sizeof(char));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
	{
		new[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash[4096];

	stash[fd] = ft_read(stash[fd], fd);
	if (stash[fd] == NULL)
		return (NULL);
	line = ft_newline(stash[fd]);
	stash[fd] = ft_newstash(stash[fd]);
	return (line);
}

// #include <fcntl.h>

// int main(int argc, char **argv)
// {
//     int fd;
// 	int fd2;
// 	int fd3;
//     char *line;

// 	(void)argc;
//     fd = open(argv[1], O_RDONLY);
// 	fd2 = open(argv[2], O_RDONLY);
// 	fd3 = open(argv[3], O_RDONLY);
//     if (fd == -1)
//     {
//         perror("Error opening file");
//         return (1);
//     }

//     // Lire les lignes du fichier
// 	int i = 0;
//     while (i < 4)
//     {
// 		line = get_next_line(fd);
//         printf("%s", line);
//         free(line);  // Libérer la mémoire allouée pour la ligne
// 		line = get_next_line(fd2);
//         printf("%s", line);
//         free(line);
// 		line = get_next_line(fd3);
//         printf("%s", line);
//         free(line);
// 		printf("\n\n");
// 		i++;
//     }

//     close(fd);
// 	close(fd2);
// 	close(fd3);
//     return (0);
// }