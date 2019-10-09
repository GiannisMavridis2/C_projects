#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#define N 30000
#define p 0.05 //produce death
#define q 0.10 //give life


int main(){
	int i,A[N],smini[N],temp,temp_plithos;
	srand((int)time(0));
	//fill A
	//-----------------------------------
	for (i=0;i<N;i++){
		temp=rand()%100+1; //temp E [1-100]
		if (temp<=50){
			A[i]=1;
		}else{
			A[i]=0;
		}
	}
	//----------------------------------
	//0 kills neighbors with propability p
	//gia to element 0
	temp=rand()%100+1;
	if (temp<=p*100){
		//kill it
		A[1]=0;
    }	
	for (i=1;i<=N-2;i++){
		//gia i diaforo toy 0 kai N-1
		//rixno to zari gia ton left neighbor
		temp=rand()%100+1;
		if (temp<=p*100){
			//kill it
			A[i-1]=0;
        }
		//rixno to zari gia to right neighbor
        temp=rand()%100+1;
		if (temp<=p*100){
			//kill it
			A[i+1]=0;
        }		
	}
	//gia to element N-1
	temp=rand()%100+1;
	if (temp<=p*100){
		//kill it
		A[N-2]=0;
    }	
	//---------------------------------------------------
    //1 gives life to neighbors with propability q
	//gia to element 0
	temp=rand()%100+1;
	if (temp<=q*100){
		//give life to it
		A[1]=1;
    }	
	for (i=1;i<=N-2;i++){
		//gia i diaforo toy 0 kai N-1
		//rixno to zari gia ton left neighbor
		temp=rand()%100+1;
		if (temp<=q*100){
			//give life to it
			A[i-1]=1;
        }
		//rixno to zari gia to right neighbor
        temp=rand()%100+1;
		if (temp<=q*100){
			//give life to it
			A[i+1]=1;
        }		
	}
	//gia to element N-1
	temp=rand()%100+1;
	if (temp<=q*100){
		//give life to it
		A[N-2]=1;
    }
	//---------------------------------------------------------
	//initialize smini
	for (i=0;i<N;i++){
		smini[i]=0;
	}
	//compute smini[]
	i=0;
	while(i<=N-1){
		temp_plithos=0;
		if (A[i]==1){
			while(A[i]==1){
				i++;
				temp_plithos++;
			}
			smini[temp_plithos]=smini[temp_plithos]+1;
			i++;
		}else{
			i++;
		}
	}
	for (i=0;i<50;i++){
		printf("%d : %d\n",i,smini[i]);
	}
	
	return 0;
}










