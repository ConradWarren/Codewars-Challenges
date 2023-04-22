#include <iostream>
#include <string>

void depth_first_search(std::vector<std::vector<bool>>& grid, int y_pos, int x_pos) {

	if (x_pos < 0 || y_pos < 0 || x_pos >= grid.size() || y_pos >= grid.size()) {
		return;
	}

	if (grid[y_pos][x_pos]) {
		return;
	}

	grid[y_pos][x_pos] = true;

	depth_first_search(grid, y_pos+1, x_pos);
	depth_first_search(grid, y_pos, x_pos+1);
	depth_first_search(grid, y_pos-1, x_pos);
	depth_first_search(grid, y_pos, x_pos-1);
}

bool path_finder(std::string maze) {
	
	int n = std::count(maze.begin(), maze.end(), '\n') + 1;
	std::vector<std::vector<bool>> grid(n, std::vector<bool>(n, false));
	
	int idx = 0;
	for (int i = 0; i < maze.length(); i++) {
		if (maze[i] == 'W') grid[idx / n][idx % n] = true;
		if (maze[i] != '\n') idx++;
	}

	depth_first_search(grid, 0, 0);

	return grid.back().back();
}
