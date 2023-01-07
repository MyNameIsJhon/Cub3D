#include "libft.h"
#include "list.h"
#include "mlx_graph.h"
#include <math.h>
#include <mlx.h>

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void draw_square(void *mlx, void *mlx_win, t_data img,int x, int y, int size, int color)
{
	int base_x;
	int base_y;

	base_x = x;
	base_y = y;

	while( x < base_x + size)
	{
		my_mlx_pixel_put(&img, x, y, color);
		my_mlx_pixel_put(&img, x, y + size, color);
		x++;
	}

	while( y  < base_y + size)
	{
		my_mlx_pixel_put(&img, x, y, color);
		my_mlx_pixel_put(&img, x - size, y, color);
		y++;
	}

}

void draw_circle(t_data data, int xc, int yc, int radius, int color)
{
    int x = 0;
    int y = radius;
    int p = 3 - (radius << 1);


    while (x <= y)
    {
        my_mlx_pixel_put(&data, xc + x, yc + y, color);
        my_mlx_pixel_put(&data, xc + y, yc + x, color);
        my_mlx_pixel_put(&data, xc - x, yc + y, color);
        my_mlx_pixel_put(&data, xc + y, yc - x, color);
        my_mlx_pixel_put(&data, xc - x, yc - y, color);
        my_mlx_pixel_put(&data, xc - y, yc - x, color);
        my_mlx_pixel_put(&data, xc + x, yc - y, color);
        my_mlx_pixel_put(&data, xc - y, yc + x, color);

        if (p < 0)
            p += (x++ << 2) + 6;
        else
            p += ((x++ - y--) << 2) + 10;
    }
}

void draw_star(t_data data, int xc, int yc, int radius, int color)
{
    int x = 0;
    int y = radius;
    int p = 3 - (radius << 1);


    while (y-- > x)
    {
        my_mlx_pixel_put(&data, xc + x, yc + y, color);
        my_mlx_pixel_put(&data, xc + y, yc + x, color);
        my_mlx_pixel_put(&data, xc - x, yc + y, color);
        my_mlx_pixel_put(&data, xc + y, yc - x, color);
        my_mlx_pixel_put(&data, xc - x, yc - y, color);
        my_mlx_pixel_put(&data, xc - y, yc - x, color);
        my_mlx_pixel_put(&data, xc + x, yc - y, color);
        my_mlx_pixel_put(&data, xc - y, yc + x, color);

        if (p < 0)
            p += (x++ << 2) + 6;
        else
            p += ((x++ - y--) << 2) + 10;
    }
}