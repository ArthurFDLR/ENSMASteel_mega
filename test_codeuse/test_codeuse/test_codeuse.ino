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

// Numéro de l'intéruption 0, il correspond à la pin 18
const int interuptA = 5;

  

// Pin 19 de l'Arduino 
const int canalB   = 19;



// Fin déclaration des constantes
//-----------------------------------------------------------

//-----------------------------------------------------------
// Déclaration des fonctions

void Reagir();


// Fin déclaration des fonctions
//-----------------------------------------------------------

//-----------------------------------------------------------
// Déclaration des variables globales
  
// Variables (compteurs) qui vont stocker 
// le nombre de tics comptés pour chaque codeur
long Ticks = 0;


// Fin Déclaration des variables globales
//-----------------------------------------------------------

//-----------------------------------------------------------
// Fonction d'initialisation
void setup()
{
  // Permet un affichage du résultat sur la consol Série
  Serial.begin(9600);   

  // Initialisation des pin 19 et 18 en entrèes 
  pinMode(canalB, INPUT);


  // Déclaration des intéruptions
  // Ici les fonctions d'intéruptions s'éxecutent
  // sur fronts montants : CHANGE
  attachInterrupt(interuptA, ReagirMontant, RISING);
//  attachInterrupt(interuptB, Reagir, CHANGE);
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


  Serial.print("   Compt D");
  Serial.println(Ticks);
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
void ReagirMontant()
{  
  if (digitalRead(canalB) == HIGH) 
  {
      Ticks ++;
  }
    else
    {
      Ticks --;
  }

}
