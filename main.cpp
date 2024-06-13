#include "std_lib_facilities.h"
#include "AnimationWindow.h"
#include "cube.h"
/*
TODO:
Make a conversion from string to cube moves, that it then executes.
Make some of the moves as efficient as possible (R' x' mainly but maybe also z z'. All other moves apart from R and U might have better solutions as well),
    removing the need for multiple function calls
Introduce inputs for the user
Create a solver
Create an artificial intelligence that can be trained on solving the cube
*/
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
        window.setBackgroundColor(Color::black);
        cube.draw_cube(window);

        window.next_frame();
    }
    return 0;
}
