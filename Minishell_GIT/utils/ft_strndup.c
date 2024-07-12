/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_strndup.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: edecorce <edecorce@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/07/10 22:17:30 by edecorce		  #+#	#+#			 */
/*   Updated: 2024/07/10 22:19:09 by edecorce		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../main/minishell.h"

char	*ft_strndup(const char *src, size_t n)
{
	size_t	i;
	size_t	len;
	char	*str;

	len = 0;
	while (src[len] && len < n)
		len++;
	str = (char *)malloc(sizeof(*str) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
