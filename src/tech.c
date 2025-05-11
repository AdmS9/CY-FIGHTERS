#include <stdio.h>
#include <string.h>
#include "tech.h"

#define MAX_TECH_POOL 128
Tech tech_pool[MAX_TECH_POOL];
int tech_pool_size = 0;

int load_techs(const char *path) {
    FILE *fp = fopen(path, "r");
    if (!fp) return 0;
    while (tech_pool_size < MAX_TECH_POOL) {
        Tech *t = &tech_pool[tech_pool_size];
        if (fscanf(fp, "%63s %d %d %d %d ", t->name, &t->val, &t->duration, &t->cooldown, &t->type) != 5)
            break;
        fgets(t->desc, sizeof(t->desc), fp); // lire la ligne restante (description)
        size_t len = strlen(t->desc);
        if (len > 0 && t->desc[len - 1] == '\n') t->desc[len - 1] = '\0'; // retirer \n
        t->cd_left = 0;
        tech_pool_size++;
    }
    fclose(fp);
    return tech_pool_size;
}

Tech* find_tech(const char *name) {
    for (int i = 0; i < tech_pool_size; i++) {
        if (strcmp(tech_pool[i].name, name) == 0)
            return &tech_pool[i];
    }
    return NULL;
}
