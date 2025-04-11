#include <stdio.h>
#include <stdlib.h>
#include "equipe.h"
#include <string.h>
#include "combattant.h"


int ChargerTechnique(const char* nomFichier,Technique tech, int n ){
  FILE *fichier= fopen (nomFichier,"r+");
  char ligne[MAXTECH];
  int i=0;
  while(fgets(ligne,sizeof(ligne),fichier)){
    Technique t;
    sscanf("[^];[^];%d;%d;%d;%f",t.nom,t.description,&t.tours_actif,&t.tours_rechargement,&t.tours_restant_reactivation,&t.valeur);
    tech[i++]=t;
  }
  fclose(fichier);
  return i;
}
