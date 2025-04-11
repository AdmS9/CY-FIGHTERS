#ifndef EQUIPE_H
#define EQUIPE_H
#define MAXCOMBATTANT 15
#define NOM 50
#include "combattant.h"
typedef struct{
    char nomEquipe[NOM];
    Combattant  combattant[MAXCOMBATTANT];
  
}Equipe;

#endif