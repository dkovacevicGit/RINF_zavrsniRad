//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "GlobalConnection.h"

#include "Unit10NewAccount.h"
#include "Unit04Racuni.h"
#include "Unit02Home.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormNewAccount *FormNewAccount;
//---------------------------------------------------------------------------
__fastcall TFormNewAccount::TFormNewAccount(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFormNewAccount::ButtonNewAccCancelClick(TObject *Sender)
{
	EditNewAccName->Text = "";
	EditNewAccNumber->Text = "";
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormNewAccount::ButtonNewAccCreateClick(TObject *Sender)
{

	// Preuzimanje vrijednosti iz polja za unos
	String nazivRacuna = EditNewAccName->Text;
	String brojRacuna = EditNewAccNumber->Text;
	double pocetnoStanje = 0.00;
	double stanjeRac = 0.00;

	String username = _prijavljeniKorisnik;

	// Provjera da li su sva polja popunjena
	if (nazivRacuna.IsEmpty() || brojRacuna.IsEmpty()) {
		ShowMessage("Molimo ispunite sva polja.");
        return;
	}

	// Kreiranje objekta NewAccount
	NewAccount newAccount(nazivRacuna, brojRacuna, pocetnoStanje, stanjeRac, username);

	// Provjera postoji li ve� ra�un s tim brojem
	if (newAccount.TraziRacun()) {
		ShowMessage("Ra�un s tim brojem ve� postoji");
	} else {
		// Upis novog ra�una u bazu podataka
		newAccount.KreirajAccount(nazivRacuna, brojRacuna, pocetnoStanje, stanjeRac, username);
		ShowMessage("Novi ra�un uspje�no dodan");
		EditNewAccName->Text = "";
		EditNewAccNumber->Text = "";
		Close(); // Zatvaranje forme nakon uspje�nog unosa
	}
}
//---------------------------------------------------------------------------

