#ifndef MINIGRAPHX
#define MINIGRAPHX


#define PI 3.14


typedef struct s_data{

	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;

} t_data;

/*Colors place*/

int create_trgb(int t, int r, int g, int b);
int get_t(int trgb);
int get_r(int trgb);
int get_g(int trgb);
int get_b(int trgb);
int add_colors(double distance, int color);
int add_shade(double distance, int color);
int invert_color(int color);

/*Fin des fonctions liée au couleurs*/
/*ligne et forme geometric simpliste*/

void my_mlx_pixel_put(t_data *data, int x, int y, int color);
void draw_square(void *mlx, void *mlx_win, t_data img,int x, int y, int size, int color);
void draw_circle(t_data data, int xc, int yc, int radius, int color);
void draw_star(t_data data, int xc, int yc, int radius, int color);



#endif