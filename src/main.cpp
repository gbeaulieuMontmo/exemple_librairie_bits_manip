// Exemple d'utilisation de la librairie bits_manip dans le cadre du cours
// de programmation "243-33A-MO Microcontrôleur 2"
// Auteur: Guillaume Beaulieu
// Date: 2024-06-03
// Pour obtenir cet exemple de code, voir le dépôt GitHub suivant :
// https://github.com/gbeaulieuMontmo/exemple_librairie_bits_manip.git

// Inclure le fichier d'en-tête Arduino pour utiliser les fonctions Arduino
// ici les <> indiquent que le fichier est dans un répertoire standard
#include <Arduino.h>

// Inclure le fichier d'en-tête pour les manipulations de bits
// ici les "" indiquent que le fichier est dans le même répertoire que ce fichier
// le fichier bits_manip.h doit être dans le répertoire src/include
// le fichier bits_manip.cpp doit être dans le répertoire src
#include "bits_manip.h" 

#define DEL PB7 // Pin de la LED (PORTB pin 7, pin numérique 13 sur l'Arduino)

void setup() {
  Serial.begin(9600);
  delay(500); // Attendre que le port série soit prêt
  DDRB |= (1 << DEL); // Configurer la pin de la LED comme sortie
  // Autre façon de configurer la pin de la LED comme sortie
  //DDRB = setBit(DDRB, DEL); 
}

void loop() {
  // Ici changer les valeurs pour tester les fonctions
  int octet = 0b00001111; // Exemple de valeur de départ
  unsigned char pos = 2; // Position du bit à manipuler (0 à 7)
  int mask = 0b11110000; // Masque pour les opérations sur plusieurs bits

  // setBit
  int res_setBit = setBit(octet, pos);
  Serial.print("setBit: ");

  // Rappel : le deuxième argument (facultatif) de Serial.println 
  // peut être BIN, DEC, HEX ou OCT
  Serial.println(res_setBit, BIN);

  // setBitM
  int res_setBitM = setBitM(octet, mask);
  Serial.print("setBitM: ");
  Serial.println(res_setBitM, BIN);

  // clearBit
  int res_clearBit = clearBit(octet, pos);
  Serial.print("clearBit: ");
  Serial.println(res_clearBit, BIN);

  // clearBitM
  int res_clearBitM = clearBitM(octet, mask);
  Serial.print("clearBitM: ");
  Serial.println(res_clearBitM, BIN);

  // clearAllBit
  int res_clearAllBit = clearAllBit(octet);
  Serial.print("clearAllBit: ");
  Serial.println(res_clearAllBit, BIN);

  // modifyBit (mettre le bit à 1)
  int res_modifyBit1 = modifyBit(octet, pos, true);
  Serial.print("modifyBit (1): ");
  Serial.println(res_modifyBit1, BIN);

  // modifyBit (mettre le bit à 0)
  int res_modifyBit0 = modifyBit(octet, pos, false);
  Serial.print("modifyBit (0): ");
  Serial.println(res_modifyBit0, BIN);

  // flipBit
  int res_flipBit = flipBit(octet, pos);
  Serial.print("flipBit: ");
  Serial.println(res_flipBit, BIN);

  // isBitSet
  bool res_isBitSet = isBitSet(octet, pos);
  Serial.print("isBitSet: ");
  Serial.println(res_isBitSet);
  while(1)
  {
    // On fait clignoter la LED intégrée pour indiquer que le programme est terminé
    PORTB ^= (1 << DEL); // Inverser l'état de la LED
    //PORTB = flipBit(PORTB, DEL); // Autre façon d'inverser l'état de la LED
    delay(1000);                     
  }
}
