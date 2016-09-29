#include <vector>
#include <stack>
#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <typeinfo>

void matrixChainMultiple(){
	int MAX_num = 100;
	int n, p[MAX_num + 1], matrix_cost[MAX_num + 1][MAX_num + 1];
	std::cin >> n;
	for(int i = 1; i <= n; i++){
		matrix_cost[i][i] = 0;
		std::cin >> p[i - 1] >> p[i];
	}
	// l: length of matrix, i: start_index, j: end_index
	for(int l = 2; l <= n; l++){
		for(int i = 1;  i <= n - l + 1; i++){
			int j = i + l - 1;
			for(int k = i; k <= j - 1; k++){
				if(k == i){
					matrix_cost[i][j] = matrix_cost[i][k] + matrix_cost[k+1][j] + p[i-1]*p[k]*p[j];
				}
				else{
					matrix_cost[i][j] = std::min(matrix_cost[i][j], matrix_cost[i][k] + matrix_cost[k+1][j] + p[i-1]*p[k]*p[j]);
				}
			}
		}
	}
	std::cout << matrix_cost[1][n] << std::endl;

}


int main(){
	matrixChainMultiple();
	return 0;
}
