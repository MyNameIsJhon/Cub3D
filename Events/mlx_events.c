#include <mlx.h>
#include "libft.h"
#include "list.h"
#include "mlx_events.h"


int close_image(int keycode, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	
}


int print_keycode(int keycode, t_vars *vars)
{
	ft_printf("%d\n", keycode);
}

int affiche_message(int x, int y, t_vars *vars)
{
	ft_printf("La souris est sur la fenêtre en position (%d, %d)\n", x, y);
}

int affiche(int keycode, t_vars *vars)
{
	ft_putstr("Vous venez de cliquer sur une touche de votre clavier \n");
}

int click_droit(int button, int x, int y, void *param)
{
	if(button == 3 || button == 1)
	{
		ft_printf("Votre sourie est dans la position x=%d, y=%d \n", x, y);
	}
}


int minilibx_onkeypress(int keycode, t_vars *vars)// tout ce qui vas se passer en cas d'une touche touchée
{
	ft_printf("%d\n", keycode);
	
	if(keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
}