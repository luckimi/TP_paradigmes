# Réponses aux Etapes des TP

## Partie C++ :

### Etape 4 :
_Comment appelle-t'on ce type de méthode et comment faut-il les déclarer ?_

La méthde open() est une méthode abstraite dans la classe de base (Media.h).\
On la déclare en ajoutant = 0 lors de sa définition.

_Si vous avez fait ce qui précède comme demandé, il ne sera plus possible d'instancer des objets de la classe de base. Pourquoi ?_
Une classe qui contient une méthode abstraite devient une classe abstraite et ne peut donc plus être instanciée.

### Etape 5 :
_Quelle est la propriété caractéristique de l'orienté objet qui permet de faire cela ?_

C'est grâce au polymorphisme qu'on peut appeler un même méthode sur plusieurs objets différents.



_Qu'est-il spécifiquement nécessaire de faire dans le cas du C++ ?_

Pour surcharger une fonction, on doit préciser `virtual` dans la classe parente et `override` dans les enfants (on peut aussi mettre `final` pour le dernier enfant).



_Quel est le type des éléments du tableau : le tableau doit-il contenir des objets ou des pointeurs vers ces objets ? Pourquoi ? Comparer à Java._

Les éléments du tableau sont des pointeurs vers la classe. Cela permet d'appeler une méthode commune sans se soucier du type d'objet. En C++ comme en java, on utilise la surcharge (override) pour avoir des comportements différents entre parent et enfant.

### Etape 7 :

_La copie d'objet peut également poser problème quand ils ont des variables d'instance qui sont des pointeurs. Quel est le problème et quelles sont les solutions ?_

Quand on fait de la copie d'objets sous la forme de pointeurs, on peut avoir des problème de fuite de mémoire (on ne détruit pas la copie), de double destruction ou d'avoir des variable d'instance partagées entre l'original et la copie.

### Etape 8 :

_Le groupe ne doit pas détruire les objets quand il est détruit car un objet peut appartenir à plusieurs groupes (on verra ce point à la question suivante). On rappelle aussi que la liste d'objets doit en fait être une liste de pointeurs d'objets. Pourquoi ? Comparer à Java._

Avoir une liste de pointeurs d'objets permet d'utiliser pleinement les proprétés liées au polymorphisme et donc de les traiter comme des objets de même type.

### Etape 10 :

_Les méthodes précédentes permettent d'assurer la cohérence de la base de données car quand on crée un objet on l'ajoute à la table adéquate. Par contre, ce ne sera pas le cas si on crée un objet directement avec new (il n'appartiendra à aucune table). Comment peut-on l'interdire, afin que seule la classe servant à manipuler les objets puisse en créer de nouveaux ?_

Pour protéger notre base de données et ne permettre l'instanciation que dans une classe spécifique, on peut mettre l'instanciation dans les méthodes privées et mettre une exeption pour le Manager (`friend class Manager;`).

## Partie Java :

### Etape 1 :

_Lancez votre programme, cliquez plusieurs fois sur les deux premiers bouton, retaillez la fenêtre. Que constate-t'on ?_

La fenêtre change sa taille mais les boutons ne s'adaptent pas à la nouvelle forme. La zone de texte ne respecte plus la taille qu'on a défini.