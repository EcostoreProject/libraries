# ecostore-common

Librairies Arduino partagées par tous les groupes du projet ecostore (hub, relais, capteurs).

| Librairie | Rôle |
|---|---|
| `FrameProtocol` | Encodage / décodage des trames échangées entre les nœuds |
| `XBeeAT` | Configuration d'un module XBee en mode AT (mode commande, adresse de destination) |

## Utilisation dans un projet

Ce repo s'ajoute comme sous-module git **à la place du dossier `libraries/`** du projet :

```
mon-projet/
  mon_croquis/mon_croquis.ino
  libraries/        ← sous-module vers ecostore-common
```

```bash
git submodule add <url-ecostore-common> libraries
```

Dans le croquis :

```c
#include <frame_protocol.h>
#include <xbee_at.h>
```

Compilation avec arduino-cli :

```bash
arduino-cli compile --fqbn arduino:avr:uno --libraries libraries mon_croquis
```

Avec l'IDE Arduino : régler l'emplacement du carnet de croquis (Préférences) sur la racine du projet.

Cloner un projet qui utilise ce sous-module :

```bash
git clone --recursive <url-du-projet>
```

Récupérer la dernière version des librairies :

```bash
git submodule update --remote libraries
```

## Protocole de trame

Trame de 4 octets :

| Octet | Contenu |
|---|---|
| 0 | Octet de début `0xAA` |
| 1 | `dest_id` (bits 7-5) · `src_id` (bits 4-2) · `cmd` (bits 1-0) |
| 2 | `value`, 8 bits non signés (0 à 255) |
| 3 | Checksum : somme des octets 0 à 2, modulo 256 |

| `cmd` | Valeur |
|---|---|
| `FRAME_CMD_READ` | `0b00` |
| `FRAME_CMD_WRITE` | `0b01` |
| *(réservé)* | `0b10`, trame rejetée à la réception |
| `FRAME_CMD_ERROR` | `0b11` |

Exemple : dest 3, src 0, `WRITE`, valeur 29 → `AA 61 1D 28`.

## Identifiants des nœuds

`dest_id` et `src_id` sont codés sur 3 bits : **8 nœuds au maximum**, hub et relais compris.

| ID | Nœud | Groupe | Adresse XBee (DH / DL) |
|---|---|---|---|
| 0 | Hub | | |
| 1 | | | |
| 2 | | | |
| 3 | | | |
| 4 | | | |
| 5 | | | |
| 6 | | | |
| 7 | | | |

## Règles de contribution

- Toute modification du protocole casse la communication avec les nœuds qui ne sont pas à jour : passer par une pull request relue par les autres groupes.
- Taguer chaque version (`v0.1.0`, `v0.2.0`…) et l'indiquer dans `library.properties`.
