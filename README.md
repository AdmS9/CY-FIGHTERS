CY Fighters
CY Fighters est un jeu de combat en tour par tour en C, dans lequel deux équipes de combattants s'affrontent en utilisant des attaques de base ou des techniques spéciales. Le jeu peut être joué en mode deux joueurs ou en solo contre une IA.

Objectif
Le but du jeu est de constituer une équipe de combattants à partir d'une pool (liste de personnages), puis de vaincre l'équipe adverse en gérant les attaques, les buffs, les soins, et les autres techniques disponibles pour chaque combattant.

Fonctionnalités principales
Combat et techniques
apply_damage(Fighter *a, Fighter *d, int v)
Applique une attaque de a sur d. Si la cible esquive (basé sur son agilité), elle évite les dégâts. Sinon, les dégâts sont calculés à partir de l'attaque, des buffs et de la défense de la cible.

apply_tech(Fighter *p, Fighter *ally, Fighter *opp, int idx)
Applique une technique de l'utilisateur p sur une cible (ally ou opp) selon le type :

0 : attaque spéciale

1 : soin

2 : buff de l’attaque

3 : debuff de la défense adverse

decay(Fighter *p)
Réduit les durées des effets (buffs ou debuffs) actifs, et décrémente les cooldowns des techniques.

Gestion des équipes
pick_team(Team *t, int size, int used[])
Permet à un joueur de choisir les combattants de son équipe parmi la liste disponible.

team_next(const Team *a, const Team *b)
Retourne le prochain combattant devant jouer, basé sur un système d’initiative avec une file de priorité (next).

team_decay(Team *t1, Team *t2)
Applique la fonction decay à tous les combattants vivants dans les deux équipes.

Tour de jeu et IA
human_turn(Fighter *p, Team *self, Team *en)
Gère l’interaction utilisateur lors d’un tour (choix d’action).

ai_turn(Fighter *p, Team *self, Team *en, int lvl)
Contrôle le comportement de l’IA selon un niveau de difficulté basique.

battle(Team *t1, Team *t2, int single, int lvl)
Lancement du combat entre les deux équipes, en alternant les tours jusqu'à la victoire d’une équipe.

Chargement des données
load_techs("techs.txt")
Charge la liste des techniques depuis un fichier texte.

load_pool("fighters.txt")
Charge les combattants disponibles depuis un fichier texte, avec leurs statistiques et leurs techniques.

Fichiers de données
techs.txt : contient les techniques disponibles (nom, valeur, durée, cooldown, type, description).

fighters.txt : contient les combattants jouables et leurs statistiques.
