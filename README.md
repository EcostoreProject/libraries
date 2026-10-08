# libraries

Librairies Arduino partagées par tous les groupes du projet ecostore (hub, relai, capteurs, servomoteur).

| Librairie | Rôle |
|---|---|
| `FrameProtocol` | Encodage / décodage des trames échangées entre les nœuds |
| `XBeeAT` | Configuration d'un module XBee en mode AT (mode commande, adresse de destination) |
| `EcostoreNodes` | Identifiants des nœuds, débit et adresses des XBee |

## Utilisation dans un projet

Ce repo s'ajoute comme sous-module git **à la place du dossier `libraries/`** du projet :

```
mon-projet/
  mon_croquis/mon_croquis.ino
  libraries/        ← sous-module vers ce repo
```

```bash
git submodule add ../libraries libraries
```

L'URL relative `../libraries` fonctionne pour tout repo de la même organisation GitHub.

Dans le croquis :

```c
#include <frame_protocol.h>
#include <xbee_at.h>
#include <ecostore_nodes.h>
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

`dest_id` et `src_id` sont codés sur 3 bits : **8 nœuds au maximum**, hub et relai compris. La référence est [`EcostoreNodes/src/ecostore_nodes.h`](EcostoreNodes/src/ecostore_nodes.h), qui contient aussi les adresses 64 bits des XBee.

| ID | Constante | Nœud | Repo |
|---|---|---|---|
| 0 | `NODE_HUB` | Hub | `hub` |
| 1 | `NODE_RELAI` | Relai | `relai` |
| 2 | `NODE_TEMP_HUM_EXT` | Température / humidité extérieure | `temp-hum-ext` |
| 3 | `NODE_PHOTORESISTANCE` | Photorésistance | `photoresistance` |
| 4 | `NODE_TEMP_INT` | Température intérieure | `temp-int` |
| 5 | `NODE_SERVO_STORE` | Servomoteur des stores | `servo-store` |
| 6-7 | | libres | |

## Règles de contribution

- Toute modification du protocole casse la communication avec les nœuds qui ne sont pas à jour : passer par une pull request relue par les autres groupes.
- Taguer chaque version (`v0.1.0`, `v0.2.0`…) et l'indiquer dans `library.properties`.
- La CI compile tous les exemples à chaque push : une pull request qui casse la compilation ne doit pas être fusionnée.
