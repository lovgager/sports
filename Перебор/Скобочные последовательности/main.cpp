#include <iostream>
#include <fstream>
#include <string>

int n, open, close;
std::ofstream fout;

void rec(std::string &s, int idx) {
	if (idx == n << 1) {
		if (open == close) fout << s << std::endl;
		return;
	}
	s[idx] = '(';
	++open;
	rec(s, idx + 1);
	--open;
	s[idx] = ')';
	++close;
	if (close <= open) rec(s, idx + 1);
	--close;
}

int main() {
	std::cin >> n;
	std::string seq(n << 1, '\0');
	fout.open("out.txt");
	rec(seq, 0);
	fout.close();
	return 0;
}