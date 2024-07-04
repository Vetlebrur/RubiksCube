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
    window.setBackgroundColor(Color::black);
    const auto start1{std::chrono::steady_clock::now()};
    Cube cube = Cube(cube_x, cube_y, cube_tile_size, cube_tile_padding);
  
    for (int i = 0; i < 1000000; i++){
        cube.move_B();
        cube.move_U();
        cube.move_R();
        cube.move_D();
    }
    cube.draw_cube(window);

    cube.draw_cube(window);
    const auto end1{std::chrono::steady_clock::now()};
    const std::chrono::duration<double> elapsed_seconds1{end1 - start1};
    std::cout << elapsed_seconds1.count()<<endl;
    const auto start2{std::chrono::steady_clock::now()};
    Cube3D cube3D = Cube3D(cube_x, cube_y, cube_tile_size, cube_tile_padding);

    for (int i = 0; i < 1000000; i++){
        cube3D.move_B();
        cube3D.move_U();
        cube3D.move_R();
        cube3D.move_D();
    }
    cube3D.geometricToFacelet();
    cube3D.draw(window);
    const auto end2{std::chrono::steady_clock::now()};
    const std::chrono::duration<double> elapsed_seconds2{end2 - start2};
    std::cout << elapsed_seconds2.count()<<endl;

    
    

    while(!window.should_close()) {
        window.setBackgroundColor(Color::black);
        cube3D.draw(window);
        cube3D.geometricToFacelet();
        
        window.next_frame();
    }
    return 0;
}
