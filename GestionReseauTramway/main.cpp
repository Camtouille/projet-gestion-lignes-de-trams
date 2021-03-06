#include "ligne.h"
#include <fstream>
#include <windows.h>
#include "graphics.h"
#include "listeligne.h"

void chargerLigne(ligne & l, const std::string & nomFichier)
{
    std::ifstream fin(nomFichier);
    int nbLignes, nbTram, nbArret, numTram;
    double vitesseMax, distMinTram, tempsRestantArret, distanceArret;
    bool vitesse, sensDeplacement;
    std::string nomArret, nomProchainArret, nomArretPrecedent;
    int dureeArret;
    pos positionArret;
    fin >> nbLignes;
    for(int i = 0 ; i<nbLignes ; ++i)
    {
        fin >> nbArret;
        for(int j = 0 ; j<nbArret ; ++j)
        {
            fin >> nomArret >> dureeArret >> positionArret.x >> positionArret.y;
            l.ajouterArret(nomArret, dureeArret, positionArret);
        }
        fin >> nbTram;
        for(int j = 0 ; j<nbTram ; ++j)
        {
            fin >> numTram >> vitesseMax >> vitesse >> distMinTram >> tempsRestantArret >> distanceArret >> sensDeplacement >> nomProchainArret >> nomArretPrecedent;
            l.ajouterTram(numTram, vitesseMax, vitesse, distMinTram, tempsRestantArret, distanceArret, sensDeplacement, l.chercherArret(nomProchainArret), l.chercherArret(nomArretPrecedent));
        }
    }
}

void chargerLignes(listeligne & l, const std::string & nomFichier)
{
    std::ifstream fin(nomFichier);
    int nbLignes, nbTram, nbArret, numTram;
    double vitesseMax, distMinTram, tempsRestantArret, distanceArret;
    bool vitesse, sensDeplacement;
    std::string nomArret, nomProchainArret, nomArretPrecedent;
    int dureeArret;
    pos positionArret;
    fin >> nbLignes;
    for(int i = 0 ; i<nbLignes ; ++i)
    {
        ligne *c = l.ajouter();
        fin >> nbArret;
        for(int j = 0 ; j<nbArret ; ++j)
        {
            fin >> nomArret >> dureeArret >> positionArret.x >> positionArret.y;
            c->ajouterArret(nomArret, dureeArret, positionArret);
        }
        fin >> nbTram;
        for(int j = 0 ; j<nbTram ; ++j)
        {
            fin >> numTram >> vitesseMax >> vitesse >> distMinTram >> tempsRestantArret >> distanceArret >> sensDeplacement >> nomProchainArret >> nomArretPrecedent;
            c->ajouterTram(numTram, vitesseMax, vitesse, distMinTram, tempsRestantArret, distanceArret, sensDeplacement, c->chercherArret(nomProchainArret), c->chercherArret(nomArretPrecedent));
        }
    }
}

int main()
{
    listeligne l;
    chargerLignes(l, "fichiertest.txt");

    int cpt=0;
    std::cout << "Donner le temps de simulation souhaite (secondes):";
    std::cin >> cpt;
    opengraphsize(1000, 700);
    setbkcolor(LIGHTGRAY);
    cleardevice();
    l.affiche();

    while(cpt!=0)
    {
        l.rafraichir();
        setbkcolor(LIGHTGRAY);
        cleardevice();
        l.affiche();
        Sleep(100);
        cpt--;
    }

    getch();
    closegraph();
}
