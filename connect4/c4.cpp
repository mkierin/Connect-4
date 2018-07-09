/* Copyright Mulholland Kierin, All rights reserved 
Copyright (C) 2007 Free Software Foundation, Inc. <http://fsf.org/>
 Everyone is permitted to copy and distribute verbatim copies
 of this license document, but changing it is not allowed.
 
 This source is protected under the GNU license which you can read here:
 http://www.gnu.org/licenses/gpl-3.0.txt
 */
 

#include<iostream>
#include "header.h"
#include "color.h"

#include<stdlib.h>
#include<conio.h>
#include <cstdlib> 
#include <ctime> 

#include <string>
#include <fstream>
#include <windows.h>


using namespace std;
   
    int iFeld[GR_ARRAY][GR_ARRAY];
    string Name[SPIELER];//Dekl. Array Name
	int iSpieler1 =1;
    int iSpieler2 =2; // wert des Spielers
	
	
    int iReihe=7; // zaehler  
    int iSpalte=0;
    int iVierZaehler=0; // Ist im überprüf verfahren eingebunden. Jedes mal wo z.b 1 auftaucht nimmt der iVierzaehler zu   111  => iVierzaehler=3  gewonnen bei vier
    int iWin=0;
	int x = 1; // für die vorschlaufen

//Name des Spiels und das Menu wird aufgerufen
int main()
{
   name();
 menu();
   //connect4();
	
return 0;
}// end menu

	// Menu vom Spiel vier gewinnt. 
	void menu()
{
  int input;
  cout<<blue <<"            "<<endl;
  cout<<blue <<char(26)<<"       1.   Neues Spiel starten"   <<endl;
  cout<<blue <<char(26)<<"       2.   Spiel Laden"<<endl;
  cout<<blue <<char(26)<<"       3.   Copyright"<<endl;
  cout<<blue <<char(26)<<"       4.   Inhalt"<<endl;
  cout<<blue <<char(26)<<"       5.   Exit\n"<<endl;

  cout<<"                   Selection:  ";
  cin>> input;
  switch ( input ) {
   case 1:            
    connect4();
    break;
   case 2:            //Dies sollte zwischen den funktionen wechseln
   vSpielstandLaden(iFeld);
    break;
   case 3:            
    copyright();
    break;
   case 4:            
   Inhalt();
    break;
	 case 5:            
   system("exit");
    break;
  default:            
    cout<<"Falsche Eingabe.\n";
    break;
  }
}//end void
	// Name des Spiels Graphic mässig ausgegeben
	void name()
{
	cout<<red <<"******************************************"<<endl;
	cout<<blue <<"        _____ _           ";
	cout<<red <<"               *"<<endl;
	cout<<blue <<"       |  |  |_|___ ___";
	cout<<red  <<"                  *"<<endl;
	cout<<blue <<"       |  |  | | -_|  _|  ";
	cout<<red  <<"               *"<<endl;
	cout<<blue <<"        "<<char(92)<<"___/|_|___|_|"<<red <<char(3)  <<endl;
    
	cout<<red <<"                 _         _"<<endl;
	cout<<red <<"   ___ ___ _ _ _|_|___ ___| |_ "<<endl;
	cout<<red <<"  | . | -_| | | | |   |   |  _|"<<endl;
	cout<<red <<"  |_  |___|_____|_|_|_|_|_|_|"<<blue<<char(6)<<endl;
	cout<<red <<"  |___|"<<blue  <<char(184) <<"Mulholland Kierin"<<endl;
	cout<<red <<"******************************************"<<endl;

} // end name 
	//Vier Gewinnt spielverlauf (beinhaltet initialisieren und game)
