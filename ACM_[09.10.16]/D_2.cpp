#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <fstream>
#define max 100
using namespace std;
int MAXINT=100;
long sum=0;

int max(int a, int b){
	return (a>b)? a:b;
}

ifstream fi("D.inp");
void Doc_File(int A[max][max], int &n, int &D, int &C) {
	int t;
	fi >> t;
	for(int i = 0; i < t; i++) {
		while(true) {
			int t1, t2;
			fi >> t1 >> t2;
			if(t1 != 0 && t2 != 0) {
				A[t1][t2] = 1;
			}
			else {
				break;
			}
		}
	}
	D = 1, C = 4;
//	FILE*f = fopen("D.inp","rb");
//	fscanf(f,"%d%d%d",&n,&D,&C);
	cout<<"Ma Tran Lien Ket Tuong Ung.\n";
	cout<<D<<" "<<C<<endl;
//	for(int i =0;i<n;i++) {
//	      for(int j =0;j<n;j++) {
//	          fscanf(f,"%d",&A[i][j]);
//	          cout<<A[i][j]<<" ";
//	}
//	cout<<endl;
//	}
//	fclose(f);
	D--; C--;
}

// thuat toan Dijkstra

void Dijkstra(int A[max][max], int n, int D, int C) {
  char DanhDau[max];
  int Nhan[max], Truoc[max], XP, min;
  for(int i=0; i<n; i++){
        Nhan[i] = MAXINT;
        DanhDau[i] = 0;
        Truoc[i] = D;
  }
  Nhan[D] = 0;
  DanhDau[D] = 1;
  XP = D;
  while(XP != C){
       for(int j=0; j<n; j++)
          if(A[XP][j]>0 && Nhan[j]>A[XP][j]+Nhan[XP] && DanhDau[j]==0) {
              Nhan[j] = A[XP][j]+Nhan[XP];
              Truoc[j] = XP;
          }
          min = MAXINT;
         // cout<<(int)DanhDau[0]<<endl;
         cout<<min<<" "<<Nhan[0];
        //  getch();
        for(int j = 0; j<n; j++)
               if(min>Nhan[j]&&(DanhDau[j])==0){
                      min = Nhan[j];
                      XP = j;
              }
        DanhDau[XP] = 1;
   }
    cout<<"Duong Di Ngan Nhat La:"<<Nhan[C]<<endl;
    cout<<C+1<<" <- "<<Truoc[C]+1;
    int i = Truoc[C];
    while(i!=D){
          i = Truoc[i];
          cout<<" <- "<<i+1;
      }
      sum+=Nhan[C];
      cout<<endl;
}

main() {
	int A[max][max],n,Dau,Cuoi;
	Doc_File(A,n,Dau,Cuoi);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			Dijkstra(A,n,i-1,j-1);
		}
	getch();
	cout<<sum*1.0/12;
}
