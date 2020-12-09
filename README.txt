Le programme permet de lancer des fonctions avec un ou plusieurs Threads;

Pour lancer le Programme il vous faut un compilateur avec Cmake. (Clion as été utiliser dans le cas présents).

Dans le programme vous pouvez Influé sur :
-le nombre de thread utiliser dans L'array ThreaList situer dans ThreadPool.hpp;
-Le nombre que la fonction foo doit compter avant d'afficher le texte dans main.cpp ligne 11;
-Appelez le nombre de fonction que vous souhaitez dans main.cpp;
-Influer sur la prioriter des taches multithreader;
-Influer sur le nombre afficher en resultats finals de la fonction Foo;
-Afficher les différents états de disponibilités des threads dans ThreadPool.hpp;
-Changer de mode de selection de thread de manuel (Par default) en automatique en décommentant les lignes 14,53-59 et commanter les lignes 15,61-67 du
ThreadPool.hpp, inversement pour re-basculer en manuel;
-Afficher les executions par ordres de prioriters en décommentant la ligne 49 du TaskSystem.hpp, l'inverse pour les masquers;

Problemes rencontrers :
-Lors du dévellopement plusieurs problèmes on été rencontrés mais le plus importants reste le fait de ne pas avoir reussi a lancer mon moteur pour pouvoir
implémenter le chargement des ressources, ce qui m'as fait perdre beaucoup trop de temps.

Le resultats obtenues est inssufisant, en effet le problème citer ci-dessus en ai la cause, je suis conscient qu'il n'y as pas non plus de prise en compte
des communications entre thread, bien que j'en aie compris le fonctionnement, j'ai perdu mon temps en mauvaise organisation.

Mais ce projets m'interresse et ma permis de progressers en C++ (en plus de rattrapper pas mal de lacune), et le sujets est très interressant voilà pourquoi
je regrette sincerements de ne pas avoir reussi a mener le projet a son termes;

Suggestion d'amelioration : 
En effet, le problème rencontrer (et je pense ne pas être le seul), vient aussi du fait que nous ne sommes pas former a cree un environement de devellopement
optimal et safe pour le travail. Cmake, MingW, installation de librairies sont des choses simples a faire une vois acquise mais longuent a apprendre en auto-
-didacte car internet regorge de ressources et docs qui ce contredisent ou on du mal a vulgariser, voilà pourquoi (si possible) j'aimerais pour nous et les
années a venir que l'on soi (les bases) former au point que je vient d'énoncer. Merci et encore désoler pour ce rendu;