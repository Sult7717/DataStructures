#include <iostream>

using namespace std;

void Breakpoints()
{
    double add = 1.0;
    double sum = 0.0;
    for (int i = 0; i < 10; i++)
    {
        sum += add * i;
        add *= 1.1;
    }
    cout << "Total sum is " << sum << endl;
}

int main()
{
    Breakpoints();
}

/*
Итерации
0. sum == 0
1. sum == 1.1000000000000001
2. sum == 3.5200000000000005
3. sum == 7.5130000000000017
4. sum == 13.369400000000004
5. sum == 21.421950000000010
6. sum == 32.051316000000014
7. sum == 45.692335700000022
8. sum == 62.841046180000035
9. sum == 84.062575399000053
*/
