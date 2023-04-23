#include <iostream>
#include <string>

void Depth_First_Search(std::vector<std::vector<int>>& grid, int y_pos, int x_pos, int current_distance) {

	if (y_pos < 0 || x_pos < 0 || y_pos >= grid.size() || x_pos >= grid.size()) {
		return;
	}

	if (grid[y_pos][x_pos] <= current_distance || grid.back().back() <= current_distance) {
		return;
	}

	grid[y_pos][x_pos] = current_distance;

	Depth_First_Search(grid, y_pos+1, x_pos, current_distance + 1);
	Depth_First_Search(grid, y_pos, x_pos+1, current_distance + 1);
	Depth_First_Search(grid, y_pos-1, x_pos, current_distance + 1);
	Depth_First_Search(grid, y_pos, x_pos-1, current_distance + 1);
}

int path_finder(std::string maze) {
	
	int n = std::count(maze.begin(), maze.end(), '\n') + 1;
	std::vector<std::vector<int>> grid(n, std::vector<int>(n, n * n));

	int idx = 0;
	for (int i = 0; i < maze.length(); i++) {
		if (maze[i] == 'W') grid[idx / n][idx % n] = -1;
		if (maze[i] != '\n') idx++;
	}

	Depth_First_Search(grid, 0, 0, 0);

	return (grid.back().back() == (n *n)) ? -1 : grid.back().back();
}
