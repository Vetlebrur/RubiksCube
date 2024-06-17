#include "cube3D.h"


/*
int cornersPermutation[] = {0, 1, 2, 3, 4, 5, 6, 7};
int edgesPermutation[] = {0, 1, 2, 3, 4, 5, 6, 7};
int cornersOrientation[] = {0, 0, 0, 0, 0, 0, 0, 0};
int edgesOrientation[] = {0, 0, 0, 0, 0, 0, 0, 0}; 

        Y
  O   B   R   G
        W
*/

void Cube3D::draw(AnimationWindow& window){
    // Draw the cube
    int start_x = 0;
    int start_y = 0;
    Color sideColors[3] = {Color::white,Color::white,Color::white};
    for (int i=0; i<8;i++){ // draw corners
        switch (cornersPermutation[i]){
            case 0://WOG
                Color sideColors[3] = {Color::white,Color::green,Color::orange};
                break;
            case 1://WOB
                Color sideColors[3] = {Color::white,Color::orange,Color::blue};
                break;
            case 2://WRB
                Color sideColors[3] = {Color::white,Color::blue,Color::red};
                break;
            case 3://WGR
                Color sideColors[3] = {Color::white,Color::red,Color::green};
                break;
            case 4://YOG
                Color sideColors[3] = {Color::yellow,Color::orange,Color::green};
                break;
            case 5://YBO
                Color sideColors[3] = {Color::yellow,Color::blue,Color::orange};
                break;
            case 6://YRB
                Color sideColors[3] = {Color::yellow,Color::red,Color::blue};
                break;
            case 7://YGR
                Color sideColors[3] = {Color::yellow,Color::green,Color::red};
                break;
        }
        


        switch (0){
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
                    Color::white);
            }
        }
    }
}

void Cube3D::move_R(){
    swap_corners(6,7);
    swap_corners(2,6);
    swap_corners(2,3);

    swap_edges(6,10);
    swap_edges(6,2);
    swap_edges(2,7);

    cornersOrientation[2] = (cornersOrientation[2]+1)%3;
    cornersOrientation[3] = (cornersOrientation[3]+2)%3;
    cornersOrientation[6] = (cornersOrientation[6]+2)%3;
    cornersOrientation[7] = (cornersOrientation[7]+1)%3;

    edgesOrientation[2] = !edgesOrientation[2];
    edgesOrientation[6] = !edgesOrientation[6];
    edgesOrientation[7] = !edgesOrientation[7];
    edgesOrientation[11] = !edgesOrientation[11];

}