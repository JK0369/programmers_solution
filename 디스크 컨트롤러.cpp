#include <string>
#include <vector>
#include <queue>
using namespace std;

typedef struct D{
    int a,b;
    D(int q, int w):a(q), b(w) {}
}D;

struct cmp{
    bool operator()(const D & d1, const D & d2) const{
        if(d1.b == d2.b)
            return d1.a > d2.a;
        return d1.b > d2.b;
    }
};

priority_queue<D, vector<D>, cmp> pq;
priority_queue<D, vector<D>, cmp> pq2;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    for (int i = 0; i < jobs.size(); i++)
        pq.push(D(jobs[i][0], jobs[i][1]));

    int sec = 0;
    while (!pq.empty() || !pq2.empty()) {
        D d = pq.top();
        pq.pop();
        bool check = false;

        if (sec >= d.a) {
            sec += d.b;
            answer += sec - d.a;
            while (!pq.empty()) {
                pq2.push(pq.top());
                pq.pop();
                check = false;
            }
        }
        else {
            pq2.push(d);
            check = true;
        }

        if (pq.empty()) {
            while (!pq2.empty()) {
                pq.push(pq2.top());
                pq2.pop();
            }
            if(check)
                sec++;
        }
    }
    answer /= jobs.size();
    return answer;
}