# CY Fighters

**CY Fighters** est un jeu de combat tour par tour en C dans lequel deux équipes de combattants s'affrontent à l'aide d'attaques de base et de techniques spéciales. Les combattants sont définis à partir de fichiers externes, et chaque joueur (ou IA) constitue son équipe avant de participer à un affrontement stratégique.

## 🎮 Fonctionnalités principales

- **Sélection d'équipe** : Chaque joueur choisit ses combattants dans une liste issue d’un fichier (`fighters.txt`). Chaque combattant possède ses propres statistiques et techniques.

- **Combat tour par tour** : Les combattants agissent en fonction de leur vitesse. Ils peuvent effectuer une attaque de base ou utiliser des techniques spéciales (offensives, de soin, de buff, ou de debuff).

- **Système de techniques (techs)** :
  - **Type 0** : Attaque spéciale (bonus de dégâts)
  - **Type 1** : Soin
  - **Type 2** : Buff (augmentation temporaire d’attaque)
  - **Type 3** : Debuff (réduction temporaire de défense)

- **IA intégrée** : En mode solo, l'équipe adverse est contrôlée par une intelligence artificielle avec une logique simple (attaque ou utilisation de techniques disponibles).

- **Affichage console** : État des équipes affiché en temps réel avec barres de vie textuelles.

- **Gestion des effets temporaires** : Les buffs et debuffs ont une durée limitée, ainsi que des cooldowns pour les techniques.

## 🧠 Structure du code

### `main.c`
- Point d'entrée du jeu.
- Chargement des techniques (`techs.txt`) et des combattants (`fighters.txt`).
- Configuration du mode solo ou multijoueur.
- Lancement du combat via la fonction `battle`.

### `game.c`
- `display_pool` : Affiche les combattants disponibles.
- `pick_team` : Permet à chaque joueur de choisir son équipe.
- `human_turn` / `ai_turn` : Détermine l'action du combattant actif.
- `battle` : Boucle principale du combat.

### `fighter.c`
- `apply_damage` : Applique une attaque de base ou modifiée à un adversaire.
- `apply_tech` : Exécute une technique spéciale.
- `decay` : Réduit la durée des effets temporaires et des cooldowns.

### `team.c`
- `team_alive` : Vérifie si une équipe est encore en jeu.
- `team_next` : Détermine le prochain combattant à agir selon l’ordre d’initiative.
- `team_pick` : Sélectionne une cible dans une équipe (aléatoire ou plus faible).
- `team_decay` : Met à jour tous les combattants des deux équipes.

### `tech.c`
- `load_techs` : Charge les techniques à partir d’un fichier.
- `find_tech` : Recherche une technique par son nom.

### `ui_console.c`
- Affiche l'état des équipes et les choix disponibles à chaque tour.

### `utils.c`
- `rnd(m)` : Génère un nombre aléatoire entre 0 et `m - 1`.

## 📁 Fichiers requis

- `fighters.txt` : Définit les combattants disponibles (nom, stats, techniques).
- `techs.txt` : Définit les techniques disponibles (nom, valeur, durée, type, etc.).
