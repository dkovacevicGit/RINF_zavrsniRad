//---------------------------------------------------------------------------

#ifndef Unit02HomeH
#define Unit02HomeH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Unit01Prijava.h>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.FileCtrl.hpp>
#include <Vcl.DockTabSet.hpp>
#include <Vcl.Tabs.hpp>
#include <System.Actions.hpp>
#include <System.ImageList.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ImgList.hpp>
#include <Vcl.ToolWin.hpp>
#include <Vcl.DBActns.hpp>
#include <Data.DB.hpp>
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
#include <Vcl.Mask.hpp>
#include <Vcl.DBCtrls.hpp>
#include <FireDAC.Phys.SQLite.hpp>
#include <FireDAC.Phys.SQLiteDef.hpp>
#include <FireDAC.Phys.SQLiteWrapper.Stat.hpp>
#include <FireDAC.Stan.ExprFuncs.hpp>
#include <string>
#include <DateUtils.hpp>
//---------------------------------------------------------------------------
class TFormHome : public TForm
{
__published:	// IDE-managed Components
	TPanel *PanelIzbornik;
	TStatusBar *StatusBar1;
	TPanel *PanelInfo;
	TButton *ButtonHome;
	TButton *ButtonRacuni;
	TButton *ButtonChooseLang;
	TButton *ButtonIzvjestaji;
	TButton *ButtonTecajna;
	TButton *ButtonPostavke;
	TPageControl *PageControl1;
	TDBEdit *DBEditFooter;
	TListBox *ListBox1;
	TButton *ButtonExit;

	void __fastcall ButtonHomeClick(TObject *Sender);
	void __fastcall ButtonRacuniClick(TObject *Sender);
	void __fastcall ButtonChooseLangClick(TObject *Sender);
	void __fastcall ButtonIzvjestajiClick(TObject *Sender);
	void __fastcall ButtonTecajnaClick(TObject *Sender);
	void __fastcall ButtonPostavkeClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ButtonExitClick(TObject *Sender);

private:	// User declarations
		void __fastcall PrikaziFormu(TForm* Form); // Deklaracije metode za prikaz formi

public:		// User declarations
	__fastcall TFormHome(TComponent* Owner);
};
//---------------------------------------------------------------------------

extern AnsiString _prijavljeniKorisnik; // Definicija globalne varijable
extern bool _darkModeEnabled; // Definicija globalne varijable

//---------------------------------------------------------------------------

class Licenciranje {
private:
	TRegistry *registry; //Pokazivaè na adresu objekta u memoriji
public:
	UnicodeString nazivLicence = "Trial";
	Licenciranje() {    //Konstruktor klase
		registry = new TRegistry();
		registry->RootKey = HKEY_CURRENT_USER;
		UnicodeString appkey = "Software\\CashFlow";
	}
	void SpremiDatumUnosaKljuca(TDateTime datum) {
		if (registry->OpenKey("Software\\CashFlow", true)) {
			registry->WriteString("Naziv licence", nazivLicence);
			registry->WriteDateTime("DatumUnosaKljuca", datum);
			registry->CloseKey();
		}
		delete registry;
	}
    TDateTime ProcitajDatumUnosaKljuca() {
		TDateTime datum = 0;
		if (registry->OpenKeyReadOnly("Software\\CashFlow")) {
			datum = registry->ReadDateTime("DatumUnosaKljuca");
			registry->CloseKey();
		}
		return datum;
		delete registry;
	}
	void ProvjeriIstekLicence() {  //ToDo - dodati nekakvu provjeru kljuèa
        TDateTime datumUnosaKljuca = ProcitajDatumUnosaKljuca();
		if (datumUnosaKljuca == TDateTime(0)) {
			ShowMessage("Aktivirajte licencu u postavkama aplikacije");
			//Application->Terminate();
			//return;
		}
		TDateTime datumIsteka = datumUnosaKljuca + 60; // Datum isteka je 60 dana od datuma unosa kljuèa
		TDateTime danas = Date();
		int preostaloDana = datumIsteka - danas;
		if (preostaloDana <= 0) {
			ShowMessage("Licenca je istekla.");
			//Application->Terminate();
			//return;
		} else {
		ShowMessage("Preostalo je još " + IntToStr(preostaloDana) + " dana do isteka licence.");
        }
	}
};

//---------------------------------------------------------------------------
extern PACKAGE TFormHome *FormHome;
//---------------------------------------------------------------------------
#endif
