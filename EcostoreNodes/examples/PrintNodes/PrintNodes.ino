#include <ecostore_nodes.h>

void setup() {
    Serial.begin(9600);
    Serial.print("Hub : ");             Serial.println(NODE_HUB);
    Serial.print("Relai : ");           Serial.println(NODE_RELAI);
    Serial.print("Temp/hum ext : ");    Serial.println(NODE_TEMP_HUM_EXT);
    Serial.print("Photorésistance : "); Serial.println(NODE_PHOTORESISTANCE);
    Serial.print("Temp int : ");        Serial.println(NODE_TEMP_INT);
    Serial.print("Servo store : ");     Serial.println(NODE_SERVO_STORE);
}

void loop() {
}
