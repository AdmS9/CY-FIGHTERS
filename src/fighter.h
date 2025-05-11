#ifndef FIGHTER_H
#define FIGHTER_H
#include "tech.h"
typedef struct{
    char name[64];
    int hp,maxhp,atk,def_,agi,spd,next;
    int ntech;
    Tech techs[MAX_TECH];
    int buff[MAX_TECH];
    int buff_turns[MAX_TECH];
}Fighter;
void apply_damage(Fighter*a,Fighter*d,int v);
void apply_tech(Fighter*p,Fighter*ally,Fighter*opp,int idx);
void decay(Fighter*p);
#endif

