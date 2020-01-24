#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

unordered_set<string> se;
bool solution(vector<string> phone_book) {
    bool answer = true;
    for(int i = 0 ; i<phone_book.size();i++){
        if(se.find(phone_book[i]) != se.end())
            return false;
        se.insert(phone_book[i]);
    }
    for(int i = 0 ; i<phone_book.size();i++)
        for(auto it = se.begin();it!=se.end();it++)
            if((*it).find(phone_book[i]) != -1)
                if(*it != phone_book[i])
                    return false;
    
    return answer;
}