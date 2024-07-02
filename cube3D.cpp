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

void Cube3D::geometricToFacelet(){
    //corners
    //corner 1
    cubeString[51] = static_cast<char>(corners[cornersPermutation[0]][cornersOrientation[0]]+48);
    cubeString[44] = static_cast<char>(corners[cornersPermutation[0]][(cornersOrientation[0]+1)%3]+48);
    cubeString[15] = static_cast<char>(corners[cornersPermutation[0]][(cornersOrientation[0]+2)%3]+48);
    //corner 2
    cubeString[45] = static_cast<char>(corners[cornersPermutation[1]][cornersOrientation[1]]+48);
    cubeString[17] = static_cast<char>(corners[cornersPermutation[1]][(cornersOrientation[1]+1)%3]+48);
    cubeString[24] = static_cast<char>(corners[cornersPermutation[1]][(cornersOrientation[1]+2)%3]+48);
    //corner 3
    cubeString[47] = static_cast<char>(corners[cornersPermutation[2]][cornersOrientation[2]]+48);
    cubeString[26] = static_cast<char>(corners[cornersPermutation[2]][(cornersOrientation[2]+1)%3]+48);
    cubeString[33] = static_cast<char>(corners[cornersPermutation[2]][(cornersOrientation[2]+2)%3]+48);
    //corner 4
    cubeString[53] = static_cast<char>(corners[cornersPermutation[3]][(cornersOrientation[3])]+48);
    cubeString[35] = static_cast<char>(corners[cornersPermutation[3]][(cornersOrientation[3]+1)%3]+48);
    cubeString[42] = static_cast<char>(corners[cornersPermutation[3]][(cornersOrientation[3]+2)%3]+48);
    //corner 5
    cubeString[0] = static_cast<char>(corners[cornersPermutation[4]][(cornersOrientation[4])]+48);
    cubeString[9] = static_cast<char>(corners[cornersPermutation[4]][(cornersOrientation[4]+1)%3]+48);
    cubeString[38] = static_cast<char>(corners[cornersPermutation[4]][(cornersOrientation[4]+2)%3]+48);
    //corner 6
    cubeString[6] = static_cast<char>(corners[cornersPermutation[5]][(cornersOrientation[5])]+48);
    cubeString[18] = static_cast<char>(corners[cornersPermutation[5]][(cornersOrientation[5]+1)%3]+48);
    cubeString[11] = static_cast<char>(corners[cornersPermutation[5]][(cornersOrientation[5]+2)%3]+48);
    //corner 7
    cubeString[8] = static_cast<char>(corners[cornersPermutation[6]][(cornersOrientation[6])]+48);
    cubeString[27] = static_cast<char>(corners[cornersPermutation[6]][(cornersOrientation[6]+1)%3]+48);
    cubeString[20] = static_cast<char>(corners[cornersPermutation[6]][(cornersOrientation[6]+2)%3]+48);
    //corner 8
    cubeString[2] = static_cast<char>(corners[cornersPermutation[7]][(cornersOrientation[7])]+48);
    cubeString[36] = static_cast<char>(corners[cornersPermutation[7]][(cornersOrientation[7]+1)%3]+48);
    cubeString[29] = static_cast<char>(corners[cornersPermutation[7]][(cornersOrientation[7]+2)%3]+48);
    
    //edges
    //edge 1
    cubeString[48] = static_cast<char>(edges[edgesPermutation[0]][edgesOrientation[0]]+48);
    cubeString[16] = static_cast<char>(edges[edgesPermutation[0]][(edgesOrientation[0]+1)%2]+48);
    //edge 2
    cubeString[46] = static_cast<char>(edges[edgesPermutation[1]][edgesOrientation[1]]+48);
    cubeString[25] = static_cast<char>(edges[edgesPermutation[1]][(edgesOrientation[1]+1)%2]+48);
    //edge 3
    cubeString[50] = static_cast<char>(edges[edgesPermutation[2]][edgesOrientation[2]]+48);
    cubeString[34] = static_cast<char>(edges[edgesPermutation[2]][(edgesOrientation[2]+1)%2]+48);
    //edge 4
    cubeString[52] = static_cast<char>(edges[edgesPermutation[3]][edgesOrientation[3]]+48);
    cubeString[43] = static_cast<char>(edges[edgesPermutation[3]][(edgesOrientation[3]+1)%2]+48);

    //edge 5
    cubeString[12] = static_cast<char>(edges[edgesPermutation[4]][edgesOrientation[4]]+48);
    cubeString[41] = static_cast<char>(edges[edgesPermutation[4]][(edgesOrientation[4]+1)%2]+48);
    //edge 6
    cubeString[21] = static_cast<char>(edges[edgesPermutation[5]][edgesOrientation[5]]+48);
    cubeString[14] = static_cast<char>(edges[edgesPermutation[5]][(edgesOrientation[5]+1)%2]+48);
    //edge 7
    cubeString[23] = static_cast<char>(edges[edgesPermutation[6]][edgesOrientation[6]]+48);
    cubeString[30] = static_cast<char>(edges[edgesPermutation[6]][(edgesOrientation[6]+1)%2]+48);
    //edge 8
    cubeString[39] = static_cast<char>(edges[edgesPermutation[7]][edgesOrientation[7]]+48);
    cubeString[32] = static_cast<char>(edges[edgesPermutation[7]][(edgesOrientation[7]+1)%2]+48);

    //edge 9
    cubeString[3] = static_cast<char>(edges[edgesPermutation[8]][edgesOrientation[8]]+48);
    cubeString[10] = static_cast<char>(edges[edgesPermutation[8]][(edgesOrientation[8]+1)%2]+48);
    //edge 10
    cubeString[7] = static_cast<char>(edges[edgesPermutation[9]][edgesOrientation[9]]+48);
    cubeString[19] = static_cast<char>(edges[edgesPermutation[9]][(edgesOrientation[9]+1)%2]+48);
    //edge 11
    cubeString[5] = static_cast<char>(edges[edgesPermutation[10]][edgesOrientation[10]]+48);
    cubeString[28] = static_cast<char>(edges[edgesPermutation[10]][(edgesOrientation[10]+1)%2]+48);
    //edge 12
    cubeString[1] = static_cast<char>(edges[edgesPermutation[11]][edgesOrientation[11]]+48);
    cubeString[37] = static_cast<char>(edges[edgesPermutation[11]][(edgesOrientation[11]+1)%2]+48);

}

