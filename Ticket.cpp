#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class BookTicket
{
    int num_seats, num_stations;

public:
    BookTicket(int x, int y)
    {
        num_seats = x;
        num_stations = y;
    }
    bool bookingTicket()
    {
        int arr[num_seats + 1][num_stations + 1] = {{0}};
        // If you initialize some (but not all) of the elements, the rest will be initialized to zero.
        //  Here, you are only explicitly initializing the first element of the first sub-array and the compiler is taking care of the rest.
        while (1)
        {
            int a, b;
            cout << "Enter departure station:[1-10] ";
            cin >> a;
            cout << "Enter destination station[1-10]: ";
            cin >> b;
            if (a > num_stations || a <= 0 || b > num_stations)
            {
                cout << "INVALID INPUT\nTRY AGAIN\n";
                continue;
            }
            int s = 0, i, j;
            for (i = 1; i <= num_seats; ++i)
            {
                int c = 0;
                for (j = a; j < b; ++j)
                {
                    if (arr[i][j] == 0)
                        ++c;
                }
                if (c == (b - a))
                {
                    cout << "Your seat number: " << i << endl;
                    s = i;
                    break;
                }
            }
            if (s != 0)
            {
                for (i = s, j = a; j < b; ++j)
                    arr[i][j] = 1;
            }
            if (i == num_seats + 1)
            {
                cout << "\nNo Single seat left for whole journey !" << endl;
                cout << "Do you want cutting seats !" << endl;
                cout << "\nPress 1 for cutting seat and 0 to exit: ";
                int c;
                cin >> c;
                if (c == 0)
                    break;
                else
                {
                    vector<pair<int, int>> ans;
                    for (j = a; j < b; ++j)
                    {
                        for (i = 1; i <= num_seats; ++i)
                        {
                            if (arr[i][j] == 0)
                                ans.push_back({i, j});
                        }
                    }
                    if (ans.size() == (b - a))
                    {
                        cout << "Your respective seats are :\n"
                             << endl;
                        for (auto it : ans)
                        {
                            cout << "For station " << it.second << " to station " << (it.second + 1) << " seat number :" << it.first << endl;
                        }
                    }
                    else
                        cout << "Sorry! no cutting seat left" << endl;
                }
            }
            cout<<"Do you want to book another ticket? [y/n] "<<endl;
            char ch;
            cin>>ch;
            if(ch=='y') continue;
            else break;
        }
    }
};