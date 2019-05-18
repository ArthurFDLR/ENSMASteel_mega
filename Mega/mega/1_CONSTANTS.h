#ifndef CONSTANTS
#define CONSTANTS
//---------------------------------- PINS&Servo   --------------------------------
#define PIN_CODEUSE2_A 37
#define PIN_CODEUSE2_B 39
#define PIN_CODEUSE1_A 29
#define PIN_CODEUSE1_B 31

#define BRAS_GAUCHE_PIN 3
#define BRAS_GAUCHE_RETRACTED 2300          //Vertical
#define BRAS_GAUCHE_HALF_RETRACTED 1500     //OSEF
#define BRAS_GAUCHE_HALF_EXTENDED 1500      //OSEF
#define BRAS_GAUCHE_EXTENDED 1330           //Horizontal

#define BRAS_DROIT_PIN 2
#define BRAS_DROIT_RETRACTED 1230           //Vertical
#define BRAS_DROIT_HALF_RETRACTED 1500      //Osef
#define BRAS_DROIT_HALF_EXTENDED 1500       //OSEF
#define BRAS_DROIT_EXTENDED 2250            //Horizontal

#define DOIGT_GAUCHE_PIN 5
#define DOIGT_GAUCHE_RETRACTED 1130         //Bloquage palet
#define DOIGT_GAUCHE_HALF_RETRACTED 1500    //Osef
#define DOIGT_GAUCHE_HALF_EXTENDED 1500     //Osef
#define DOIGT_GAUCHE_EXTENDED 1700          //Caché

#define DOIGT_DROIT_PIN 4
#define DOIGT_DROIT_RETRACTED 1780           //Bloquage palet
#define DOIGT_DROIT_HALF_RETRACTED 1500     //OSEF
#define DOIGT_DROIT_HALF_EXTENDED 1500      //OSEF
#define DOIGT_DROIT_EXTENDED  1280         //caché

#define PINCE_GAUCHE_PIN 7
#define PINCE_GAUCHE_RETRACTED 2290         //pince cachée
#define PINCE_GAUCHE_HALF_RETRACTED 1570    //Capture palet
#define PINCE_GAUCHE_HALF_EXTENDED 1080    //Entonnoire
#define PINCE_GAUCHE_EXTENDED 600           //Depart

#define PINCE_DROITE_PIN 6
#define PINCE_DROITE_RETRACTED 700          //Pince cachée
#define PINCE_DROITE_HALF_RETRACTED 1350    //Capture palet
#define PINCE_DROITE_HALF_EXTENDED 1900     //Entonnoire
#define PINCE_DROITE_EXTENDED 2400          //Depart

#define MILLIS_CLEAR 500

// --------------------------------- Filtre ---------------------------------
enum typeFiltreE { PAS_DE_FILTRE, LOWPASS1, LOWPASS2, DELAY };

// --------------------------------- Messages ---------------------------------
#define NB_MESSAGES 11
enum MessageE
{
	Default, Impossible, Tirette, Pince_Ouverte, Pince_Mi_Fermee, Pince_Fermee, Evitemment, Ok, Done, New_Action, Sync, Evitemment_Clear
};

// --------------------------------- Barillet ---------------------------------
#define BARILLET_PIN_A 11
#define BARILLET_PIN_B 12

enum PaletE
{
	Rouge, Bleu, Vert, Gold, VIDE
};

// --------------------------------- FILO ---------------------------------
#define TAILLE_FILO 40

// --------------------------------- Elevator ---------------------------------
#define LONGUEUR_COURSE 0.1

enum ElevatorStateE
{
	Moving, Up, Down
};

// --------------------------------- Bras ---------------------------------

#endif // !CONSTANTS
