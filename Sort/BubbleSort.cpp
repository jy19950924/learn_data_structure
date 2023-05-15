// newCode_zuochengyun.cpp: 定义应用程序的入口点。
//

#include "public.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::swap;
using std::for_each;

int main() {
	int n = 0;
	cin >> n;
	vector<int> arr(n , 0);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}

	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n && arr[i]>arr[j]; j++){
			swap(arr[i] , arr[j]);
		}
	}
	for_each(arr.begin() , arr.end() , [](int arr){
		cout << arr << ' '; });
	cout << endl;

	return 0;
}
