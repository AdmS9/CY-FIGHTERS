#ifndef TECH_H
#define TECH_H
#include <stdio.h>
#define MAX_TECH 4
typedef struct{char name[64];int val,duration,cooldown,cd_left,type;char desc[128];}Tech;
extern Tech tech_pool[];
extern int tech_pool_size;
int load_techs(const char *path);
Tech* find_tech(const char *name);
#endif

