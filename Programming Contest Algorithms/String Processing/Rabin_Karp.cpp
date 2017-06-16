typedef unsigned long long ull;

const int MAX = 1e5 + 10, base = 31;
char pat [MAX], str [MAX];
ull power [MAX], prefixhash [MAX], pathash;
vector <int> occurance;

void powGen () {
    power [0] = 1;
    for (int i = 1; i <= MAX - 10; i++) {
        power [i] = power [i - 1] * base;
    }
}

void rabinKarp () {
    int lenp = strlen (pat);
    int lens = strlen (str);

    for (int i = 0; i < lens; i++) {
        prefixhash [i] = str [i] * power [i];
        prefixhash [i] += i? prefixhash [i - 1] : 0;
    }

    pathash = 0;
    for (int i = 0; i < lenp; i++) {
        pathash += pat [i] * power [i];
    }

    occurance.clear ();
    for (int i = 0; i + lenp - 1 < lens; i++) {
        ull curhash = prefixhash [i + lenp - 1];
        curhash -= i? prefixhash [i - 1] : 0;

        if (carhash == pathash * power [i]) occurance.push_back (i);
    }
}
