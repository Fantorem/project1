#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;

int main()
{
    bool gagne, perdu, pileVide=false, finJeu=false;
    string player1, player2, player;
    char pile,stay;
    int A,B,C,retirBato, cptPlayer(1), max;
    cout << "Nom du premier Joueur : " << endl;
    cin >> player1;
    cout << "Nom du deuxième Joueur : " << endl;
    cin >> player2;
    cout << "Nombre de baton au maximum : ";
    cin >> max;
    while (max <= 0){
        cout << "La valeur maximale est incorrect veuillez en entrer une nouvelle: ";
        cin >> max;
    }
    srand(time(NULL));
    A=rand()%max + 1;
    B=rand()%max + 1;
    C=rand()%max + 1;
    stay='o';

    do{
        if (cptPlayer>2){
            cptPlayer=1;
        }
        if(cptPlayer==1){
            player=player1;
        }
        else{
            player=player2;
        }
        cout << "A: ";
        for(int i=0;i<A;i++){
            cout<<"|";
        }
        cout << "     ";
        cout << "B: ";
        for(int j=0;j<B;j++){
            cout<<"|";
        }
        cout << "     ";
        cout<<"C:";
        for(int k=0;k<C;k++){
            cout<<'|';
        }
        cout <<"     " << endl;

        cout << player << " choisissez une pile : ";
        cin >> pile;
        if(pile=='A')
        {
            if(A==0)
            {
                cout<<player<<" a perdu !"<<endl;
                pileVide=true;
                finJeu=true;

            }
        }
        else if(pile=='B')
        {
            if(B==0)
            {
                cout<<player<<" a perdu !"<<endl;
                pileVide=true;
                finJeu=true;
            }
        }
        else
        {
            if(C==0)
            {
                cout<<player<<" a perdu !"<<endl;
                pileVide=true;
                finJeu=true;
            }
        }
        if(pileVide==false)
        {
            while (pile!='A' && pile!='B' && pile!='C'){
                cout << "Veuillez saisir une pile valide : ";
                cin >> pile;
            }
            cout << "Combien de baton voulez vous prélever : ";
            cin >> retirBato;
            switch(pile){
                case 'A' :{
                    while(retirBato >A || retirBato<=0)
                    {
                        cout << "Veuillez saisir un prélevement valide : ";
                        cin >> retirBato;
                    }
                    A=A-retirBato;

                }break;
                case 'B' :{
                    while(retirBato > B || retirBato <= 0){
                        cout << "Veuillez saisir un prélevement valide : ";
                        cin >> retirBato;
                    }
                    B=B-retirBato;
                }break;
                case 'C' :{
                    while(retirBato > C || retirBato <= 0){
                        cout << "Veuillez saisir un prélevement valide : ";
                        cin >> retirBato;
                    }
                    C=C-retirBato;
                }break;
            }

            if (A==0 && B==0 && C==0)
            {
                cout << player << " gagne la partie"<< endl;
                finJeu=true;
            }
        cptPlayer=cptPlayer+1;
        }
        if(finJeu==true)
        {
            cout << "Voulez vous recommencer : o/n : ";
            cin >> stay;
            if(stay=='o'){
                A=rand()%max + 1;
                B=rand()%max + 1;
                C=rand()%max + 1;
                finJeu=false;
                pileVide=false;
            }
        }

    }while(stay=='o');
    return 0;
}
