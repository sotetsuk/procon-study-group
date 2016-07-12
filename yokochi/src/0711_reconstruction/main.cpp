#include <iostream>
#include <vector>
int N;
int count;
std::vector<int> answer;
int find(int* inorder, int c)
{
    for (int i = 0; i < N; i++) {
	if (inorder[i] == c) {
	    return i;
	}
    }
    return 0;
}
void rec(int* preorder, int* inorder, int l, int r)
{
    if (l >= r) {
	return;
    }
    int c = preorder[count++];
    int m = find(inorder, c);
    rec(preorder, inorder, l, m);
    rec(preorder, inorder, m + 1, r);
    answer.push_back(c);
}
int main()
{
    std::cin >> N;
    int* preorder = (int*)malloc(N * sizeof(int));
    int* inorder = (int*)malloc(N * sizeof(int));
    count = 0;
    for (int i = 0; i < N; i++) {
	std::cin >> preorder[i];
    }
    for (int i = 0; i < N; i++) {
	std::cin >> inorder[i];
    }
    rec(preorder, inorder, 0, N);
    for (int i = 0; i < N; i++) {
	std::cout << answer[i];
	if (i + 1 < N) {
	    std::cout << " ";
	}
    }
    std::cout << std::endl;
}
