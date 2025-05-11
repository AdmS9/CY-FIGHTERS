#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pool.h"
#include "game.h"
#include "ui_console.h"

#include "tech.h"  

int main() {
    srand(time(NULL));

    if (!load_techs("techs.txt")) {
        fprintf(stderr, "Error: could not load techs.txt\n");
        return 1;
    }

    if (!load_pool("fighters.txt")) {
        fprintf(stderr, "Error: could not load fighters.txt\n");
        return 1;
    }

    Team t1, t2;
    int used[MAX_POOL] = {0};
    int size, single;

    printf("Team size (max %d): ", MAX_TEAM);
    scanf("%d", &size);
    if (size < 1 || size > MAX_TEAM) size = MAX_TEAM;

    printf("Enter name for Team 1: ");
    scanf("%63s", t1.name);
    printf("Enter name for Team 2: ");
    scanf("%63s", t2.name);
    printf("Single player? (1/0): ");
    scanf("%d", &single);

    pick_team(&t1, size, used);
    pick_team(&t2, size, used);

    

    battle(&t1, &t2, single, 2);
    
    return 0;
}
