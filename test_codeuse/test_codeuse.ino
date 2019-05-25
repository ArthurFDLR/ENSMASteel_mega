/************************************************************
           ___    _____  ____ 
          / _ \  / ___/ / __ \
         / , _/ / /__  / /_/ /
        /_/|_|  \___/  \____/ 

  Auteur : Association Robotique Club de l'Ouest
  
  Petit exemple de logiciel pour l'acquisition de tics
  pour codeurs incrementals. 

  Cet exemple vos pour l'acquisition de deux codeurs
  incrementaux sur une Arduino Uno mais il est très 
  simplement adaptable sur d'autres types d'arduino

************************************************************/

//-----------------------------------------------------------
// Déclaration des constantes

// Numéro de l'intéruption 0, il correspond à la pin 2
const int interuptG = 2;
// Numéro de l'intéruption 1, il correspond à la pin 3
const int interuptD = 3;  

// Pin 9 de l'Arduino Uno
const int canalBG   = 20;  
// Pin 10 de l'Arduino Uno
const int canalBD   = 21; 

// Fin déclaration des constantes
//-----------------------------------------------------------

//-----------------------------------------------------------
// Déclaration des fonctions

void Reagir();
void ReagirBis();

// Fin déclaration des fonctions
//-----------------------------------------------------------

//-----------------------------------------------------------
// Déclaration des variables globales
  
// Variables (compteurs) qui vont stocker 
// le nombre de tics comptés pour chaque codeur
long comptD = 0;
long comptG = 0;

// Fin Déclaration des variables globales
//-----------------------------------------------------------

//-----------------------------------------------------------
// Fonction d'initialisation
void setup()
{
  // Permet un affichage du résultat sur la consol Série
  Serial.begin(9600);   

  // Initialisation des pin 9 et 10 en entrèes
  pinMode(canalBG, INPUT);  
  pinMode(canalBD, INPUT);

  // Déclaration des intéruptions
  // Ici les fonctions d'intéruptions s'éxecutent
  // sur fronts montants : RISING
  attachInterrupt(interuptG, Reagir, RISING);
  attachInterrupt(interuptD, ReagirBis, RISING);
}
// Fin initialisation
//-----------------------------------------------------------


//-----------------------------------------------------------
// Fonction principale
// Avec l'utilisation des intéruptions la fonction loop qui
// habituellement est très remplie, la ne sert presque à rien
// sinon afficher le résultat du comptage sur le port série
void loop()
{
  Serial.print("Compt G");
  Serial.print(comptG); 

  Serial.print("   Compt D");
  Serial.println(comptD);
}
// Fin fonction principale
//-----------------------------------------------------------

//-----------------------------------------------------------
// Fonction d'intéruption pour le codeur gauche
// 
// Fonction appelée par un tic du codeur gauche. 
// On regarde le sens de rotation de celui-ci 
// (on teste l'état de la voie déphasée) et on 
// incrémente ou décrémente le compteur comptG.
void Reagir()
{  
  if(digitalRead(canalBG) == HIGH)
  {
    comptG--;        
  }
  else
  {
    comptG++;      
  }      
}
// Fin fonction d'intéruption pour le codeur gauche
//-----------------------------------------------------------


//-----------------------------------------------------------
// Fonction d'intéruption pour le codeur droit
// 
// Fonction appelée par un tic du codeur droit. 
// On regarde le sens de rotation de celui-ci 
// (on teste l'état de la voie déphasée) et on 
// incrémente ou décrémente le compteur comptD.
void ReagirBis()
{     
  if(digitalRead(canalBD) == HIGH)
  {
    comptD ++;
  }
  else
  {
    comptD--;     
  }
}
// Fin fonction d'intéruption pour le codeur droit
//-----------------------------------------------------------
