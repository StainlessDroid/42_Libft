/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 17:00:09 by mpascual          #+#    #+#             */
/*   Updated: 2022/09/25 12:20:30 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft.h"
# include <stdarg.h>

typedef struct s_var
{
	int				printed_chars;
	int				width;
	int				precision;
	unsigned int	format_pos;
	bool			zero;
	bool			minus;
	bool			is_precision;
	bool			nb_neg;
}					t_var;

int					ft_printf(const char *format, ...);
void				init_flags(t_var *var);
int					mod_putchar(char c);
int					is_type(char c);
int					find_flags(const char *format, va_list arg, t_var *var);
void				check_type(const char c, va_list arg, t_var *var);
int					print_c(char c, t_var *var);
int					print_s(char *str, t_var *var);
void				print_di(int nb, t_var *var);
void				print_u(unsigned int nb, t_var *var);
void				print_p(unsigned long ptr, t_var *var);
void				print_x(unsigned int nb, bool mayus, t_var *var);
void				ft_itohex(unsigned long nb, bool mayus, t_var *var);
int					get_number(const char *str);
int					get_precision(const char *format, va_list arg, t_var *var);
int					minus(t_var *var);
int					star(t_var *var, va_list arg);
void				ft_printnbr(int nb, t_var *var);
void				ft_printnbr_u(unsigned int nb, t_var *var);

#endif
