#include "mlx.h" // Include the mlx library

int main(void)
{
    void *mlx; // The magical mlx pointer
    void *win; // The window pointer
    void *img; // The sprite image pointer
    int width; // Width of the sprite
    int height; // Height of the sprite
    int frame = 1; // Current frame of the sprite animation

    // Initialize mlx
    mlx = mlx_init();

    // Create a window
    win = mlx_new_window(mlx, 800, 600, "Sprite Animation Ritual");

    // The animation loop
    while (1) {
        // Load the current frame of your sprite animation
        char frame_filename[20]; // Assuming frame filenames are like "frame1.xpm", "frame2.xpm", etc.
        sprintf(frame_filename, "bonus/textures_bonus/frame_%d.xpm", frame);
        img = mlx_xpm_file_to_image(mlx, frame_filename, &width, &height);

        // Display the sprite on the window
        mlx_put_image_to_window(mlx, win, img, 100, 100);

        // Update the frame for the next iteration
        frame = (frame % 5) + 1; // Change frame from 1 to NUM_FRAMES and loop back

        // Adjust the frame rate for your desired animation speed
        usleep(100000); // Sleep for 0.1 seconds (adjust as needed)
    }

    return 0;
}