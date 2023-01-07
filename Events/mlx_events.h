#ifndef MLX_EVENTS
#define MLX_EVENTS

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct s_vars{
	void *mlx;
	void *win;
}		t_vars;

int close_image(int keycode, t_vars *vars);
int print_keycode(int keycode, t_vars *vars);
int affiche(int keycode, t_vars *vars);
int affiche_message(int x, int y, t_vars *vars);
int click_droit(int button, int x, int y, void *param);
int minilibx_onkeypress(int keycode, t_vars *vars);// tout ce qui vas se passer en cas d'une touche touchée

#endif