int connect4()
{
   // definieren der variablen
    system("cls");
 
    int iSpieler1 =1;
    int iSpieler2 =2; // wert des Spielers
	
	
    int iReihe=7; // zaehler  
    int iSpalte=0;
    int iVierZaehler=0; // Ist im überprüf verfahren eingebunden. Jedes mal wo z.b 1 auftaucht nimmt der iVierzaehler zu   111  => iVierzaehler=3  gewonnen bei vier
    int iWin=0;
	int x = 1;
	int iRandomplayer = 0;
   
    
   
   // Anfangen mit dem Feld înitialisieren und leer ausgeben
    vEingabeSpielername(Name);//Aufruf Funktion
    initialisierenArray(iFeld); // das Feld wird mir 0er aufgefüllt
    AusgabeArray(iFeld,iReihe,iSpalte,iSpieler1,iSpieler2); // nach jedem eintrag steht die neue Zahl im Feld 	eingetragen
	srand((unsigned)time(0));
	iRandomplayer = (rand()%2)+1;
	if (iRandomplayer == 1){
	game1(iFeld,iWin);
	}
	if (iRandomplayer == 2){
	game2(iFeld,iWin);
	}
	
return 0;
}
		//Eingabe des Spielernamen Für Spieler 1 und Spieler 2
		void vEingabeSpielername(std::string Name[SPIELER])
{
string NameSpieler;
for(int x=1; x<3; x++)
	{
		//Eingabe Name und TaschenGeld
		cout << "Gebe den Namen des " << x <<". Spielers ein!" <<endl;
		cin >> Name[x];
		 
	system("cls");	
	}
}//end void
		//Spielstand speichern
		void  vSpielstandSpeichern(int iFeld[GR_ARRAY][GR_ARRAY]) 
		{
		ofstream outfile;
        outfile.open ("viergewinntSpielstand.txt");
		for (int x = 1; x < GR_ARRAY; x++){
                 for (int y = 1; y < GR_ARRAY; y++){
                 outfile<<iFeld[x][y];
				 
                 }  // end for
        }  // end for
		outfile.close();
		
		
		}
		void  vSpielstandLaden(int iFeld[GR_ARRAY][GR_ARRAY])
		{
char cZahlen[100];
int a=3;


ifstream infile("viergewinntSpielstand.txt");
if ( !infile.is_open()) { cout << "Fehler:Datei konnte nicht geöffnet werden\n"; return; }
while (! infile.eof() )
{
    infile.getline (cZahlen,100);
    cout << cZahlen << endl;
}
			

			
			
//			
//			ifstream in_file("viergewinntSpielstand.txt", ios::binary);
//	//Check if the file is open
//	if(!in_file.is_open()){
//		cout << "File not opened..." << endl;
//		
//	}
//	//read the file (two columns) to the array
//	for(int i=0; !in_file.eof(); i++){
//		infile.getline (cZahlen,100);
//    cout << cZahlen << endl;
//		
//	}
//for(int i=0; i<49; i++){
//		cout << iFeld[i][0];
//	}
//				 
//

  


  

  AusgabeArray(iFeld,iReihe,iSpalte,iSpieler1,iSpieler2);
}
		
		
		// Die Funktion Game wiederholt sich solange kein Spieler eine Reihe von Vier gemacht hat (Zuerst kommt eine Random funktion der bestimmt welcher Spieler anfängt)
			int game1(int iFeld[GR_ARRAY][GR_ARRAY],int iWin)
{
     
	iWin = iSpieler1Pack(iFeld);//Alle Funktionen die für den ersten Spieler sind 
    if (iWin == 1)
	{
		vWinSp1();
	}
	iWin =iSpieler2Pack(iFeld);//Alle Funktionen die für den zweiten Spieler sind
	if (iWin ==2)
	{
		vWinSp2();
	}
	else{
	  game1(iFeld,iWin);
	}
return 0;
}


			int game2(int iFeld[GR_ARRAY][GR_ARRAY],int iWin)
{
     
	iWin = iSpieler2Pack(iFeld);//Alle Funktionen die für den ersten Spieler sind 
    if (iWin == 2)
	{
		vWinSp2();
	}
	iWin =iSpieler1Pack(iFeld);//Alle Funktionen die für den zweiten Spieler sind
	if (iWin ==1)
	{
		vWinSp1();
	}
	else{
	  game2(iFeld,iWin);
	}
return 0;
}


			
			//Initialisierung des Spielfeldes und Ausgabe
			void initialisierenArray(int iFeld[GR_ARRAY][GR_ARRAY])
{
     for (int x = 1; x < GR_ARRAY; x++){
                 for (int y = 1; y < GR_ARRAY; y++){
                 iFeld[x][y] = 0;
                 }  // end for
        }  // end for
} // end void

			void AusgabeArray(int iFeld[GR_ARRAY][GR_ARRAY],int iReihe,int iSpalte, int iSpieler1, int iSpieler2)
{
 // Wir benutzen Ascii charachter um die Buchschtaben anzuzeigen
 cout << "   ";
 for (int x = 1; x != GR_ARRAY; x++){
 cout << red << x << " ";
        
 } // end for
 cout <<green <<"(Press 8 to return to the menu)";
 cout << endl;
 cout << "  ";  // Ausgabe des oberen Ramens des spielfeldes
        for (int i = 1;i < 16;i++){
     cout<< blue <<char(219);
 } // end for
		cout << endl;
                 for (int x = 1; x < GR_ARRAY; x++){
                     if(x==8) { 
                     cout << "  ";
                            for(int i=0;i<17;i++) {  // Margin left 6e
                            
                             } // end for
                             cout<<endl;
                             cout << "  "; //Margin left 6e
                                 }else{
                                  cout << "  ";
                                 } // end else
                                
				         for (int y = 1; y < GR_ARRAY; y++) { // feld vertical
                                              cout <<blue<<char(179)<<blue;
											  if (iFeld[x][y] ==1)
											  {
											  cout<<blue<<char(6);
											  }
											  else if (iFeld[x][y]==2){
											  cout<< red<<char(3);
											  }
											  else
											  {
												  cout<<" ";
											  }
											  //Ausgabe der 0 als leere Felder 
											  
													  
												  
											  
                                                      if(y==7){
                                                      cout <<white <<char(179);
                                                       } // end if
                                               } // end for
                                                cout << endl;
                            } // end for 
                            cout << "  ";
                            for (int i = 1;i < 16;i++){
                            cout<<blue <<char(219);
                 } // end for
                cout << endl;
} // end void


					
					//Die Ganzen Abläufe von jedem Spieler werden in zwei Funktionen verpackt. 
					int iSpieler1Pack(int iFeld[GR_ARRAY][GR_ARRAY])
{
   
    
    int iSpieler1 =1;
    int iSpieler2 =2; // wert des Spielers
	
	
    int iReihe=7; // zaehler  
    int iSpalte=0;
    int iVierZaehler=0; // Ist im überprüf verfahren eingebunden. Jedes mal wo z.b 1 auftaucht nimmt der iVierzaehler zu   111  => iVierzaehler=3  gewonnen bei vier
    int iWin=0;
	int x = 1;
	
	 
   iSpalte = iEingabeSp1(iSpieler1); // Eingabe des ersten Spielers
   iReihe = iCheckbesetzt(iFeld,iReihe,iSpalte,iSpieler1,iSpieler2); // kontrolliert ob ein Spieler seine Figur dort setzten kann // unabhängig welchen Spieler spieltvAusgabeSp1(iFeld,iReihe,iSpalte,iSpieler1,iSpieler2);
   vAnimationSp1(iFeld,iReihe,iSpalte,iSpieler1,iSpieler2);
   vAusgabeSp1(iFeld,iReihe,iSpalte,iSpieler1,iSpieler2);
   iWin = iCheckWinHorSp1(iFeld,iReihe,iSpalte,iSpieler1,iSpieler2);
   
   if (iWin==1){
   return 1;
   }
   iWin = iCheckWinVerSp1(iFeld,iReihe,iSpalte,iSpieler1,iSpieler2);
   if (iWin==1){
   return 1;
   }
  iWin =  iCheckWinDia1Sp1(iFeld,iReihe,iSpalte,iSpieler1,iSpieler2);
   if (iWin==1){
   return 1;
   }
  iWin =  iCheckWinDia2Sp1(iFeld,iReihe,iSpalte,iSpieler1,iSpieler2);
   if (iWin==1){
   return 1;
   }
   return 0;
	 
   
   }//end while
					int iSpieler2Pack(int iFeld[GR_ARRAY][GR_ARRAY])
{
  
    int iSpieler1 =1;
    int iSpieler2 =2; // wert des Spielers
	
	
    int iReihe=7; // zaehler  
    int iSpalte=0;
    int iVierZaehler=0; // Ist im überprüf verfahren eingebunden. Jedes mal wo z.b 1 auftaucht nimmt der iVierzaehler zu   111  => iVierzaehler=3  gewonnen bei vier
    int iWin=0;
	int x = 1;
    
	
	iSpalte = iEingabeSp2(iSpieler2); // Ausgabe des Feldes
    iReihe = iCheckbesetzt(iFeld,iReihe,iSpalte,iSpieler1,iSpieler2); // kontrolliert ob ein Spieler seine Figur dort setzten kann
   vAnimationSp2(iFeld,iReihe,iSpalte,iSpieler1,iSpieler2);
	vAusgabeSp2(iFeld,iReihe,iSpalte,iSpieler1,iSpieler2);
    iWin = iCheckWinHorSp2(iFeld,iReihe,iSpalte,iSpieler1,iSpieler2);
   if (iWin==2){
   return 2;
   }
   iWin = iCheckWinVerSp2(iFeld,iReihe,iSpalte,iSpieler1,iSpieler2);
   if (iWin==2){
   return 2;
   }

   iWin =  iCheckWinDia1Sp1(iFeld,iReihe,iSpalte,iSpieler1,iSpieler2);
   if (iWin==2){
   return 2;
   }
  iWin =  iCheckWinDia2Sp1(iFeld,iReihe,iSpalte,iSpieler1,iSpieler2);
   if (iWin==2){
   return 2;
   }
   
   
   return 0;
}// end int




						
					//Der Spieler gibt die Spalte ein wo seine Figur gesetzt werden soll
						int iEingabeSp1(int iSpieler1)

