#include <iostream>
#include <stdlib.h>
#include <time.h>

#define max 9

using namespace std;

class pozicija
{
    public:
    int x;
    int y;
    int broj;
};

pozicija poz;
pozicija temp;

void kreirajTablu(int grid[max][max], int size)
{
    int i,j;
    int random, randbr;
    srand(time(0));
    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            random = rand() % 100;
            if(random < 35)
            {
                randbr = 1 + rand() % 9;
                grid[i][j] = randbr;
            }
        }
    }
}

void ispisTable(int grid[max][max], int size)
{
    int a,b;
    cout << "Evo je trenutna tabla" << endl;
    cout << "Prvo unosis poziciju pa broj" << endl << endl;;
    cout << "   1 2 3 4 5 6 7 8 9" << endl;
    cout << "  __________________" << endl;
    for(a = 0; a < size; a++)
    {
        cout << a+1 << "| ";
        for(b = 0; b < size; b++)
        {
            cout << grid[a][b] << " ";
        }
            cout << endl;
    }
}

void proveraTable(int grid[max][max], int size)
{
    int j,k,z;
    for(k = 0; k < size; k++)
    {
        for(j = 0; j < size; j++)
        {
            for(z = 0; z < size; z++)
            {
                if(grid[k][j] == grid[k][z])
                {
                    if(j == z){
                        continue;
                    }
                    grid[k][z] = 0;
                }
            }
        }
    }

    for(k = 0; k < size; k++)
    {
        for(j = 0; j < size; j++)
        {
            for(z = 0; z < size; z++)
            {
                if(grid[j][k] == grid[z][k])
                {
                    if(j == z)
                    {
                        continue;
                    }
                    grid[k][z] = 0;
                }
            }
        }
    }
}

void kraj(int grid[max][max], int size)
{
    int i,j;
    int brpoz = 0;
    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            if(grid[i][j] != 0)
            {
                brpoz++;
            }
        }
        if(brpoz == 81)
        {
            cout << "Kraj. Pobedio si." << endl;
        }
    }
}

void check(int grid[max][max], int size, bool *T, int x, int y)
{
    int j;
    *T = true;
            for(j = 0; j < size; j++)
            {
                if(grid[x][y] == grid[x][j])
                {
                    if(y == j)
                    {
                        continue;
                    }
                    grid[x][y] = 0;
                    *T = false;
                    break;
               }
            }
            for(j = 0; j < size; j++)
            {
                if(grid[x][y] == grid[j][y])
               {
                   if(x == j)
                   {
                       continue;
                   }
                   grid[x][y] = 0;
                   *T = false;
                   break;
               }
            }
}

void swap(int grid[max][max], int pozx, int pozy)
{
    tu:
    cout << "S kojim cete elementom da ga zamenite?" << endl;
    int x,y;
    cin >> x >> y;
    x--; y--;
    if((x >= 10) || (y >= 10))
    {
        printf("Nemoguce koordinate...");
        goto tu;
    }
    temp.broj = grid[pozx][pozy];
    grid[pozx][pozy] = grid[x][y];
    grid[x][y] = temp.broj;
}

int main()
{
    int tabla[9][9] = {0};
    kreirajTablu(tabla,9);
    proveraTable(tabla,9);
    ispisTable(tabla, 9);
    bool T = true;

    while(1)
    {
        pocetak:
        cout << "Izaberi poziciju. Prvo koordinate pa broj." << endl;
        cin >> poz.x >> poz.y;
        if(poz.x >= 10 || poz.y >= 10)
        {
            cout << "Pogresan unos. ";
            goto pocetak;
        }
        poz.x--; poz.y--;
        if(tabla[poz.x][poz.y] != 0)
        {
            swap(tabla,poz.x,poz.y);
            ispisTable(tabla,9);
            goto pocetak;
        }
        cin >> poz.broj;
        if(poz.broj >= 10)
        {
            cout << "Pogresan unos. ";
            goto pocetak;
        }
        tabla[poz.x][poz.y] = poz.broj;
        check(tabla, 9, &T, poz.x, poz.y);
        if(T == false)
        {
            cout << "Ne moze" << endl;
            ispisTable(tabla,9);
            goto pocetak;
        }
        ispisTable(tabla,9);
        kraj(tabla,9);
    }
    

    return 0;
}