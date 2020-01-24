#include <string>
#include <vector>

using namespace std;
// 재귀문제 2^20개의 경우의 수

int cnt=0;

void recur(int i, vector<int> &n, int t, int sum, int size){
        if (i == size) {
        if (sum == t)
            cnt++;
        return;
    }
    recur(i + 1, n, t, sum + n[i], size);
    recur(i + 1, n, t, sum - n[i], size);
}

int solution(vector<int> numbers, int target) {
    int size = numbers.size();
    recur(0, numbers, target, 0, size);
    return cnt;
}