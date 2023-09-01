#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct s_vars 
{
    void *mlx_ptr;
    void *window;
    void *image;
} t_vars;

int close_window(int button, t_vars *vars)
{
    printf("Saliendo...\n");
    exit(0);
}

int check_key(int key, t_vars *vars)
{
    printf("Key code = %d\n", key);
    if (key == 53)
    {
        mlx_destroy_window(vars->mlx_ptr, vars->window);
        exit(0);
    }
    else if (key == 0)
        printf("Has pulsado la A\n");
    else if (key == 1)
        printf("Has pulsado la S\n");
    else if (key == 2)
        printf("Has pulsado la D\n");
    else if (key == 13)
        printf("Has pulsado la W\n");
    return (0);
}

int main()
{
    t_vars vars;
    int status = 1;
    int width = 46, height = 46;

    vars.mlx_ptr = mlx_init();
    vars.window = mlx_new_window(vars.mlx_ptr, 46 * 10, 46 * 7, "so_long");
    vars.image = mlx_xpm_file_to_image(vars.mlx_ptr, "textures/MudkipSouth1.xpm", &width, &height);
    mlx_put_image_to_window(vars.mlx_ptr, vars.window, vars.image, 0, 0);
    mlx_key_hook(vars.window, check_key, &vars);
    mlx_hook(vars.window, 17, 0, close_window, &vars);
    mlx_loop(vars.mlx_ptr);
}