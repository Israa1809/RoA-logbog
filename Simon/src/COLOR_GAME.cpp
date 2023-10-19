#include <Arduino.h>
#include "COLOR_GAME.h"

int melody[] = {
    NOTE_G4, NOTE_A4, 0, NOTE_C5, 0, 0, NOTE_G4, 0, 0, 0,
    NOTE_E4, 0, NOTE_D4, NOTE_E4, NOTE_G4, 0,
    NOTE_D4, NOTE_E4, 0, NOTE_G4, 0, 0,
    NOTE_D4, 0, NOTE_E4, 0, NOTE_G4, 0, NOTE_A4, 0, NOTE_C5, 0};

int noteDuration = 115; // Dette indstiller tempoet

int LEDnumber = 0; // Holder styr på, hvilken LED vi er på (0-3)

// Spiltilstandsvariabler
byte gameMode = MODE_MEMORY;
byte gameBoard[32]; // Indeholder kombinationen af knapper, som spilleren skal trykke på
byte gameRound = 0; // Tæller antallet af vellykkede runder, som spilleren har klaret

// ###############################################

void setLEDs(byte leds)
{
  if ((leds & CHOICE_RED) != 0)
    digitalWrite(LED_RED, HIGH);
  else
    digitalWrite(LED_RED, LOW);

  if ((leds & CHOICE_GREEN) != 0)
    digitalWrite(LED_GREEN, HIGH);
  else
    digitalWrite(LED_GREEN, LOW);

  if ((leds & CHOICE_BLUE) != 0)
    digitalWrite(LED_BLUE, HIGH);
  else
    digitalWrite(LED_BLUE, LOW);

  if ((leds & CHOICE_YELLOW) != 0)
    digitalWrite(LED_YELLOW, HIGH);
  else
    digitalWrite(LED_YELLOW, LOW);
}

void buzz_sound(int buzz_length_ms, int buzz_delay_us)
{
  // Konverterer den samlede afspilningstid fra millisekunder til mikrosekunder
  long buzz_length_us = buzz_length_ms * (long)1000;

  // Kør, indtil den resterende afspilningstid er mindre end en enkelt buzz_delay_us
  while (buzz_length_us > (buzz_delay_us * 2))
  {
    buzz_length_us -= buzz_delay_us * 2; // Formindsk den resterende afspilningstid

    // Skift buzzeren ved forskellige hastigheder
    digitalWrite(BUZZER1, LOW);
    digitalWrite(BUZZER2, HIGH);
    delayMicroseconds(buzz_delay_us);
    digitalWrite(BUZZER1, HIGH);
    digitalWrite(BUZZER2, LOW);
    delayMicroseconds(buzz_delay_us);
  }
}

void toner(byte which, int buzz_length_ms)
{
  setLEDs(which); // Tænd for en given LED

  // Afspil lyden forbundet med den givne LED
  switch (which)
  {
  case CHOICE_RED:
    buzz_sound(buzz_length_ms, 1136);
    break;

  case CHOICE_GREEN:
    buzz_sound(buzz_length_ms, 568);
    break;

  case CHOICE_BLUE:
    buzz_sound(buzz_length_ms, 851);
    break;

  case CHOICE_YELLOW:
    buzz_sound(buzz_length_ms, 638);
    break;
  }

  setLEDs(CHOICE_OFF); // Sluk for alle LED'er
}

byte checkButton(void)
{
  if (digitalRead(BUTTON_RED) == 0)
    return (CHOICE_RED);
  else if (digitalRead(BUTTON_GREEN) == 0)
    return (CHOICE_GREEN);
  else if (digitalRead(BUTTON_BLUE) == 0)
    return (CHOICE_BLUE);
  else if (digitalRead(BUTTON_YELLOW) == 0)
    return (CHOICE_YELLOW);

  return (CHOICE_NONE); // Når ingen knap er blevet trykket på
}

