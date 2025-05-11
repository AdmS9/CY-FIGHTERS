#include <stdio.h>
#include "fighter.h"
#include "utils.h"
void apply_damage(Fighter*a,Fighter*d,int v){
    if(rnd(100)<d->agi+d->buff[2]){printf("%s dodged\n",d->name);return;}
    int raw=a->atk+a->buff[0]+v;
    int out=raw*(100-(d->def_+d->buff[1]))/100;
    d->hp-=out; if(d->hp<0)d->hp=0;
    printf("%s hits %s for %d\n",a->name,d->name,out);
}
void apply_tech(Fighter*p,Fighter*ally,Fighter*opp,int idx){
    Tech*t=&p->techs[idx];
    switch(t->type){
        case 0:apply_damage(p,opp,t->val);break;
        case 1:
            ally->hp+=t->val; if(ally->hp>ally->maxhp)ally->hp=ally->maxhp;
            printf("%s heals %s\n",p->name,ally->name);
            break;
        case 2:
            ally->buff[0]+=t->val;
            ally->buff_turns[idx]=t->duration;
            printf("%s buffs %s AT\n",p->name,ally->name);
            break;
        case 3:
            opp->buff[1]-=t->val;
            opp->buff_turns[idx]=t->duration;
            printf("%s debuffs %s DF\n",p->name,opp->name);
            break;
    }
    t->cd_left=t->cooldown;
}
void decay(Fighter*p){
    for(int i=0;i<p->ntech;i++){
        if(p->buff_turns[i]>0&&(--p->buff_turns[i]==0))
            p->buff[i]=0;
        if(p->techs[i].cd_left>0) p->techs[i].cd_left--;
    }
}

