#include <stdio.h>
#include <stdlib.h>
#include "equipe.h"
#include <string.h>
#include "combattant.h"
#include "technique.h"


int ChargerCombattant(const char* nomFichier,Combattant *combattant, int n ){
  FILE *fichier= fopen (nomFichier,"r+");
  char ligne[MAXCOMBATTANT];
  int i=0;
  while(fgets(ligne,sizeof(ligne),fichier)){
    Combattant a;
    sscanf("[^];%d;%d;%d;%d;%d",a.nom,&a.pv_max,&a.atq,&a.def,&a.agi,&a.vit);
    a.pv_courant=a.pv_max;
    a.nbtech= ChargerTechnique("techniques.txt", a.techspe, MAX_TECHNIQUE);
    combattant[i++]=a;
  }
  fclose(fichier);
  return i;
}
