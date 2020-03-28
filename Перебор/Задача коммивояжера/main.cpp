#include <iostream>
#include <vector>
#include <fstream>

int n, min;
std::vector<int> perms, ans;
std::vector<bool> used;
std::ifstream fin;

void check(std::vector<std::vector<int>> &a) {
	int sum = 0;
	for (int i = 0; i < n - 1; ++i) {
		int first = perms[i], second = perms[i + 1];
		sum += a[first][second];
		if (sum >= min) return;
	}
	sum += a[perms[n - 1]][perms[0]];
	if (sum < min) { 
		min = sum;
		ans = perms;
	}
}

void rec(int idx, std::vector<std::vector<int>> &a) {
	if (idx == n) {
		check(a);
		return;
	}
	for (int i = 0; i < n; ++i) {
		if (used[i]) continue;
		perms[idx] = i;
		used[i] = 1;
		rec(idx + 1, a);
		used[i] = 0;
	}
}

int main() {
	fin.open("salesman.in");
	fin >> n;
	std::vector<std::vector<int>> a;
	for (int i = 1; i <= n; ++i) {
		std::vector<int> temp;
		for (int j = 1; j <= n; ++j) {
			int temp_int;
			fin >> temp_int;
			temp.push_back(temp_int);
		}
		a.push_back(temp);
	}
	fin.close();
	for (int i = 0; i < n; ++i) 
		min += a[0][i];
	perms = std::vector<int>(n);
	ans = std::vector<int>(n);
	used = std::vector<bool>(n + 1);
	for (int i = 0; i < n; ++i) 
		ans[i] = i;
	rec(0, a);
	
	std::cout << min << std::endl;
	for (int i = 0; i < n; ++i) 
		std::cout << ans[i];
	std::cout << std::endl;
	return 0;
}