#include <Keyboard.h>
// https://github.com/alextaujenis/RBD_Button
#include <RBD_Timer.h>
#include <RBD_Button.h>

int LED_PIN = 9;
int BUTTON_PIN = 6;
RBD::Button muteButton(BUTTON_PIN);
bool muted = false;

void setup() {
    pinMode(LED_PIN, OUTPUT);
    Serial.begin(115200);
    Keyboard.begin();
}

void setStatusLED() {
    digitalWrite(LED_PIN, muted ? LOW : HIGH);
}

void muteToggle() {
    muted = !muted;
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press('m');
    delay(100);
    Keyboard.releaseAll();
}

void loop() {
    if (muteButton.onPressed()) {
        muteToggle();
    }
    setStatusLED();
    delay(10);
}