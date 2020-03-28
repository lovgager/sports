#include <iostream>
#include <fstream>
#include <vector>

std::vector<int> a;
int n, m;
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
	for (int i = 1; i <= m; ++i) {
		a[idx] = i;
		rec(idx + 1);
	}
}

int main (void) {
	fout.open("out.txt");
	std::cin >> n >> m;
	a = std::vector<int>(n);
	rec(0);
	fout.close();
	return 0;
}