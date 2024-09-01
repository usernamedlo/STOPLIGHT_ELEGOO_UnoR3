#include <Arduino.h>

// /*
//    Code 11 - Edurobot.ch, destiné à l'Arduino
//    Reproduit le principe du feu rouge
// */

const int bouton = 4; // la broche 4 devient bouton
const int green = 12; // la broche 12 devient green
const int red = 13;   // la broche 13 devient red
const int yellow = 7; // la broche 7 devient yellow

bool boutonEtat = LOW;        // Variable pour stocker l'état du bouton
bool etat = LOW;              // Variable pour stocker l'état ON/OFF
bool dernierBoutonEtat = LOW; // Variable pour stocker le dernier état du bouton

void setup()
{
  pinMode(bouton, INPUT);  // Initialise le bouton comme entrée
  pinMode(green, OUTPUT);  // Initialise la green comme sortie
  pinMode(red, OUTPUT);    // Initialise la red comme sortie
  pinMode(yellow, OUTPUT); // Initialise la yellow comme sortie
  digitalWrite(red, HIGH); // La red est allumée par défaut
  digitalWrite(yellow, LOW);
  digitalWrite(green, LOW);
  Serial.begin(9600); // Ouvre le port série à 9600 bauds
}

void loop()
{
  boutonEtat = digitalRead(bouton); // On mémorise l'état du bouton

  if (boutonEtat == HIGH && dernierBoutonEtat == LOW) // Si le bouton est pressé
  {
    etat = !etat; // Change l'état ON/OFF
    if (etat == HIGH)
    {
      digitalWrite(yellow, HIGH); // Allume la yellow
      digitalWrite(red, LOW);
      delay(2000);               // Attend 2 secondes
      digitalWrite(yellow, LOW); // Éteint la yellow
    }
    else
    {
      digitalWrite(yellow, HIGH); // Allume la yellow
      digitalWrite(green, LOW);
      delay(2000);               // Attend 2 secondes
      digitalWrite(yellow, LOW); // Éteint la yellow
    }
  }

  dernierBoutonEtat = boutonEtat; // Mémorise l'état du bouton

  if (etat == HIGH) // Si l'état est ON
  {
    digitalWrite(red, LOW); // la red s'éteint

    digitalWrite(green, HIGH); // la green est allumée
  }
  else // Si l'état est OFF
  {
    digitalWrite(green, LOW);
    digitalWrite(red, HIGH);
  }
}
