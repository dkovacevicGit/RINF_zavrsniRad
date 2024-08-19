//---------------------------------------------------------------------------

#ifndef Unit01PrijavaH
#define Unit01PrijavaH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.jpeg.hpp>
#include <Vcl.Imaging.pngimage.hpp>
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
#include <FireDAC.Comp.DataSet.hpp>
#include <FireDAC.DApt.hpp>
#include <FireDAC.DApt.Intf.hpp>
#include <FireDAC.DatS.hpp>
#include <FireDAC.Stan.Param.hpp>
#include "Unit09NewUser.h"
#include "Unit12Language.h"
#include "Unit02Home.h"
#include "GlobalConnection.h"
#include "Unit13Help.h"

//---------------------------------------------------------------------------
class TFormPrijava : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupBox1;
	TLabel *Label1;
	TLabel *Label2;
	TEdit *EditUsername;
	TEdit *EditPassword;
	TButton *BtnPrijava;
	TButton *BtnNewUser;
	TButton *ButtonAbout;
	TButton *ButtonHelp;
	TButton *BtnZatvori;
	TImage *Image1;
	TImage *Image2;

	void __fastcall BtnZatvoriClick(TObject *Sender);
	void __fastcall BtnPrijavaClick(TObject *Sender);
	void __fastcall BtnNewUserClick(TObject *Sender);
	void __fastcall EditUsernameKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall EditPasswordKeyPress(TObject *Sender, System::WideChar &Key);

	void __fastcall ButtonHelpClick(TObject *Sender);
	void __fastcall ButtonAboutClick(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TFormPrijava(TComponent* Owner);
};

 //---------------------------------------------------------------------------

class UserLogin {
public:
	String username="";
	String password="";
	//TFDConnection *dbkonekcija; // Èlan klase za povezivanje na bazu podataka

	// Konstruktor klase koji postavlja inicijalne vrijednosti èlanova klase
	//UserLogin(TFDConnection *dbKonekcija, String username, String password) : dbkonekcija(dbKonekcija), username(username), password(password) {}
	UserLogin(String username, String password) : username(username), password(password) {}

	// Metoda za traženje korisnika u bazi podataka
	bool TrazenjeKorisnika() {
		TFDQuery *query = new TFDQuery(NULL); // Stvaranje objekta upita
		query->Connection = GlobalFDConnection; // Postavljanje veze na objekt upita
		//query->Connection = FormHome->FDConnectionX; // Postavljanje veze na objekt upita
		query->SQL->Text = "SELECT * FROM korisnik k1 WHERE k1.Username = :username AND k1.Password = :password"; // Postavljanje SQL upita
		query->ParamByName("username")->AsString = username;
		query->ParamByName("password")->AsString = password;
		query->Open(); // Izvršavanje upita

		bool userFound = !query->Eof; // Provjera je li korisnik pronaðen
		query->Close();
		delete query; // Oslobaðanje memorije rezervirane za objekt upita
		return userFound; // Vraæanje rezultata pretrage korisnika
	}
};

//---------------------------------------------------------------------------
extern PACKAGE TFormPrijava *FormPrijava;
//---------------------------------------------------------------------------
#endif
