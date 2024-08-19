#include <vcl.h>
#pragma hdrstop

#include "GlobalConnection.h"

// Definišite globalni pokazivaè
TFDConnection *GlobalFDConnection = nullptr;

// Funkcija za inicijalizaciju konekcije
void InitializeGlobalConnection() {
    try {
        if (GlobalFDConnection == NULL) {
            GlobalFDConnection = new TFDConnection(NULL);
            GlobalFDConnection->DriverName = "SQLite"; // Postavite parametre konekcije
			//GlobalFDConnection->Params->Values["Database"] = "cashflowdb_lite.sdb";
			GlobalFDConnection->Params->Values["Database"] = ExtractFilePath(Application->ExeName) + "cashflowdb_lite.sdb";
			GlobalFDConnection->Params->Values["User_Name"] = "";
            GlobalFDConnection->Params->Values["Password"] = "";
            GlobalFDConnection->Params->Values["CharacterSet"] = "utf8";
            GlobalFDConnection->Params->Values["LockingMode"] = "Normal";
            GlobalFDConnection->Connected = true; // Otvaranje konekcije
        }
    } catch (Exception &E) {
		ShowMessage("Greška prilikom povezivanja sa bazom podataka: " + E.Message);
	}
}

// Funkcija za èišæenje konekcije
void FinalizeGlobalConnection() {
    if (GlobalFDConnection != NULL) {
        GlobalFDConnection->Connected = false; // Zatvaranje konekcije
        delete GlobalFDConnection; // Oslobaðanje memorije
        GlobalFDConnection = NULL;
	}
}

