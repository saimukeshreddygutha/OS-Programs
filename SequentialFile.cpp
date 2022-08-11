#include<iostream>
using namespace std;

int main(){

	int n;
	cin>>n;


	int startblocks[n], length[n];

	for(int i = 0;i < n;i++){
		cin>>startblocks[i];
		cin>>length[i];

	}

	cout<<"File"<<"     "<<"start"<<"     "<<"length"<<endl;


	for(int i = 0;i < n;i++){
		cout<<i<<"\t"<<startblocks[i]<<"\t"<<length[i]<<endl;
	}
}