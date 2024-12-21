You are given a rows x cols matrix grid representing a field of cherries where 
grid[i][j] represents the number of cherries that you can collect from the (i, j) cell.  
You have two robots that can collect cherries for you:  
Robot #1 is located at the top-left corner (0, 0), and  
Robot #2 is located at the top-right corner (0, cols - 1).  
Return the maximum number of cherries collection using both robots by following 
the rules below:  
From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).  
When any robot passes through a cell, It picks up all cherries, and the cell becomes 
an empty cell.  
When both robots stay in the same cell, only one takes the cherries.  
Both robots cannot move outside of the grid at any moment.  
Both robots should reach the bottom row in grid. 


 #include <iostream>
#include <algorithm>
 using  namespace std; 
int maxCherries(int** grid, int rows, int cols) {    
 int  dp[rows][cols][cols];  // DP table to store max cherries at each step     // 
Initialize the DP table with -1 for non-visited states    
  for (int i = 0; i < rows; i++) { 
        j2 < cols; j2++) {                 
}  
}  
}  
for (int j1 = 0; j1 < cols; j1++) {             
dp[i][j1][j2] = -1;  
dp[0][0][cols - 1] = grid[0][0] + grid[0][cols - 1];     
for (int i = 1; i < rows; i++) {         
for (int j1 = 0; j1 
for (int j2 = 0; 
< cols; j1++) {             for (int j2 = 0; j2 < cols; 
j2++) {  
                if (dp[i - 1][j1][j2] != -1) {  // If this state was reachable from the 
previous row  
                    for (int dj1 = -1; dj1 <= 1; dj1++) 
{                         for (int dj2 = -1; dj2 <= 1; dj2++) 
{                             int newJ1 = j1 + dj1;                             
int newJ2 = j2 + dj2;  
  
                            if (newJ1 >= 0 && newJ1 < cols && newJ2 >= 0 && newJ2 < 
cols) {                                 int cherries = grid[i][newJ1] + grid[i][newJ2];  
                                if (newJ1 == newJ2) cherries -= grid[i][newJ1]; // If both 
robots are at the same cell, only one picks cherries  
                                dp[i][newJ1][newJ2] = max(dp[i][newJ1][newJ2], dp[i - 
1][j1][j2] + cherries);  
                            }  
                        }  
                    }  
                }  
            }  
        }  
    }  
    int maxCherries = 0;     for (int j1 = 0; j1 < cols; j1++) 
{         for (int j2 = 0; j2 < cols; j2++) {             maxCherries = 
max(maxCherries, dp[rows - 1][j1][j2]);  
        }  
    }  
    return maxCherries;  
}  
  
int main() {     int rows, cols;     cout << "Enter the 
number of rows and columns: ";     cin >> rows >> 
cols;  
  
    int** grid = new int*[rows];     cout << 
"Enter the grid (cherry counts):\n";     for (int 
i = 0; i < rows; i++) {         grid[i] = new 
int[cols];         for (int j = 0; j < cols; j++) 
{             cin >> grid[i][j];  
        }  
}  
int result = maxCherries(grid, rows, cols);     cout << 
"Maximum cherries collected: " << result << endl;     for (int 
i = 0; i < rows; i++) {         
}     delete[] 
grid;  
return 0; 
          
