1. En décompilant le code et en le réécrivant un peu (voir `pseudo_cpp`), nous avons pu avoir une meilleure idée de ce que fait le programme.

Première étape :
- si nous lui passons ARG1, celui-ci est décodé puis comparé avec une string
- si les deux strings sont les mêmes, on décode aussi un potentiel ARG2 et on envoie un `ping` à l'adresse contenue dans ARG2 (s'il s'agit d'une adresse IP valide)
- si les deux strings diffèrent, nous ne recevons que le message `Nice try fellow!`
- ARG2 correspond donc à une adresse IP qui a été encryptée => on XOR chaque caractère avec 170, puis on encode le tout en base64

Ensuite :
- le code affiche un premier message en mandarin, puis appelle des fonctions windows pour faire clignoter notre écran
- on remarque également la présence d'une string encryptée, `m5OYhJuckoSbmZiEm56Y`
- le programme appelle une fonction qui prend cette string en argument

Enfin :
- la dernière fonction concatène trois strings hard-codées, la première étant le nom du programme lui-même, ce qui nous donne :
```
"wannasmile  wd3r05OZxpeX  m5OYhJuckoSbmZiEm56Y"
```
- la chaîne concaténée est utilisée comme ligne de commande par la fonction Windows `CreateProcessW()`, ce qui signifie que le programme se relance avec les deux chaînes encryptées en arguments
- si un nouveau process est créé et qu'il réussit, nous accédons à une fonction mystère appelée `death()`
- si un nouveau process est créé mais que son code de sortie vaut 0, l'exécutable se détruit (comportement surtout constaté en sandbox)
- on reçoit également un second message en mandarin
- si le process échoue à la création, nous recevons gronk gronk.

2. La chaîne `m5OYhJuckoSbmZiEm56Y` correspond donc à l'adresse `192.168.132.142`, une fois décodée. On la retrouve dans le `main()`, peu avant l'appel de la fonction6() (`relaunchSelf()`). Tous les éléments pour comprendre et décoder la chaîne sont présents en dur dans le code, telle que la clé 170 utilisée pour XOR. On remarque également que des indices (`64 comme la nintendo` etc) ont été stockés dans un tableau de constantes (du moins, selon le décompilateur). Ils sont tous immédiatement accessibles grâce à `strings`.

3. Nous avons écrit un script python qui prend en paramètre le chemin d'un programme et automatise ce que nous avons fait à la main :
- le script utilise `strings` et analyse l'output afin de récupérer des chaînes de caractères potentiellement encodées en base64
- il les décode, puis les XOR avec la clé 170
- il analyse le résultat pour voir s'il s'agit bien d'une adresse IPv4 ou IPv6 valide
- si oui, il nous l'affiche.

