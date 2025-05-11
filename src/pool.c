#include <stdio.h>
#include "pool.h"
#include "tech.h"
Fighter pool[MAX_POOL];
int pool_size=0;
int load_pool(const char*path){
    FILE*fp=fopen(path,"r"); if(!fp)return 0;
    while(pool_size<MAX_POOL){
        Fighter*p=&pool[pool_size];
        if(fscanf(fp,"%63s %d %d %d %d %d %d",
            p->name,&p->maxhp,&p->atk,&p->def_,&p->agi,&p->spd,&p->ntech)!=7)break;
        p->hp=p->maxhp;
        for(int i=0;i<MAX_TECH;i++){p->buff[i]=0;p->buff_turns[i]=0;}
        p->next=0;
        for (int i = 0; i < p->ntech; i++) {
   	    char tech_name[64];
            fscanf(fp, "%63s", tech_name);
            Tech *t = find_tech(tech_name);
            if (t) {
                p->techs[i] = *t; 
                 } 
	    else {
        	fprintf(stderr, "Warning: tech '%s' not found\n", tech_name);
    }
}

        pool_size++;
    }
    fclose(fp);
    return pool_size;
}

