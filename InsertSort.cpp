#include "newCode_zuochengyun.h"

int main(){
	int n = 0;
	cin >> n;
	vector<int> arr(n , 0);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}

	for(int i = 1; i < n; i++){
		for(int j = i; j > 0 && arr[j-1] > arr[j]; j--){
			swap(arr[j] , arr[j- 1]);
		}
	}

	for_each(arr.begin() , arr.end() , [](int a){cout << a << " "; });
	cout << endl;
	
	return 0;
}