//matrix transposition


#include<iostream>
#include<time.h>
#include<cmath>
#include<ctime>
#include<stdlib.h>

using namespace std;

#define DIM 4096*2


class matrix_sol{

public:

    int* matrix_trans1(int *arr, int dim){
        int * res=new int[dim*dim];
        for( int i = 0; i < dim; i++ )
            for( int j = 0; j < dim; j++ )
                res[j+i*dim] = arr[i+j*dim];
    }


    int* matrix_trans2(int *arr, int dim, int blocksize){
        int * res=new int[dim*dim];
        for( int i = 0; i < dim; i+=blocksize )
            for( int j = 0; j < dim; j+=blocksize )
                for (int k = i; k < i + blocksize; k++)
                    for (int l = j; l < j + blocksize; l++)
                        if(k + l*dim< dim*dim && l + k*dim<dim*dim )  res[k + l*dim] = arr[l + k*dim];


    }


};

double diffclock( clock_t clock1, clock_t clock2 ) {
    double diffticks = clock1 - clock2;
    double diffms    = diffticks / ( CLOCKS_PER_SEC / 1000 );
    return diffms;
}

int main(int argc ,char * argv[]){
   // int DIM=atoi(argv[1]);
    int *arr=new int[DIM*DIM];
    int *res1,*res2;
    srand(time(NULL));
    for(int i=0;i<DIM*DIM;i++){
        arr[i]=rand();
    }
    matrix_sol sol;
    clock_t time_s=clock();
    res1=sol.matrix_trans1(arr,DIM);
    clock_t time_e=clock();
    cout<<"naive approach: "<<diffclock(time_e,time_s)<<endl;;

    for(int i=1;i<10;i++){
        clock_t time_s=clock();
        res2=sol.matrix_trans2(arr,DIM,pow(2,i));
        clock_t time_e=clock();
        cout<<"block size =2^"<<i<<": "<<diffclock(time_e,time_s)<<endl;
    }


    return 0;


}
