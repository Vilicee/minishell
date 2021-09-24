/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 16:11:33 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/24 17:26:29 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <sys/stat.h>
# include "../libft/includes/libft.h"
# include "../libft/ft_printf/includes/ft_printf.h"
# define BUFF_SIZE 256
# define DQUOTE '"'
# define SQU0TE '\''
# define BQUOTE '`'

typedef struct s_mini
{
	int				i;
	int				ii;
	int				index;
	int				e_i;
	int				a_index;
	int				flag;
	int				e_skip;
	int				link_flag;
	int				ret;
	char			exec_fail;
	char			quote;
	char			cd_l;
	char			cd_p;
	char			*buf;
	char			*old;
	char			*new;
	char			*cd_path;
	char			*check;
	char			*temp;
	char			*cd_temp;
	char			*new_word;
	char			*env;
	char			**words;
	char			**array;
	char			**cd_array;
	char			**arr_temp;
	char			**variables;
	struct stat		stats;
}					t_mini;

char				*ft_save_input(void);
char				*ft_is_link(t_mini *data, char **array, char tilde);
char				*ft_echo_parser(char *str, int i, int len, t_mini *data);
char				*ft_command_parser(char *str, int len, int i);
char				*ft_cd_parser(char *str, t_mini *data, int i);
char				*ft_get_next_command(char *str, int i, char quote,
						t_mini *data);
char				*ft_extract_env_value(char **variables, char *word);
char				*ft_extract_command_path(char **variables, char *word,
						char *command, t_mini *dt);
char				*ft_read_until_matching_quote(char *str);
char				**ft_copy_env(void);
char				**ft_adhoc_split(char const *str, char c, int len, int i);
char				**ft_path_parser(char *str, char c);
int					ft_which_command(char *str, t_mini *data, char *word,
						char *temp);
int					ft_shell(t_mini *data);
int					ft_check_echo_flag(char *str, int i);
int					ft_dollar_check(char *str, int i, char quote);
int					ft_check_start(char *str);
int					ft_dotdot_slash(char **array, t_mini *data, char *current);
int					ft_check_path(char *str);
int					ft_check_dot(char *str);
int					ft_is_quote(char c);
int					ft_find_echo_start(char *str);
int					ft_new_dir(char **array, t_mini *data);
int					ft_execve(char *str, t_mini *data, char *command);
int					ft_dollar(char *temp, int i, char c, char **variables);
int					ft_check_quotation(char *str, int i, int ret, char c);
int					ft_which_quote(char *str, int squote, int dquote,
						int bquote);
int					ft_dotdot(char *str, int i, int count);
int					ft_dash_check(char *str);
int					ft_check_buf(char *str, int ret, int len);
int					ft_check_semic(char *str, int i, int ret);
int					ft_search_env(char *temp, int i, char **variables);
int					ft_write(char *str, int i, char quote);
void				ft_cd(char *str, t_mini *data, int ret);
void				ft_print_env(int i, char **variables);
void				ft_mini_echo(char *str, char c);
void				ft_ignore(int signo);
void				ft_execute_cd(t_mini *data, int ret);
void				ft_echo(char *str, t_mini *data);
void				ft_setenv(char *str, t_mini *data, int overwrite);
void				ft_unsetenv(char *str, t_mini *data, int ret);
void				ft_command_not_found(char *command, t_mini *data);

#endif
