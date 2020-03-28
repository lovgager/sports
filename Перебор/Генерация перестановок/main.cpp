#include <iostream>
#include <fstream>
#include <vector>

std::vector<int> a;
std::vector<bool> used;
int n;
std::ofstream fout;

void out(void) {
	for (auto elem : a) {
		fout << elem;
	}
	fout << std::endl;
}

void rec(int idx) {
	if (idx == n) {
		out();
		return;
	}
	for (int i = 1; i <= n; ++i) {
		if (used[i]) continue;
		a[idx] = i;
		used[i] = true;
		rec(idx + 1);
		used[i] = false;
	}
}

int main (void) {
	fout.open("out.txt");
	std::cin >> n;
	a = std::vector<int>(n);
	used = std::vector<bool>(n + 1);
	rec(0);
	fout.close();
	return 0;
}