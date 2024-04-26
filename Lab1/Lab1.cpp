#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

bool nextPermutation(vector<int>& P) {
    int n = P.size();

    int i = n - 2;
    while (i >= 0 && P[i] >= P[i + 1]) {
        i--;
    }

    if (i == 1 ) {
        return false;
    }

    int j = n - 1;
    while (P[j] <= P[i]) {
        j--;
    }

    if (P[j] == P[i]) {
        return false;
    }

    swap(P[i], P[j]);
    reverse(P.begin() + i + 1, P.end());

    return true;
}
int main()
{
    int mass[256][256], n;

    cout << "Vvedite kolichestvo gorodov" << endl;
    cin >> n;
    cout << "Postavti dlinu puti iz odnogo goroda v drugoy. Yesli put otsivstvuet, postavte 0." << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mass[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (i != j)
            {
                cout << "Iz goroda " << i + 1 << " v gorod " << j + 1 << ": ";
                cin >> mass[i][j];
                mass[j][i] = mass[i][j];
            }
        }
    }
    cout << "Poluchim matritsu vesov" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mass[i][j] << " ";
            if (j == n - 1)
            {
                cout << endl;
            }
        }

    }

    vector<int> cities(n);
    for (int i = 0; i < n; i++)
    {
        cities[i] = i;
    }

    int min_distance = INT_MAX;
    vector<int> best_route;

    do
    {
        int distance = 0;
        for (int i = 0; i < n - 1; i++)
        {
            distance += mass[cities[i]][cities[i + 1]];
        }
        distance += mass[cities[n - 1]][cities[0]];

        if (distance < min_distance)
        {
            min_distance = distance;
            best_route = cities;
        }

        cout << "Marshrut: ";
        for (int i = 0; i < n; i++)
        {
            cout << cities[i] + 1 << " ";
        }
        cout << "\nRastoyaniy: " << distance << endl;

    } while (nextPermutation(cities));


    cout << "Korotkiy marshtrut: ";
    for (int i = 0; i < n; i++)
    {
        cout << best_route[i] + 1 << " ";
    }
    cout << "\nObshee rastoyaniy: " << min_distance << endl;

    system("pause");
    return 0;
}