#include <iostream>
using namespace std;

int main()
{
    string s;

    cout << "Enter the string: ";
    cin >> s;

    int countA = 0, countB = 0;
    int length = s.length();

    for (int i = 0; i < length; i++)
    {
        if (s[i] == 'A')
        {
            countA++;
        }

        else if (s[i] == 'B')
        {
            countB++;
        }

        else if (s[i] == '-')
        {
            int ldist = -1;
            int rdist = -1;
            for (int j = i - 1; j >= 0; j--)
            {
                if (s[j] != '-')
                {
                    ldist = i - j;
                    break;
                }
            }

            for (int j = i + 1; j < length; j++)
            {
                if (s[j] != '-')
                {
                    rdist = j - i;
                    break;
                }
            }

            if (ldist != -1 && rdist != -1)
            {
                if (ldist < rdist)
                {
                    if (s[i - ldist] == 'A')
                        countA++;
                    else
                        countB++;
                }

                else if (rdist < ldist)
                {
                    if (s[i + rdist] == 'A')
                        countA++;
                    else
                        countB++;
                }

            }
            else if (ldist != -1)
            {
                if (s[i - ldist] == 'A')
                    countA++;
                else
                    countB++;
            }

            else if (rdist != -1)
            {
                if (s[i + rdist] == 'A')
                    countA++;
                else
                    countB++;
            }
        }
    }
    if (countA > countB)
    {
        cout << "A" << endl;
    }
    else if (countB > countA)
    {
        cout << "B" << endl;
    }
    else
    {
        cout << "Coalition government" << endl;
    }
    return 0;
}