#ifndef CONSTANTS
#define CONSTANTS


#define STATE
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
#define PINCE_GAUCHE_HALF_RETRACTED 1625    //Capture palet
#define PINCE_GAUCHE_HALF_EXTENDED 1000    //Entonnoire
#define PINCE_GAUCHE_EXTENDED 600           //Depart

#define PINCE_DROITE_PIN 6
#define PINCE_DROITE_RETRACTED 700          //Pince cachée
#define PINCE_DROITE_HALF_RETRACTED 1320    //Capture palet
#define PINCE_DROITE_HALF_EXTENDED 1900     //Entonnoire
#define PINCE_DROITE_EXTENDED 2400          //Depart

#define MILLIS_CLEAR 250

#define POMPE_GAUCHE_PIN_MOTEUR_PWR     11
#define POMPE_GAUCHE_PIN_MOTEUR_SENS    51
#define POMPE_GAUCHE_PIN_MOTEUR_BRAKE   49
#define POMPE_GAUCHE_PIN_AMP            A0

#define POMPE_DROITE_PIN_MOTEUR_PWR     10
#define POMPE_DROITE_PIN_MOTEUR_SENS    47
#define POMPE_DROITE_PIN_MOTEUR_BRAKE   45
#define POMPE_DROITE_PIN_AMP            A1

#define SHARP_PALET_GAUCHE_PIN          A2
#define SHARP_PALET_DROITE_PIN          A7
#define SHARP_PALET_SEUIL               300

#define SHARP_AVG_PIN           A4
#define SHARP_AVD_PIN           A5
#define SHARP_ARG_PIN           A8
#define SHARP_ARD_PIN           A3
#define SHARP_ANTICOL_AR_SEUIL       500
#define SHARP_ANTICOL_AV_SEUIL_PROMITY     400
#define SHARP_ANTICOL_AV_SEUIL_ALERT     550



// --------------------------------- Filtre ---------------------------------
enum typeFiltreE { PAS_DE_FILTRE, LOWPASS1, LOWPASS2, DELAY };

// --------------------------------- Messages ---------------------------------
#define NB_MESSAGES 11
enum MessageE
{
	Default, Impossible, Tirette, Pince_Ouverte, Pince_Mi_Fermee, Pince_Fermee, Evitemment, Ok, Done, New_Action, Sync, Evitemment_Clear
};

// --------------------------------- Barillet ---------------------------------
#define BARILLET_PIN_A 20
#define BARILLET_PIN_B 20

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

#define MAXPWM 255
// --------------------------------- Bras ---------------------------------

#endif // !CONSTANTS
