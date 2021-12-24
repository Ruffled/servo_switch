#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

#define OFFSET -9
#define SWING 28
#define LOOP_LIMIT 2000
#define SWITCH_DELAY 400
int center = 90 + OFFSET;
int max_rot = center + SWING;
int min_rot = center - SWING;
char *at_position = "unset";

void setup() {
    myservo.attach(9);  // attaches the servo on pin 9 to the servo object
    Serial.begin(115200);
    select_one();
    for (int i = 0; i < 5; i++) {
        Serial.println();
    }
    Serial.println("========================= Welcome =========================");
    for (int i = 0; i < 5; i++) {
        Serial.println();
    }
}

void select_one(void) {
    myservo.write(min_rot);
    delay(SWITCH_DELAY);
    myservo.write(center);
    at_position = "one";
}

void select_two(void) {
    myservo.write(max_rot);
    delay(SWITCH_DELAY);
    myservo.write(center);
    at_position = "two";
}

int got_marker = 0;
void loop() {
    static int loop_count = LOOP_LIMIT;
    int rc;
    while (Serial.available() > 0) {
        rc = Serial.read();
        if (got_marker) {
            if ( rc == '1' ) {
                select_one();
                loop_count = LOOP_LIMIT;
            }
            else if ( rc == '2' ) {
                select_two();
                loop_count = LOOP_LIMIT;
            }
            else if ( rc == '=' ) {
                Serial.println(at_position);
            }
            else {
                Serial.println("Invalid port selection");
            }
            got_marker = 0;
        }
        else if ( rc == '=' ) {
            got_marker = 1;
        }
    }
    delay(10);
    if (loop_count++ >= LOOP_LIMIT) {
        Serial.println(at_position);
        loop_count = 0;
    }
}

// vim: sw=4 ts=4 et
