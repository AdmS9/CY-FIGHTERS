#ifndef GAME_H
#define GAME_H
#include "team.h"
void display_pool(int used[]);
void pick_team(Team*t,int size,int used[]);
void human_turn(Fighter*p,Team*self,Team*en);
void ai_turn(Fighter*p,Team*self,Team*en,int lvl);
void battle(Team*t1,Team*t2,int single,int ai_lvl);
#endif