{
int iSpalte =0;

           cout<< blue<<Name[1] <<  " muss spielen: " ;
            cin>> iSpalte;
			if (iSpalte==8){
            system("cls");
				main();
			}
return iSpalte;
            
            
           
	 
          }   // end void                                 

						int iEingabeSp2(int iSpieler2)

{
int iSpalte =0;
			
			cout<<red << Name[2] <<  " muss spielen: " ;
            cin>> iSpalte;
            if (iSpalte==8){
            system("cls");
				main();
			}
			return iSpalte;
           
	 
          }   // end void                                 


						
						//Animation 
						void vAnimationSp1(int iFeld[GR_ARRAY][GR_ARRAY],int iReihe,int iSpalte,int iSpieler1, int iSpieler2)
						{
						
							for (int x=1;x<iReihe;x++){
							system("cls");
							iFeld[x][iSpalte]=1;
							AusgabeArray(iFeld,iReihe,iSpalte,iSpieler1,iSpieler2);
							Sleep(100);
							
							iFeld[x][iSpalte]=0;
							
							}//end for

						}
						void vAnimationSp2(int iFeld[GR_ARRAY][GR_ARRAY],int iReihe,int iSpalte,int iSpieler1, int iSpieler2)
						{
						
							for (int x=1;x<iReihe;x++){
							system("cls");
							iFeld[x][iSpalte]=2;
							AusgabeArray(iFeld,iReihe,iSpalte,iSpieler1,iSpieler2);
							Sleep(100);
							
							iFeld[x][iSpalte]=0;
							
							}//end for

						}
						
						//Hier wird überprüft ob ein Feld schon eine Einheit drauf hat.
						int iCheckbesetzt(int iFeld[GR_ARRAY][GR_ARRAY],int iReihe,int iSpalte,int iSpieler1,int iSpieler2)
{
    
    
   while (iFeld[iReihe][iSpalte]!=0){  // Während das Feld ungleich null ist dann wird das Integer iReihe -1 gerechnet.
    iReihe--;
    }
    return iReihe;   
       
        

} // end int
		                
						//Ausgabe Funktion von beide Spieler
						void vAusgabeSp1(int iFeld[GR_ARRAY][GR_ARRAY],int iReihe,int iSpalte,int iSpieler1,int iSpieler2)
{
 
           
          
            iFeld[iReihe][iSpalte] = iSpieler1;
            system("cls");
	        AusgabeArray(iFeld,iReihe,iSpalte,iSpieler1,iSpieler2);
			vSpielstandSpeichern(iFeld);
	        
	         
                    
                       
}// end void
						void vAusgabeSp2(int iFeld[GR_ARRAY][GR_ARRAY],int iReihe,int iSpalte,int iSpieler1,int iSpieler2)
{
 
           
          
            iFeld[iReihe][iSpalte] = iSpieler2;
            system("cls");
	        AusgabeArray(iFeld,iReihe,iSpalte,iSpieler1,iSpieler2);
	        
	         
                    
                       
}// end void
//Hier wird überprüft ob vier Zahlen von einem Spieler horizontal,vertical oder diagonal sind
//Überprüfung des ersten Spielers
int iCheckWinHorSp1(int iFeld[GR_ARRAY][GR_ARRAY],int iReihe,int iSpalte,int iSpieler1,int iSpieler2)
{

int iVierZaehler=0;
int m=0;
int n=0;
int iWin=0;
// horizontal überprüfen. Von unten nach oben für Spieler 1

for (m=GR_ARRAY;m>1;m--){ //Vorschlaufe zählt die Zeilen von unten nach oben
	iVierZaehler=0;
	for (n=1;n<GR_ARRAY;n++){ // Zaehlt die Spalten von links nach rechts
		
			if (iFeld[m][n]==1 && iVierZaehler<4)
{
			iVierZaehler++;
			
}
if (iFeld[m][n]==1 && iVierZaehler==4)
{	
			iWin=1;
				return iWin;
}			
if(iFeld[m][n]==2)
{
		iVierZaehler=0;
}// end if
		
if(iFeld[m][n]==0)
		{
		iVierZaehler=0;
		

 
}//end if

		}
	
}// end for
iVierZaehler=0;
return 0;

		



}   // end int
//Diagonal check von links unten nach rechts oben  --> \ 
int iCheckWinVerSp1(int iFeld[GR_ARRAY][GR_ARRAY],int iReihe,int iSpalte,int iSpieler1,int iSpieler2)
{


int iVierZaehler=0;
int m=0;
int n=0;
int iWin=0;
// horizontal überprüfen. Von unten nach oben für Spieler 1

for (n=1;n<GR_ARRAY;n++){ //Vorschlaufe zählt die Spalten von unten nach oben
	iVierZaehler=0;
	for (m=GR_ARRAY;m>1;m--){ // Zaehlt die Reihen von links nach rechts
		if (iFeld[m][n]==1 && iVierZaehler<4)
{
			iVierZaehler++;
			
}
if (iFeld[m][n]==1 && iVierZaehler==4)
{	
			iWin=1;
				return iWin;
}			
if(iFeld[m][n]==2)
{
		iVierZaehler=0;
}// end if
		
if(iFeld[m][n]==0)
		{
		iVierZaehler=0;
		

 
}//end if

		}
	
}// end for
iVierZaehler=0;
return 0;

}   // end int

