#include <Adafruit_NeoPixel.h>

#define LED_PIN     6
#define NUM_LEDS    6

Adafruit_NeoPixel strip(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

enum State { GREEN, YELLOW, RED, PURPLE };
State currentState = RED;

unsigned long lastChange = 0;
unsigned long stateDuration = 1000;

void setup() {
  strip.begin();
  strip.setBrightness(50);
  strip.show();
  randomSeed(analogRead(0)); // For randomness
  pickNewState();
}

void loop() {
  unsigned long now = millis();

  if (now - lastChange > stateDuration) {
    pickNewState();
  }

  if (currentState == PURPLE) {
    flashPurple();
  }
}

void pickNewState() {
  lastChange = millis();
  stateDuration = random(1000, 2500);  // in milliseconds

  int roll = random(100); // 0–99

  if (roll < 40) {
    setState(GREEN);
  } else if (roll < 80) {
    setState(RED);
  } else if (roll < 95) {
    setState(YELLOW);
  } else {
    setState(PURPLE);
    stateDuration = random(1000, 3500); // purple has its own range
  }
}

void setState(State newState) {
  currentState = newState;
  strip.clear();

  switch (newState) {
    case GREEN:
      strip.setPixelColor(0, strip.Color(0, 255, 0));
      strip.setPixelColor(1, strip.Color(0, 255, 0));
      break;
    case YELLOW:
      strip.setPixelColor(2, strip.Color(255, 150, 0));
      strip.setPixelColor(3, strip.Color(255, 150, 0));
      break;
    case RED:
      strip.setPixelColor(4, strip.Color(255, 0, 0));
      strip.setPixelColor(5, strip.Color(255, 0, 0));
      break;
    case PURPLE:
      // We’ll flash purple in loop()
      break;
  }

  strip.show();
}

void flashPurple() {
  static bool on = false;
  static unsigned long lastFlash = 0;

  if (millis() - lastFlash > 300) { // blink every 300ms
    lastFlash = millis();
    on = !on;

    for (int i = 0; i < NUM_LEDS; i++) {
      strip.setPixelColor(i, on ? strip.Color(150, 0, 150) : 0);
    }
    strip.show();
  }
}
