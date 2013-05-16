#include <iostream>
using namespace std;


void echanger (int &a, int &b) // entré sortie a et b
{
    int c;
    c=a;
    a=b;
    b=c;
    
}
// fonction partionner
int partionner(int tableau [], int pos1,int posd,int pivot) // "entré sortie tableau"  pos1 et posD et pivo entré
{
    
    echanger(tableau [posd],tableau[pivot]);
    
    int j =pos1;
    
    for (int i=pos1;i<posd;i++)
    {
        
        if ( tableau[i]<tableau[posd])
        {
            echanger(tableau[i],tableau[j]);
            j++;
        }
        
    }
    
    echanger (tableau[j],tableau [posd]);
    
    return j; // algo
    
}
// procedure ecrire tableau
void ecriretableau(int tableau[])
{
    cout<<"tableau : ";
    for(int i=0;i<10;i++)
    {
        cout<<tableau[i]<<";";  // pas algo
    }
    cout<<endl;
}
// fonction triRapide
void triRapide(int tableau[],int pos1,int posd)  // entré sortie tableau"  pos1 et posD  entré
{
    int pivot;
    
    if(pos1<posd)
    {
        pivot=pos1;                     // algo
        
        pivot=partionner(tableau,pos1,posd,pivot);
        triRapide(tableau,pos1,pivot-1);
        triRapide(tableau,pivot+1,posd);
    }
}

int main(int argc, const char * argv[])
{
    
    // tester la fonction echanger
    cout<<"teste de la fonction echanger :"<<endl<<endl;
    ;
    int a=3;
    int b=5;
    cout<<" a="<<a<<endl;
    cout<<" b="<<b<<endl;
    echanger (a,b);
    cout<<"echange de valeur :"<<endl;
    cout<<" a="<<a<<endl;// a ete modifié avec b, on obtient 5
    cout<<" b="<<b<<endl;     // b ete modifié avec a, on obtient 3
    
    // fonction partionner
    
    cout<<"test de la fonction partionner :"<<endl;
    
    int tableau[10]={1,4,6,2,10,9,3,7,5,8};
    
    int pivot=partionner(tableau,0,9,6); // le pivot a l'indice 6 correspond a la valeur 3 du tableau
    
    ecriretableau(tableau);
    cout<<"nouvel indicie du pivot :"<<pivot<<endl;  // c'est le nouvel indice de la valeur 3
    
    // fonction triRapide
    cout<<"test de la fonction triRapide :"<<endl;
    triRapide(tableau,0,9);
    ecriretableau(tableau);
    
    
    
    
    
    
    
    
    
    return 0;
}