//Diagonal check on links oben nach rechts unten  --> /

int iCheckWinDia1Sp1(int iFeld[GR_ARRAY][GR_ARRAY],int iReihe,int iSpalte,int iSpieler1,int iSpieler2)
{
int iVierZaehler1=0;
int iVierZaehler2=0;
int iWin=0;
int iSpalten=0;
int iAnfangsWert=0;
int iZeilen = 0;
int iEndWert=0;
int AnzDurchlauefe=0;
// horizontal überprüfen. Von unten nach oben für Spieler 1
for (AnzDurchlauefe=1;AnzDurchlauefe<8;AnzDurchlauefe++)
{
	//cout<<"AnzDurchlauefe:"<<AnzDurchlauefe<<endl;
	iVierZaehler1=0;
	iVierZaehler2=0;
	switch ( AnzDurchlauefe ) {
  case 1:            
    iAnfangsWert=4;
	iEndWert=1;
    break;
  case 2:            
    iAnfangsWert=5;
	iEndWert=1;
    break;
  case 3:            
    iAnfangsWert=6;
	iEndWert=1;
    break;
	case 4:            
    iAnfangsWert=7;
	iEndWert=1;
    break;
	case 5:            
    iAnfangsWert=7;
	iEndWert=2;
    break;
	case 6:            
    iAnfangsWert=7;
	iEndWert=3;
    break;
	case 7:            
    iAnfangsWert=7;
	iEndWert=4;
    break;
  } //end switch

for (int iZeilen = iAnfangsWert;iZeilen>=iEndWert;iZeilen--)
{
    
	switch ( AnzDurchlauefe ) {
	case 1:            
		iSpalten = iZeilen + 3;
	break;
	case 2:            
		iSpalten = iZeilen + 2;
	break;
	case 3:            
		iSpalten = iZeilen + 1;
	break;
	case 4:            
		iSpalten = iZeilen;
	break;
	case 5:            
		iSpalten = iZeilen - 1;
	break;
	case 6:            
		iSpalten = iZeilen - 2;
	break;
	case 7:            
		iSpalten = iZeilen - 3;
	break;


  } //end switch

if (iFeld[iZeilen][iSpalten]==1 && iVierZaehler1<4)
{
			iVierZaehler2=0;	
			iVierZaehler1++;
			//cout<<"SP1 urnol 15.50:"<<iVierZaehler1<<endl;
}
if (iFeld[iZeilen][iSpalten]==1 && iVierZaehler1==4)
{	
				iVierZaehler2=0;
				iWin=1;
			//	cout<<"SP1 urnol 15.50 gewinnt:"<<iVierZaehler1<<endl;
				return iWin;
}		
if (iFeld[iZeilen][iSpalten]==2 && iVierZaehler2<4)
{
			iVierZaehler1=0;
			iVierZaehler2++;
			//cout<<"SP2 urnol 15.50:"<<iVierZaehler2<<endl;
}
if (iFeld[iZeilen][iSpalten]==2 && iVierZaehler2==4)
{	
				iVierZaehler1=0;
				iWin=2;
			//	cout<<"SP2 urnol 15.50 gewinnt:"<<iVierZaehler2<<endl;
				return iWin;
		

 
}//end if
iSpalten=0;
}// end for iZeile = ...
}//end for AnzDurchlauefe

	return 0;
}   // end int

