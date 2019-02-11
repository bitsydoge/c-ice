Notes are in FRENCH *terrible noise*
 
 
 
 Priorité : 
 - PhysFS pour tous les objets.
 - Check error de load
 - Font par defaut engine
 - Array de font
 - Remove des Label et les implémenté sur les Entity et Gui
 - GUI REFONTE !
 - Splashscreen custom
 
 
 
 
 
 
 
 //////////////////////////////////



Ajouter le manager et numero dans tous les asset pour utiliser seulement GET

!! Supprimer Label dans le monde pour ajouter cette fonction aux entité


- Ajouter aux input les Push et Release pour gérer un event unique de pression et de relachement et avoir une state pour EnTrainDePresser et PasEnTrainDePresser
- Sprite faire comme le projet test pour que les fonction fonctionnes (olol)

















///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////


OLD


:: Update/Upgrade ::

	- Refaire le systeme de GUI completement bugué et pas utile à fusioner avec les Label
	- Nouveau systeme de Get ?? avec Get.h
	- Implémenter l'UTF-8 

:: Graphisme ::          ^
                         |
	- More Background    |
		Image : -Taille original centré
				-Zoomé mais qui entre dans tous l'écran (cropé)
				-Zoomé jusqu'a touché l'écran (non cropé)
				-Etiré
				-Repeat X, Y ou XY
		Couleur
	- Ajouter Sprites 
	- Ajouter Zoom (:o :o :o :o :o)

:: Loader :: 

	- Ajouter Maps/Tileset
	- Assets Zippé Packé

:: Physique :: 

	- Implementer Chipmunk

:: Debug :: 

	- Faire une fenêtre séparé avec des infos de débugs
