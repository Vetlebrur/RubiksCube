#include "cube3D.h"


/*
Facelet form for drawing the cube:
        Y
  O   B   R   G
        W

        0
    1   2   3   4
        5
    String of 54 characters, with num 0-5 representing the color of the sticker
    UUUUUUUUULLLLLLLLLFFFFFFFFFRRRRRRRRRBBBBBBBBBDDDDDDDDD
    000000000111111111222222222333333333444444444555555555

    Geometric for spacially mapping the cube:

    corners front and back:
   4    -   5       7   -   6     
    |          |        |         |  
    0    -   1       3   -   2

    sides front middle and back:

    x   9   x       8   x  10     x  11  x
    5   x   6       x   x   x      4   x   7
    x   1   x       0   x   2      x   3   x




*/
int cornersPermutation[] = {0, 1, 2, 3, 4, 5, 6, 7};
int edgesPermutation[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9 ,10, 11};
int cornersOrientation[] = {0, 0, 0, 0, 0, 0, 0, 0};
int edgesOrientation[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; 
string cubeString = "000000000111111111222222222333333333444444444555555555";


string Cube3D::cubeToFacelet(){
    return ".";
}

void Cube3D::draw(AnimationWindow& window){
    Color stickerColor = Color::white;
    for (int i = 0; i<54;i++){
        if (i <9){//top
            window.draw_rectangle(
            {cube_x+cube_tile_size*(i%3+3)+cube_tile_padding*(i%3+3),
            cube_y+cube_tile_size*(i/3)+cube_tile_padding*(i/3)},
            cube_tile_size,cube_tile_size,charToColorMap.at(cubeString.at(i)));
        }
        else if (i <18){//left
            window.draw_rectangle(
                {cube_x+cube_tile_size*(i%3)+cube_tile_padding*(i%3),
                cube_y+cube_tile_size*(i/3)+cube_tile_padding*(i/3)}
                ,cube_tile_size,cube_tile_size,charToColorMap.at(cubeString.at(i)));
        }
        else if (i <27){//front
            window.draw_rectangle(
                {cube_x+cube_tile_size*(i%3+3)+cube_tile_padding*(i%3+3),
                cube_y+cube_tile_size*(i/3-3)+cube_tile_padding*(i/3-3)}
                ,cube_tile_size,cube_tile_size,charToColorMap.at(cubeString.at(i)));
        }
        else if (i <36){//right
            window.draw_rectangle(
                {cube_x+cube_tile_size*(i%3+6)+cube_tile_padding*(i%3+6),
                cube_y+cube_tile_size*(i/3-6)+cube_tile_padding*(i/3-6)}
                ,cube_tile_size,cube_tile_size,charToColorMap.at(cubeString.at(i)));
        }
        else if (i <45){//back
            window.draw_rectangle(
                {cube_x+cube_tile_size*(i%3+9)+cube_tile_padding*(i%3+9),
                cube_y+cube_tile_size*(i/3-9)+cube_tile_padding*(i/3-9)}
                ,cube_tile_size,cube_tile_size,charToColorMap.at(cubeString.at(i)));
        }
        else if (i <54){//bottom
            window.draw_rectangle(
                {cube_x+cube_tile_size*(i%3+3)+cube_tile_padding*(i%3+3),
                cube_y+cube_tile_size*(i/3-9)+cube_tile_padding*(i/3-9)},
                cube_tile_size,cube_tile_size,charToColorMap.at(cubeString.at(i)));
        }
    }
}

void Cube3D::represent(AnimationWindow& window){
    // Draw the cube
    /*int start_x = 0;
    int start_y = 0;
    for (int i=0; i<8;i++){ // draw corners
        Color sideColors[3];
        switch (cornersPermutation[i]){
            case 0://WOG
                sideColors[3] = {Color::white,Color::green,Color::orange};
                break;
            case 1://WOB
                sideColors[3] = {Color::white,Color::orange,Color::blue};
                break;
            case 2://WRB
                sideColors[3] = {Color::white,Color::blue,Color::red};
                break;
            case 3://WGR
                sideColors[3] = {Color::white,Color::red,Color::green};
                break;
            case 4://YOG
                sideColors[3] = {Color::yellow,Color::orange,Color::green};
                break;
            case 5://YBO
                sideColors[3] = {Color::yellow,Color::blue,Color::orange};
                break;
            case 6://YRB
                sideColors[3] = {Color::yellow,Color::red,Color::blue};
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
    */
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