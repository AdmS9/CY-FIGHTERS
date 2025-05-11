#include "team.h"
int team_alive(const Team*t){
    for(int i=0;i<t->n;i++)if(t->f[i].hp>0)return 1;
    return 0;
}
Fighter*team_next(const Team*a,const Team*b){
    Fighter*best=NULL;
    for(int i=0;i<a->n;i++){
        Fighter*p=&((Team*)a)->f[i];
        if(p->hp>0&&(!best||p->next<best->next))best=p;
    }
    for(int i=0;i<b->n;i++){
        Fighter*p=&((Team*)b)->f[i];
        if(p->hp>0&&(!best||p->next<best->next))best=p;
    }
    return best;
}
Fighter*team_pick(const Team*t,int w){
    Fighter*tgt=NULL;
    for(int i=0;i<t->n;i++){
        Fighter*p=&((Team*)t)->f[i];
        if(p->hp<=0)continue;
        if(!tgt||(w&&p->hp<tgt->hp))tgt=p;
    }
    return tgt;
}
void team_decay(Team*a,Team*b){
    for(int i=0;i<a->n;i++)decay(&a->f[i]);
    for(int i=0;i<b->n;i++)decay(&b->f[i]);
}