void winner_sound(void)
{
  // Skifter buzzeren
  for (byte x = 250; x > 70; x--)
  {
    for (byte y = 0; y < 3; y++)
    {
      digitalWrite(BUZZER2, HIGH);
      digitalWrite(BUZZER1, LOW);
      delayMicroseconds(x);
      digitalWrite(BUZZER2, LOW);
      digitalWrite(BUZZER1, HIGH);
      delayMicroseconds(x);
    }
  }
}

void play_winner(void)
{
  setLEDs(CHOICE_GREEN | CHOICE_BLUE);
  winner_sound();

  setLEDs(CHOICE_RED | CHOICE_YELLOW);
  winner_sound();

  setLEDs(CHOICE_GREEN | CHOICE_BLUE);
  winner_sound();

  setLEDs(CHOICE_RED | CHOICE_YELLOW);
  winner_sound();
}

void play_loser(void)
{
  setLEDs(CHOICE_RED | CHOICE_GREEN);
  buzz_sound(255, 1500);

  setLEDs(CHOICE_BLUE | CHOICE_YELLOW);
  buzz_sound(255, 1500);

  setLEDs(CHOICE_RED | CHOICE_GREEN);
  buzz_sound(255, 1500);

  setLEDs(CHOICE_BLUE | CHOICE_YELLOW);
  buzz_sound(255, 1500);
}

void attractMode(void)
{
  while (1)
  {
    setLEDs(CHOICE_RED);
    delay(100);

    if (checkButton() != CHOICE_NONE)
      return;

    setLEDs(CHOICE_BLUE);
    delay(100);

    if (checkButton() != CHOICE_NONE)
      return;

    setLEDs(CHOICE_GREEN);
    delay(100);

    if (checkButton() != CHOICE_NONE)
      return;

    setLEDs(CHOICE_YELLOW);
    delay(100);

    if (checkButton() != CHOICE_NONE)
      return;
  }
}

void changeLED(void)
{
  setLEDs(1 << LEDnumber); // Skift LED'en
  LEDnumber++;             // Gå videre til næste LED

  if (LEDnumber > 3)
    LEDnumber = 0; // Wrap tælleren ved behov
}

void play_beegees()
{
  // Tænd for bunden til højre (gul) LED
  setLEDs(CHOICE_YELLOW);
  toner(CHOICE_YELLOW, 150);
  setLEDs(CHOICE_RED | CHOICE_GREEN | CHOICE_BLUE);

  while (checkButton() != CHOICE_NONE)
    ; // Vent på, at brugeren stopper med at trykke på knappen

  setLEDs(CHOICE_NONE); // Sluk for LED'er
  delay(1000);          // Vent et sekund, før sangen afspilles
  digitalWrite(BUZZER1, LOW);

  while (checkButton() == CHOICE_NONE)
  {
    // Gennemgå tonerne i melodien:
    for (int thisNote = 0; thisNote < 32; thisNote++)
    {
      changeLED();
      tone(BUZZER2, melody[thisNote], noteDuration);

      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      // Stop med at afspille tonen:
      noTone(BUZZER2);
    }
  }
}

byte wait_for_button(void)
{
  long startTime = millis();
  while ((millis() - startTime) < ENTRY_TIME_LIMIT)
  {
    byte button = checkButton();

    if (button != CHOICE_NONE)
    {
      toner(button, 150); // Afspil den knap, brugeren lige har trykket på

      while (checkButton() != CHOICE_NONE)
        ;

      delay(10); // Dette hjælper med debouncing og utilsigtede dobbelttryk
      return button;
    }
  }

  return CHOICE_NONE; // Hvis vi når hertil, er tiden udløbet!
}

void playMoves(void)
{
  for (byte currentMove = 0; currentMove < gameRound; currentMove++)
  {
    toner(gameBoard[currentMove], 150);
    // Vent en vis tid mellem afspilning af knappen

    delay(150); // 150 fungerer godt. 75 bliver hurtigt.
  }
}

