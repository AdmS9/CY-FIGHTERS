#ifndef UI_CONSOLE_H
#define UI_CONSOLE_H

#include "team.h"

// Affiche une barre de vie dans une chaîne buffer (20 caractères de largeur)
void draw_health_bar(int current, int max, char *buffer);

// Affiche l’état complet des deux équipes dans la console
void ui_draw_state_console(const Team *t1, const Team *t2);

// Gère l'entrée utilisateur pour choisir une action (attaque ou technique)
int ui_process_events_console(const Fighter *p);

// Affiche l’équipe gagnante à la fin du combat
void ui_draw_winner_console(const Team *t);

#endif // UI_CONSOLE_H
