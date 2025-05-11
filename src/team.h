#ifndef TEAM_H
#define TEAM_H
#include "fighter.h"
#define MAX_TEAM 5
typedef struct{char name[64];Fighter f[MAX_TEAM];int n;}Team;
int team_alive(const Team*t);
Fighter*team_next(const Team*a,const Team*b);
Fighter*team_pick(const Team*t,int weakest);
void team_decay(Team*a,Team*b);
#endif

