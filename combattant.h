#ifndef COMBATTANT_H
#define COMBATTANT_H
#define SIZE 50
#include "technique.h"
typedef struct{
  char nom[SIZE];
  int pv_courant;
  int pv_max;
  int atq;
  int def;
  int agi;
  int vit;
  Technique techspe[MAX_TECHNIQUE];
  int nbtech;
}Combattant;
int ChargerCombattantsDepuisFichier(const char* nomFichier, Combattant* combattants, int max);
#endif