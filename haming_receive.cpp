#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string data;

    cout << "Enter data bits: ";
    cin >> data;

    int m = data.length();

    // Calculate number of redundant bits
    int r = 0;

    while ((1 << r) < (m + r + 1))
    {
        r++;
    }

    int total = m + r;

    vector<int> h(total + 1, 0);

    // ------------------------------------------------
    // Place data bits
    // Redundant bits are at positions 1,2,4,8,...
    // ------------------------------------------------

    int j = 0;

    for (int i = 1; i <= total; i++)
    {
        if ((i & (i - 1)) != 0)   // not power of 2
        {
            h[i] = data[j] - '0';
            j++;
        }
    }

    cout << "\nData bits: " << data << endl;
    cout << "Number of data bits (m): " << m << endl;
    cout << "Number of redundant bits (r): " << r << endl;
    cout << "Total bits: " << total << endl;

    cout << "\nRedundant bit calculation:\n";

    // ------------------------------------------------
    // Calculate redundant bits
    // ------------------------------------------------

    for (int p = 1; p <= total; p *= 2)
    {
        int parity = 0;

        cout << "\nR" << p << " checks positions: ";

        for (int i = 1; i <= total; i++)
        {
            if (i & p)
            {
                cout << i << " ";
                
                if (i != p)
                    parity ^= h[i];
            }
        }

        h[p] = parity;

        cout << "\nR" << p << " = " << parity << endl;
    }

    // ------------------------------------------------
    // Display final codeword
    // ------------------------------------------------

    cout << "\nPosition: ";

    for (int i = 1; i <= total; i++)
        cout << i << " ";

    cout << "\nBits:     ";

    for (int i = 1; i <= total; i++)
        cout << h[i] << " ";

    cout << "\n\nFinal Hamming Code: ";

    for (int i = 1; i <= total; i++)
        cout << h[i];

    cout << endl;

    return 0;
}