#include <iostream>
using namespace std;

bool ispali(const string& str, int start, int end) {
    while (start < end) {
        if (str[start] != str[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

int Palisub(const string& s, int l, int r) {
    int count = 0;
    for (int i = l - 1; i < r; ++i) {
        for (int j = i; j < r; ++j) {
            if (ispali(s, i, j)) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    // for taking string input
    string s;
    cin >> s;
    
    // for taking position combination
    int comb1[10], comb2[10], out[10];
    int n_pos;
    
    cin >> n_pos;
    

    for (int i = 0; i < n_pos; ++i) {
        cin >> comb1[i] >> comb2[i];
        out[i] = Palisub(s, comb1[i], comb2[i]);
    }
    
    for (int i = 0; i < n_pos; ++i) {
        cout << out[i] << endl;
    }
    
    return 0;
}
