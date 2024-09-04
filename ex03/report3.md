1. Le logiciel a été codé en C++, et suit les normes de C++17 si l'on en croit l'info trouvée grâce à `strings` :
```Shell
GNU C17 13.2.0 -mtune=core2 -march=nocona -g -g -g -O2 -O2 -O2 -fno-ident -fPIC -fbuilding-libgcc -fno-stack-protector
```

2. La seule fonction du code qui utilise l'IP est la fonction4(), car elle appelle `inet_addr()` et `IcmpSendEcho()` pour `ping` une adresse.

3. L'argument de fonction4() est une string construite par fonction5(). Elle est d'abord décodée en base64, puis passée à fonction3() qui XOR chaque caractère par 170.

BONUS - renommer les fonctions :

- fonction1() : `displayMsgBox()` => prend un message en argument et l'affiche à l'écran sous la forme d'une boîte de dialogue
- fonction3() : `strXor()` => XOR chaque caractère d'une string par 170
- fonction4() : `sendPing()` => envoie un `ping` avec le contenu `dataMakeSens` à une adresse spécifiée
- fonction5() : `decode()` => permet de décrypter une chaîne en base64 et utilise `strXor()`
- fonction6() : `relaunchSelf()` => tente de relancer le programme sous certaines conditions avec des arguments codés en dur.
