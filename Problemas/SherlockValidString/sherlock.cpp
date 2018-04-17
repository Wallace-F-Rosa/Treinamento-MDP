#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

string isValid(string s){

    vector<char> elements;

    vector<int>freq;

    for(int i = 0; i < s.size() ; i++)
    {
        bool new_element = true;
        for(int j = 0; j < elements.size() ; j++)
            if(elements[j] == s[i])
                new_element = false;
        
        if(new_element)
            elements.push_back(s[i]);
        new_element = true;
    }

    freq.resize(elements.size());

    for(int i = 0; i < elements.size();i++)
    {
        for(int j = 0; j <s.size();j++)
            if(elements[i] == s[j])
                freq[i] = freq[i] + 1;
    }

    bool valid = true;
    for(int i = 0 ; i < freq.size() - 1; i++)
    {
        if(freq[i] == freq[i+1])
            valid = true;
        else
            valid = false;

        if(!valid)
            break;
    }

    if(valid)
        return "YES";
    
    valid = true;
    for(int i = 0; i < freq.size(); i++)
    {
        freq[i] = freq[i] - 1;
        
        int key = 0;
        for(int j = 0; j < freq.size(); j++)
        {
            if(freq[j] != 0)
                key = freq[j];
            if(key != 0) break;
        }

        for(int j = 0; j < freq.size();j++)
        {
            if(freq[j] != 0 && freq[j] != key)
                valid = false;
            if(!valid)
                break;
        }
        
        if(valid) return "YES";
        
        freq[i] = freq[i] + 1;    
        valid = true;
    }


    return "NO";
}

int main()
{
    string s;
    cin >> s;
    string result = isValid(s);
    //input 1:
    //
    //input 2:
    //hfchdkkbfifgbgebfaahijchgeeeiagkadjfcbekbdaifchkjfejckbiiihegacfbchdihkgbkbddgaefhkdgccjejjaajgijdkd
    cout << result << endl;

    return 0;
}