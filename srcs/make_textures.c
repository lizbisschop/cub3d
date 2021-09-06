/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_textures.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lbisscho <lbisscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/18 11:37:21 by lbisscho      #+#    #+#                 */
/*   Updated: 2020/06/29 16:46:28 by lbisscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	make_texture_no(t_data *data)
{
	if (ft_strnstr(data->map.no_path, ".xpm", ft_strlen(data->map.no_path)))
	{
		data->textures[0].tex = mlx_xpm_file_to_image(data->mlx.mlx,
		data->map.no_path, &data->textures[0].tex_width,
		&data->textures[0].tex_height);
	}
	else if (ft_strnstr(data->map.no_path, ".png",
	ft_strlen(data->map.no_path)))
	{
		data->textures[0].tex = mlx_png_file_to_image(data->mlx.mlx,
		data->map.no_path, &data->textures[0].tex_width,
		&data->textures[0].tex_height);
	}
}

void	make_texture_so(t_data *data)
{
	if (ft_strnstr(data->map.so_path, ".xpm", ft_strlen(data->map.so_path)))
	{
		data->textures[1].tex = mlx_xpm_file_to_image(data->mlx.mlx,
		data->map.so_path, &data->textures[1].tex_width,
		&data->textures[1].tex_height);
	}
	else if (ft_strnstr(data->map.so_path,
	".png", ft_strlen(data->map.so_path)))
	{
		data->textures[1].tex = mlx_png_file_to_image(data->mlx.mlx,
		data->map.so_path, &data->textures[1].tex_width,
		&data->textures[1].tex_height);
	}
}

void	make_texture_ea(t_data *data)
{
	if (ft_strnstr(data->map.ea_path, ".xpm", ft_strlen(data->map.ea_path)))
	{
		data->textures[3].tex = mlx_xpm_file_to_image(data->mlx.mlx,
		data->map.ea_path, &data->textures[3].tex_width,
		&data->textures[3].tex_height);
	}
	else if (ft_strnstr(data->map.ea_path,
	".png", ft_strlen(data->map.ea_path)))
	{
		data->textures[3].tex = mlx_png_file_to_image(data->mlx.mlx,
		data->map.ea_path, &data->textures[3].tex_width,
		&data->textures[3].tex_height);
	}
}

void	make_texture_we(t_data *data)
{
	if (ft_strnstr(data->map.we_path, ".xpm", ft_strlen(data->map.we_path)))
	{
		data->textures[2].tex = mlx_xpm_file_to_image(data->mlx.mlx,
		data->map.we_path, &data->textures[2].tex_width,
		&data->textures[2].tex_height);
	}
	else if (ft_strnstr(data->map.we_path,
	".png", ft_strlen(data->map.we_path)))
	{
		data->textures[2].tex = mlx_png_file_to_image(data->mlx.mlx,
		data->map.we_path, &data->textures[2].tex_width,
		&data->textures[2].tex_height);
	}
}

void	make_texture_sprite(t_data *data)
{
	if (ft_strnstr(data->map.sprite, ".xpm", ft_strlen(data->map.sprite)))
	{
		data->textures[4].tex = mlx_xpm_file_to_image(data->mlx.mlx,
		data->map.sprite, &data->textures[4].tex_width,
		&data->textures[4].tex_height);
	}
	else if (ft_strnstr(data->map.sprite, ".png", ft_strlen(data->map.sprite)))
	{
		data->textures[4].tex = mlx_png_file_to_image(data->mlx.mlx,
		data->map.sprite, &data->textures[4].tex_width,
		&data->textures[4].tex_height);
	}
}
