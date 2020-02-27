#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
struct D{
    string s;
    int i;  
    int index;
};

unordered_map<string, int> h1; // 장르별 카운트 <장르, 갯수>

bool cmp(D d1, D d2){
    int i1=0;
    int i2=0;
    for(auto i = h1.begin() ; i != h1.end() ; ++i){
        if(d1.s == i->first)
            i1 = i->second;
        if(d2.s == i->first)
            i2 = i->second;
    }
    
    if(i1==i2)
        return d1.i > d2.i;
    else
        return i1 > i2;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;    
    
    for(int i =0 ; i < genres.size() ; ++i){
        h1[genres[i]]+=plays[i];
    }
    
    vector<D> v;
    
    for(int i = 0 ; i < plays.size() ; ++i)
        v.push_back({genres[i], plays[i], i});
    
    sort(v.begin(), v.end(), cmp);
    
    unordered_map<string, int> ch;
    for(int i = 0 ; i < v.size() ; ++i){
        if(ch[v[i].s] < 2){
            ch[v[i].s]++;
            answer.push_back(v[i].index);
        }
    }
    
    return answer;
}