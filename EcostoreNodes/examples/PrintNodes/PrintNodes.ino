#include <ecostore_nodes.h>

void setup() {
    Serial.begin(9600);
    Serial.print("Hub : ");             Serial.println(NODE_HUB);
    Serial.print("Relai : ");           Serial.println(NODE_RELAI);
    Serial.print("Temp ext : ");        Serial.println(NODE_CAPTEUR_TEMPERATURE_EXTERNE);
    Serial.print("Humidite : ");        Serial.println(NODE_CAPTEUR_HUMIDITE);
    Serial.print("Photorésistance : "); Serial.println(NODE_CAPTEUR_PHOTORESISTANCE);
    Serial.print("Temp int : ");        Serial.println(NODE_CAPTEUR_TEMPERATURE_INTERNE);
    Serial.print("Servo store : ");     Serial.println(NODE_SERVOMOTEUR);
}

void loop() {
}