void add_to_moves(void)
{
  byte newButton = random(0, 4); // min (inkluderet), max (ekskluderet)
  // Knapperne 0 til 3, konverteres til CHOICEs

  if (newButton == 0)
    newButton = CHOICE_RED;

  else if (newButton == 1)
    newButton = CHOICE_GREEN;

  else if (newButton == 2)
    newButton = CHOICE_BLUE;

  else if (newButton == 3)
    newButton = CHOICE_YELLOW;

  gameBoard[gameRound++] = newButton; // Tilføj denne nye knap til spilarrayet
}

boolean play_memory(void)
{
  randomSeed(millis());
  gameRound = 0; // Nulstil spillet til begyndelsen
  while (gameRound < ROUNDS_TO_WIN)
  {
    add_to_moves(); // Tilføjer en knap til de nuværende træk og afspil dem derefter
    playMoves();    // Afspil de nuværende knapper

    for (byte currentMove = 0; currentMove < gameRound; currentMove++)
    {
      byte choice = wait_for_button(); // Ser hvilken knap brugeren trykker på
      if (choice == 0)
        return false; // Hvis ventetiden udløber, taber spilleren

      if (choice != gameBoard[currentMove])
        return false; // Hvis valget er forkert, taber spilleren
    }
    delay(1000);
  }
  return true; // Hvis vi når hertil, har spilleren vundet
}

boolean play_battle(void)
{
  gameRound = 0; // Nulstil spillet til begyndelsen
  while (1)
  {
    byte newButton = wait_for_button(); // Vent på, at brugeren indtaster det næste træk
    gameBoard[gameRound++] = newButton; // Tilføj denne nye knap til spilarrayet

    for (byte currentMove = 0; currentMove < gameRound; currentMove++)
    {
      byte choice = wait_for_button();
      if (choice == 0)
        return false; // Hvis ventetiden udløber, taber spilleren.

      if (choice != gameBoard[currentMove])
        return false; // Hvis valget er forkert, taber spilleren.
    }
    delay(100); // Giv brugeren ekstra 100 ms til at overgive spillet til den anden spiller
  }
  return true; // Vi bør aldrig nå hertil
}

void setup()
{

  // knapper
  pinMode(BUTTON_RED, INPUT_PULLUP);
  pinMode(BUTTON_GREEN, INPUT_PULLUP);
  pinMode(BUTTON_BLUE, INPUT_PULLUP);
  pinMode(BUTTON_YELLOW, INPUT_PULLUP);

  // LED'er
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);

  // Buzzer
  pinMode(BUZZER1, OUTPUT);
  // pinMode(BUZZER2, OUTPUT);

  // Mode-check
  gameMode = MODE_MEMORY; // Som standard spiller vi hukommelsesspillet

  if (checkButton() == CHOICE_YELLOW)
    play_beegees();

  if (checkButton() == CHOICE_GREEN)
  {
    gameMode = MODE_BATTLE; // Sæt spillet i kamp-tilstand

    setLEDs(CHOICE_GREEN);
    toner(CHOICE_GREEN, 150);
    setLEDs(CHOICE_RED | CHOICE_BLUE | CHOICE_YELLOW); // Tænd de andre LED'er, indtil du slipper knappen

    while (checkButton() != CHOICE_NONE)
      ; // Vent på, at brugeren stopper med at trykke på knappen
  }

  play_winner(); // Spil vinder-toner
}

void loop()
{
  attractMode(); // Blink lysene, mens vi venter på, at brugeren trykker på en knap

  // Indikér begyndelsen af spillet
  setLEDs(CHOICE_RED | CHOICE_GREEN | CHOICE_BLUE | CHOICE_YELLOW); // Tænd alle LED'er
  delay(1000);
  setLEDs(CHOICE_OFF); // Sluk LED'er
  delay(250);

  if (gameMode == MODE_MEMORY)
  {
    // Spil hukommelsesspillet og håndter resultatet
    if (play_memory() == true)
      play_winner(); // Spilleren vandt, afspil vinder-toner

    else
      play_loser(); // Spilleren tabte, afspil taber-toner
  }

  if (gameMode == MODE_BATTLE)
  {
    play_battle(); // Spil kampspillet og håndter resultatet
    play_loser();  // Spilleren tabte, afspil taber-toner
  }
}
