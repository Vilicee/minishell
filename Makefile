# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/06 13:58:33 by wvaara            #+#    #+#              #
#    Updated: 2021/09/21 18:23:13 by wvaara           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

FLAGS = -Wall -Wextra -Werror

SRCS = main.c ft_shell.c ft_echo.c ft_read_until_matching_quote.c \
	ft_save_input.c ft_check_quotation.c ft_which_quote.c ft_check_semic.c \
	ft_dollar.c ft_which_command.c ft_search_env.c ft_print_env.c \
	ft_copy_env.c ft_setenv.c ft_write.c ft_unsetenv.c ft_execve.c \
	ft_extract_env_value.c ft_extract_command_path.c ft_cd.c ft_dash_check.c \
	ft_check_path.c ft_execute_cd.c ft_check_dot.c ft_dotdot_slash.c \
	ft_check_buf.c ft_dotdot.c ft_mini_echo.c ft_path_parser.c ft_is_link.c \
	ft_check_start.c ft_command_not_found.c ft_is_quote.c ft_ignore.c \
	ft_get_next_command.c ft_dollar_check.c ft_check_echo_flag.c \
	ft_echo_parser.c ft_command_parser.c ft_cd_parser.c ft_new_dir.c \
	ft_adhoc_split.c

OBJECTS = $(SRCS:.c=.o)

INCLUDES = includes/

LIBRARIES = libft/libft.a libft/libftprintf.a

LIB_DIR = libft

all: $(NAME)

$(NAME): $(LIBRARIES) $(OBJECTS)
	gcc $(FLAGS) $(LIBRARIES) $(OBJECTS) -I $(INCLUDES) -o $(NAME)

$(LIBRARIES):
	$(MAKE) -C $(LIB_DIR)

$(OBJECTS): $(SRCS)

$(SRCS):
	gcc -c $(FLAGS) $(SRCS)

clean:
	$(MAKE) -C $(LIB_DIR) clean
	rm -rf $(OBJECTS)

fclean: clean
	$(MAKE) -C $(LIB_DIR) fclean
	rm -f $(NAME)

re: fclean all

.Phony: all clean fclean re