int iCheckWinDia2Sp1(int iFeld[GR_ARRAY][GR_ARRAY],int iReihe,int iSpalte,int iSpieler1,int iSpieler2)
{
int iVierZaehler1=0;
	int iVierZaehler2=0;
int iWin=0;
int iSpalten=0;
int iAnfangsWert=0;
int iZeilen = 0;
int iEndWert=0;
int AnzDurchlauefe=0;
// horizontal überprüfen. Von unten nach oben für Spieler 1
for (AnzDurchlauefe=1;AnzDurchlauefe<8;AnzDurchlauefe++)
{
	//cout<<"AnzDurchlauefe:"<<AnzDurchlauefe<<endl;
	iVierZaehler1=0;
	iVierZaehler2=0;
	switch ( AnzDurchlauefe ) {
  case 1:            
    iAnfangsWert=4;
	iEndWert=1;
    break;
  case 2:            
    iAnfangsWert=5;
	iEndWert=1;
    break;
  case 3:            
    iAnfangsWert=6;
	iEndWert=1;
    break;
	case 4:            
    iAnfangsWert=7;
	iEndWert=1;
    break;
	case 5:            
    iAnfangsWert=7;
	iEndWert=2;
    break;
	case 6:            
    iAnfangsWert=7;
	iEndWert=3;
    break;
	case 7:            
    iAnfangsWert=7;
	iEndWert=4;
    break;
  } //end switch

for (int iZeilen = iAnfangsWert;iZeilen>=iEndWert;iZeilen--)
{
  iSpalten = (iAnfangsWert + iEndWert) - iZeilen; 

if (iFeld[iZeilen][iSpalten]==1 && iVierZaehler1<4)
{
			iVierZaehler2=0;	
			if(iVierZaehler<=3){
			iVierZaehler1++;
			}
			else{
			iVierZaehler2=0;
				iWin=1;
				//cout<<"SP1 ulnor 8.10 gewinnt:"<<iVierZaehler1<<endl;
				return iWin;
			}
			//cout<<"SP1 ulnor 8.10:"<<iVierZaehler1<<endl;
}
if (iFeld[iZeilen][iSpalten]==1 && iVierZaehler1==4)
{	
				iVierZaehler2=0;
				iWin=1;
				//cout<<"SP1 ulnor 8.10 gewinnt:"<<iVierZaehler1<<endl;
				return iWin;
}		
if (iFeld[iZeilen][iSpalten]==2 && iVierZaehler2<4)
{
			iVierZaehler1=0;
			if(iVierZaehler2<=3){
			iVierZaehler2++;
			}
			else{
			iVierZaehler2=0;
				iWin=1;
				//cout<<"SP1 ulnor 8.10 gewinnt:"<<iVierZaehler1<<endl;
				return iWin;
			}
			//cout<<"SP2 ulnor 8.10:"<<iVierZaehler2<<endl;
}
if (iFeld[iZeilen][iSpalten]==2 && iVierZaehler2==4)
{	
				iVierZaehler1=0;
				iWin=2;
				//cout<<"SP2 ulnor 8.10 gewinnt:"<<iVierZaehler2<<endl;
				return iWin;
		
}//end if
}// end for iZeile = ...
}//end for AnzDurchlauefe

	return 0;
}   // end int
//Überprüfung  des zweiten Spielers
int iCheckWinHorSp2(int iFeld[GR_ARRAY][GR_ARRAY],int iReihe,int iSpalte,int iSpieler1,int iSpieler2)
{


int iVierZaehler=0;
int m=0;
int n=0;
int iWin=0;
// horizontal überprüfen. Von unten nach oben für Spieler 1

for (m=GR_ARRAY;m>1;m--){ //Vorschlaufe zählt die Zeilen von unten nach oben
	iVierZaehler=0;
	for (n=1;n<GR_ARRAY;n++){ // Zaehlt die Spalten von links nach rechts
		if (iFeld[m][n]==2 && iVierZaehler<4)
{
			iVierZaehler++;
			
}
if (iFeld[m][n]==2 && iVierZaehler==4)
{	
			iWin=2;
				return iWin;
}			
if(iFeld[m][n]==1)
{
		iVierZaehler=0;
}// end if
		
if(iFeld[m][n]==0)
		{
		iVierZaehler=0;
		

 
}//end if

		}
	
}// end for
iVierZaehler=0;
return 0;

		



}   // end int


