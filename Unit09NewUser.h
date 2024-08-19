//---------------------------------------------------------------------------

#ifndef Unit09NewUserH
#define Unit09NewUserH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
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
//---------------------------------------------------------------------------
class TFormNewUser : public TForm
{
__published:	// IDE-managed Components
	TEdit *EditNewName;
	TEdit *EditNewSecName;
	TEdit *EditNewEmail;
	TEdit *EditNewCity;
	TEdit *EditNewUsername;
	TEdit *EditNewPass;
	TEdit *EditNewPassConfirm;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TButton *ButtonNewUserCreate;
	TButton *ButtonNewUserCancel;
	void __fastcall ButtonNewUserCancelClick(TObject *Sender);
	void __fastcall ButtonNewUserCreateClick(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TFormNewUser(TComponent* Owner);
};

extern TFDConnection *GlobalFDConnection;
//---------------------------------------------------------------------------

class NewUser {
public:
	String ime="";
	String prezime="";
	String email="";
	String city="";
	String username="";
	String password="";
	String passwordConfirm="";
	//TFDConnection *dbkonekcija; // Èlan klase za povezivanje na bazu podataka

	// Konstruktor klase koji postavlja inicijalne vrijednosti èlanova klase
	// NewUser(TFDConnection *dbKonekcija, String username) : dbkonekcija(dbKonekcija), username(username) {} - ne koristi se
	NewUser(String ime, String prezime, String email, String city, String username, String password, String passwordConfirm ) :
			ime(ime), prezime(prezime), email(email), city(city), username(username), password(password), passwordConfirm(passwordConfirm) {}

	// Metoda za traženje korisnika u bazi podataka
	bool TraziUsername() {
		TFDQuery *query = new TFDQuery(NULL); // Stvaranje objekta upita
		query->Connection = GlobalFDConnection; // Postavljanje veze na objekt upita
		query->SQL->Text = "SELECT * FROM korisnik k1 WHERE k1.Username = :username"; // Postavljanje SQL upita
		query->ParamByName("username")->AsString = username;
		query->Open(); // Izvršavanje upita

		bool userFound = !query->Eof; // Provjera je li korisnik pronaðen
		query->Close();
		delete query; // Oslobaðanje memorije rezervirane za objekt upita
		return userFound; // Vraæanje rezultata pretrage korisnika
	}

	// Metoda za upis korisnika u bazu
	void UpisiKorisnika(String ime, String prezime, String email, String city, String username, String password) {
		TFDQuery *query = new TFDQuery(NULL);
		query->Connection = GlobalFDConnection;
		query->SQL->Text = "INSERT INTO korisnik (ime, prezime, email, city, username, password) VALUES (:ime, :prezime, :email, :city, :username, :password)";
		query->ParamByName("ime")->AsString = ime;
		query->ParamByName("prezime")->AsString = prezime;
		query->ParamByName("email")->AsString = email;
		query->ParamByName("city")->AsString = city;
		query->ParamByName("username")->AsString = username;
		query->ParamByName("password")->AsString = password;

		try {
			query->ExecSQL();
		} catch (Exception &e) {
			ShowMessage("Greška kod unosa novog korisnika: " + e.Message);
		}

		delete query;
	}
};
//---------------------------------------------------------------------------
extern PACKAGE TFormNewUser *FormNewUser;
//---------------------------------------------------------------------------
#endif
