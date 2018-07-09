// definieren der Grösse des Arrays
const int GR_ARRAY = 8;
const int SPIELER = 2;
void AusgabeArray(int iFeld[GR_ARRAY][GR_ARRAY],int izaehler,int iReihe, int iSpieler1, int iSpieler2);
void initialisierenArray(int iFeld[GR_ARRAY][GR_ARRAY]);

/* Copyright Mulholland Kierin, All rights reserved 
Copyright (C) 2007 Free Software Foundation, Inc. <http://fsf.org/>
 Everyone is permitted to copy and distribute verbatim copies
 of this license document, but changing it is not allowed.
 
 This source is protected under the GNU license which you can read here:
 http://www.gnu.org/licenses/gpl-3.0.txt
 */
//Spiel Kopf
void name();
void menu();
int connect4();
//Game 1 erster Spieler fängt an, bei game 2 umgekehrt
int game1(int iFeld[GR_ARRAY][GR_ARRAY],int iWin); //Spieler 1 fängt an
int game2(int iFeld[GR_ARRAY][GR_ARRAY],int iWin); //Spieler 2 fängt an
//Gesamter Teil des ersten Spieler
int iSpieler1Pack(int iFeld[GR_ARRAY][GR_ARRAY]);
int iSpieler2Pack(int iFeld[GR_ARRAY][GR_ARRAY]);

//Eingabe der Namen
void vEingabeSpielername(std::string Name[SPIELER]);

//Eingabe des Spielers
int iEingabeSp1(int iSpieler1);
int iEingabeSp2(int iSpieler2);

//Animation
void vAnimationSp1(int iFeld[GR_ARRAY][GR_ARRAY],int iReihe,int iSpalte,int iSpieler1, int iSpieler2);
void vAnimationSp2(int iFeld[GR_ARRAY][GR_ARRAY],int iReihe,int iSpalte,int iSpieler1, int iSpieler2);

// Ausgabe des Spielers
void vAusgabeSp1(int iFeld[GR_ARRAY][GR_ARRAY],int iReihe,int iSpalte,int iSpieler1,int iSpieler2);
void vAusgabeSp2(int iFeld[GR_ARRAY][GR_ARRAY],int izaehler,int iReihe,int iSpieler1,int iSpieler2);

//check ob feld besetzt ist oder nicht
int iCheckbesetzt(int iFeld[GR_ARRAY][GR_ARRAY],int izaehler,int iReihe,int iSpieler1,int iSpieler2);
//Check horizontal,vertical und diagonal für den ersten Spieler
int iCheckWinHor(int iFeld[GR_ARRAY][GR_ARRAY],int iReihe,int iSpalte,int iSpieler1,int iSpieler2);
int iCheckWinVer(int iFeld[GR_ARRAY][GR_ARRAY],int iReihe,int iSpalte,int iSpieler1,int iSpieler2);
int iCheckWinDia1(int iFeld[GR_ARRAY][GR_ARRAY],int iReihe,int iSpalte,int iSpieler1,int iSpieler2);
int iCheckWinDia2(int iFeld[GR_ARRAY][GR_ARRAY],int iReihe,int iSpalte,int iSpieler1,int iSpieler2);



// Ausgabe des Gewinners
void vWinSp1();
void vWinSp2();

//Extras
void  vSpielstandSpeichern(int iFeld[GR_ARRAY][GR_ARRAY]);
void  vSpielstandLaden(int iFeld[GR_ARRAY][GR_ARRAY]);

void copyright();
void Inhalt();



