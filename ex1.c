/*
 * Écrivez un programme qui permet à l'utilisateur d'indiquer, en minutes, le retard que son train a eu, chaque jour.  0 indique qu'il n'y a pas eu de retard et -1 que l'encodage est terminé.  
 * Ça lui permettra de recevoir une compensation de la sncb grâce au calcul suivant: 
 * pour 15 minutes de retard ou plus, remboursement de 25% du trajet.  
 * Pour 30 minutes ou plus, 50% du trajet. 
 * Pour  60minutes ou plus, 100% du trajet
 *
 * Le programme affichera ensuite la moyenne des retards effectifs (en ne comptant pas les jours où n'y a pas eu de retard donc), le montant total de la compensation qu'il peut demander à 
 * la SNCB et le plus grand nombre de jours consécutifs sans retard
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

int nbJourRetard = 0;
int cumulMinRetard = 0;
int maxNbJourRetardConsecutif = 0;
int tamponNbJourRetardConsecutif = 0;
int cumulRemboursement = 0;

int saisieUtilisateur(){
    int saisie = 0;
    
    printf("%s", "Saisissez le retard du jour ");
    scanf("%d", &saisie);
    if(saisie == -1){
        maxNbJourRetardConsecutif = tamponNbJourRetardConsecutif;
        return -1;
    } else if(saisie != 0){
        nbJourRetard ++ ;
        cumulMinRetard+=saisie;
        tamponNbJourRetardConsecutif++;
        if(saisie > 15 && saisie <= 30)
            cumulRemboursement += 25;
        else if (saisie > 30 && saisie <=60)
            cumulRemboursement += 50 ;
        else if (saisie > 60) 
            cumulRemboursement += 100;
    } else if (saisie == 0){
        maxNbJourRetardConsecutif = tamponNbJourRetardConsecutif;
        tamponNbJourRetardConsecutif = 0;
    }

    saisieUtilisateur();
}

float calcMoyRetard(){
    return cumulMinRetard/nbJourRetard;
}

int main() {
    saisieUtilisateur();
    printf("%s", "Moyenne des retards : ");
    printf("%f", calcMoyRetard());
    printf("%s", "\nNombre de jour de retard consécutifs maximum : ");
    printf("%d", maxNbJourRetardConsecutif);
    printf("%s", "\nRemboursement total (en pourcent) : ");
    printf("%d", cumulRemboursement);
}
