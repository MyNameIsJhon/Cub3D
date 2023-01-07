#include "mlx_graph.h"
#include "list.h"
#include "libft.h"
#include <math.h>
#include <mlx.h>

int create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int get_b(int trgb)
{
	return (trgb & 0xFF);
}

int add_colors(double distance, int color)
{
	int tab[4] = {get_r(color), get_g(color), get_b(color), get_t(color)};

	int x = 0;

	if(distance > 1 )
		return 0;

	for(int w = 0 ; w < 3 ; w++)
	{
		if(x > tab[w])
			x = tab[w];
	}

	x = (255 - x) * distance;

	for(int w = 0 ; w < 3 ; w++)
	{
		if((tab[w] + x) > 255)
		{
			tab[w] = 255;
			continue;
		}
		tab[w] += x;
	}
	return create_trgb(tab[3], tab[0], tab[1], tab[2]);
}

int add_shade(double distance, int color)
{
    int value;
    int i = 0;

    double tab[4] = {get_r(color) /100, get_g(color)/ 100, get_b(color)/ 100, get_t(color)};
    double colors[4] = {get_r(color), get_g(color), get_b(color), get_t(color)};

    value = (int)(distance * 100);

    while(i < value)
    {
        for(int y = 0 ; y < 3 ; y++)
            colors[y] -= tab[y];
        i++;
    }

    return create_trgb(colors[3], colors[0], colors[1], colors[2]);
}

int invert_color(int color)
{
    int r = 255 - get_r(color);
    int g = 255 - get_g(color);
    int b = 255 - get_b(color);
    int a = get_t(color);

    return create_trgb(r, g, b, a);
}