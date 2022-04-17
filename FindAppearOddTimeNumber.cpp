#include "newCode_zuochengyun.h"

int main(){
	int n = 0;
	cin >> n;
	vector<int> arr(n , 0);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	int res = 0;
	for_each(arr.begin() , arr.end() , [&](int t){
		res = res ^ t;
		});
	cout << res << endl;
	return 0;
}