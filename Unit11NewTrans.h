//---------------------------------------------------------------------------

#ifndef Unit11NewTransH
#define Unit11NewTransH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Comp.DataSet.hpp>
#include <FireDAC.DApt.hpp>
#include <FireDAC.DApt.Intf.hpp>
#include <FireDAC.DatS.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Param.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <FireDAC.Phys.hpp>
#include <FireDAC.Stan.Def.hpp>
#include <FireDAC.UI.Intf.hpp>
#include <Vcl.ComCtrls.hpp>
#include <FireDAC.Phys.MySQL.hpp>
#include <FireDAC.Phys.MySQLDef.hpp>
#include <FireDAC.Stan.Pool.hpp>
#include <FireDAC.VCLUI.Wait.hpp>
//---------------------------------------------------------------------------
class TFormNewTrans : public TForm
{
__published:	// IDE-managed Components
	TDataSource *DataSourceKlijent;
	TFDQuery *FDQueryKlijent;
	TDBLookupComboBox *DBLookupKlijent;
	TDateTimePicker *DateTimePicker1;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TGroupBox *GroupBox1;
	TRadioButton *RadioButtonPlacanje;
	TRadioButton *RadioButtonUplata;
	TEdit *EditTransIznos;
	TMemo *Memo1;
	TButton *ButtonTransSpremi;
	TButton *ButtonTransOdbaci;
	TDBLookupComboBox *DBLookupAcc;
	TStringField *FDQueryKlijentNaziv;
	void __fastcall ButtonTransOdbaciClick(TObject *Sender);
	void __fastcall ButtonTransSpremiClick(TObject *Sender);
	void __fastcall RadioButtonUplataClick(TObject *Sender);
	void __fastcall RadioButtonPlacanjeClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TFormNewTrans(TComponent* Owner);
};

extern AnsiString _prijavljeniKorisnik; // Definicija globalne varijable
extern TFDConnection *GlobalFDConnection;
//---------------------------------------------------------------------------

class NewTransaction {
public:
	String datum;
	String racun="";
	String primatelj="";
	double iznosUplate;
	double iznosPlacanja;
	String opis;
	String username=_prijavljeniKorisnik;


	//TFDConnection *dbkonekcija; // Èlan klase za povezivanje na bazu podataka

	// Konstruktor klase koji postavlja inicijalne vrijednosti èlanova klase
	NewTransaction(String datum, String racun, String primatelj, double iznosUplate, double iznosPlacanja, String opis, String username) :
			datum(datum), racun(racun), primatelj(primatelj), iznosUplate(iznosUplate), iznosPlacanja(iznosPlacanja), opis(opis), username(username) {}

	// Metoda za upis transakcije u bazu
	void spremiTransakciju(String datum, String racun, String primatelj, double iznosUplate, double iznosPlacanja, String opis, String username) {
		TFDQuery *query = new TFDQuery(NULL);
		query->Connection = GlobalFDConnection;
		query->SQL->Text = "INSERT INTO transakcija (Datum, UplataIznos, PlacanjeIznos, TereceniRacun, KlijentIme, Opis, Username)"
							"VALUES (:datum, :iznosUplate, :iznosPlacanja, :racun, :primatelj, :opis, :username)";
		query->ParamByName("datum")->AsDate = datum;
		query->ParamByName("iznosUplate")->AsFloat = iznosUplate;   // Koristimo AsFloat za double vrijednost
		query->ParamByName("iznosPlacanja")->AsFloat = iznosPlacanja;
		query->ParamByName("racun")->AsString = racun;
		query->ParamByName("primatelj")->AsString = primatelj;
		query->ParamByName("opis")->AsString = opis;
		query->ParamByName("username")->AsString = username;

		try {
			query->ExecSQL();
		} catch (Exception &e) {
			ShowMessage("Greška kod unosa transakcije: " + e.Message);
		}

		delete query;
	}
};


//---------------------------------------------------------------------------

extern PACKAGE TFormNewTrans *FormNewTrans;
//---------------------------------------------------------------------------
#endif
