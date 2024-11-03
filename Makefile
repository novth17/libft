NAME = libft.a

CC = cc

CFLAG = -Wall -Wextra -Werror

SOURCES =	ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_tolower.c \
			ft_putchar_fd.c \
			ft_toupper.c

OBJS = $(SOURCES:%.c=%.o)
$(info "OBJS = $(OBJS)")

all: $(NAME)

$(NAME): $(OBJS)
	@ar crs $(NAME) $(OBJS)

%.o: %.c
	@echo "Now compiling $< to make $@" 
	$(CC) $(CFLAG) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: $(fclean) all
