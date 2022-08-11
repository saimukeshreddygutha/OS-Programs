#include<bits/stdc++.h>
using namespace std;


int main(){
	int n;
	cin>>n;

	int bt[n], at[n], p[n], ct[n], tat[n], wt[n], sumbt = 0, t = 0, pt[n];
	for(int i = 0;i < n;i++){cin>>bt[i];p[i] = i + 1;sumbt += bt[i];}
	for(int i = 0;i < n;i++)cin>>at[i];
	for(int i = 0;i < n;i++)cin>>pt[i];

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

				temp = pt[j];
				pt[j] = pt[i];
				pt[i] = temp;
			}
		}
	}

	
	while(t < sumbt){

		int min = INT_MAX, k = -1;
		for(int i = 0;i < n;i++){
			
			if(at[i] <= t && bt[i] != 0 && min > pt[i]){
				min = bt[i];
				k = i;
			}
		}
		t++;
		bt[k]--;
		if(bt[k] == 0){
			ct[k] = t;
			tat[k] = ct[k] - at[k];
			wt[k] = tat[k] - bt[k];
		}
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