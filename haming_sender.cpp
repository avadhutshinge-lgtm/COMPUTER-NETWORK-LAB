#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string code;

    cout << "Enter received Hamming code: ";
    cin >> code;

    int total = code.length();

    vector<int> h(total + 1);

    for (int i = 1; i <= total; i++)
        h[i] = code[i - 1] - '0';

    // Find number of redundant bits
    int r = 0;

    while ((1 << r) <= total)
    {
        r++;
    }

    cout << "\nReceived Code: " << code << endl;
    cout << "Total bits: " << total << endl;
    cout << "Redundant bits: " << r << endl;

    int errorPosition = 0;

    cout << "\nChecking redundant bits:\n";

    // Calculate syndrome
    for (int p = 1; p <= total; p *= 2)
    {
        int parity = 0;

        cout << "\nR" << p << " checks positions: ";

        for (int i = 1; i <= total; i++)
        {
            if (i & p)
            {
                cout << i << " ";
                parity ^= h[i];
            }
        }

        cout << "\nR" << p << " = " << parity << endl;

        if (parity == 1)
            errorPosition += p;
    }

    cout << "\nError position = " << errorPosition << endl;

    if (errorPosition == 0)
    {
        cout << "No error detected." << endl;
    }
    else if (errorPosition <= total)
    {
        cout << "Error detected at position: "
             << errorPosition << endl;

        // Correct error
        h[errorPosition] ^= 1;

        cout << "Corrected code: ";

        for (int i = 1; i <= total; i++)
            cout << h[i];

        cout << endl;
    }
    else
    {
        cout << "Error position is outside codeword." << endl;
    }

    // Extract original data
    string data = "";

    for (int i = 1; i <= total; i++)
    {
        if ((i & (i - 1)) != 0)
        {
            data += char(h[i] + '0');
        }
    }

    cout << "Original data: " << data << endl;

    return 0;
}