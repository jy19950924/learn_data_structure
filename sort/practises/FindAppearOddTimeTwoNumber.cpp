#include"public.h"

int main() {

    int n = 0;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int eor = 0;
    for_each(arr.begin(), arr.end(), [&](int t) {
        eor = eor ^ t;
    });

    int EOR = (~eor + 1) & eor;
    int eor1 = 0;
    for_each(arr.begin(), arr.end(), [&](int t) {
        if ((EOR & t) == EOR) {
            eor1 = eor1 ^ t;
        }
    });
    if (eor1 > (eor ^ eor1)) {
        cout << (eor ^ eor1) << ' ' << eor1 << endl;
    } else {
        cout << eor1 << ' ' << (eor ^ eor1) << endl;
    }
    return 0;
}