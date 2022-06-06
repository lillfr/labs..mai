#include <stdio.h>
#include <stdbool.h>
int a = 1072, A = 1040,
    e = 1101, E = 1069,
    je = 1077, Je = 1045,
    jo = 1105, Jo = 1025,
    o = 1086, O = 1054,
    y = 1099, Y = 1067,
    u = 1091, U = 1059,
    ju = 1102, Ju = 1070,
    i = 1080, I = 1048,
    ja = 1103, Ja = 1071;
typedef unsigned long long set;
bool is_sep(char c) {
    return c == ' ' || c == ',' || c == '\t' || c == '\n';
}
int getcharutf8(){
    int c = getchar();
    if (is_sep(c) || c < 128) return c;
    int k = 1;
    int b = c - 128 - 64;
    if (b - 32 >= 0){
        b -= 32;
        k++;
        if (b - 16 >= 0){
            b -= 16;
            k++;
        }
    }
    int c1;
    for (int i = 0; i < k; ++i){
        c1 = getchar();
        b = b<<6;
        b += c1 - 128;
    }
    return b;
}
int toindex(int c) {
    if (c >= a && c <= ja) {
        if (c <= je) return c - a;
        else return c - a + 1;
    }
    if (c >= A && c <= Ja) {
        if (c <= Je) return c - A;
        else return c - A + 1;
    }
    if (c == jo || c == Jo) return 6;
    return -1;
}
set char_to_set(int c) {
    int i = toindex(c);
    if (i == -1) return 0;
    else return (set)1 << i;
}
typedef enum {
    state_outside,
    state_possibly_good_word,
    state_inside
} state;
int main() {
    set sa = char_to_set(a),
        se = char_to_set(e),
        sje = char_to_set(je),
        sjo = char_to_set(jo),
        so = char_to_set(o),
        sy = char_to_set(y),
        su = char_to_set(u),
        sju = char_to_set(ju),
        si = char_to_set(i),
        sja = char_to_set(ja);
    set vowels = sa | se | sje | sjo | so | sy | su | sju | si | sja;
    set letters = (set)1 << 33;
    letters -= 1;
    set consonants = letters & ~vowels;
    int c;
    int k = 0;
    set added;
    bool at_least_one = false;
    state s = state_outside;
    while (true) {
        c = getcharutf8();
        if (c == EOF) {
            if (k == 1) at_least_one = true;
            break;
        }
        if (s == state_outside) {
            if (k == 1) at_least_one = true;
            if (!is_sep(c)) s = state_possibly_good_word;
            k = 0;
        }
        if (s == state_possibly_good_word) {
            added = char_to_set(c);
            if (added & consonants) k += 1;
            if (k > 1) s = state_inside;
            if (is_sep(c))s = state_outside;
        }
        if (s == state_inside) {
            if (is_sep(c)) s = state_outside;
        }
    }
    putchar('\n');
    if (at_least_one) printf("слово с одной согласной имеется\n");
    else printf("слова с одной согласной не имеется\n");
}
