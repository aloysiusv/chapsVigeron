1. Comme évoqué précédemment, le programme tente de `ping` l'adresse `192.168.132.142`, mais celle-ci ne le `pong` pas. En analysant le code de plus près, on se rend compte qu'il faudrait trouver un moyen de pouvoir répondre à ce `ping` pour déclencher le vrai comportement du programme.

2. Un problème se présente : il n'est pas possible de changer l'adresse dans le code, ou via les arguments du programme. Lorsqu'il se relance, il utilise nécessairement l'adresse qui ne `pong` pas.
Ma solution (voir Screenshots) :

- trouver une adresse IP capable de répondre au `ping` (j'ai choisi l'adresse de `loopback`, la fameuse 127.0.0.1)
- rediriger l'IP du code vers cette adresse grâce à la commande `netsh` dans Powershell.

Et voilà, nous sommes correctement infectés !

3. J'ai trouvé ce défi très divertissant et j'ai pu découvrir beaucoup de nouvelles choses. Merci beaucoup !

4. Pour répondre à la question de Cyrille : je pense que Aimé a mis 11min pour finir le README.md, mais il a peut-être bien mis 2h entre le moment de la première compilation et la rédaction du tout ! Merci `unzip -l ` pour m'avoir donné les dates des dernières modifications avant ajout à l'archive. 
```Shell
$ unzip -l wannasmile.zip

Archive:  wannasmile.zip
  Length      Date    Time    Name
---------  ---------- -----   ----
   178629  2024-08-23 02:28   wannasmile
     3714  2024-08-23 02:39   README.md
---------                     -------
   182343                     2 files
```