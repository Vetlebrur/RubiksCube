#pragma once
#include "AnimationWindow.h"
#include <unordered_map>
#include <string>
using namespace TDT4102;
using namespace std;

class Cube3D{
    private:
        std::unordered_map<char,Color> charToColorMap = {
        {'0',Color::yellow},
        {'1',Color::orange},
        {'2',Color::blue},
        {'3',Color::red},
        {'4',Color::green},
        {'5',Color::white}
        };

        int cube_x;
        int cube_y;
        int cube_tile_size;
        int cube_tile_padding;

        int cornersPermutation[8] = {0, 1, 2, 3, 4, 5, 6, 7};
        int cornersOrientation[8] = {0, 0, 0, 0, 0, 0, 0, 0};
        int corners[8][3] = {{5, 4, 1}, {5, 1, 2}, {5, 2, 3}, {5, 3, 4}, {0, 1, 4}, {0, 2, 1}, {0, 3, 2}, {0, 4, 3}};

        int edgesPermutation[12] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
        bool edgesOrientation[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; 
        int edges[12][2] = {{5, 1}, {5, 2}, {5, 3}, {5, 4}, {4, 1}, {2, 1}, {2, 3}, {4, 3}, {0, 1}, {0, 2}, {0, 3}, {0, 4}};

        string cubeString = "000000000111111111222222222333333333444444444555555555";

    public:
        Cube3D(int cube_x,int cube_y,int cube_tile_size, int cube_tile_padding): 
        cube_x{cube_x}, cube_y{cube_y}, cube_tile_size{cube_tile_size}, cube_tile_padding{cube_tile_padding} {};


        void swap_corners(int a,int b){
            swap(cornersPermutation[a],cornersPermutation[b]);
        }
        void swap_edges(int a,int b){
            swap(edgesPermutation[a],edgesPermutation[b]);
        }

        void twist_corner(int cornerIndex, int amount){
            cornersOrientation[cornersPermutation[cornerIndex]] = (cornersOrientation[cornersPermutation[cornerIndex]] + amount) % 3;
        }
        void flip_edge(int cornerIndex){
            edgesOrientation[edgesPermutation[cornerIndex]] = !edgesOrientation[edgesPermutation[cornerIndex]];
        }

        void geometricToFacelet();

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