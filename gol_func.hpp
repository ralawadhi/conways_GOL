#include <vector>
#include <bitset>
#include <random>

std::vector<std::vector<int>> makeGrid(int size0, int size1, int population);


int neighbourCount(std::vector<std::vector<int>> &grid, int position0, int position1);


std::vector<std::vector<int>> simulation(std::vector<std::vector<int>> &grid);