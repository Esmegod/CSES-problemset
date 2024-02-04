#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n;
	cin>>n;
	int x[n-1];
	vector<int> y(n+1,0);
	
	for(int i=0; i<n-1; i++) cin>>x[i];
	for(int i=0; i<n-1; i++) y[x[i]]++;
	
	for(int i: y){
		cout<<i<<" ";
	}
	cout<<endl;
	return 0;
}
