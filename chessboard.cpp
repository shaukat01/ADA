#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int board[20][20];
int tile;
void tiling(int trow, int tcol, int drow, int dcol,int size){
    if(size==1)
        return;
    int qsize=size/2;
    int tileToUse=tile++;
    if(drow<=trow+qsize-1 && dcol<=tcol+qsize-1){
        tiling(trow,tcol,drow,dcol,qsize);
    }
    else{
        board[trow+qsize-1][tcol+qsize-1]=tileToUse;
        tiling(trow,tcol,trow+qsize-1,tcol+qsize-1,qsize);
    }
    if(drow<=trow+qsize-1 && dcol>=tcol+qsize){
        tiling(trow,tcol+qsize,drow,dcol,qsize);
    }
     else{
        board[trow+qsize-1][tcol+qsize]=tileToUse;
        tiling(trow,tcol+qsize,trow+qsize-1,tcol+qsize,qsize);
    }
    if(drow>=trow+qsize && dcol<=tcol+qsize-1){
        tiling(trow+qsize,tcol,drow,dcol,qsize);
    }
    else{
        board[trow+qsize][tcol+qsize-1]=tileToUse;
        tiling(trow+qsize,tcol,trow+qsize,tcol+qsize-1,qsize);
    }
    if(drow>=trow+qsize && dcol>=tcol+qsize){
        tiling(trow+qsize,tcol+qsize,drow,dcol,qsize);
    }
    else{
        board[trow+qsize][tcol+qsize]=tileToUse;
        tiling(trow+qsize,tcol+qsize,trow+qsize,tcol+qsize,qsize);
    }
}

int main(){
    int n,drow,dcol,i,j;
    cout<<"Enter the size"<<endl;
    cin>>n;
    cout<<"Enter defective row and column"<<endl;
    cin>>drow>>dcol;
    tiling(0,0,drow,dcol,n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}