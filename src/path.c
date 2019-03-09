/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 22:35:43 by jmeier            #+#    #+#             */
/*   Updated: 2019/03/08 06:24:25 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	find_binary(DIR *dir, char *path, t_map *map_p)
{
	struct dirent	*file;
	struct stat		file_info;
	unsigned		len;
	char			*path_mod;
	char			*tmp;

	len = ft_strlen(path);
	path_mod = len > 1 && path[len - 1] != '/' ? ft_strjoin(path, "/") :
		ft_strdup(path);
	while ((file = readdir(dir)))
	{
		tmp = ft_strjoin(path_mod, file->d_name);
		if (file->d_name[0] != '.' || !access(tmp, X_OK))
		{
			stat(tmp, &file_info);
			if (S_ISREG(file_info.st_mode))
			{
				free(ft_map_remove(map_p, ft_map_hash(map_p, file->d_name)));
				ft_map_set(map_p, ft_map_hash(map_p, file->d_name),
				ft_strdup(tmp));
			}
		}
		free(tmp);
	}
	free(path_mod);
}

void	update_path(t_sh *sh)
{
	t_cont		*env_path;
	char		**path_arr;
	DIR			*dir;
	int			i;

	if (!(env_path = ft_map_get(&sh->env, ft_map_hash(&sh->env, "PATH"))))
		return ;
	path_arr = ft_strsplit(env_path->value, ':');
	i = 0;
	while (path_arr[i])
	{
		if ((dir = opendir(path_arr[i])))
		{
			find_binary(dir, path_arr[i], &sh->path);
			closedir(dir);
		}
		free(path_arr[i++]);
	}
	free(path_arr);
}
