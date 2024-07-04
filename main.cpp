#include "std_lib_facilities.h"
#include "AnimationWindow.h"
#include "cube.h"
#include "cube3D.h"
/*
TODO:
MAP 3D CUBE ONTO 2D PLANE GRAPHICS
Make a conversion from string to cube moves, that it then executes.
Make some of the moves as efficient as possible (R' x' mainly but maybe also z z'. All other moves apart from R and U might have better solutions as well),
    removing the need for multiple function calls
Introduce inputs for the user
Create a scrambler
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
    Cube3D cube3D = Cube3D(cube_x, cube_y, cube_tile_size, cube_tile_padding);
    // U' D' L' B' F' R'
    // cube.move_U_prime();
    // cube.move_D_prime();
    // cube.move_L_prime();
    // cube.move_B_prime();
    // cube.move_F_prime();
    // cube.move_R_prime();
    
    cube3D.move_B();
    //cube3D.move_U();
    cube3D.move_U();
    //cube3D.move_R();
    cube3D.move_R();
    cube3D.move_D();

    while(!window.should_close()) {
        window.setBackgroundColor(Color::black);
        cube3D.draw(window);
        cube3D.geometricToFacelet();
        
        window.next_frame();
    }
    return 0;
}
