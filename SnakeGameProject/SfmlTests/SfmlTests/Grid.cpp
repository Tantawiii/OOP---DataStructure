#include "Grid.h"
// Function to read the grid from a file and store it in a 2D array and vector of empty positions
void Grid::getGrid(const string& path, char grid[10][10], vector<Position>& emptyPositions) {
    ifstream myfile(path, ios_base::in);

    if (!myfile.is_open()) {
        cerr << "Error: Could not open file." << endl;
        return;
    }

    string line;
    int row = 0;

    while (getline(myfile, line) && row < 10) {
        for (int col = 0; col < 10; col++) {
            if (line[col] == '0') {
                grid[row][col] = '0';
                emptyPositions.push_back({ row, col }); // Add empty position to the list
            }
            else {
                grid[row][col] = 'X';
            }
        }
        row++;
    }

    myfile.close();
}

// Function to draw the grid and walls based on the grid data
void Grid::drawWalls(RenderWindow& window, char grid[10][10], int cellSizeX, int cellSizeY) {
    for (int row = 0; row < 10; row++) {
        for (int col = 0; col < 10; col++) {
            RectangleShape cell(Vector2f(cellSizeX, cellSizeY));
            cell.setPosition(col * cellSizeX, row * cellSizeY);

            // Set dark grey background for all cells
            cell.setFillColor(Color(50, 50, 50)); // Dark grey background
            cell.setOutlineColor(Color::Black);   // Black border to create grid lines
            cell.setOutlineThickness(-1);         // Draw outline inward

            // If the cell is a wall ('X'), set it to blue color
            if (grid[row][col] == 'X') {
                cell.setFillColor(Color::Blue);
            }

            window.draw(cell);
        }
    }
}