#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;

int main()
{
    const int MAXPILE=3;
    bool pileVide=false, finJeu=false, bot=false;
    string player1, player2, player,robot;
    char pile,stay,choiceGame,robotChoicePile;
    int A,B,C,retirBato, cptPlayer(1), maxVal, winPlayer1(0), winPlayer2(0) , win(0),cptRobot(0);

    robot="MrRobot";

    cout << "#############################################" << endl;
    cout << "#                                           #" << endl;
    cout << "#                                           #" << endl;
    cout << "#               Le Jeu de Nim               #" << endl;
    cout << "#                                           #" << endl;
    cout << "#                                           #" << endl;
    cout << "#############################################" << endl;

    cout << "Voulez-vous jouer contre l'ordinateur ? o/n : ";
    cin >> choiceGame;

    cout << "Nom du premier joueur : ";
    cin >> player1;
    if (choiceGame=='n'){
        cout << "Nom du deuxième joueur : ";
        cin >> player2;
    }
    else{
        cout << "Vous jouez contre l'ordinateur !" << endl;
        bot=true;
    }
    cout << "Nombre de batonnet(s) au maximum : ";
    cin >> maxVal;
    while (maxVal <= 0){
        cout << "La valeur maximale est incorrect veuillez en entrer une nouvelle: ";
        cin >> maxVal;
    }
    srand(time(NULL));
    A=rand()%maxVal + 1;
    B=rand()%maxVal + 1;
    C=rand()%maxVal + 1;
    stay='o';

    do{
        win=0;
        if (bot){
            if(cptRobot>1){
                cptRobot=0;
            }
            if(cptRobot==0){
                player=player1;
            }
            else{
                player=robot;
            }
        }
        else{
            if (cptPlayer>2){
                cptPlayer=1;
            }
            if(cptPlayer==1){
                player=player1;
            }
            else{
                player=player2;
            }
        }


        // Affichage des piles :

        cout << "Pile A: ";
        for(int i=0;i<A;i++){
            cout<<'|';
        }
        cout << endl;
        cout << "Pile B: ";
        for(int j=0;j<B;j++){
            cout<<'|';
        }
        cout << endl;
        cout<<"Pile C: ";
        for(int k=0;k<C;k++){
            cout<<'|';
        }
        cout << endl;

        // Début des choix du joueurs en fonction de la pile :

        if (cptRobot==0){
            cout << player << " choisissez une pile : ";
            cin >> pile;
        }
        else{
            robotChoicePile=rand()%MAXPILE+1;
            switch(robotChoicePile){
                case 1:{
                    pile='A';
                    if(A!=0){
                        retirBato=rand()%A+1;
                    }
                } break;
                case 2:{
                    pile='B';
                    if(B!=0){
                        retirBato=rand()%B+1;
                    }
                } break;
                case 3:{
                    pile='C';
                    if(C!=0){
                        retirBato=rand()%C+1;
                    }
                } break;
            }
        }

        if(pileVide==false){
            while (pile!='A' && pile!='B' && pile!='C'){
                cout << "Veuillez saisir une pile valide : ";
                cin >> pile;
            }
            switch(pile){
                case 'A' :{
                    if(A==0){
                        cout<<player<<" a perdu !"<<endl;
                        pileVide=true;
                        finJeu=true;
                        if (player==player1){
                            winPlayer2=winPlayer2+1;
                        }
                        else{
                            winPlayer1=winPlayer1+1;
                        }
                    }
                    else{
                        if (cptRobot==0){
                            cout << "Combien de batonnet(s) voulez vous prélever : ";
                            cin >> retirBato;
                            while(retirBato > A || retirBato <= 0){
                                cout << "Veuillez saisir un prélevement valide : ";
                                cin >> retirBato;
                            }
                        }
                        else{
                            cout << player << " a choisit la pile " << pile << " et a retiré " << retirBato << " batonnet(s)." << endl;
                        }
                        A=A-retirBato;
                        if(bot){
                            cptRobot=cptRobot+1;
                        }
                        else{
                            cptPlayer=cptPlayer+1;
                        }
                    }
                } break;
                case 'B' :{
                    if(B==0){
                        cout<<player<<" a perdu !"<<endl;
                        pileVide=true;
                        finJeu=true;
                        if (player==player1){
                            winPlayer2=winPlayer2+1;
                        }
                        else{
                            winPlayer1=winPlayer1+1;
                        }
                    }
                    else{
                        if (cptRobot==0){
                            cout << "Combien de batonnet(s) voulez vous prélever : ";
                            cin >> retirBato;
                            while(retirBato > B || retirBato <= 0){
                                cout << "Veuillez saisir un prélevement valide : ";
                                cin >> retirBato;
                            }
                        }
                        else{
                            cout << player << " a choisit la pile " << pile << " et a retiré " << retirBato << " batonnet(s)." << endl;
                        }
                        B=B-retirBato;
                        if(bot){
                            cptRobot=cptRobot+1;
                        }
                        else{
                            cptPlayer=cptPlayer+1;
                        }
                    }
                } break;
                case 'C' :{
                    if(C==0){
                        cout<<player<<" a perdu !"<<endl;
                        pileVide=true;
                        finJeu=true;
                        if (player==player1){
                            winPlayer2=winPlayer2+1;
                        }
                        else{
                            winPlayer1=winPlayer1+1;
                        }
                    }
                    else{
                        if (cptRobot==0){
                            cout << "Combien de batonnet(s) voulez vous prélever : ";
                            cin >> retirBato;
                            while(retirBato > C || retirBato <= 0){
                                cout << "Veuillez saisir un prélevement valide : ";
                                cin >> retirBato;
                            }
                        }
                        else{
                            cout << player << " a choisit la pile " << pile << " et a retiré " << retirBato << " batonnet(s)." << endl;
                        }
                        C=C-retirBato;
                        if(bot){
                            cptRobot=cptRobot+1;
                        }
                        else{
                            cptPlayer=cptPlayer+1;
                        }
                    }
                } break;
            }

            // Vérification de Victoire :

            if (A==0 && B==0 && C==0){
                if (player==player1){
                    winPlayer1=winPlayer1+1;
                    win=winPlayer1;
                }
                else{
                    winPlayer2=winPlayer2+1;
                    win=winPlayer2;
                }

                cout << player << " gagne la partie et possède "<< win << " victoire(s)."<< endl;
                finJeu=true;
            }
        }

        // Demande aux joueurs si ils souhaitent refaire une partie et réinitialise si Oui

        if(finJeu==true){
            cout << "Voulez vous recommencer : o/n : ";
            cin >> stay;
            if(stay=='o'){
                cout << "Nombre de batonnet(s) au maximum : ";
                cin >> maxVal;
                while (maxVal <= 0){
                    cout << "La valeur maximale est incorrect veuillez en entrer une nouvelle : ";
                    cin >> maxVal;
                }
                cptRobot=0;
                cptPlayer=0;
                A=rand()%maxVal + 1;
                B=rand()%maxVal + 1;
                C=rand()%maxVal + 1;
                finJeu=false;
                pileVide=false;
            }
            else{
                if(bot){
                    player2=robot;
                }
                cout << "Les scores finals sont :" << endl << player1 << " : " << winPlayer1 << " victoire(s) et "<< winPlayer2 << " défaite(s)."<< endl << player2 << " : " << winPlayer2 << " victoire(s) et "<< winPlayer1 << " défaite(s).";;
            }
        }
    } while(stay=='o');
    return 0;
}
