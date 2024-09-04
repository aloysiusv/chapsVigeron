1. Nous avons affaire à un fichier de type `.exe`, en 64-bits :
```Shell
$ file wannasmile
wannasmile: PE32+ executable (GUI) x86-64, for MS Windows
```

2. Voici son hash MD5:
```Shell
$ md5sum wannasmile
88dc2dde82fe70786b9af5e36f0ae9b5 wannasmile
```

3. Voici son hash SHA256:
```Shell
$ sha256sum wannasmile
3427843e2492c8fe06503a09a8c79aada97c7300a6336c576592a7fee1717946  wannasmile
```

4. Voici sa date de compilation, obtenue grâce à un script python (voir 'script'):
```Shell
$ python getCompilationTime.py  
Date de compilation: 2024-08-23 00:28:44
```

5. J'ai découvert après coup que tous ces 
éléments pouvaient être obtenus facilement grâce à VirusTotal.
Voici d'autres éléments intéressants :
- la date de compilation me permet de savoir que la personne qui a créé ce PE travaille très tard
- le nom du fichier rend hommage au virus Wannacry
- le retour de la commande `strings` donne quelques indices =>
```Shell
wireshark
64 comme la nintendo
tu connais le chiffrement xor ?
Felix Lebrun
```
- il y a aussi des chaînes de caractères suspectes :
```Shell
 wd3r05OZxpeX 
Y`O(W
N0R`O& & 
kwAy93l==
`O}Y
v*geg
*****
m5OYhJuckoSbmZiEm56Y
[...]
""gY0uKgg0=L""
```