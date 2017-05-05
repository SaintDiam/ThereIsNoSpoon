#include <iostream>
#include <string>
#include <vector>

using namespace std;

void findRight(vector<vector<int>>, int, int, int);
void findDown(vector<vector<int>>, int, int, int);

int main(void) {
    int rows, columns;
    cin >> columns >> rows; cin.ignore();
    
    vector<vector<int>> graph(rows, vector<int>(columns));
    
    // Fetch grid
    for (int i = 0; i < rows; i++) {
        int counter = 0;
        string line;
        getline(cin, line);
        
        for(char & c : line) {
            graph[i][counter] = (c == '0' ? 1 : 0); // 1 = Valid Node, 0 = Empty Node
            counter++;
        }
    }
    
    // Check each cell
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (graph[i][j] == 1) {
                cout << j << " " << i << " ";
                findRight(graph, i, j, columns);
                findDown(graph, i, j, rows);
                cout << endl;
            }
        }
    }
}

// Find valid node to the right
void findRight(vector<vector<int>> graph, int currentRow, int currentColumn, int columns)
{
    if (currentColumn+1 >= columns)
        { cout << "-1 -1 "; }
    
    else if (graph[currentRow][currentColumn+1] == 1)
        { cout << currentColumn+1 << " " << currentRow << " "; }
        
    else
        { findRight(graph, currentRow, currentColumn+1, columns); }
}

//Find valid node below
void findDown(vector<vector<int>> graph, int currentRow, int currentColumn, int rows)
{
    if (currentRow+1 >= rows)
        { cout << "-1 -1"; }
    
    else if (graph[currentRow+1][currentColumn] == 1)
        { cout << currentColumn << " " << currentRow+1; }
        
    else
        { findDown(graph, currentRow+1, currentColumn, rows); }
}
