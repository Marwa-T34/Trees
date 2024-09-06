#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int val;
    struct node *gauche;
    struct node *droit;
    }arbre;
    
 arbre* Creer_Arbre_Vide(){
     return NULL;
     }
     
 int Est_Vide(arbre *a){
      return(a == NULL);
     }
 
 int Hauteur(arbre *a){
     if(a == NULL)
         return -1;
     else{
     int Hg = Hauteur(a->gauche);
     int Hd = Hauteur(a->droit);
     return (Hg > Hd ? Hg:Hd)+1;
     }
 }
 
 arbre*Gauche(arbre *a){
     if(a==NULL)
         return NULL;
     else
     return a->gauche;
 }
 arbre*Droit(arbre *a){
     if(a==NULL)
         return NULL;
     else 
         return a->droit;
 }
 arbre* Creer_Arbre(int x,arbre *g,arbre *d){
    arbre *tree = malloc(sizeof(arbre));
     tree->val = x;
     tree->gauche = g;
     tree->droit = d;
     return tree;
 }
 void Inserer(arbre **a, int x){
     if(*a == NULL)
         *a = Creer_Arbre(x,NULL,NULL);
     else{
         if(x > (*a)->val)
             Inserer(&((*a)->droit) , x);
         else 
             Inserer(&((*a)->gauche) , x);       
 }}
 int Rechercher(arbre *a,int x){
     if(a == NULL)
         return 0;
     else if(a->val == x)
         return 1;
     else if(x > a->val)
         return Rechercher(a->droit,x); 
     else 
         return Rechercher(a->gauche,x);
}
int Rechercher_min(arbre *a){
    if(a == NULL)
        return -1;
    while(a->gauche !=NULL ){ 
        a = a->gauche;
    }
         return a->val;  
 }
 void Afficher(arbre *a){
     if(a == NULL)
         return;
     Afficher(a->gauche);
     printf("%d ",a->val);
     Afficher(a->droit);
 }
 int Somme(arbre *a){
     if(a == NULL)
         return 0;
     return a->val + Somme(a->gauche) + Somme(a->droit);   
 }
 arbre *FindMin(arbre *a){
        while(a->gauche != NULL){
            a = a->gauche; }
            return a;
    }
void Supprimer(arbre **a,int x){
    if(*a == NULL)
        return;
    else if(x<(*a)->val)
        Supprimer(&((*a)->gauche),x);
    else if(x>(*a)->val)    
        Supprimer(&((*a)->droit),x);
    else{
        if((*a)->gauche == NULL && (*a)->droit == NULL){
            free(*a);
            *a = NULL; }
        else if((*a)->gauche == NULL){
            arbre *temp = *a;
            *a = (*a)->droit;
            free(temp);
            }
        else if((*a)->droit == NULL){    
            arbre *temp = *a;
            *a=(*a)->gauche;
            free(temp);
            }
        else{
            arbre *temp = FindMin((*a)->droit);
            (*a)->val = temp->val;
            Supprimer(&((*a)->droit),temp->val);
        }}}
int main(){
int choix1,choix2,x;
arbre *tree =NULL;
do{
do{
printf("1)Creer un arbre vide.\n");
printf("2)L'arbre est-il vide ?\n");
printf("3)Hauteur de l'arbre.\n");
printf("4)Sous-arbre gauche.\n");
printf("5)Sous-arbre droit.\n");
printf("6)Creer arbre.\n");
printf("7)Inserer neudes.\n");
printf("8)Rechercher un element.\n");
printf("9)Rechercher le min de l'arbre.\n");
printf("10)Supprimer un element.\n");
printf("11)Calculer la somme des valeurs de l'arbre.\n");
printf("12)Afficher l'arbre.\n");

printf("Entrer le numero du votre option: ");
scanf("%d",&choix1);
printf("\n");
}while(choix1 > 12 || choix1 < 1);

switch(choix1){
    case 1:
        tree = Creer_Arbre_Vide();
        printf("L'arbre vide a ete cree.\n");
        break;
    case 2:
        if(Est_Vide(tree))
            printf("L'arbre est vide.\n");
        else
            printf("L'arbre n'est pas vide.\n"); 
        break;
    case 3:
         printf("L'hauteur de l'arbre: %d\n",Hauteur(tree));
        break;
    case 4:
    printf("Le sous-arbre gauche: \n");
    Afficher(Gauche(tree));
        break;
    case 5:
    printf("Le sous-arbre droit: \n");
    Afficher(Droit(tree));
        break;
    case 6:
    printf("Donnez la valeur de noeud: ");
    scanf("%d",&x);
    tree = Creer_Arbre(x,NULL,NULL);
        break;
    case 7:
    printf("Entrez la valeur a inserer: ");
    scanf("%d",&x);
    Inserer(&tree,x);
        break;
    case 8:
    printf("Entrez la valeur que vous recherchez: ");
    scanf("%d",&x);
    if(Rechercher(tree,x))
        printf("La valeur %d existe dans l'arbre.\n",x);
        else
        printf("\nLa valeur %d n'existe pas dans l'arbre.\n",x);
        break;
    case 9:
    if(Rechercher_min(tree)== -1)
        printf("L'arbre est vide!");
    else     
    printf("La valeur minimale : %d\n",Rechercher_min(tree));
        break;
    case 10:
    printf("Enterz la valeur a supprimer: ");
    scanf("%d",&x);
    Supprimer(&tree,x); 
    printf("Le noeud de valeur %d a ete supprime.",x);
        break;    
    case 11:
        printf("La somme des valeurs de l'arbre: %d",Somme(tree));
        break;
    case 12:
    printf("Les valeurs de l'arbre sont: \n");
    Afficher(tree); 
    break;
}        
printf("\nSi vous souhaitez continuer,entrez '1' sionon entrez '0':");
scanf("%d",&choix2);
}while(choix2 == 1); 
}
