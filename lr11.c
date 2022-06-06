#include <stdio.h>
#include <stdbool.h>
bool is_sep(char c) {
	return (c >= '\t' && c <= '\r') || c == ' ';
}
bool is_num(char c) {
	return c >= '0' && c <= '9';
}
bool is_sign(char c) {
	return c == '+' || c == '-';
}
bool is_letter(char c) {
	return !is_sep(c) && !is_num(c) && !is_sign(c) && (c != EOF);
}
typedef enum {
	state_perhaps_num,
	state_sign,
	state_not_num,
	state_after_first_num,
	state_not_num_but_sep
} state;
int main() {
	int x1 = 0, x2 = 0, k = 0, res;
	bool p1 = false, p2 = false;
	state s = state_not_num_but_sep;
	int c;
	while (true) {
		c = getchar();
		if (c == EOF) {
			if (s != state_not_num_but_sep) printf("\n");
			if (s == state_perhaps_num) {
				if (p1) p2 = true;
				x1 = x2;
				x2 = k;
			}
			res = x1;
			break;
		}
		if (s == state_not_num_but_sep) {
			if (is_num(c) || is_sign(c)) s = state_perhaps_num;
			if (is_sep(c)) s = state_not_num_but_sep;
			if (is_letter(c)) s = state_not_num;
		}
		if (s == state_perhaps_num) {
			if (is_letter(c) || is_sign(c)) {
				s = state_not_num;
				k = 0;
			}
			if (is_sep(c)) {
				if (p1 == true) p2 = true;
				p1 = true;
				x1 = x2;
				x2 = k;
				k = 0;
				s = state_not_num_but_sep;
			}
			if (is_num(c)) k += c - 48;
		}
		if (s == state_not_num) {
			if (is_sep(c)) s = state_not_num_but_sep;
			if (c == EOF) break;
		}
	}
	if (p2) printf("%d\n",res);
}