int iCheckWinVerSp2(int iFeld[GR_ARRAY][GR_ARRAY],int iReihe,int iSpalte,int iSpieler1,int iSpieler2)
{


int iVierZaehler=0;
int m=0;
int n=0;
int iWin=0;
// horizontal überprüfen. Von unten nach oben für Spieler 1

for (n=1;n<GR_ARRAY;n++){ //Vorschlaufe zählt die Spalten von unten nach oben
	iVierZaehler=0;
	for (m=GR_ARRAY;m>1;m--){ // Zaehlt die Reihen von links nach rechts
		if (iFeld[m][n]==2 && iVierZaehler<4)
{
			iVierZaehler++;
			
}
if (iFeld[m][n]==2 && iVierZaehler==4)
{	
			iWin=2;
				return iWin;
}			
if(iFeld[m][n]==1)
{
		iVierZaehler=0;
}// end if
		
if(iFeld[m][n]==0)
		{
		iVierZaehler=0;
		

 
}//end if

		}
	
}// end for
iVierZaehler=0;
return 0;

}   // end int


//Ausgabe des Gewinners
void vWinSp1()
{
	
	cout << Name[1]<< " hat gewonnen!" <<endl;
    menu();
	system("cls");
}// end void
void vWinSp2()
{
	cout<<red<< Name[2] << " hat gewonnen!" <<endl;
	menu();
  
}
//Copyright 
void copyright()
{
	system("Cls");
	cout<<yellow << "Dieses Spiel wurde im Ramen einer c++ Pruefung von" <<endl;
    cout << "Mulholland Kierin geschrieben." <<endl;
	cout << "15.11.09" <<endl;
	
menu();
	
}// end void

void Inhalt()
{
	system("cls");
cout<<yellow<<"Inhalt von diesem Programm"<<endl;
cout<<blue<<"************************"<<endl;
cout<<yellow<<char(26)<<"  Menu"<<endl;
cout<<blue<<char(26)<<"  Eingabe von Spielernamen"<<endl;
cout<<yellow<<char(26)<<"  Ausgabe mit Farben"<<endl;
cout<<blue<<char(26)<<"  Zufahls generator (Für den Spieler der anfängt)"<<endl;
cout<<yellow<<char(26)<<"  Checkfunktion"<<endl;
cout<<blue<<char(26)<<"  Animation der Steine"<<endl;
cout<<yellow<<char(26)<<"  "<<endl;
cout<<blue<<char(26)<<"  Automatische Spielstand speicherung"<<endl;
cout<<yellow<<char(26)<<"  Auslesen funktioniert nach dem schliessen nicht"<<endl;


menu();
}