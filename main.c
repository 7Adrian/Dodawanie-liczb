#include <stdio.h>
#include <stdlib.h>

/*  l1          - liczba 1
 *  l2          - liczba 2
 *  licz1       - dlugosc liczby 1
 *  licz2       - dlugosc liczby 2
 *  licz3       - dlugosc liczby 3
 *  wieksza     - wskazuje która z lczb 1 i 2 jest większa
 *  pozycz      - liczba pożyczona z wyższego rzędu podczas odejmowania
 *  wsk1        - wskaznik do liczba 1
 *  wsk2        - wskaznik do liczba 2
 *  wsk3        - wskaznik do liczba 3 wynik dodawania
 *  wsk4        - wskaznik do liczba 4 wynik odejmowania
 *  buffwsk;    - bufforowy wskaznik do swapu wskaźników
 *  ileliczba() - zwraca ile znaków powinna mieć nowa liczba
 *                (wskaznik liczba 1, wskaznik liczba 2, dlugosc liczby 1, dlugosc liczby 2)
 *  reszta      - część dziesiętna wyniku a+b>=10
 *  dodawanie() - oblicza liczba1 + liczba2 = liczba3
 *                (wskzanik liczba 1, wskaznik liczba 2, wskaznik liczba 3, dlugosc liczby 1, dlugosc liczby 2, dlugosc liczby 3)
 *  kwieksza()  - sprawdza która liczba jest większa
 *                (wskaznik liczba 1, wskaznik liczba 2, dlugosc liczby 1, dlugosc liczby 2)
 *  odejmowanie()-oblicza liczba1 - liczba2 = liczba4
 *                (wskaznik liczba 1, wskaznik liczba 2, wskaznik liczba 4, dlugosc liczby 1, dlugosc liczby 2)
 *  obetnij0()  - wycina 0 z początku liczby
 *                (dlugosc liczby, wskaznik do tej liczby)
 *
*/

int ileliczba(char *wsk1, char *wsk2, int licz1, int licz2) //(wskaznik liczba 1, wskaznik liczba 2, dl l1, dl l2)
{
    int reszta = 0;  //część dziesiętna wyniku a+b>=10
    char *buffwsk;   //bufforowy wskaznik do swapu wskaźników

    if (licz1<licz2) //zamienia liczby kolejnością tak by pierwsza z nich zawsze była większa
    {
        reszta = licz2;
        licz2  = licz1;
        licz1  = reszta;
        buffwsk = wsk1;
        wsk1  = wsk2;
        wsk2  = buffwsk;
        reszta = 0;
    }

    for (int i=licz1-1, j=licz2-1; i >= 0; i--, j--) //liczy wartość ostatniego przesunięcia w dodawaniu
    {
        if (j >= 0) //liczenie reszty z uwzględnianiem drugiej liczby
        {
            reszta = *(wsk1 + i) - '0' + *(wsk2 + j) - '0' + reszta; //sumowanie liczb i dodanie reszty
            reszta /= 10; //część dziesiętna wyniku a+b>=10
        }
        else //lieczenie reszty bez uwzględniania drugiej liczby
        {
            reszta = *(wsk1 + i) - '0' + reszta; //sumowanie liczb i dodanie reszty
            reszta /= 10; //część dziesiętna wyniku a+b>=10
        }

    }
    if (reszta!=0) return licz1+1; //nowa liczba będzie dłuższa
    else           return licz1;   //nowa lcizba nie będzie dłuższa
}

void dodawanie(char *wsk1, char *wsk2, char *wsk3, int licz1, int licz2, int licz3) //(wsk1, wsk2, wsk3, dl l1, dl l2, dl l3)
{
    int reszta = 0;  //część dziesiętna wyniku a+b>=10
    char *buffwsk;   //bufforowy wskaznik do swapu wskaźników

    if (licz1<licz2) //zamienia liczby kolejnością tak by pierwsza z nich zawsze była większa
    {
        reszta = licz2;
        licz2  = licz1;
        licz1  = reszta;
        buffwsk = wsk1;
        wsk1  = wsk2;
        wsk2  = buffwsk;
        reszta = 0;
    }

    for (int i=licz1-1, j=licz2-1; i >= 0; i--, j--) //liczy wartość ostatniego przesunięcia w dodawaniu
    {
        if (j >= 0) //liczenie reszty z uwzględnianiem drugiej liczby
        {
            reszta = *(wsk1 + i) - '0' + *(wsk2 + j) - '0' + reszta; //sumowanie liczb i dodanie reszty
            if (licz3 > licz1)
                 *(wsk3 + i + 1) = reszta % 10 + '0'; //tworzenie liczby 3 od prawej strony
            else *(wsk3 + i) = reszta % 10 + '0';

            reszta /= 10; //część dziesiętna wyniku a+b>=10
        }
        else //lieczenie reszty bez uwzględniania drugiej liczby
        {
            reszta = *(wsk1 + i) - '0' + reszta; //sumowanie liczb i dodanie reszty
            if (licz3 > licz1)
                 *(wsk3 + i + 1) = reszta % 10 + '0'; //tworzenie liczby 3 od prawej strony
            else *(wsk3 + i) = reszta % 10 + '0';

            reszta /= 10; //część dziesiętna wyniku a+b>=10
        }
    }
    if (reszta!=0) *wsk3 = reszta + '0'; //nowa liczba będzie dłuższa
    *(wsk3+licz3) = '\0';                //skończenie l3
}

