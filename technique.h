#ifndef TECHNIQUE_H
#define TECHNIQUE_H
#define TAILLE 50
#define DESC 200
#define MAXTECH 3
#define MAX_TECHNIQUE 256

typedef struct{
  char nom[TAILLE];
  char description[DESC];
  int tours_actif;
  int tours_rechargement;
  int tours_restant_reactivation;
  float valeur;
}Technique;

int ChargerTechnique(const char* nomFichier, Technique* techniques, int max);

#endif