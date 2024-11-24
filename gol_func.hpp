#include <vector>
#include <bitset>
#include <random>

std::vector<std::vector<int>> makeGrid(int size0, int size1, const int liveStates, int population);


int neighbourCount(std::vector<std::vector<int>> &grid, int position0, int position1, const int liveStates);


void simulation(std::vector<std::vector<int>> &grid, const int liveStates);