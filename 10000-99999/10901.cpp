#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int T, n, t, m;
    cin >> T;
    for(int I = 0; I < T; ++I){
        cin >> n >> t >> m;
        int tt, cur_time = 0;
        string direction;
        queue< pair<int, int> > left_q, right_q;
        vector<int> times(m);
        for(int i = 0; i < m; ++i){
            cin >> tt >> direction;
            if(direction == "left")
                left_q.push(make_pair(i,tt));
            else
                right_q.push(make_pair(i,tt));
        }
        bool at_left = 1;
        while(!left_q.empty() || !right_q.empty()){
            if(at_left){
                if(!left_q.empty()){
                    if(!right_q.empty() && left_q.front().second > max(cur_time, right_q.front().second)){
                        cur_time = max(cur_time, right_q.front().second) + t;
                        at_left = 0;
                        continue;
                    }
                    int cap = 1;
                    cur_time = max(cur_time, left_q.front().second);
                    times[left_q.front().first] = cur_time + t;
                    left_q.pop();
                    while(cap < n && !left_q.empty() && left_q.front().second <= cur_time){
                        cap++;
                        times[left_q.front().first] = max(cur_time, left_q.front().second) + t;
                        left_q.pop();
                    }
                }
                else if(!right_q.empty() && right_q.front().second > cur_time)
                    cur_time = right_q.front().second;
                cur_time += t;
                at_left = 0;
            }
            else{
                if(!right_q.empty()){
                    if(!left_q.empty() && right_q.front().second > max(cur_time, left_q.front().second)){
                        cur_time = max(cur_time, left_q.front().second) + t;
                        at_left = 1;
                        continue;
                    }
                    int cap = 1;
                    cur_time = max(cur_time, right_q.front().second);
                    times[right_q.front().first] = cur_time + t;
                    right_q.pop();
                    while(cap < n && !right_q.empty() && right_q.front().second <= cur_time){
                        cap++;
                        times[right_q.front().first] = max(cur_time, right_q.front().second) + t;
                        right_q.pop();
                    }
                }
                else if(!left_q.empty() && left_q.front().second > cur_time)
                    cur_time = left_q.front().second;
                cur_time += t;
                at_left = 1;
            }
        }
        for(int i = 0; i < m; ++i)
            cout << times[i] << '\n';
        if(I != T - 1)                                                  //presentation error without this
            cout<<'\n';
    }
    return 0;
}
