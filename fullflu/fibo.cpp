#include <vector>
#include <stack>
#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>

#include <typeinfo>


void fibo(){
	int n;
	std::cin >> n; 
	int tmp_1 = 1;
	int tmp_2 = 1;
	int result;

	if(n < 2)
		std::cout << 1 << std::endl;
	else{
		for(int i = 1; i < n ; i++){
			result = tmp_1 + tmp_2;
			tmp_1 = tmp_2;
			tmp_2 = result;
		}
		std::cout << result << std::endl;
	}
}


int main(){
	fibo();
	return 0;
}
