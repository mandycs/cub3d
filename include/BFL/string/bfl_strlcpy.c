/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfl_strlcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 19:02:59 by mancorte          #+#    #+#             */
/*   Updated: 2025/03/16 19:03:17 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BFL.h"

size_t	bfl_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	dlen;
	size_t	srclen;
	size_t	i;

	if (!dst || !src)
		return (0);
	dlen = bfl_strlen(dst);
	srclen = bfl_strlen(src);
	if (dstsize <= dlen)
		return (dstsize + srclen);
	i = 0;
	while (src[i] && (dlen + i) < (dstsize - 1))
	{
		dst[dlen + i] = src[i];
		i++;
	}
	dst[dlen + i] = '\0';
	return (dlen + srclen);
}
