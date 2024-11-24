#include "gol_func.hpp"

// updating to polylife
// grid cells have values in {0,1,2}

std::vector<std::vector<int>> makeGrid(int size0, int size1, const int liveStates, int population){
    
    std::vector<std::vector<int>> grid(size0, std::vector<int> (size1));

    //populate the elements of the grid randomly with zeros and ones if population parameter = 1.
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0,liveStates);

    if (population==1){
        for(int i=0; i<size0; ++i){
            for(int j=0; j<size1; ++j){
                grid[i][j] = distrib(gen);
            }
        }
    }


    return grid;
}


int neighbourCount(std::vector<std::vector<int>> &grid, int position0, int position1, const int liveStates){
    // Counts the neightbours of the cell at position0 and position1
    int totalNeighbours{0};

    totalNeighbours = 
    ( ( grid[(position0+1)%grid.size()][position1]  == liveStates ) ? 1:0)
    + ((grid[(position0-1+grid.size())%grid.size()][position1] == liveStates) ? 1:0)
    + ((grid[position0][(position1+1)%grid[0].size()] == liveStates) ? 1:0)
    + ((grid[position0][(position1-1+grid[0].size())%grid[0].size()] == liveStates) ? 1:0)
    
    + ((grid[(position0+1)%grid.size()][(position1-1+grid[0].size())%grid[0].size()] == liveStates) ? 1:0)
    + ((grid[(position0+1)%grid.size()][(position1+1)%grid[0].size()] == liveStates) ? 1:0)
    + ((grid[(position0-1+grid.size())%grid.size()][(position1+1)%grid[0].size()] == liveStates) ? 1:0)
    + ((grid[(position0-1+grid.size())%grid.size()][(position1-1+grid[0].size())%grid[0].size()] == liveStates) ? 1:0)
    ;
    
    return totalNeighbours;


}

void simulation(std::vector<std::vector<int>> &grid, const int liveStates){

    std::vector<std::vector<int>> newGrid(grid.size(), std::vector<int> (grid[0].size())); 
    newGrid = grid;

    
    // int const rows = grid.size();
    // int const cols = grid[0].size();
    

    //We go through each cell and apply the rules of the game. We store the new values in a new grid and return it.
    for(int i{0}; i < grid.size(); ++i){
        for(int j{0}; j < grid[0].size(); ++j){
            // int neighbours = neighbourCount(grid, i, j, liveStates);

            // If the grid is of type liveState=1, we count its neighbours that have liveState=1
            if (grid[i][j] == 1){
                int neighbourOne = neighbourCount(grid, i, j, 1);
                if ( ( (2 <= neighbourOne) && (neighbourOne <= 3)) ){
                    newGrid[i][j] = 1;
                }
                else if ((neighbourOne > 3) || (neighbourOne < 2)){
                    newGrid[i][j] = 0;
                }
                
            }
            // then we do the same for other liveStates
            else if (grid[i][j] == 2){
                int neighbourTwo = neighbourCount(grid, i, j, 2);
                if ( ( (2 <= neighbourTwo) && (neighbourTwo <= 3)) ){
                    newGrid[i][j] = 2;
                }
                else if ((neighbourTwo > 3) || (neighbourTwo < 2)){
                    newGrid[i][j] = 0;
                }
                
            }
            
            else if (grid[i][j] == 0){
                if (neighbourCount(grid,i,j,1) == 3){
                    newGrid[i][j] = 1;
                }
                else if (neighbourCount(grid,i,j,2) == 3){
                    newGrid[i][j]=2;
                }
            }
            
         }
    }


    grid = newGrid;
    
    // return grid;

}