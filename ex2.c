/*
 * Dans la pratique ancienne de la numérologie, le destin d'un sujet était calculé à l'aide de quatre nombres de bases, trois étant obtenus à partir du prénom et du nom reçus à la naissance et 
 * le dernier dérivant de la date de naissance. Les numérologues analysent ces chiffres afin d'y découvrir les clés du caractère d'un individu, sa destinée et ses cycles de vie. 
 * Mais il est possible de le faire soi-même, en calculant ces quatre nombres et en consultant leurs interprétations telles qu'elles figurent, sous une forme simplifiée. 
 * Les humains sont les sujets habituels de ce type de recherche, mais elle peut également être appliquée à tout ce qui a un prénom, un nom, une date de naissance et une origine, 
 * comme un animal de compagnie, une entreprise, un nation et même une idée.
 * 
 * 
 * La première étape de ce curieux exercice consista à transcrire un prénom en son équivalent numérique, à l'aide du tableau de correspondance lettre-chiffres que l'on peut voir ci-dessous. 
 * Chaque lettre correspond à un chiffre simple, numéroté dans l'ordre alphabétique. A jusqu'à I : 1 à 9, les autres lettres se ramenant à l'un de ces chiffres par simple addition. 
 * Ainsi le J, dixième lettre de l'aphabet, donne 1 (10 = 1 + 0= 1), tandis que le U, ou vingt et unième lettre, donne 3 (21 = 2 + 1 = 3)
 * 
 * (source: http://www.signification-prenom.net/numerologie_gratuite.php)
 * 
 * Il y a 12 numéro possibles pour les prénoms: 1 à 9, 11, 22 et 33.  Ces trois derniers sont particuliers: ce sont des maitres nombres.
 * Pour calculer le numéro associé à votre prénom additionnez tous les chiffres correspondants aux lettres du prénom.  Additionnez tous les chiffres du nombre 
 * obtenu jusqu'à arriver à un maitre nombre ou un nombre à un chiffre.
 * 
 * Écrivez un programme qui calcule le numéro associé à un prénom en suivant la technique décrite ci-dessus.  L'utilisateur entrera son prénom caractère par caractère. 
 * Et il faudra lui sortir le chiffre qui correspond à son prénom.
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

int somme = 0;

int sommeChiffres(int nombre){
    int somme = 0;
    while(nombre>0){
        somme+=nombre%10;
        nombre/=10;
    }
    return somme;
}

//PRE: c est un caractère minuscule de l'alphabet (a-z, sans caractères accentués)
//POST: renvoie la valeur numérique (entre 1 et 9) de la lettre.
int versChiffre(char c){
    return (c-'a')%9+1;
}


int saisieUser(){
    char lettre;
    int val = 0;
    printf("%s", "Saisissez la lettre du prenom ");
    scanf("%c", &lettre);
    
    if(lettre == '-')
        return -1;
    else {
        val = versChiffre(lettre);
        somme += sommeChiffres(val);
        saisieUser();
    }
        
}

int main() {
   saisieUser();
   printf("%d", somme);
}




