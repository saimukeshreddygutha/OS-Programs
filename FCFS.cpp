#include<bits/stdc++.h>
using namespace std;


int main(){
	int n;
	cin>>n;

	int bt[n], at[n], p[n], ct[n], tat[n], wt[n];
	for(int i = 0;i < n;i++){cin>>bt[i];p[i] = i + 1;}
	for(int i = 0;i < n;i++)cin>>at[i];

	for(int i = 0;i < n - 1;i++){
		for(int j = 0;j < n - i - 1;j++){
			if(at[j] > at[j + 1]){
				int temp = at[j];
				at[j] = at[i];
				at[i] = temp;

				temp = bt[j];
				bt[j] = bt[i];
				bt[i] = temp;

				temp = p[j];
				p[j] = p[i];
				p[i] = temp;
			}
		}
	}

	ct[0] = bt[0];
	tat[0] = ct[0] - at[0];
	wt[0] = tat[0] - bt[0];

	for(int i = 1;i < n;i++){
		ct[i] = ct[i - 1] + bt[i];
		tat[i] = ct[i] - at[i];
		wt[i] = tat[i] - bt[i];
	}


	double ttat = accumulate(tat, tat + n, 0)/(n*1.0);
	double twt = accumulate(wt, wt + n, 0)/(n*1.0);

	cout<<"P"<<"\t"<<"CT"<<"\t"<<"BT"<<"\t"<<"TAT"<<"\t"<<"WT"<<endl;

	for(int i = 0;i < n;i++){
		cout<<p[i]<<"\t"<<ct[i]<<"\t"<<bt[i]<<"\t"<<tat[i]<<"\t"<<wt[i]<<endl;
	}

	cout<<"AVG WT Time : "<<twt<<endl;
	cout<<"AVG TAT Time : "<<ttat<<endl;

}