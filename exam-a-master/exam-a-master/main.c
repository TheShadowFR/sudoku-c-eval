#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// A lire !!!!!!              <--------------------------------

// Je ne suis pas arriver à compiler le programme et à l'executer avec les commandes: gcc main.c -o C:\Users\ncabande\Documents\c sudoku\exam-a-master\exam-a-master\build\main.exe
//                                                                                    puis EXAM-A-MASTER\exam-a-master\build\main.exe


// j'ai alors réalisé le code sans pouvoir executer le programme (donc il y a beaucoup d'erreur !)




















/*
Pour l'exercice vous aurez besoin de generer des entiers aléatoire : rand() renvoit un entier aléatoire.
il s'utilise : rand() % NOMBREMAX + 1 
Pour un entier aléatoire entre 0 et 1 il faut donc faire rand() %2
voir dans la methode main.
*/






// Ecrire la fonction generer(), elle prend en paramètre la grille et renvoie le nombre d'éléments non nuls

// Ce lien vous sera utile : https://www.geeksforgeeks.org/pass-2d-array-parameter-c/


/*Écrire une fonction saisir() qui demande à l’utilisateur de saisir au clavier les indices i et j et la valeur v à placer à l’emplacement (i,j).
La fonction doit vérifier la validité des indices et de la valeur.
Si la case n’est pas occupée, la valeur doit être placée dans la grille. remplissage est alors incrémentée*/


/*
Écrire la fonction verifierLigneColonne() qui prend en paramètre un numéro et un sens (HORIZ ou VERT)
qui vérifie que la ligne ou la colonne (suivant les cas) numéro est bien remplie.
On pourra utiliser un tableau intermédiaire pour vérifier cela. La fonction retournera 1 si tout s’est bien passé, 0 sinon.
 Les constantes HORIZ de valeur 0 et VERT de valeur 1 sont à définir.
*/

/*
Écrire la fonction verifierRegion() qui prend en paramètre deux indices k et l qui correspondent à la région (k,l)
et qui renvoie 1 si la région est correctement remplie, 0 sinon.
*/

//Écrire la fonction verifierGrille() qui renvoie 1 si la grille est correctement remplie et 0 sinon


//Écrire le programme principal, en supposant que la seule condition d’arrêt est la réussite du sudoku (ce test ne devra être fait que si nécessaire)

#define NOMBREMAX 40

int main(){                                                     //Ne pas toucher le code entre les commentaires
    int i, j, k, v;                                             //MODIFICATION --> ajout de la variable v pour enregistrer les réponses de user
    int solution[9][9];
    int tableauUser[9][9];
    char chaine[9];
    srand( time( NULL ) );


    int i, j, k, v;                                             //MODIFICATION --> ajout de la variable v pour enregistrer les réponses de user
    int solution[9][9];
    int tableauUser[9][9];
    char chaine[9];
    printf("SOLUTION");  
    printf("\n");  
    printf("---------------------------------");  
    printf("\n");  
    for(j=0;j<9; ++j) 
    {
    for(i=0; i<9; ++i)
        solution[j][i] = (i + j*3 +j /3) %9 +1;
        tableauUser[j][i] = solution[j][i];                       //MODIFICATION --> copier solution dans tableauUser
    }
    
    for(i=0;i<9; ++i) 
    {
    for(j=0; j<9; ++j)
        printf("%d ", solution[i][j]);
        printf("\n");  
    }
    printf("---------------------------------");  
    printf("\n");  
    //toucher le code entre les commentaires 
    
    void generer();{      //elle prend en paramètre la grille et renvoie le nombre d'éléments non nuls
                                             
        for(i=0; i<20; ++i){
            tableauUser[rand()%10][rand()%10] = 0; 
        }                            
        printf("%d", tableauUser);
    }
    void saisir();{                                           //demande à l’utilisateur de saisir au clavier les indices i et j et la valeur v à placer à l’emplacement (i,j).
        printf("saisisser les coordonnées(x puis y)");
        scanf("%d %d", i, j );
        printf("saisisser le chiffre à insérer(de 1 à 9");                                                    // La fonction doit vérifier la validité des indices et de la valeur.
        scanf("%d", v);                                                   // Si la case n’est pas occupée, la valeur doit être placée dans la grille. remplissage est alors incrémentée*/
        if(v >= 0 && v <= 9 ){
            if (tableauUser[i][j] == 0){
                tableauUser[i][j] = v;
                if(verifierLigneColonne() == 1 && verifierRegion() == 1){
                    printf("%d placer en %d %d", v, i, j);
                    if (verifierGrille() == 1){
                        rintf("Bienjoué !! Tu as gagné ! voici la solution:");
                        for(i=0;i<9; ++i){
                            for(j=0; j<9; ++j){
                                printf("%d ", solution[i][j]);
                                printf("\n");
                            }      
                        }
                    }else{
                        for(i=0;i<9; ++i){
                            for(j=0; j<9; ++j){
                                printf("%d ", tableauUser[i][j]);
                                printf("\n");  
                            }    
                        }
                    }                
                }else{
                    printf("Faux !!!");
                    tableauUser[i][j] = 0;
                }
            }else{
                printf("vous avez entrer de mauvais coordonnées !!!");
            }  
        }else{
            printf("vous avez entrer une mauvaise valeur !!!");
        }
    }
    int verifierLigneColonne(){
        //verifier ligne
        int x;
        for(x=1; x<10; ++x){
            if (tableauUser[i][x] == solution[i][x] || tableauUser[i][x] == 0){
                if (tableauUser[x][j] == solution[x][j] || tableauUser[x][j] == 0){
                    return 1;
                }else{
                    return 0;
                }
            }else{
                return 0;
            }
        }                           
    }

    int verifierRegion(){
        int coloneCase;
        int ligneCase;
        if (i <= 3){
            coloneCase = 1;
        }
        else if (i <= 6){
            coloneCase = 4;
        }
        else if (i <= 9){
            coloneCase = 7;
        }
        if (j <= 3){
            ligneCase = 1;
        }
        else if (j <= 6){
            ligneCase = 4;
        }
        else if (j <= 9){
            ligneCase = 7;
        }
        for(i = coloneCase ;i<(coloneCase + 3); ++i){
        for(j= ligneCase; j<(ligneCase + 3); ++j){
             if (tableauUser[i][j] == solution[i][j] || tableauUser[i][j] == 0){
                return 1;
             }else{
                return 0;
             }
        }
    }                                       

    int verifierGrille(){                                      
        if (tableauUser == solution){
            return 1;
        }
        else{
            return 0;
        }
        
    }
    generer();
    saisir();
    //Ne pas toucher au code ci dessous
    system("pause");
    return 0;
}
