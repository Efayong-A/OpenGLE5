## Comment lancer le programme 
---
Afin de lancer le Projet, placez-vous dans le répertoire Build puis :

- cmake ../.
- make
- ./TP_Project/TP_Project_Project 


## Le programme 
---
Vous pouvez vous déplacer à l'aide des touches Z Q S D, permettant d'aller de l'avant, à gauche, en arrière et à droite.

Le clic droit de votre souris permettra de pouvoir se déplacer avec la caméra freefly. 

Vous pourrez voir la bielle statique eclairée par une lumière directionnelle. 

## Travail effectué 
---
- Bielle statique
- Gestion de la caméra
- Eclairage

Ajout d'un système de tableau d'objects. Un object est un objet primitif comme une sphère, un cône, ou un quadrilatère (type créé). Le programme ne dépend que de ce tableau d'Objects, permettant de ne modifier que ce tableau afin d'ajouter des élements à la scène.

## Problèmes rencontrés
---
Abandon d'un système de spécification de la liste d'objets à rendre dans la scène dans un fichier séparé. Afin de rendre le code principal indépendant des modifications, j'avais commencé à construire un fichier cpp et hpp qui contenait toutes les spécifications de lumières, couleurs et liste d'objets sur la scène. Par manque de temps et devant la compléxité de la tâche j'ai décidé de rester avec un système de déclaration interne au fichier principal.

Vous noterez la présence dans la struct Object d'attributs en rapport avec l'éclairage Blinn-Phong. La scène marche en Blinn Phong pour l'éclairage (Ambient, Diffus, Speculaire), mais rencontre des problèmes que je n'ai pas su résoudre. 

Je n'ai également pas réussi à texturer mes quadilatères, ni a modéliser une scène convenable pour représenter un environnement industriel. 

Lorsque avec la caméra l'utilisateur regarde en l'air en mettant sa souris dans un coin, la caméra subit une rotation d'angle non prévue sur l'axe des z. 