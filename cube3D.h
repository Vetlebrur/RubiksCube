#pragma once
#include "AnimationWindow.h"
#include <unordered_map>
using namespace TDT4102;
using namespace std;

class Cube3D{
    private:
        std::unordered_map<int,Color> intToColorMap = {
        {0,Color::white},
        {1,Color::yellow},
        {2,Color::red},
        {3,Color::orange},
        {4,Color::green},
        {5,Color::blue}
    };

        int cube_x;
        int cube_y;
        int cube_tile_size;
        int cube_tile_padding;
        int cornersPermutation[8] = {0, 1, 2, 3, 4, 5, 6, 7};
        int edgesPermutation[12] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
        int cornersOrientation[8] = {0, 0, 0, 0, 0, 0, 0, 0};
        bool edgesOrientation[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; 

    public:
        Cube3D(int cube_x,int cube_y,int cube_tile_size, int cube_tile_padding): 
        cube_x{cube_x}, cube_y{cube_y}, cube_tile_size{cube_tile_size}, cube_tile_padding{cube_tile_padding} {};

        void swap_corners(int a,int b){
            swap(cornersPermutation[a],cornersPermutation[b]);
        }
        void swap_edges(int a,int b){
            swap(edgesPermutation[a],edgesPermutation[b]);
        }

        void draw(AnimationWindow& window);
        
        void move_U();
        void move_U_prime();
        void move_D();
        void move_D_prime();
        void move_L();
        void move_L_prime();
        void move_R();
        void move_R_prime();
        void move_F();
        void move_F_prime();
        void move_B();
        void move_B_prime();
        void move_x();
        void move_x_prime();
        void move_y();
        void move_y_prime();
        void move_z();
        void move_z_prime();
        
};