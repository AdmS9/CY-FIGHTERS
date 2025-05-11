#include <stdio.h>
#include "ui_console.h"

void draw_health_bar(int current, int max, char *buffer) {
    int bar_width = 20;
    int filled = bar_width * current / max;

    buffer[0] = '[';
    for (int i = 1; i <= bar_width; i++) {
        buffer[i] = (i <= filled) ? '#' : '-';
    }
    buffer[bar_width + 1] = ']';
    buffer[bar_width + 2] = '\0';
}

void ui_draw_state_console(const Team *t1, const Team *t2) {
    printf("\n=== BATTLE STATUS ===\n");

    printf("Team 1: %s\n", t1->name);
    for (int i = 0; i < t1->n; i++) {
        char bar[64];
        draw_health_bar(t1->f[i].hp, t1->f[i].maxhp, bar);
        printf("%-12s %3d/%3d %s %s\n", t1->f[i].name, t1->f[i].hp, t1->f[i].maxhp, bar,
               t1->f[i].hp <= 0 ? "[DEFEATED]" : "");
    }

    printf("\nTeam 2: %s\n", t2->name);
    for (int i = 0; i < t2->n; i++) {
        char bar[64];
        draw_health_bar(t2->f[i].hp, t2->f[i].maxhp, bar);
        printf("%-12s %3d/%3d %s %s\n", t2->f[i].name, t2->f[i].hp, t2->f[i].maxhp, bar,
               t2->f[i].hp <= 0 ? "[DEFEATED]" : "");
    }
    printf("======================\n");
}

int ui_process_events_console(const Fighter *p) {
    printf("\n-- %s's Turn --\n", p->name);
    printf("1) Basic Attack\n");
    for (int i = 0; i < p->ntech; i++) {
        printf("%d) %s (CD: %d) - %s\n", i + 2, p->techs[i].name,
               p->techs[i].cd_left, p->techs[i].desc);
    }

    int choice;
    do {
        printf("Choose action (1-%d): ", p->ntech + 1);
        scanf("%d", &choice);
    } while (choice < 1 || choice > p->ntech + 1);
    return choice;
}

void ui_draw_winner_console(const Team *t) {
    printf("\n=== %s WINS THE BATTLE! ===\n", t->name);
}