void Cube3D::move_R(){
    swap_corners(6,7);
    swap_corners(2,6);
    swap_corners(2,3);

    swap_edges(7,2);
    swap_edges(7,10);
    swap_edges(6,10);

    cornersOrientation[cornersPermutation[2]] = (cornersOrientation[cornersPermutation[2]]+1)%3;
    cornersOrientation[cornersPermutation[3]] = (cornersOrientation[cornersPermutation[3]]+2)%3;
    cornersOrientation[cornersPermutation[6]] = (cornersOrientation[cornersPermutation[6]]+2)%3;
    cornersOrientation[cornersPermutation[7]] = (cornersOrientation[cornersPermutation[7]]+1)%3;

    //edgesOrientation[edgesPermutation[2]] = !edgesOrientation[2]; only change orientation on F or B moves
    //edgesOrientation[edgesPermutation[6]] = !edgesOrientation[6];
    //edgesOrientation[edgesPermutation[7]] = !edgesOrientation[7];
    //edgesOrientation[edgesPermutation[10]] = !edgesOrientation[10];
}
void Cube3D::move_U(){
    swap_corners(4,5);
    swap_corners(5,6);
    swap_corners(6,7);

    swap_edges(8,9);
    swap_edges(9,10);
    swap_edges(10,11);

    //corner orientation stays the same unless it is not pointing up
}

void Cube3D::move_B(){
    swap_corners(4,7);
    swap_corners(7,3);
    swap_corners(3,0);

    swap_edges(11,7);
    swap_edges(7,3);
    swap_edges(3,4);

    cornersOrientation[cornersPermutation[0]] = (cornersOrientation[cornersPermutation[0]]+2)%3;
    cornersOrientation[cornersPermutation[3]] = (cornersOrientation[cornersPermutation[3]]+1)%3;
    cornersOrientation[cornersPermutation[4]] = (cornersOrientation[cornersPermutation[4]]+1)%3;
    cornersOrientation[cornersPermutation[7]] = (cornersOrientation[cornersPermutation[7]]+2)%3;

    edgesOrientation[edgesPermutation[3]] = !edgesOrientation[edgesPermutation[3]];
    edgesOrientation[edgesPermutation[4]] = !edgesOrientation[edgesPermutation[4]];
    edgesOrientation[edgesPermutation[7]] = !edgesOrientation[edgesPermutation[7]];
    edgesOrientation[edgesPermutation[11]] = !edgesOrientation[edgesPermutation[11]];

}