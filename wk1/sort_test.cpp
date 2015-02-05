//
//  sort_test.cpp
//  
//
//  Created by CHEUNG SIN SHUEN on 1/31/15.
//
//

#include <stdio.h>
#include<iostream>
#include<vector>
#include<stdlib.h>
#include<ctime>
#include<time.h>
#include<cmath>
using namespace std;

class Solution {
public:
    
    void msort ( int  *numstr ,int n, int K){
        
        
        if(n>K) {
            int middle = n/2;
            int *temp1; int size1;
            int *temp2; int size2;
            temp1=numstr; size1=middle;
            temp2=numstr +middle; size2=n-middle;

            msort(temp1,size1,K);
            msort(temp2,size2,K);
            int *rv= merge(temp1,size1,temp2,size2);
            for (int i=0; i< n;i++){
                numstr[i]= rv[i];
                //cout<< numstr[i]<<" ";
            }
            //cout<<endl;
        }
        else if(n>=2){
            for (int i=1; i< n; i++){
                int j=i-1;
                int temp=numstr[i];
                while(j>=0 && numstr[j]< temp ){
                    numstr[j+1]=numstr[j];
                    j--;
                }
                if(j==0 && numstr[j]<temp) numstr[j]=temp;
                else{ numstr[j+1]=temp ;}
            }
        }
    }
    
    
    int * merge(int numstr1[], int size1, int numstr2[], int size2){
        int *result=new int[size1+size2];
        int counter=0;
        int i=0, j=0;
        while(i< size1 && j< size2){
            if(numstr1[i]>=numstr2[j]){
                result[counter++]=numstr1[i];
                i++;
            }
            else{
                result[counter++]=(numstr2[j]);
                j++;
            }
        }
        
        while(i< size1) {
            result[counter++]=(numstr1[i]);
            i++;
        }
        while(j< size2) {
            result[counter++]=(numstr2[j]);
            j++;
        }
        return result;
    }
    
};

double diffclock( clock_t clock1, clock_t clock2 ) {
    double diffticks = clock1 - clock2;
    double diffms    = diffticks / ( CLOCKS_PER_SEC / 1000 );
    return diffms;
}

int main(){
    
    
    int T=1024*1024;
    
    double arr[15];
    
    for(int t=0; t< 20; t++){
        int *vec = new int[T];
        srand(time(NULL));
        for (int i=0; i<T; i++){
            vec[i]=rand()  ;
        }
    
        for (int K=1; K<16;K++ ){
            int *vec1= new int [T];
            for(int i=0;i<T;i++){
                vec1[i]=vec[i];
            }
            Solution sol;
            clock_t time_s=clock();
            sol.msort(vec1, T ,pow(2,K));
            clock_t time_e=clock();
            arr[K-1]+= diffclock(time_e,time_s)/20;
        }
    }
    for(int t=0;t< 15;t++){
        cout<< "K=2^ "<< t+1 << " time " << arr[t]<<endl;
    }
    
}



