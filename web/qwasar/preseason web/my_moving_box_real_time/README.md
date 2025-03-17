# Welcome to My Moving Box Realtime
***

## Task
Le problème est que nous devons compléter le code js manquant afin de pouvoir déplacer le div 
avec l'id « my_box_realtime» aux coordonnées : Bas = 0 && Droite = 0
Le défi est donc de réussir à déplacer la boîte de manière fluide, c'est à dire de la bouger 
lentement. 1 point toutes les 0,5 secondes. Donc la boîte se déplace en diagonale et cela 
prendra 35 secondes.

## Description
Tout d'abord on récupère l'ID de la boîte avec ses informations (types coordonnés)
Ensuite on crée 2 variables pour avoir accès aux coordonnées right et bottom, à l'intérieur
de celle ci on transforme les chaînes de caractères en nombre pour pouvoir faire bouger
correctement la boîte.
Par la suite, une boucle est crée pour répéter l'action de la fonction «my_box_realtime»
avec un temps qui est 500 millisecondes.
Enfin la fonction «my_box_realtime» grâce à la boucle if, tant que rigth et bottom
sont supérieur à 0 la boucle s'effectue. Pour donc faire bouger la boîte on utilise des
décrémentations sur rigth et bottom pour déplacer la boîte jusqu'au coordonnés
right = 0 && bottom = 0.

## Installation
Je n'ai pas besoin d'installer ce projet.

## Usage
Pour commencer, on récupère l'ID de la boîte "my_box_realtime" avec ses informations,
c'est à dire son nom.

Ensuite on crée 2 variables nommée "var right" et "var bottom" pour avoir accès
aux coordonnées right et bottom. À l'intérieur de celles-ci on transforme les chaînes de
caractères en nombre grâce à la commande "parseInt" (car les coordonnés de base 70 dans
le "style=" de la boîte sont en chaîne de caractère et non des nombres) pour pouvoir faire
bouger correctement la boîte. Ses coordonnés sont récupérés grâce à ce qui est écrit entre
parenthèses "(box.style.right)" et "(box.style.bottom)".

Par la suite, une boucle est crée grâce à "setInterval(fonction, temps)" pour répéter
l'action de la fonction "my_box_realtime" avec un temps qui est 500 millisecondes.

Enfin la fonction «my_box_realtime()» grâce à la boucle if, qui consiste à ce que tant que
rigth et bottom sont supérieur à 0 la boucle s'effectue "if( right > 0 && bottom > 0)".
Pour donc faire bouger la boîte on utilise des décrémentations sur rigth et bottom
"rigth -= 1 ;" et "bottom -= 1 ;" pour déplacer la boîte jusqu'au coordonnés
right = 0 && bottom = 0.
En plus au dessous on rappelle que les coordonnés sont des pixels grâce à "px".

```
./my_project argument1 argument2
```

### The Core Team


<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px' /></span>
