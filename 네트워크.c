#include <string>
#include <vector>
#include <queue>
using namespace std;
#define MAX 1001

// 그래프 순회 문제 : 서치 함수를 부르는 횟수
int cnt;
bool visited[MAX];

void bfs(int start, vector<vector<int>> &computers){
    if(visited[start])
        return;
    cnt++;
    queue<int> q;
    q.push(start);
    
    while(!q.empty()){
        start = q.front();
        q.pop(); // pop() 하는 순간 : 방문
        visited[start] = true;
        
        for(int i = 0; i<computers[start].size();i++){
            if(visited[i] || computers[start][i] == 0)
                continue;
            q.push(i);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    
    for(int i = 0 ; i < n ; i++)
        bfs(i, computers);
    
    return cnt;
}