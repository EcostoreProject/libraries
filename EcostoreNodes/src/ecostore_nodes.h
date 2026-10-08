#ifndef ECOSTORE_NODES_H
#define ECOSTORE_NODES_H

// Identifiants des nœuds du réseau ecostore (champs dest_id / src_id de FrameProtocol).
// Codés sur 3 bits : 8 nœuds au maximum (0 à 7).
// Toute modification doit passer par une pull request validée par tous les groupes.

#define NODE_HUB                            0
#define NODE_CAPTEUR_PHOTORESISTANCE        1
#define NODE_CAPTEUR_TEMPERATURE_INTERNE    2
#define NODE_SERVOMOTEUR                    3
#define NODE_RELAI                          4
#define NODE_CAPTEUR_TEMPERATURE_EXTERNE    5
#define NODE_CAPTEUR_HUMIDITE               6

// Débit UART commun à tous les modules XBee
#define XBEE_BAUD 9600

// Adresses 64 bits des modules XBee (DH / DL), à relever sur l'étiquette de chaque module
// ou avec les commandes ATSH / ATSL.
#define XBEE_HUB_DH               0x00000000
#define XBEE_HUB_DL               0x00001000
#define XBEE_PHOTORESISTANCE_DH   0x00000000 
#define XBEE_PHOTORESISTANCE_DL   0x00001001
#define XBEE_TEMP_INT_DH          0x00000000
#define XBEE_TEMP_INT_DL          0x00001002 
#define XBEE_SERVO_STORE_DH       0x00000000
#define XBEE_SERVO_STORE_DL       0x00001003 
#define XBEE_RELAI_DH             0x00000000
#define XBEE_RELAI_DL             0x00001004
#define XBEE_TEMP_HUM_EXT_DH      0x00000000
#define XBEE_TEMP_HUM_EXT_DL      0x00001005
#define XBEE_HUMUDITE_EXT_DH      0x00000000
#define XBEE_HUMIDITE_EXT_DL      0x00001006

#endif // ECOSTORE_NODES_H
