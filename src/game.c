#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "game.h"
#include "pool.h"
#include "ui_console.h"
#include "team.h"

void display_pool(int used[]) {
    printf("\n╔══════════════ Available Fighters ═══════════════╗\n");
    for (int i = 0; i < pool_size; i++) {
        if (used[i]) continue;
        Fighter *p = &pool[i];
        printf("║ %2d: %-12s HP:%-4d ATK:%-3d DEF:%-3d AGI:%-3d ║\n",
               i, p->name, p->maxhp, p->atk, p->def_, p->agi);
        printf("║    Speed:%-3d   Techniques: %-2d                    ║\n",
               p->spd, p->ntech);
        printf("╟───────────────────────────────────────────────╢\n");
    }
    printf("╚═══════════════════════════════════════════════╝\n");
}

void pick_team(Team *t, int size, int used[]) {
    if (size < 1 || size > MAX_TEAM) size = MAX_TEAM;
    t->n = size;
    char input[32];
    int choice;

    printf("\n%s's team selection phase\n", t->name);

    for (int i = 0; i < size; i++) {
        while (1) {
            display_pool(used);
            printf("\nSelect fighter %d of %d for team %s\n", i + 1, size, t->name);
            printf("Enter fighter number (0-%d): ", pool_size - 1);

            if (!fgets(input, sizeof(input), stdin)) {
                printf("Error reading input. Try again.\n");
                continue;
            }

            input[strcspn(input, "\n")] = 0;  // Remove newline

            if (strlen(input) == 0) {
                printf("Empty input. Please enter a number.\n");
                continue;
            }

            int valid = 1;
            for (int j = 0; input[j]; j++) {
                if (!isdigit(input[j]) && !(j == 0 && input[j] == '-')) {
                    valid = 0;
                    break;
                }
            }

            if (!valid) {
                printf("'%s' is not a valid number. Try again.\n", input);
                continue;
            }

            choice = atoi(input);
            if (choice < 0 || choice >= pool_size) {
                printf("Number %d is out of range. Try again.\n", choice);
                continue;
            }

            if (used[choice]) {
                printf("Fighter %d is already picked. Choose another.\n", choice);
                continue;
            }

            break;
        }

        t->f[i] = pool[choice];
        t->f[i].hp = t->f[i].maxhp;
        used[choice] = 1;

        printf("Added %s to team %s!\n", t->f[i].name, t->name);
    }
}

void human_turn(Fighter *p, Team *self, Team *en) {
    ui_draw_state_console(self, en);
    int opt;
    do {
        opt = ui_process_events_console(p);
    } while (opt < 1);

    Fighter *tgt = team_pick(en, 0);
    if (opt == 1)
        apply_damage(p, tgt, 0);
    else
        apply_tech(p, p, tgt, opt - 2);
}

void ai_turn(Fighter *p, Team *self, Team *en, int lvl) {
    if (lvl == 0 || lvl == 1) {
        Fighter *tgt = team_pick(en, lvl);
        apply_damage(p, tgt, 0);
        return;
    }

    for (int i = 0; i < p->ntech; i++) {
        if (p->techs[i].cd_left == 0) {
            Fighter *tgt = (p->techs[i].type == 1)
                           ? team_pick(self, 0)
                           : team_pick(en, 1);
            apply_tech(p, p, tgt, i);
            return;
        }
    }

    Fighter *tgt = team_pick(en, 1);
    apply_damage(p, tgt, 0);
}

void battle(Team *t1, Team *t2, int single, int lvl) {
    while (team_alive(t1) && team_alive(t2)) {
        Fighter *p = team_next(t1, t2);
        Team *self = (p >= t1->f && p < t1->f + t1->n) ? t1 : t2;
        Team *en = (self == t1) ? t2 : t1;

        if (single && self == t2)
            ai_turn(p, self, en, lvl);
        else
            human_turn(p, self, en);

        p->next += 1000 / (p->spd + p->buff[3]);
        team_decay(t1, t2);
    }

    ui_draw_winner_console(team_alive(t1) ? t1 : t2);
}
