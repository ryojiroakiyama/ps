NAME_G = gnl.a

NAME_U = utils.a

NAME_PS = push_swap

NAME_C = checker

SRCS_G = gnl/get_next_line.c gnl/get_next_line_utils.c

SRCS_U = srcs_utils/libfunc.c srcs_utils/operations1.c srcs_utils/operations2.c srcs_utils/operations3.c srcs_utils/tools_of_circl.c srcs_utils/tools_of_oplist.c srcs_utils/tools_to_finish.c

SRCS_PS = srcs_push_swap/main_ps.c srcs_push_swap/optimize_func1.c srcs_push_swap/optimize_func2.c srcs_push_swap/optimize_func3.c srcs_push_swap/tools_to_sort.c srcs_push_swap/tools_to_operations.c srcs_push_swap/utils.c

SRCS_C = srcs_checker/main_c.c

HEADER_G = gnl/get_next_line.h

HEADER = header.h

OBJS_G = ${SRCS_G:.c=.o}

OBJS_U = ${SRCS_U:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

all: ${NAME_PS}

${NAME_G}: ${OBJS_G} ${HEADER_G}
	ar rcs ${NAME_G} ${OBJS_G}

${NAME_U}: ${OBJS_U} ${HEADER}
	ar rcs ${NAME_U} ${OBJS_U}

${NAME_PS}: ${SRCS_PS} ${NAME_U} ${HEADER}
	${CC} ${CFLAGS} -o ${NAME_PS} ${SRCS_PS} ${NAME_U}

${NAME_C}: ${SRCS_C} ${NAME_G} ${NAME_U} ${HEADER}
	${CC} ${CFLAGS} -o ${NAME_C} ${SRCS_C} ${NAME_G} ${NAME_U}

bonus: ${NAME_C}

clean:
	${RM} ${OBJS_U} ${OBJS_G}

fclean: clean
	${RM} ${NAME_PS} ${NAME_U} ${NAME_C} ${NAME_G}

re: fclean all

.PHONY: all bonus clean fclean re
