Notes are in FRENCH *terrible noise*

- Remove le main côté utilisateur (ajouter protection de compilation pour winmain)

Trouvé ça dans je sais plus quoi
```
extern "C" int __stdcall WinMain( struct HINSTANCE__*, struct HINSTANCE__*, char*, int ) { return main( __argc, __argv ); }
```

- More Background
	Image : -Taille original centré
			-Zoomé mais qui entre dans tous l'écran (cropé)
			-Zoomé jusqu'a touché l'écran (non cropé)
			-Etiré
			-Repeat X, Y ou XY

- Ajouter Sprites (no far)
- Ajouter Zoom (:o :o :o :o :o)
- Ajouter Maps/Tileset (EZ PZ LEMON SQUEAZY)
- Ajouter Physics (CHIPUMUNKU)

Faire une deuxieme fenetre avec toutes les entité dans la scene ????
(Define pour la compile en debug)