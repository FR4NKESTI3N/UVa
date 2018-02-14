//NOTE: avoid using std::stable_sort for custom objects.

#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<algorithm>
#include<sstream>

using namespace std;

void toUpper(string& s){
    for(int i = 0; i < s.size(); ++i){
        if(s[i] > 'Z'){
            s[i] -= 'z' - 'Z';
        }
    }
    return;
}

void stableSortAndPrint(vector<pair<string, vector<string> > > title_dict){
    for(int i = 1; i < title_dict.size(); ++i){
        pair<string, vector<string>> key = title_dict[i];
        int j = i - 1;
        while(j >= 0 && title_dict[j].first > key.first){
            title_dict[j + 1] = title_dict[j];
            --j;
        }
        title_dict[j + 1] = key;
    }
    for(int i = 0; i < title_dict.size(); ++i){
        for(int j = 0; j < title_dict[i].second.size() - 1; ++j)
            cout<<title_dict[i].second[j]<<' ';
        cout<<*(title_dict[i].second.end() - 1)<<'\n';
    }
}

int main(){
    vector< string > to_ignore, titles;
    string s;
    while(true){
        cin >> s;
        if(s == "::")
            break;
        to_ignore.push_back(s);
    }
    // cin.ignore();
    sort(to_ignore.begin(), to_ignore.end());
    while(getline(cin, s)){
        for(int i = 0; i < s.size(); ++i){
            if(s[i] != ' ' && s[i] < 'a')
                s[i] += 'a' - 'A';
        }
        titles.push_back(s);
    }
    vector < pair < string, vector<string> > > title_dict;
    for(int i = 0; i < titles.size(); ++i){
        stringstream ss(titles[i]);
        string temp;
        vector<string> broken_str, temp_broken_str;
        while(ss >> temp){
            broken_str.push_back(temp);
        }
        for(int i = 0; i < broken_str.size(); ++i){
            if(!binary_search(to_ignore.begin(), to_ignore.end(), broken_str[i])){
                temp_broken_str = broken_str;
                toUpper(temp_broken_str[i]);
                title_dict.push_back(make_pair(temp_broken_str[i], temp_broken_str));
            }
        }
    }
    stableSortAndPrint(title_dict);
    return 0;
}
