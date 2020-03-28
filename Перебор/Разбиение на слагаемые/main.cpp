#include <iostream>
#include <fstream>
#include <vector>

std::vector<bool> v;
int n, m;
std::ofstream fout;

void out() {
	for (int i = 0; i < n; ++i)
		if (v[i]) fout << '*';
		else fout << '.';
	fout << std::endl;
}

void rec(int idx, bool last) {
	if (n == idx && m > 0) return;
	if (m == 0 || n == idx) {
		for (int i = idx; i < n; ++i) 
			v[i] = 0;
		out();
		return;
	}
	if (!last) {
		v[idx] = 1;
		--m;
		rec(idx + 1, 1);
		++m;
	}
	v[idx] = 0;
	rec(idx + 1, 0);
}

int main() {
	fout.open("out.txt");
	std::cin >> n >> m;
	v = std::vector<bool>(n);
	rec(0, 0);
	fout.close();
	return 0;
}