#include <stdio.h>
#include <stdlib.h>
int x,S,s,v[1001],v1[1001],v2[1001],v3[1001],k,m,nr,l1,l2,l3,ok,dif,d1,d2,d3,s1,s2,s3;

int suma(int v[],int n)  /// functie pentru suma elementelor dintr-un vector
{
    int s=0;
    for(int i=1; i<=n; i++)
    {
        s+=v[i];
    }
    return s;
}
int maxim(int a,int b,int c)  ///functie pentru determinarea maximului dintre 3 numere
{
    int Max;
    if(a>b)
    {
        Max=a;
    }
    else
    {
        Max=b;
    }
    if(c>Max)
    {
        Max=c;
    }
    return Max;
}
int abs(int a)  ///functia modul
{
    if(a<0)
    {
        a=-a;
    }
    return a;
}
void deplasare_stanga(int v[],int n)  ///functie pentru deplasarea la stanga a elementelor unui vector
{
    for(int i=1; i<n; i++)
    {
        v[i]=v[i+1];
    }
}
void deplasare_dreapta(int v[],int n)   ///functie pentru deplasarea la dreapta a elementelor unui vector
{
    for(int i=n; i>1; i--)
    {
        v[i]=v[i-1];
    }
}
int main()
{

    printf("TEMA DE CASA \n\n\n");
    printf("DUPA CE INTRODUCETI VALORILE, TASTATI 0 SI APOI APASATI ENTER PENTRU A VEDEA REZULTATELE. \n");
    printf("INTRODUCETI VALORILE: ");
    while(scanf("%d",&x)) ///citire valori
    {
        if(x==0)
        {
            break;  ///conditie oprire citire
        }
        v[++k]=x;  ///se insereaza in vectorul principal valoarea citita
        S+=x;      ///se aduna valoarea la suma totala
    }
    if(k<3)
    {
        printf("EROARE: TREBUIE SA INTRODUCETI MINIM 3 VALORI");
        return 0;
    }
    if(k==3)
    {
        printf("%d -- ",v[1]);
        printf("%d -- ",v[2]);
        printf("%d ",v[3]);
        return 0;
    }
    m=S/3;    ///media pentru fiecare cititor (un numar aproximativ de pagini pentru fiecare cititor)
    nr=1;     ///se incepe numararea numararea cititorilor (primul o sa fie cititorul 1, adica v1)
    for(int i=1; i<=k; i++)  ///se parcurg elementele din vectorul principal
    {
        if(s+v[i]>m && nr<3)   ///daca numarul de pagini (s) al cititorului actual depaseste media, se trece la urmatorul cititor
        {
            nr++;
            s=0;              ///numarul de pagini devine 0 cand se trece la urmatorul cititor
        }
        s+=v[i];
        if(nr==1)
        {
            v1[++l1]=v[i];
        }
        if(nr==2)
        {
            v2[++l2]=v[i];
        }
        if(nr==3)
        {
            v3[++l3]=v[i];
        }
    }                         ///pana aici a fost o repartizare initiala a cartilor catre fiecare cititor
    while(ok==0)         ///incepe repartizarea finala a cartilor
    {
        s1=suma(v1,l1);  ///se calculeaza numarul de pagini care trebuie parcurs de fiecare cititor
        s2=suma(v2,l2);
        s3=suma(v3,l3);
        d1=abs(s1-s2);   ///se calculeaza diferenta dintre numerele de pagini ale fiecarui cititor
        d2=abs(s2-s3);
        d3=abs(s1-s3);
        dif=maxim(d1,d2,d3);   ///cea mai mare diferenta
        ok=1;
        if(dif==d1)   ///diferenta maxima este intre cititorii 1 si 2
        {
            if(abs(s1+v2[1]-(s2-v2[1]))<dif)  ///daca prin mutarea primei carti de la cititorul 2 la cititorul 1 obtinem o diferenta mai mica intre ei, se realizeaza mutarea
            {
                ok=0;
                l1++;
                v1[l1]=v2[1];
                deplasare_stanga(v2,l2);
                l2--;
            }
            if(abs(s1-v1[l1]-(s2+v1[l1]))<dif)   ///daca prin mutarea ultimei carti de la cititorul 1 la cititorul 2 obtinem o diferenta mai mica intre ei, se realizeaza mutarea
            {
                ok=0;
                l2++;
                deplasare_dreapta(v2,l2);
                v2[1]=v1[l1];
                l1--;
            }
        }
        if(dif==d2)      ///diferenta maxima este intre cititorii 2 si 3
        {
            if(abs(s2+v3[1]-(s3-v3[1]))<dif)   ///daca prin mutarea primei carti de la cititorul 3 la cititorul 2 obtinem o diferenta mai mica intre ei, se realizeaza mutarea
            {
                ok=0;
                l2++;
                v2[l2]=v3[1];
                deplasare_stanga(v3,l3);
                l3--;
            }
            if(abs(s2-v2[l2]-(s3+v2[l2]))<dif)    ///daca prin mutarea ultimei carti de la cititorul 2 la cititorul 3 obtinem o diferenta mai mica intre ei, se realizeaza mutarea
            {
                ok=0;
                l3++;
                deplasare_dreapta(v3,l3);
                v3[1]=v2[l2];
                l2--;
            }
        }
        if(dif==d3)    ///diferenta maxima este intre cititorii 1 si 3 (din moment ce ordinea cartilor nu se poate schimba, mutarea se poate realiza numai prin cititorul 2)
        {
            if(abs(s1+v2[1]-(s3-v3[1]))<dif)   ///se muta prima carte de la cititorul 2 la cititorul 1 si prima carte de la cititorul 3 la cititorul 2
            {
                ok=0;
                l1++;
                v1[l1]=v2[1];
                deplasare_stanga(v2,l2);
                v2[l2]=v3[1];
                deplasare_stanga(v3,l3);
                l3--;
            }
            if(abs(s1-v1[l1]-(s3+v2[l2]))<dif)   ///se muta ultima carte de la cititorul 1 la cititorul 2 si ultima carte de la cititorul 2 la cititorul 3
            {
                ok=0;
                l3++;
                deplasare_dreapta(v3,l3);
                v3[1]=v2[l2];
                deplasare_dreapta(v2,l2);
                v2[1]=v1[l1];
                l1--;
            }                                        ///daca s-au gasit diferentele minime intre cititori, variabila "ok" ramane 1 si se iese din while
        }
    }
    for(int i=1; i<=l1; i++)     ///afisare carti pentru fiecare cititor
    {
        printf("%d ",v1[i]);
    }
    printf("-- ");
    for(int i=1; i<=l2; i++)
    {
        printf("%d ",v2[i]);
    }
    printf("-- ");
    for(int i=1; i<=l3; i++)
    {
        printf("%d ",v3[i]);
    }
    return 0;
}