int kwieksza(char *wsk1, char *wsk2, int licz1, int licz2) //(wskaznik liczba 1, wskaznik liczba 2, dl l1, dl l2)
{
    if (licz1>licz2) return 0;      //l1 jest większa
    else if (licz2>licz1) return 1; //l2 jest większa

    for (int i=0; i<licz1; i++)
    {
        if (*(wsk1+i)>*(wsk2+i))
            return 0;
        else if (*(wsk1+i)<*(wsk2+i))
            return 1;
    }
    return 2;
}

void odejmowanie(char *wsk1, char *wsk2, char *wsk4, int licz1, int licz2) //(wsk1, wsk2, wsk3, dl l1, dl l2)
{
    int pozycz = 0; //liczba pożyczona z wyższego rzędu podczas odejmowania

    for (int i = licz1 - 1, j = licz2 - 1; i>=0; i--, j--)
    {
        if (j>=0)   //uwzględnianie drugiej liczby
        {
            if(*(wsk1+i) - *(wsk2+j) - pozycz >= 0)               //odjemowanie pisemne
            {
                *(wsk4+i) = *(wsk1+i) - *(wsk2+j) - pozycz + '0'; //wpisanie wyniku
                pozycz = 0;
            }
            else
            {
                *(wsk4+i) = 10 + *(wsk1+i) - *(wsk2+j) - pozycz + '0'; //wpisanie wyniku
                pozycz = 1;
            }
        }
        else        //pominięcie drugiej liczby
        {
            if(*(wsk1+i) - pozycz - '0' >= 0)
            {
                *(wsk4+i) = *(wsk1+i) - pozycz;                     //wpisanie wyniku
                pozycz = 0;
            }
            else
            {
                *(wsk4+i) = 10 + *(wsk1+i) - pozycz;                //wpisanie wyniku
                pozycz = 1;
            }
        }
    }
    *(wsk4+licz1) = '\0';                //skończenie l3
    obetnij0(licz1, wsk4);               //obcina 0  z początku wskaźnika
}

void obetnij0(int dlugosc, char *wsk4) //wycina 0 z początku liczby
{
    for (int i=0; i < dlugosc && *(wsk4+i) == '0' ; i++) //szukanie 0 z początku
    {
        *(wsk4+i) = 127; //zastąpienie 0 pustym znakiem
    }
}

int main()
{
    char l1[]="100000000"; //Pierwsza liczba
    char l2[]="1";  //Druga Liczba

    int licz1 = sizeof(l1)-1; // dlugosc liczby l1
    int licz2 = sizeof(l2)-1; // dlugosc liczby l2
    int licz3 = 0;            // dlugosc liczby l3
    int wieksza;              // wskazuje ktora z liczb jest większa

    char *wsk1=&l1[0];        //wsk1 wskaźnik do pierwszej liczby
    char *wsk2=&l2[0];        //wsk2 wskaznik do drugiej liczby

    licz3 = ileliczba(wsk1, wsk2, licz1, licz2);      //Obliczenie dlugości trzeciej liczby
    char *wsk3 = (char*) calloc(licz3, sizeof(char)); //alokowanie pamięci na wynik (wskaznik)
    dodawanie(wsk1, wsk2, wsk3, licz1, licz2, licz3); //dodaje l1+l2=l3

    printf("%s + %s = %s\n", wsk1, wsk2, wsk3);       //wyświetlanie wyniku dodawania
    free(wsk3);                                       //czyszczenie pamięci

    char *wsk4;
    if (licz1>=licz2)                                //utworzenie zmiennej z odpowiednią ilością znaków
        wsk4 = (char*) calloc(licz1, sizeof(char)); //wynik odejmowania
    else
        wsk4 = (char*) calloc(licz2, sizeof(char)); //wynik odejmowania

    wieksza = kwieksza(wsk1, wsk2, licz1, licz2);    //spradza która liczba większa
    if (wieksza==2)                                  //obsługa równości l1 == l2
        printf("%s - %s = 0\n", wsk1, wsk2);         //wyświetlanie wyniku odejmowania
    else if (wieksza==0)                             //obsluga l1 > l2
    {
        odejmowanie(wsk1, wsk2, wsk4, licz1, licz2); //obliczanie wyniku odejmowania
        printf("%s - %s = %s\n", wsk1, wsk2, wsk4);  //wyświetlanie wyniku odejmowania
    }
    else                                             //obsługa l1 < l2
    {
        odejmowanie(wsk2, wsk1, wsk4, licz2, licz1); //obliczanie wyniku odejmowania
        printf("%s - %s = -%s\n", wsk1, wsk2, wsk4);  //wyświetlanie wyniku odejmowania
    }

    free(wsk4);                                      //czyszczenie pamięci
    return 0;
}
