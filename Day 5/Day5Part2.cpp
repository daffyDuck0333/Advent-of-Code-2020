#include <bits/stdc++.h>

using namespace std;


// Day 5 Part 2

int main()
{
    #ifndef ONLINE_JUDGE
    freopen ("inputfile.txt", "r", stdin);
    freopen ("outputfile.txt", "w", stdout);
    #endif   

    string s;
    vector < long long > v;

    

    int row = -24, column = -23;

    while (cin >> s)
    {
        int front = 0, back = 127, left = 0, right = 7;
        for (int i = 0; i < 7; i++)
        {
            if (s[i] == 'F')
            {
                back = round((back + front) / 2.0) - 1;
            }
            else
                front = round((back + front) / 2.0);


            if (front == back)
            {
                row = front;
            }
        }


        for (int i = 7; i < 10; i++)
        {
            if (s[i] == 'R')
            {
                left = round((left + right) / 2.0);
            }
            else
            {
                right = round((left + right) / 2.0) - 1;
            }

            if (right == left)
            {
                column = right;
            }
        }

        v.push_back(row * 8 + column);



    }

    sort(v.begin(), v.end());

    
    for (int i = 1, l = v.size(); i < l; i++)
    {
        if (v[i] <= 7)
            continue;
        if (v[i] >= 1016 and v[i] <= 1023)
            continue;
        if ((v[i] - 2 == v[i - 1]))
        {
            cout << v[i] - 1 << endl;
        }
    }
}
