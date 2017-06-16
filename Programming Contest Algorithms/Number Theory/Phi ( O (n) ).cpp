
typedef long long ll;
const int MAXN = 1e7 + 7;

int p;
ll prime [MAXN], phi [MAXN];
bool check [MAXN];

void Phi () {
    for (int i = 2; i <= MAXN - 7; i++) {
        if(! check [i]) {
            prime [++p] = i;
            phi [i] = i - 1;
        }
        for (int j = 1; j <= p && i * prime [j] <= MAXN - 7; ++j) {
            check [i * prime [j]] = true;
            if(i % prime [j] == 0){
                phi [i * prime [j]] = prime [j] * phi [i];
                break;
            }else{
                phi [i * prime [j]] = (prime [j] - 1) * phi [i];
            }
        }
    }
}
