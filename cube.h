#pragma once
#include "AnimationWindow.h"
#include <unordered_map>
using namespace TDT4102;
using namespace std;
class Cube{
    std::unordered_map<int,Color> intToColorMap = {
        {0,Color::white},
        {1,Color::yellow},
        {2,Color::red},
        {3,Color::orange},
        {4,Color::green},
        {5,Color::blue}
    };

    private:
        int cube_x;
        int cube_y;
        int cube_tile_size;
        int cube_tile_padding;
        // 0 - white, 1 - yellow, 2 - red, 3 - orange, 4 - green, 5 - blue
        /*
             1
        3   5   2   4
             0
        */
        int cube[6][3][3] = {
            {   {0, 0, 0},
                {0, 0, 0},
                {0, 0, 0}},
            {   {1, 1, 1},
                {1, 1, 1},
                {1, 1, 1}},
            {   {2, 2, 2},
                {2, 2, 2},
                {2, 2, 2}},
            {   {3, 3, 3},
                {3, 3, 3},
                {3, 3, 3}},
            {   {4, 4, 4},
                {4, 4, 4},
                {4, 4, 4}},
            {   {5, 5, 5},
                {5, 5, 5},
                {5, 5, 5}}
        };
    public:
        Cube(int cube_x,int cube_y,int cube_tile_size, int cube_tile_padding): 
        cube_x{cube_x}, cube_y{cube_y}, cube_tile_size{cube_tile_size}, cube_tile_padding{cube_tile_padding}{};

        void draw_cube(TDT4102::AnimationWindow& window);


        void swap_face(int a,int b){
            swap(cube[a],cube[b]);
        }

        void rotate_face_clockwise(int a){
            swap(cube[a][0][0],cube[a][0][2]);//corners
            swap(cube[a][0][0],cube[a][2][0]);
            swap(cube[a][2][0],cube[a][2][2]);

            swap(cube[a][0][1],cube[a][1][2]);//edges
            swap(cube[a][0][1],cube[a][1][0]);
            swap(cube[a][1][0],cube[a][2][1]);
        }

        void rotate_face_counter_clockwise(int a){
            swap(cube[a][2][0],cube[a][2][2]);//corners
            swap(cube[a][0][0],cube[a][2][0]);
            swap(cube[a][0][0],cube[a][0][2]);
            
            swap(cube[a][1][0],cube[a][2][1]);//edges
            swap(cube[a][0][1],cube[a][1][0]);
            swap(cube[a][0][1],cube[a][1][2]);
        }


        void move_x(){
            rotate_face_clockwise(2);
            rotate_face_counter_clockwise(3);
            swap_face(5,1);
            swap_face(5,0);
            swap(cube[4][2][2],cube[0][0][0]);
            swap(cube[4][2][1],cube[0][0][1]);
            swap(cube[4][2][0],cube[0][0][2]);
            swap(cube[4][1][2],cube[0][1][0]);
            swap(cube[4][1][1],cube[0][1][1]);
            swap(cube[4][1][0],cube[0][1][2]);
            swap(cube[4][0][2],cube[0][2][0]);
            swap(cube[4][0][1],cube[0][2][1]);
            swap(cube[4][0][0],cube[0][2][2]);
        }
        void move_x_prime(){
            move_x();
            move_x();
            move_x();
        }
        void move_y(){
            rotate_face_clockwise(1);
            rotate_face_counter_clockwise(0);

            swap_face(5,3);
            swap_face(5,2);
            swap_face(2,4);
        }
        void move_y_prime(){
            rotate_face_clockwise(0);
            rotate_face_counter_clockwise(1);

            swap_face(5,2);
            swap_face(5,3);
            swap_face(3,4);
        }
        void move_z(){
           move_x();
           move_y();
           move_x_prime();
        }
        void move_z_prime(){
            move_x();
            move_y_prime();
            move_x_prime();
        }

        void move_R(){
            rotate_face_clockwise(2);

            swap(cube[5][0][2],cube[1][0][2]);
            swap(cube[5][1][2],cube[1][1][2]);
            swap(cube[5][2][2],cube[1][2][2]);

            swap(cube[5][0][2],cube[0][0][2]);
            swap(cube[5][1][2],cube[0][1][2]);
            swap(cube[5][2][2],cube[0][2][2]);

            swap(cube[0][0][2],cube[4][2][0]);
            swap(cube[0][1][2],cube[4][1][0]);
            swap(cube[0][2][2],cube[4][0][0]);
        }
        void move_R_prime(){
            move_R();
            move_R();
            move_R();
        }
        void move_U(){
            rotate_face_clockwise(1);
            swap(cube[5][0],cube[3][0]);
            swap(cube[5][0],cube[2][0]);
            swap(cube[2][0],cube[4][0]);
        }
        void move_U_prime(){
            rotate_face_counter_clockwise(1);
            swap(cube[5][0],cube[2][0]);
            swap(cube[5][0],cube[3][0]);
            swap(cube[3][0],cube[4][0]);
        }
        void move_L(){
            move_y();
            move_y();
            move_R();
            move_y();
            move_y();
        }
        void move_L_prime(){
            move_y();
            move_y();
            move_R_prime();
            move_y();
            move_y();
        }
        void move_F(){
            move_y_prime();
            move_R();
            move_y();
        }
        void move_F_prime(){
            move_y_prime();
            move_R_prime();
            move_y();
        }
        void move_D(){
            move_x();
            move_x();
            move_U();
            move_x();
            move_x();
        }
        void move_D_prime(){
            move_x();
            move_x();
            move_U_prime();
            move_x();
            move_x();
        }
        void move_B(){
            move_y();
            move_R();
            move_y_prime();
        }
        void move_B_prime(){
            move_y();
            move_R_prime();
            move_y_prime();
        }
};