#include "minilibx-linux/mlx_int.h"
#include "minilibx-linux/mlx.h"
#include <stdio.h>

int check_hook2(int button, void *param)
{
    if (button == 2)
        mlx_loop_end(param);
}

int check_hook(int key, void *param)
{
    printf("Key (%c) code = %d\n", key, key);
    if (key == 'e')
        mlx_loop_end(param);
    return (0);
}

int main()
{
    void *mlx_ptr;
    void *window;
    int status = 1;

    mlx_ptr = mlx_init();
    window = mlx_new_window(mlx_ptr, 23 * 10, 23 * 7, "so_long");
    mlx_key_hook(window, check_hook, mlx_ptr);
    mlx_loop_hook(window, check_hook2, mlx_ptr);
    mlx_loop(mlx_ptr);
    printf("Fin de programa\n");
}