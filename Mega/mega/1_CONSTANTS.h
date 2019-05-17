#ifndef CONSTANTS
#define CONSTANTS

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
