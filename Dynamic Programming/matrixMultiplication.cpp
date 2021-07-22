#include<climits>
int mcm(int *p,int s,int e,int **out){
    if(s==e){
        return 0;
    }
    if(out[s][e]!=-1){
        return out[s][e];
    }
    int ans=INT_MAX;
    for(int k=s;k<e;k++){
        int temp=mcm(p,s,k,out)+mcm(p,k+1,e,out)+p[s-1]*p[k]*p[e];
        ans=min(ans,temp);
    }
    out[s][e]=ans;
    return out[s][e];
}

int mcm(int* p, int n){

    int **out=new int*[n+1];
    for(int i=0;i<=n;i++){
        out[i]=new int[n+1];
        for(int j=0;j<=n;j++){
            out[i][j]=-1;
        }
    }
    return mcm(p,1,n,out);
}
