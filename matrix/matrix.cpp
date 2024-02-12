#include <iostream>
#include <ctime>
#include <Windows.h>
#include <stdlib.h>
#include <iomanip>
using namespace std;

int main() {
    srand(time(0));
    int m, n, i, j, a[50][50], b[2500], p, e, k, q, z;
    bool t;
    COORD pos, posv, posc, posa, posb;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    cout << "N = "; cin >> n;   // Initialization of variables and arrays, user input of matrix sizes (n, m)
    cout << "M = "; cin >> m;

    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            a[i][j] = rand() % 101 - 10; // Fills the matrix with random numbers in the given range [-10, 90]

    pos.X = 30;
    k = 1;

    //	Arrange animated display of matrix elements in columns with changing text color

    for (j = 0; j < m; j++) {
        cout << '\n';
        pos.Y = 5;
        for (i = 0; i < n; i++) {
            SetConsoleCursorPosition(hConsole, pos);
            SetConsoleTextAttribute(hConsole, k);
            printf("%6d", a[i][j]);
            for (e = 1; e < 1e+8; e++); // animation delay and using the 'e' variable to create an artificial delay
            pos.Y += 2;
        }
        k++;
        pos.X += 6;
    }

    posv.X = 1;
    posv.Y = pos.Y + 3;
    pos.X = 30;
    cout << '\n';

    // Search for columns where all elements are positive and display animatedly

    for (j = 0; j < m; j++) {
        t = true;
        for (i = 0; i < n; i++) {
            if (a[i][j] <= 0) {
                t = false;
                break;
            }
        }
        if (t) {
            p = j;
            k = j + 1;
            for (i = 0; i < n; i++) {
                posc.X = pos.X + j * 6;
                pos.Y = 5 + i * 2;
                for (posc.Y = pos.Y; posc.Y < posv.Y - 1; posc.Y++) {
                    SetConsoleCursorPosition(hConsole, posc);
                    SetConsoleTextAttribute(hConsole, k);
                    cout << setw(3) << a[i][j];
                    for (e = 1; e < 1e+8; e++);
                    SetConsoleCursorPosition(hConsole, posc);
                    cout << "   ";
                }
                if (posc.X < posv.X) {
                    while (posc.X < posv.X) {
                        for (e = 1; e < 1e+8; e++);
                        SetConsoleCursorPosition(hConsole, posc);
                        cout << "   ";
                        posc.X++;
                        SetConsoleCursorPosition(hConsole, posc);
                        SetConsoleTextAttribute(hConsole, k);
                        cout << setw(3) << a[i][j];
                    }
                    for (e = 1; e < 1e+8; e++);
                    SetConsoleCursorPosition(hConsole, posc);
                    cout << "   ";
                    posc.Y++;
                    SetConsoleCursorPosition(hConsole, posc);
                    SetConsoleTextAttribute(hConsole, k);
                    cout << setw(3) << a[i][j];
                    for (e = 1; e < 1e+8; e++);
                }
                else {
                    while (posc.X > posv.X) {
                        for (e = 1; e < 1e+8; e++);
                        SetConsoleCursorPosition(hConsole, posc);
                        cout << "   ";
                        posc.X--;
                        SetConsoleCursorPosition(hConsole, posc);
                        SetConsoleTextAttribute(hConsole, k);
                        cout << setw(3) << a[i][j];
                    }
                    for (e = 1; e < 1e+8; e++);
                    SetConsoleCursorPosition(hConsole, posc);
                    cout << "   ";
                    SetConsoleCursorPosition(hConsole, posv);
                    SetConsoleTextAttribute(hConsole, k);
                    cout << setw(3) << a[i][j];
                    for (e = 1; e < 1e+8; e++);
                }
                posv.X += 3;
            }
            k++;
        }
    }
    cout << endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    // Assembling positive elements into 'a' one-dimensional array 'b'
    q = -1;
    for (j = 0; j < m; j++) {
        t = true;
        for (i = 0; i < n; i++) {
            if (a[i][j] <= 0) {
                t = false;
                break;
            }
        }
        if (t) {
            for (i = 0; i < n; i++) {
                q++;
                b[q] = a[i][j];
            }
        }
    }
    // Sorting an array 'b' using the selection method with animated output of each sort step
    for (k = 0; k < q; k++) {
        i = k;
        for (j = i + 1; j <= q; j++)
            if (b[j] < b[i]) i = j;
        if (i > k) {
            posb.Y = posc.Y = posa.Y = posv.Y;
            posa.X = 1 + 3 * k;
            posv.X = 1;
            posb.X = posc.X = 1 + 3 * i;
            SetConsoleCursorPosition(hConsole, posa);
            cout << "   ";
            posa.Y--;
            SetConsoleCursorPosition(hConsole, posa);
            cout << setw(3) << b[k];
            SetConsoleCursorPosition(hConsole, posb);
            cout << "   ";
            posb.Y++;
            SetConsoleCursorPosition(hConsole, posb);
            cout << setw(3) << b[i];
            while (posa.X != posc.X) {
                SetConsoleCursorPosition(hConsole, posa);
                cout << "   ";
                posa.X++;
                SetConsoleCursorPosition(hConsole, posa);
                cout << setw(3) << b[k];
                SetConsoleCursorPosition(hConsole, posb);
                cout << "   ";
                posb.X--;
                SetConsoleCursorPosition(hConsole, posb);
                cout << setw(3) << b[i];
                for (e = 1; e < 1e+8; e++);
            }
            SetConsoleCursorPosition(hConsole, posb);
            cout << "   ";
            posb.Y--;
            SetConsoleCursorPosition(hConsole, posb);
            cout << setw(3) << b[i];
            SetConsoleCursorPosition(hConsole, posa);
            cout << "   ";
            posa.Y++;
            SetConsoleCursorPosition(hConsole, posa);
            cout << setw(3) << b[k];
            z = b[k];
            b[k] = b[i];
            b[i] = z;

        }
    }

    cout << '\n';



    return 0;
}
