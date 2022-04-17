#include<iostream>
#include<vector>
#include<algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::swap;
using std::for_each;

int main(){
	int n = 0;
	cin >> n;
	vector<int> arr(n , 0);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}

	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			if(arr[i] > arr[j]){
				swap(arr[i] , arr[j]);
			}
		}
	}

	for_each(arr.begin() , arr.end() , [](int a){cout << a << ' '; });
	cout << endl;
 }