CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror -Imlx
NAME			=	cub3D
RM				=	rm -rf
LMLX_M			=	-Lmlx -lmlx -framework OpenGL -framework AppKit
SOURCE			=	main.c begin_reset.c top_map_check.c \
					trans_image_rgb.c frgb_control.c crgb_control.c  \
					location_init.c gmap_int.c begin_reset2.c\
					map_space_player_count.c wall_image_making.c \
					button_assignment.c game_build.c key_move.c raycasting_init.c \
					libft.c libft2.c libft3.c libft4.c \
					map_control.c map_control2.c map_control3.c map_control4.c \
					map_control5.c

MLXM	=	 $(C_MLXD) $(LMLX_M)

OBJECT			=	$(SOURCE:.c=.o)

C_MLXC			=	./mlx/
C_MLXD			=	./mlx/libmlx.a

all: 				$(NAME)

$(NAME):			$(OBJECT)
					@echo "$(YELLOW)Compiling...$(END)"
					@$(MAKE) -C $(C_MLXC)
					@$(CC) $(CFLAGS) $(OBJECT) $(MLXM) -o ${NAME}
					@echo "$(GREEN)===> Game ready to start <===$(END)"

%.o:		%.c
					@echo "$(YELLOW)Compiling...$(END)"
					$(CC) -c $(CFLAGS) -o $@ $<
					@printf "$(GREEN)"

clean:
					$(MAKE) -C $(C_MLXC) clean
					${RM} $(OBJECT)

fclean: 			clean
					$(MAKE) -C $(C_MLXC) clean
					$(RM) $(C_MLXD)
					${RM} $(NAME)
					@echo "$(RED)===> Cub3D & Mlx Cleaned <===$(END)"
					@echo "$(RED)===> DONE <===$(END)"

re:					fclean $(NAME)

.PHONY:				all clean fclean re bonus

