#ifndef TRAMWAY_H
#define TRAMWAY_H
#include "arret.h"
class ligne;


class tramway
{
    friend class listeTramways;
    public:
        tramway(int num, ligne* li, double vitMax, bool vit, double distTram, double tArret, double distArret, bool sens, arret* arretSuivant, arret* arretPrecedent);
        double distance(const arret & a1, const arret & a2) const;
        double distance(const tramway & t1, const arret & a2) const;
        double distance(const tramway & t1, const tramway & t2) const;
        void GetPosition(pos & p) const;
        void affiche() const;
        void avancer();

    private:
        int d_numeroTram;
		ligne *d_ligne; ///ligne sur laquelle roule le tramway
		double d_vitesseMax;
		bool d_vitesse;
		double d_distanceMiniTram; ///distance minimale avec le tramway de devant
		double d_tempsRestantArret; ///temps passé sur l'arrêt, -1.0 si il n'est pas sur un arrêt
		double d_distanceArret; ///distance qui sépare le tramway du prochain arret
		bool d_sensDeplacement;
		arret *d_arretSuiv;///prochain arret (si le tram est sur un arret, cet arret)
		arret *d_arretPrec;
		tramway *d_suiv;
		tramway *d_prec;
		int d_cmpt;
		bool d_inPause;
		bool d_change;
};

#endif // TRAMWAY_H
