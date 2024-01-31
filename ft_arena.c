/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 22:08:41 by tdelage           #+#    #+#             */
/*   Updated: 2024/01/31 08:12:18 by tdelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

struct s_arena	ft_arena_create(size_t size)
{
	struct s_arena	arena;

	arena.ptr = ft_calloc(size, sizeof(t_u8));
	arena.size = size;
	arena.is_free = FALSE;
	arena.current = arena.ptr;
	return (arena);
}

void	ft_arena_destroy(struct s_arena *arena)
{
	ft_free(FT_PTR, arena->ptr);
	arena->ptr = NULL;
	arena->size = 0;
	arena->is_free = TRUE;
	arena->current = NULL;
}

void	*ft_arena_alloc(struct s_arena *arena, size_t size)
{
	void	*ptr;

	if (arena->is_free)
		return (NULL);
	if (arena->current + size > arena->ptr + arena->size)
		return (NULL);
	arena->current += size;
	return (ptr);
}
