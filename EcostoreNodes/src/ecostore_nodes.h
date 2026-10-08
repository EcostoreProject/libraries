#ifndef ECOSTORE_NODES_H
#define ECOSTORE_NODES_H

// Identifiants des nœuds du réseau ecostore (champs dest_id / src_id de FrameProtocol).
// Codés sur 3 bits : 8 nœuds au maximum (0 à 7).
// Toute modification doit passer par une pull request validée par tous les groupes.

#define NODE_HUB              0
#define NODE_RELAI            1
#define NODE_TEMP_HUM_EXT     2
#define NODE_PHOTORESISTANCE  3
#define NODE_TEMP_INT         4
#define NODE_SERVO_STORE      5
// 6 et 7 : libres

// Débit UART commun à tous les modules XBee
#define XBEE_BAUD 9600

// Adresses 64 bits des modules XBee (DH / DL), à relever sur l'étiquette de chaque module
// ou avec les commandes ATSH / ATSL.
#define XBEE_HUB_DH               0x0013A200
#define XBEE_HUB_DL               0x00000000  // TODO
#define XBEE_RELAI_DH             0x0013A200
#define XBEE_RELAI_DL             0x00000000  // TODO
#define XBEE_TEMP_HUM_EXT_DH      0x0013A200
#define XBEE_TEMP_HUM_EXT_DL      0x00000000  // TODO
#define XBEE_PHOTORESISTANCE_DH   0x0013A200
#define XBEE_PHOTORESISTANCE_DL   0x00000000  // TODO
#define XBEE_TEMP_INT_DH          0x0013A200
#define XBEE_TEMP_INT_DL          0x00000000  // TODO
#define XBEE_SERVO_STORE_DH       0x0013A200
#define XBEE_SERVO_STORE_DL       0x00000000  // TODO

#endif // ECOSTORE_NODES_H
