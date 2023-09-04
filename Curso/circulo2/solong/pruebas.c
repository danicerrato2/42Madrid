#include "mlx.h"

int main()
{
    void *mlx;
    void *window;
    void *floor;
    void *stairs;
    void *mudkip;
    int size = 46;

    mlx = mlx_init();
    window = mlx_new_window(mlx, 2 * size, 2 * size, "pruebas");
    floor = mlx_xpm_file_to_image(mlx, "textures/Floor.xpm", &size, &size);
    stairs = mlx_xpm_file_to_image(mlx, "textures/Stairs.xpm", &size, &size);
    mudkip = mlx_xpm_file_to_image(mlx, "Mudkip.xpm", &size, &size);

    mlx_put_image_to_window(mlx, window, floor, 0, 0);
    mlx_put_image_to_window(mlx, window, stairs, size, size);
    mlx_put_image_to_window(mlx, window, mudkip, 0, size);
    mlx_put_image_to_window(mlx, window, mudkip, 0, 0);
    mlx_put_image_to_window(mlx, window, mudkip, size, size);

    mlx_loop(mlx);

    return (0);
}