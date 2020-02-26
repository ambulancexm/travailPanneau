petit programme sur arduino Uno
==============
pour calculer le travail fourni d'un panneau 

j'utilise plusieurs shield 
- ACS712 20A Module capteur de courant Comme ampèremetre
- Haljia Max 25 V détecteur de tension Gamme 3 terminal pour le voltmetre
- je gere la lumière avec un capteur et un pont diviseur de 10Kohm

je voulais essayer avec un DC 5V WCS1800 on verra à l'avenir


Ampère sur A0
volt sur A1
lumière sur A2

cet ensemble doit juste servir de terminal de capture de données
impossible de garder des données à long terme sur un arduino

les prochains essais se feront avec un wemos R1 avec wifi intégré et
un serveur websocket sur nodejs