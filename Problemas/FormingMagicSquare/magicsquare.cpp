#include <bits/stdc++.h>

using namespace std;

bool magic(vector < vector<int> >  &s)
{

        int sLine = 0;
        int sColumn = 0;
        int sDiagonal_P = 0;
        int sDiagonal_S = 0;
        bool valid = true;     
        for(int i = 0;i < 3;i++)
        {
            for(int j = 0;j < 3;j++)
            {
                if(i == j)
                    sDiagonal_P+= s[i][j];
                if(j == 2 - i)
                    sDiagonal_S += s[i][j];
                
                sLine += s[i][j];
                sColumn += s[j][i];
            }

            if(sLine != 15 || sColumn != 15)
                valid = false;
            if(!valid)
                break;
            
            sLine = 0;
            sColumn = 0;
        }
        //checking diagonals
        if(sDiagonal_P != 15 || sDiagonal_S != 15)
            valid = false;

    return valid;
}


int square_cost(vector < vector<int> >  &s, vector < vector<int> >  &s2)
{
    int cost = 0;

        for(int i = 0;i < 3;i++)
            for(int j = 0;j < 3;j++)
                cost += abs(s[i][j] - s2[i][j]);

    return cost;
}

int result( vector < vector<int> >  &s, vector < vector<int> >  &s2, int pos) // if magic, return cost
{
    
    //cheking the sumn of the rows and columns
    //if isn't magic, return -1
    if(pos == 9)
    {
        if(!magic(s2))
            return -1;

        int cost = square_cost(s,s2); 
        return cost;
    }
    else
    {

        if(pos == 3 || pos == 6)
        {
            int sLine = 0;
            for(int i = 0; i <= (pos-1)/3 ; i++)
            {
                for(int j = 0; j <= (pos-1)%3; j++)
                {
                    
                    sLine += s2[i][j];
                }

                if(sLine != 15 )
                    return -1;
            
                
                sLine = 0;
            }
        }
        
        int old_cost = -1;
        int new_cost = -1;
        for(int i = 1; i < 10; i++)
        {
            int aux = s2[pos/3][pos%3];
            s2[pos/3][pos%3] = i;
            new_cost = result(s,s2,pos+1);
            if(new_cost != -1)
            {
                if(old_cost == -1)
                    old_cost = new_cost;
                else if(old_cost > new_cost)
                        old_cost = new_cost;
            }
            s2[pos/3][pos%3] = aux;
        }

        return old_cost;
    }
    
}

int formingMagicSquare(vector < vector<int> > &s) {
    
    int cost = 0;
    vector< vector<int> > cpy_s(3,vector<int>(3));


    for(int i = 0;i < 3;i++)
       for(int j = 0;j < 3;j++)
        cpy_s[i][j] = s[i][j];

    cost = result(s,cpy_s,0);
    
    return cost;
}

int main() {
    vector< vector<int> > s(3,vector<int>(3));
    for(int s_i = 0;s_i < 3;s_i++){
       for(int s_j = 0;s_j < 3;s_j++){
          cin >> s[s_i][s_j];
       }
    }

    int result = formingMagicSquare(s);
    cout << result << endl; 
    return 0;
}
