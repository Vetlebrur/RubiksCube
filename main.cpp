#include "std_lib_facilities.h"
#include "AnimationWindow.h"
#include "cube.h"

constexpr int window_size = 1024;
constexpr int cube_x = 100;
constexpr int cube_y = 100;
constexpr int cube_tile_size = 50;
constexpr int cube_tile_padding = 5;
int main() {
    TDT4102::AnimationWindow window(100,100,1024,1024);
    Cube cube = Cube(cube_x, cube_y, cube_tile_size, cube_tile_padding);
    // U' D' L' B' F' R'
    // cube.move_U_prime();
    // cube.move_D_prime();
    // cube.move_L_prime();
    // cube.move_B_prime();
    // cube.move_F_prime();
    // cube.move_R_prime();
    
    
    while(!window.should_close()) {
        window.draw_rectangle({0,0}, window_size,window_size, Color::black);
        cube.draw_cube(window);

        window.next_frame();
    }
    return 0;
}
