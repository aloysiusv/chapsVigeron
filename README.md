Bonjour, je vous remercie d'avoir pris le temps de me lire.
Voici un résumé de ma résolution du challenge.

Comportement du programme :
- il décode des chaînes de caractères qui ont été cryptées en base64 et XOR avec une clé de 170
- l'un de ses arguments est une adresse IP cryptée qu'il tente de contacter avec un `ping`
- comme cette adresse -impossible à modifier- ne répond pas, nous n'accédons pas au vrai comportement du programme

Il faut donc rediriger cette adresse vers une adresse capable de répondre au `ping`. Le programme se relance alors correctement et lance une multitude de boîtes de dialogue pour recouvrir l'écran du système, la seule solution étant alors de tout quitter.

Outils utilisés :
- `virtualBOx` pour créer un environnement isolé sur l'ordinateur, afin d'y lancer le programme
- les commandes Linux `unzip`, `file`, `strings` pour avoir des infos sur la nature du fichier et quelques données intéressantes, en amont de la décompilation et de l'exécution
- `GDB` et `HexRays` (avec un rapide coup d'oeil à `Ghidra` et `radare2`) pour analyser le code en assembleur, et surtout en C++
- `wireshark` pour surveiller le comportement réseau

Merci encore pour ce passionnant petit challenge !