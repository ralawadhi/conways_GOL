//run this code by executing clang++ -std=c++20  main.cpp gol_func.cpp -framework IOKit -framework Cocoa -framework OpenGL $(pkg-config --libs --cflags raylib) -o main
// then run the main file using ./main

#include <iostream>
#include <thread>
#include <chrono>
// #include <vector>
// #include <random>
#include "gol_func.hpp"
#include <raylib.h>





int main(){

    // Grid size
    const int size0{100};
    const int size1{100};
    // Number of simulation updates. Currently not used as the simulation runs indefinitely until the user closes the window.
    const int generations{500};

    

    // Defining colours to be used in Raylib.
    Color GREY = {29,29,29,255};
    Color BLUISH = {0, 106, 135,255};
    
    const int WINDOW_WIDTH = 1000;
    const int WINDOW_HEIGHT =1000;
    const int COLS =250;
    const int ROWS = 250;
    const int cellWidth = WINDOW_WIDTH/COLS;
    const int cellHeight = WINDOW_HEIGHT/ROWS;

    const int FPS = 30;

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Elementary Automaton");
    SetTargetFPS(FPS);

    // initialising the grid, choosing the number of live states, and randomly populating it(or not) with zeros and ones.
    std::vector<std::vector<int>> grid = makeGrid(ROWS,COLS, 2, 1);
    // optional Glider
    // grid[0][0] = 2;
    // grid[1][1] = 2;
    // grid[1][2] = 2;
    // grid[2][0] = 2;
    // grid[2][1] = 2;

    // grid[4][5] = 2;
    // grid[4][6] = 2;
    // grid[5][6] = 2;
    // grid[5][5] = 0;
    
    // The below commented code is for printing out the simulation into the terminal.

    // for(int gen=0; gen<generations;++gen){
    //    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    
    // for(int i=0; i<size0;++i){
    //     for(int j=0; j<size1; ++j){
    //         std::cout<< (grid[i][j] ? '#':' ')<<' ';
            
    //     }
    //     std::cout<<'\n';
    // }
    
    
    // std::cout<<"\n\n";
    // grid = simulation(grid);
    
    // }

    Vector2 position = {5.0,5.0};

while(WindowShouldClose() == false){
    
        
        
        
        // 1. Event Handling
        if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
            position = GetMousePosition();
            int posY = position.y/cellHeight;
            int posX = position.x/cellWidth;
            grid[posY][posX] = 1;
        }

        // 2. Update State
        // this function updates the grid according to the rules. Initialy I was returning 'grid' but now I have changed it to void
        simulation(grid, 1);
       
        // 3. Drawing
        BeginDrawing();
        ClearBackground(BLACK);
        for (int row=0;row<ROWS;row++){
            // if(eventTriggered(0.001)){
            // updateMat[row] = mat[row];}
            for (int col=0; col<COLS; col++){
                DrawRectangle(col*cellWidth,row*cellWidth,cellWidth-1,cellHeight-1, GREY );
                // DrawRectangle(col*cellWidth,row*cellWidth,cellWidth-1,cellHeight-1, grid[row][col] ? BLUISH:GREY );
                if (grid[row][col]==1){
                    DrawRectangle(col*cellWidth,row*cellWidth,cellWidth-1,cellHeight-1, BLUISH);

                }
                else if(grid[row][col]==2){
                    DrawRectangle(col*cellWidth,row*cellWidth,cellWidth-1,cellHeight-1, BEIGE);
                }
                // else{
                //     DrawRectangle(col*cellWidth,row*cellWidth,cellWidth-1,cellHeight-1, GREY);
                // }
            }
        }
            
            
            
            EndDrawing();
        

        }
    return 0;
    }
    

    
    