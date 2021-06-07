#include <iostream>
#include<algorithm>
using namespace std;
class edges{
  public:
    int s;
    int d;
    int w;
};

// for sorting
bool comp(edges e1,edges e2)
{
    return e1.w < e2.w;
}

int findparent(int i,int *parent)
{
    if(i==parent[i])
        return i;
    else
        return findparent(parent[i],parent);
}

void kruskal(edges *input,edges *output,int n,int e,int *parent)
{
    int count=0;
    for(int i=0;i<e &&count!=n-1;i++)
    {
        int sourceparent=findparent(input[i].s,parent);
        int destparent=findparent(input[i].d,parent);
        if(sourceparent!=destparent)
        {
            output[count]=input[i];
            count++;
            parent[sourceparent]=destparent;
        }
    }
    
    // printing smalling vertex first
    for(int i=0;i<n-1;i++)
    {
        if(output[i].s < output[i].d)
            cout<<output[i].s<<" "<<output[i].d<<" "<<output[i].w<<endl;
        else
           cout<<output[i].d<<" "<<output[i].s<<" "<<output[i].w<<endl; 
    }
}
int main()
{
  	int V, E;
  	cin >> V >> E;
  	edges *input=new edges[E];
  	edges *output=new edges[V-1];
  	for(int i=0;i<E;i++)
  		cin>>input[i].s>>input[i].d>>input[i].w;
    sort(input,input+E,comp);  // sort array in ascending order(acc. to weight)
    int *parent=new int[V];
    for(int i=0;i<V;i++)
        parent[i]=i;
    kruskal(input,output,V,E,parent);
  	return 0;
}



