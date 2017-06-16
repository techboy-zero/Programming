#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int MAX = 1e6 + 7;
char pat [MAX], str [MAX];
int pi [MAX], len;
vector <int> occurance;

void failure () {
    int i, shift = 0;
    for (i = 2; pat [i - 1]; ++i) {
        while (shift > 0 && pat [shift] != pat [i - 1]) shift = pi [shift];
        if (pat [shift] == pat [i - 1]) shift++;
        pi [i] = shift;
    }
}

int KMP () {
    failure ();
    int i, shift = 0;
    occurance.clear ();

    for (i = 0; str [i]; ++i) {
        while (shift > 0 && pat [shift] != str [i]) shift = pi [shift];
        if (pat [shift] == str [i]) ++shift;
        if (shift == len) {
            occurance.push_back (i - len + 1);
            shift = pi [shift];
        }
    }
    return occurance.size ();
}
