#include<bits/stdc++.h>

using namespace std;
#define ROW 5
#define COL 5

bool isSafe(int M[][COL], int row, int col, bool visited[][COL]){
	return (row>=0) && (row<ROW) && (col>=0) && (col<COL) && (M[row][col] && !visited[row][col]);
}

void DFS(int M[][COL], int row, int col, bool visited[][COL]){
	// to check all 8 neighbours
	static int nrow[] = {-1, -1, -1,  0, 0,  1, 1, 1};
	static int ncol[] = {-1,  1,  0, -1, 1, -1, 0, 1};
	visited[row][col] = true;
	for(int k=0; k<8; k++){
		if(isSafe(M, row + nrow[k], col + ncol[k], visited))
			DFS(M, row + nrow[k], col + ncol[k], visited);
	}
}

int countIslands(int M[][COL]){
	bool visited[ROW][COL];
	memset(visited, 0, sizeof(visited));
	int no_of_islands = 0;
	for(int i=0; i<ROW; i++){
		for(int j=0; j<COL; j++){
			if(M[i][j] && !visited[i][j]){
				DFS(M, i, j, visited);
				no_of_islands++;
			}
		}
	}
	return no_of_islands;
}

int main(int argc, const char *argv[]){
	int M[][COL] = { { 1, 1, 0, 0, 0 }, 
                     { 0, 1, 0, 0, 1 }, 
                     { 1, 0, 0, 1, 1 }, 
                     { 0, 0, 0, 0, 0 }, 
                     { 1, 0, 1, 0, 1 } };
	cout << "Number of islands is: " << countIslands(M); 
	return 0;
}
