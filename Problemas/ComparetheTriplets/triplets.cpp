#include <bits/stdc++.h>

using namespace std;
vector<int> solve(int a0, int a1, int a2, int b0, int b1, int b2) {
    int scoreA = 0, scoreB = 0;

    int a[3] = {a0,a1,a2};
    int b[3] = {b0,b1,b2};

    for(int i = 0; i < 3; i++)
    {
        if(a[i] > b[i])
            scoreA++;
        else if(a[i] < b[i])
                scoreB++;
    }
    vector <int> result(2);
    result[0] = scoreA;
    result[1] = scoreB;

    return result;
}

int main()
{
    int a0,a1,a2;
    int b0,b1,b2;
    cin >> a0 >> a1 >> a2;
    cin >> b0 >> b1 >> b2;

    vector<int> result = solve(a0,a1,a2,b0,b1,b2);
    cout << result[0] <<" " <<  result [1] << endl;
}