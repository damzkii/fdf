#include "mlx.h"
#include <math.h>
#include <stdio.h>

int draw_line(void *mlx_ptr, void *win_ptr, int beginX, int beginY, int endX, int endY, int color)
{
    double deltaX;
    double deltaY;
    double pixelX;
    double pixelY;
    int pixels;

    
    deltaX = endX - beginX;
    deltaY = endY - beginY;
    printf("%f\n", deltaX);
    printf("%f\n", deltaY);
    pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
    printf("%d\n", pixels);
    deltaX /= pixels;
    deltaY /= pixels;
    printf("%f\n", deltaX);
    printf("%f\n", deltaY);
    pixelX = beginX;
    pixelY = beginY;
    while(pixels)
    {
        mlx_pixel_put(mlx_ptr, win_ptr, pixelX, pixelY, color);
        pixelX += deltaX;
        pixelY += deltaY;
        --pixels;
    }
}

int main()
{
    void    *mlx_ptr;
    void    *win_ptr;
    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 1980, 1280, "Tutorial Window");
    draw_line(mlx_ptr, win_ptr, 1980, 1080, 0, 0, 0xFFFFFF);
    mlx_loop(mlx_ptr);
}