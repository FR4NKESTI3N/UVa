#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<algorithm>
#include<sstream>

using namespace std;

bool Compare(const pair<string, string>& l, const pair<string, string>& r){
    return l.first < r.first;
}

int main(){
    vector<string> to_ignore;
    string s;
    while(true){
        cin >> s;
        if(s == "::")
            break;
        to_ignore.push_back(s);
    }
    sort(to_ignore.begin(), to_ignore.end());
    vector<pair<string, string>> titles;
    while(getline(cin, s)){
        string title = s, temp;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        stringstream ss(s);
        while(ss>>temp){
            if(!binary_search(to_ignore.begin(), to_ignore.end(), temp))
                titles.push_back(make_pair(temp, title));
        }
    }
    sort(titles.begin(), titles.end(), Compare);
    for(auto a : titles)
        cout<<a.second<<'\n';
    return 0;
}
