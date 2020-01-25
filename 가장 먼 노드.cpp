#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 20020

bool v[MAX];
int sol[MAX];
int maxValue = 0;
int arr[MAX][MAX];
int size;

void bfs(int start){
    queue<int> q;
    q.push(start);
    v[start] = true;
    sol[start]++;
    
    while(!q.empty()){
        start = q.front();
        q.pop();
        
        for(int i =1 ; i <= size;i++){
            if(arr[start][i] == 1 && !v[i]){
                v[i] = true;
                sol[i] = sol[start]+1;
                q.push(i);
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    size = n;
    for(int i = 1; i<=edge.size();i++){
        arr[edge[i-1][0]][edge[i-1][1]]=1;
        arr[edge[i-1][1]][edge[i-1][0]]=1;
    }
    
    bfs(1);
    
    int maxV = *max_element(sol+1, sol+size+1);
    int ch = 0;
    for(int i =1;i<= size;i++){
        if(maxV==sol[i])
            answer++;
        if(sol[i] == 0)
            ch++;
        
    }
    
    // 연결되지 않은 노드가 존재하는 경우
    if(ch != 0)
        answer= ch;
    return answer;
}