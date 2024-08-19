//---------------------------------------------------------------------------

#ifndef Unit10NewAccountH
#define Unit10NewAccountH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.Dialogs.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Phys.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Phys.MySQL.hpp>
#include <FireDAC.Phys.MySQLDef.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Def.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Pool.hpp>
#include <FireDAC.UI.Intf.hpp>
#include <FireDAC.VCLUI.Wait.hpp>
#include <Data.DB.hpp>
#include "Unit04Racuni.h"

//---------------------------------------------------------------------------
class TFormNewAccount : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TEdit *EditNewAccName;
	TEdit *EditNewAccNumber;
	TButton *ButtonNewAccCreate;
	TButton *ButtonNewAccCancel;
	void __fastcall ButtonNewAccCancelClick(TObject *Sender);
	void __fastcall ButtonNewAccCreateClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormNewAccount(TComponent* Owner);
};

extern AnsiString _prijavljeniKorisnik; // Definicija globalne varijable
extern TFDConnection *GlobalFDConnection;
//---------------------------------------------------------------------------

class NewAccount {
public:
	String nazivRacuna="";
	String brojRacuna="";
	double pocetnoStanje;
	double stanjeRac;
	String username=_prijavljeniKorisnik;

	//TFDConnection *dbkonekcija; // Èlan klase za povezivanje na bazu podataka

	// Konstruktor klase koji postavlja inicijalne vrijednosti èlanova klase
	NewAccount(String nazivRacuna, String brojRacuna, double pocetnoStanje, double stanjeRac, String username) :
			nazivRacuna(nazivRacuna), brojRacuna(brojRacuna), pocetnoStanje(pocetnoStanje), stanjeRac(stanjeRac), username(username) {}

	// Metoda za traženje korisnika u bazi podataka
	bool TraziRacun() {
		TFDQuery *query = new TFDQuery(NULL); // Stvaranje objekta upita
		query->Connection = GlobalFDConnection; // Postavljanje veze na objekt upita
		query->SQL->Text = "SELECT * FROM racun r1 WHERE r1.BrojRacuna = :brojRacuna";
		query->ParamByName("brojRacuna")->AsString = brojRacuna;
		query->Open();

		bool accountFound = !query->Eof; // Provjera je li racun pronaðen
		query->Close();
		delete query; // Oslobaðanje memorije rezervirane za objekt upita
		return accountFound; // Vraæanje rezultata pretrage korisnika
	}

	// Metoda za upis raèuna u bazu
	void KreirajAccount(String nazivRacuna, String brojRacuna, double pocetnoStanje, double stanjeRac, String username) {
		TFDQuery *query = new TFDQuery(NULL);
		query->Connection = GlobalFDConnection;
		query->SQL->Text = "INSERT INTO racun (RacNaziv, BrojRacuna, PocetnoStanje, StanjeRac, Username) VALUES (:nazivRacuna, :brojRacuna, :pocetnoStanje, :stanjeRac, :username)";
		query->ParamByName("nazivRacuna")->AsString = nazivRacuna;
		query->ParamByName("brojRacuna")->AsString = brojRacuna;
		query->ParamByName("pocetnoStanje")->AsFloat = pocetnoStanje; // Koristimo AsFloat za double vrijednost
		query->ParamByName("stanjeRac")->AsFloat = stanjeRac;
		query->ParamByName("username")->AsString = username;

		try {
			query->ExecSQL();

		} catch (Exception &e) {
			ShowMessage("Greška kod unosa novog raèuna: " + e.Message);
		}

		delete query;
	}
};
//---------------------------------------------------------------------------
extern PACKAGE TFormNewAccount *FormNewAccount;
//---------------------------------------------------------------------------
#endif
