1. Lorsque l'exécutable se lance sans arguments, une boîte de dialogue s'ouvre avec un message en mandarin. Quitter la boîte de dialogue (avec `OK` ou la croix) crée un clignotement de toute la surface de l'écran suivi d'un second message, toujours en mandarin.
Lancer l'exécutable avec 1 ou 2 arguments, depuis la ligne de commande, ouvre une nouvelle boîte de dialogue avec `Nice try, fellow`.

2. Avec `wireshark` en parallèle, nous nous apercevons qu'il y a effectivement une activité réseau :
- le protocole `ICMP` est utilisé
- notre machine `10.0.2.15` envoie un `ping` à l'adresse `192.168.132.142` (une adresse locale d'admin routeur ?) mais le paquet contient également la string `dataMakeSens`
- malheureusement, il n'y a pas de réponse à ce `ping`.