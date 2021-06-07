#include<queue>
int buyTicket(int *arr, int n, int k) {
    queue<int> peopleQue;
    priority_queue<int> maxheap;
    for(int i = 0; i < n; i++) {
        que.push(arr[i]);
        maxheap.push(arr[i]);
    }
    int count = 0;
    while(!que.empty()) {
        int pi = peopleQue.front();
        peopleQue.pop();
         if(pi ==  maxheap.top()) {
             if(k == 0)
                 return count + 1;
             ++count;
             --k;
            maxheap.pop();
        }
        else {
            peopleQue.push(pi);
            if(k == 0) 
                k = peopleQue.size() - 1; // my position will become last
            else 
                --k;
        }
    }
}
