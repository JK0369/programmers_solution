#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
#define MAX 51

// 다익스트라가 아닌 bfs문제 + DP문제

int arr[MAX][MAX];
int size;
int len;
unordered_map<string, int> um;
int ind;

bool ch(string s1, string s2){
    int c = 0;
    for(int i=0;i<len;i++)
        if(s1[i] != s2[i])
            c++;
    if(c ==1)
        return true;
    return false;
}

void bfs(int start, int v[], int sol[]){
    queue<int> q;
    q.push(start);
    v[start] = 1;
    sol[start] =1;
    
    while(!q.empty()){
        start = q.front();
        q.pop();
        
        for(int i = 0 ; i< size;i++){
            if(v[i]==0 && arr[start][i] == 1){
                sol[i] = sol[start] + 1;
                v[i] = 1;
                q.push(i);
            }
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 100;
    // 저장
    size = words.size();
    len = words[0].length();
    
    for(int i = 0;i<size;i++)
        um.insert({words[i], i});
    if(um.find(target)==um.end())
        return 0;
    
    for(int i = 0;i<size;i++)
        for(int j = 0 ; j <size ; j ++){
            if(ch(words[i], words[j])){
                arr[um[words[i]]][um[words[j]]] = 1;
                arr[um[words[j]]][um[words[i]]] = 1;
                
            }
        }
    
    for(int i = 0 ; i < size; i++){
        if(ch(begin, words[i])){
            int v[MAX] = {0,};
            int sol[MAX] = {0,};
            bfs(i, v, sol);    
            
            if(sol[um[target]] != 0 && answer > sol[um[target]] && um.find(target) != um.end())
                answer = sol[um[target]];
            
        }
    }
    
    if(answer == 100)
        answer=0;
    return answer;
}