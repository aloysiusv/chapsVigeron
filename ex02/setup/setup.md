1. Afin d'exécuter le fichier, la première étape a été de créer une VM Windows (édition 10 Famille, min 50GB de mémoire, 11 coeurs).

2. Ensuite, dézipper le dossier `wannasmile` grâce au mot de passe `infected`, extraire les fichiers et renommer `wannasmile` en `wannasmile.exe`.

3. Plusieurs problèmes se présentent alors :
- `libgcc_s_seh-1.dll` et `libstdc++-6.dll` manquantes
- erreur `0xc000007b`, l'application n'a pas réussi a démarrer correctement.

La résolution de ces problèmes consistait à :
- arrêter d'être stupide
- installer `chocolatey`
- l'utiliser pour installer `minGW`.

4. Grâce à `chocolatey`, nous avons également pu installer les programmes suivants :
- `wireshark` pour analyser les paquets échangés
- `sandboxie` pour lancer le binaire dans un environnement encore plus isolé (c'était peut-être une décision paranoïaque)
- `ghidra` (ne pas oublier d'ajouter `adoptopenjdk`) et `radare2`, pour tenter d'analyser le fichier avec de nouveaux outils.

Finalement, j'ai préféré désassembler avec `GDB` sur Linux pour aller plus vite et décompiler avec `HexRays` car le rendu m'était plus familier. Toutefois, il a été utile de comparer les différentes versions des décompilateurs.
