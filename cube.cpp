#include "cube.h"

/*Draws a representation of the given Cube object in the window*/
void Cube::draw_cube(TDT4102::AnimationWindow& window){
    
    int start_x = 0;
    int start_y = 0;
    for (int face=0; face<6; face++){
        switch (face){
            case 0://Bottom
                start_x = cube_x+cube_tile_size*3+cube_tile_padding*3;
                start_y = cube_y+cube_tile_size*6+cube_tile_padding*6;
                break;
            case 1://Top
                start_x = cube_x+cube_tile_size*3+cube_tile_padding*3;
                start_y = cube_y;
                break;
            case 2: //Left
                start_x = cube_x+cube_tile_size*6+cube_tile_padding*6;
                start_y = cube_y+cube_tile_size*3+cube_tile_padding*3;
                break;
            case 3://Right
                start_x = cube_x;
                start_y = cube_y+cube_tile_size*3+cube_tile_padding*3;
                break;
            case 4://back
                start_x = cube_x+cube_tile_size*9+cube_tile_padding*9;
                start_y = cube_y+cube_tile_size*3+cube_tile_padding*3;
                break;
            case 5: //Front
                start_x = cube_x+cube_tile_size*3+cube_tile_padding*3;
                start_y = cube_y+cube_tile_size*3+cube_tile_padding*3;
                break;
        }
        for (int row=0; row<3; row++){
            for (int tile = 0; tile<3;tile++){
                window.draw_rectangle(
                    {start_x+tile*cube_tile_size+tile*cube_tile_padding,start_y+row*cube_tile_size+row*cube_tile_padding},
                    cube_tile_size,
                    cube_tile_size,
                    intToColorMap.at(cube[face][row][tile]));
            }
        }
    }
}