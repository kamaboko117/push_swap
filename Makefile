# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/21 14:20:20 by asaboure          #+#    #+#              #
#    Updated: 2021/11/08 13:22:10 by asaboure         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

SRCS	=	push_swap.c															\
			sources/stack_operations.c											\
			sources/ps_operations.c												\
			sources/ps_operations2.c											\
			sources/utils.c														\
			sources/ps_operations3.c											\
			sources/stack_operations2.c											\
			sources/utils2.c													\
			sources/algorithmics.c												\
			sources/algorithmics2.c												\
			sources/algorithmics3.c												\
			sources/algorithmics4.c												\
			sources/init.c														\
			sources/utils3.c
			
LIBFTSRCS = ft_memccpy.c														\
			ft_memchr.c															\
			ft_memcmp.c															\
			ft_memcpy.c															\
			ft_memmove.c														\
			ft_memset.c															\
			ft_putchar_fd.c														\
			ft_putendl_fd.c														\
			ft_putnbr_fd.c														\
			ft_putstr_fd.c														\
			ft_split.c															\
			ft_strchr.c															\
			ft_strdup.c															\
			ft_strjoin.c														\
			ft_strlcat.c														\
			ft_strlcpy.c														\
			ft_strlen.c															\
			ft_strmapi.c														\
			ft_strncmp.c														\
			ft_strnstr.c														\
			ft_strrchr.c														\
			ft_strtrim.c														\
			ft_substr.c															\
			ft_tolower.c														\
			ft_toupper.c														\
			ft_atoi.c															\
			ft_bzero.c															\
			ft_calloc.c															\
			ft_isalnum.c														\
			ft_isalpha.c														\
			ft_isascii.c														\
			ft_isdigit.c														\
			ft_isprint.c														\
			ft_itoa.c															\
			ft_putnbrbase_fd.c													\
			ft_putnbru_fd.c														\
			ft_putnbrubase_fd.c													\
			ft_numlen.c															\
			get_next_line.c														\
			get_next_line_utils.c												\
			ft_strjoin_free.c													\
			ft_strcmp.c

LIBFTOBJS =${LIBFTSRCS:.c=.o}

BONUSSRCS	=

OBJS	= ${SRCS:.c=.o}

BONUSOBJS	= ${BONUSSRCS:.c=.o}

CC		= gcc

LIBFT	= ./libft/libft.a

CFLAGS	= -Wall -Wextra -Werror

LIBFT_DIR = ./libft

LIBS	= -L${LIBMLX_DIR} -lmlx -lXext -lX11 -lm -L${LIBFT_DIR} -lft

RM		= rm -f

${NAME}:	${LIBFT} ${MLXHEADER} ${LIBMLX} ${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBS}

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${LIBFT}:
	@make -sC ./libft -j

all:	${NAME}

bonus:

clean:
	 ${RM} ${OBJS} ${BONUSOBJS}

fclean:	clean
	${RM} ${NAME}

re:		fclean all

coffee:
	@clear
	@echo ""
	@echo "                   ("
	@echo "	                     )     ("
	@echo "               ___...(-------)-....___"
	@echo '           .-""       )    (          ""-.'
	@echo "      .-''''|-._             )         _.-|"
	@echo '     /  .--.|   `""---...........---""`   |'
	@echo "    /  /    |                             |"
	@echo "    |  |    |                             |"
	@echo "     \  \   |                             |"
	@echo "      '\ '\ |                             |"
	@echo "        '\ '|                             |"
	@echo "        _/ /\                             /"
	@echo "       (__/  \                           /"
	@echo '    _..---""` \                         /`""---.._'
	@echo " .-'           \                       /          '-."
	@echo ":               '-.__             __.-'              :"
	@echo ':                  ) ""---...---"" (                :'
	@echo "\'._                '"--...___...--"'              _.'"
	@echo '   \""--..__                              __..--""/'
	@echo "     '._     """----.....______.....----"""         _.'"
	@echo '         ""--..,,_____            _____,,..--"""'''
	@echo '                      """------"""'
	@sleep 0.5
	@clear
	@echo ""
	@echo "                 ("
	@echo "	                  )      ("
	@echo "               ___..(.------)--....___"
	@echo '           .-""       )   (           ""-.'
	@echo "      .-''''|-._      (       )        _.-|"
	@echo '     /  .--.|   `""---...........---""`   |'
	@echo "    /  /    |                             |"
	@echo "    |  |    |                             |"
	@echo "     \  \   |                             |"
	@echo "      '\ '\ |                             |"
	@echo "        '\ '|                             |"
	@echo "        _/ /\                             /"
	@echo "       (__/  \                           /"
	@echo '    _..---""` \                         /`""---.._'
	@echo " .-'           \                       /          '-."
	@echo ":               '-.__             __.-'              :"
	@echo ':                  ) ""---...---"" (                :'
	@echo "\'._                '"--...___...--"'              _.'"
	@echo '   \""--..__                              __..--""/'
	@echo "     '._     """----.....______.....----"""         _.'"
	@echo '         ""--..,,_____            _____,,..--"""'''
	@echo '                      """------"""'
	@sleep 0.5
	@clear
	@echo ""
	@echo "               ("
	@echo "	                  )     ("
	@echo "               ___..(.------)--....___"
	@echo '           .-""      )    (           ""-.'
	@echo "      .-''''|-._      (       )        _.-|"
	@echo '     /  .--.|   `""---...........---""`   |'
	@echo "    /  /    |                             |"
	@echo "    |  |    |                             |"
	@echo "     \  \   |                             |"
	@echo "      '\ '\ |                             |"
	@echo "        '\ '|                             |"
	@echo "        _/ /\                             /"
	@echo "       (__/  \                           /"
	@echo '    _..---""` \                         /`""---.._'
	@echo " .-'           \                       /          '-."
	@echo ":               '-.__             __.-'              :"
	@echo ':                  ) ""---...---"" (                :'
	@echo "\'._                '"--...___...--"'              _.'"
	@echo '   \""--..__                              __..--""/'
	@echo "     '._     """----.....______.....----"""         _.'"
	@echo '         ""--..,,_____            _____,,..--"""'''
	@echo '                      """------"""'
	@sleep 0.5
	@clear
	@echo ""
	@echo "             (         ) "
	@echo "	              )        ("
	@echo "               ___)...----)----....___"
	@echo '           .-""      )    (           ""-.'
	@echo "      .-''''|-._      (       )        _.-|"
	@echo '     /  .--.|   `""---...........---""`   |'
	@echo "    /  /    |                             |"
	@echo "    |  |    |                             |"
	@echo "     \  \   |                             |"
	@echo "      '\ '\ |                             |"
	@echo "        '\ '|                             |"
	@echo "        _/ /\                             /"
	@echo "       (__/  \                           /"
	@echo '    _..---""` \                         /`""---.._'
	@echo " .-'           \                       /          '-."
	@echo ":               '-.__             __.-'              :"
	@echo ':                  ) ""---...---"" (                :'
	@echo "\'._                '"--...___...--"'              _.'"
	@echo '   \""--..__                              __..--""/'
	@echo "     '._     """----.....______.....----"""         _.'"
	@echo '         ""--..,,_____            _____,,..--"""'''
	@echo '                      """------"""'i

.PHONY:		all clean fclean re coffee bonus
