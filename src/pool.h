#ifndef POOL_H
#define POOL_H
#include "fighter.h"
#define MAX_POOL 64
extern Fighter pool[MAX_POOL];
extern int pool_size;
int load_pool(const char*path);
#endif

