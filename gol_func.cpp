#include "gol_func.hpp"

std::vector<std::vector<int>> makeGrid(int size0, int size1, int population){
    
    std::vector<std::vector<int>> grid(size0, std::vector<int> (size1));

    //populate the elements of the grid randomly with zeros and ones if population parameter = 1.
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0,1);

    if (population==1){
        for(int i=0; i<size0; ++i){
            for(int j=0; j<size1; ++j){
                grid[i][j] = distrib(gen);
            }
        }
    }


    return grid;
}


int neighbourCount(std::vector<std::vector<int>> &grid, int position0, int position1){
    // Counts the neightbours of the cell at position0 and position1
    int totalNeighbours{0};

    totalNeighbours = 
    grid[(position0+1)%grid.size()][position1] 
    + grid[(position0-1+grid.size())%grid.size()][position1] 
    + grid[position0][(position1+1)%grid[0].size()] 
    + grid[position0][(position1-1+grid[0].size())%grid[0].size()]
    
    + grid[(position0+1)%grid.size()][(position1-1+grid[0].size())%grid[0].size()]
    + grid[(position0+1)%grid.size()][(position1+1)%grid[0].size()]
    + grid[(position0-1+grid.size())%grid.size()][(position1+1)%grid[0].size()]
    + grid[(position0-1+grid.size())%grid.size()][(position1-1+grid[0].size())%grid[0].size()]
    ;

    return totalNeighbours;


}

void simulation(std::vector<std::vector<int>> &grid){

    std::vector<std::vector<int>> newGrid(grid.size(), std::vector<int> (grid[0].size())); 
    newGrid = grid;

    
    // int const rows = grid.size();
    // int const cols = grid[0].size();
    

    //We go through each cell and apply the rules of the game. We store the new values in a new grid and return it.
    for(int i{0}; i<grid.size();++i){
        for(int j{0}; j<grid[0].size();++j){
            int neighbours = neighbourCount(grid, i, j);

            if (grid[i][j] == 1){
                if ( ( (2 <= neighbours) && (neighbours <= 3)) ){
                    newGrid[i][j] = 1;
                }
                else if ((neighbours > 3) || (neighbours < 2)){
                    newGrid[i][j] = 0;
                }
                
            }
            else if (grid[i][j] == 0){
                if (neighbours == 3){
                    newGrid[i][j] = 1;
                }
            }
            
         }
    }


    grid = newGrid;
    
    // return grid;

}