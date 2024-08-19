#include <vcl.h>
#pragma hdrstop

#include "Unit11NewTrans.h"
#include "Unit04Racuni.h"
#include "Unit02Home.h"
#include "GlobalConnection.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormNewTrans *FormNewTrans;
//---------------------------------------------------------------------------
__fastcall TFormNewTrans::TFormNewTrans(TComponent* Owner)
    : TForm(Owner)
{
	FDQueryKlijent->Connection = GlobalFDConnection;
	FDQueryKlijent->Active = true;
	FDQueryKlijent->Open();
	FDQueryKlijent->Refresh();
}
//---------------------------------------------------------------------------

void __fastcall TFormNewTrans::ButtonTransOdbaciClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormNewTrans::ButtonTransSpremiClick(TObject *Sender)
{
	// Preuzimanje vrijednosti iz polja za unos
    TDateTime datum = DateTimePicker1->Date;
    String racun = DBLookupAcc->Text;
    String primatelj = DBLookupKlijent->Text;
    double iznos = StrToFloat(EditTransIznos->Text);
    EditTransIznos->Text = FormatFloat("0.00", iznos);
    double iznosPlacanja;
    double iznosUplate;
    String opis = Memo1->Text;
    String tipTransakcije = RadioButtonPlacanje->Checked ? "isplata" : "uplata";
    String username = _prijavljeniKorisnik;

    // Provjera da li je polje iznos prazno
    if (EditTransIznos->Text.IsEmpty()) {
        ShowMessage("Molimo unesite iznos transakcije.");
        return;
    }

    // Provjera radi li se o uplati ili isplati sa raèuna
    if (RadioButtonPlacanje->Checked) {
        iznosPlacanja = iznos;
        iznosUplate = 0.0;
    } else {
        iznosPlacanja = 0.0;
        iznosUplate = iznos;
    }

    // Kreiranje objekta NewTransaction
	NewTransaction newTransaction(datum, racun, primatelj, iznosUplate, iznosPlacanja, opis, username);

    // Upis nove transakcije u bazu podataka
	newTransaction.spremiTransakciju(datum, racun, primatelj, iznosUplate, iznosPlacanja, opis, username);

    // Ažuriranje salda raèuna
    TFDQuery *query = new TFDQuery(NULL);
	query->Connection = GlobalFDConnection;

    if (tipTransakcije == "isplata") {
		query->SQL->Text = "UPDATE racun SET StanjeRac = StanjeRac - :iznos WHERE RacNaziv= :racun AND Username = :username";
	} else {
		query->SQL->Text = "UPDATE racun SET StanjeRac = StanjeRac + :iznos WHERE RacNaziv  = :racun AND Username = :username";
	}

    query->ParamByName("iznos")->AsFloat = iznos;
    query->ParamByName("racun")->AsString = racun;
    query->ParamByName("username")->AsString = username;

	try {
        query->ExecSQL();
		//ShowMessage("Saldo raèuna uspješno ažuriran");
    } catch (Exception &e) {
        ShowMessage("Greška kod ažuriranja salda: " + e.Message);
    }

    delete query;

	// Osvježavanje podataka u DBGrid
//	FormRacuni->FDQueryRacuni->Close();
//	FormRacuni->FDQueryRacuni->Open();
//	FormRacuni->FDQueryTrans->Close();
//	FormRacuni->FDQueryTrans->Open();
//	FormRacuni->FDQueryTrans->First();

    ShowMessage("Nova transakcija uspješno dodana");
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormNewTrans::RadioButtonUplataClick(TObject *Sender)
{
    DBLookupKlijent->Enabled = False;
    DBLookupKlijent->KeyValue = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TFormNewTrans::RadioButtonPlacanjeClick(TObject *Sender)
{
    DBLookupKlijent->Enabled = True;
}
//---------------------------------------------------------------------------

void __fastcall TFormNewTrans::FormCreate(TObject *Sender)
{
	DateTimePicker1->Date = Now();
}
//---------------------------------------------------------------------------


