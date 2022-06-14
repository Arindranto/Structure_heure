#include <stdio.h>
#include <stdlib.h>

typedef struct{
    // Structure de definition d'une heure representer en heure:minute:seconde
    int hh, min, sec;
} Heure;

int main()
{
    // Prototypes
    void lire(Heure *);
    void afficher(Heure);
    int nbr_sec(Heure);
    Heure en_heure(int);
    Heure additionner(Heure, Heure);

    Heure t1, t2;
    int s, choix;

    printf("-STRUCTURE HEURE-\n\n");
    puts("1/ Heure -> Secondes");
    puts("2/ Secondes -> Heure");
    puts("3/ Additionne de 2 heures");
    printf("\n");
    puts("0/ Quitter");

    do{
        printf("\nVotre choix: ");
        scanf("%d", &choix);

        switch (choix){
        case 1:
            // Heures -> Secondes
            // INPUT
            lire(&t1);

            // OUTPUT
            afficher(t1);
            printf(" = %d secondes\n", nbr_sec(t1));
            break;

        case 2:
            // Secondes -> Heures
            // INPUT
            printf("Le nombre de secondes: ");
            scanf("%d", &s);

            // OUTPUT
            printf("%d secondes = ", s);
            afficher(en_heure(s));
            printf("\n");
            break;
        case 3:
            // Addition de 2 dates
            // INPUT
            printf("Heure 1:\n");
            lire(&t1);
            printf("\n\nHeure 2;\n");
            lire(&t2);

            // OUTPUT
            afficher(t1);
            printf(" + ");
            afficher(t2);
            printf(" = ");
            afficher(additionner(t1, t2));
            printf("\n");
            break;
        default:;
        }
    }while(choix != 0);
    printf("\nA bientot\n");
    return 0;
}

void lire(Heure *t){
    // Lit les donnees d'une variable heure
    int tmp;

    // Heures
    do{
        printf("Heure (de 0 a 23): ");
        scanf("%d", &tmp);
    }while(tmp < 0 || tmp > 23);
    t->hh= tmp;

    // Minutes
    do{
        printf("Minutes (de 0 a 59): ");
        scanf("%d", &tmp);
    }while(tmp < 0 || tmp > 59);
    t->min= tmp;

    // Secondes
    do{
        printf("Secondes (de 0 a 59): ");
        scanf("%d", &tmp);
    }while(tmp < 0 || tmp > 59);
    t->sec= tmp;
}

void afficher(Heure t){
    // Affiche l'heure
    printf("%d:%d:%d", t.hh, t.min, t.sec);
}

int nbr_sec(Heure t){
    // Retourne le nombre de secondes dans une heure donnee
    return t.hh * 3600 + t.min * 60 + t.sec;
}

Heure en_heure(int sec){
    // Retourne une heure a partir d'un nombre de seconde donne
    Heure t;
    t.hh= sec / 3600;
    t.min= sec % 3600 / 60;
    t.sec= sec % 3600 % 60;
    return t;
}

Heure additionner(Heure t1, Heure t2){
    // Additionne 2 heures
    Heure t= en_heure(nbr_sec(t1) + nbr_sec(t2));

    // Ajustement
    t.hh%= 24;
    t.min%= 60;
    t.sec%= 60;

    return t;
}
