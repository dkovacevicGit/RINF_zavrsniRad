//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "GlobalConnection.h"

#include "Unit04Racuni.h"
#include "Unit02Home.h"
#include <jpeg.hpp>
#include <pngimage.hpp>
#include "Unit01Prijava.h"
#include "Unit10NewAccount.h"
#include "Unit11NewTrans.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormRacuni *FormRacuni;
//---------------------------------------------------------------------------

void __fastcall TFormRacuni::FormCreate(TObject *Sender)
{
	// Postavljanje vrijednosti parametra upita iz varijable _prijavljeniKorisnik
	FDQueryRacuni->Connection = GlobalFDConnection;
	FDQueryRacuni->ParamByName("username")->AsString = _prijavljeniKorisnik;
	FDQueryRacuni->Active = true;
	//FDQueryRacuni->Open();
	//FDQueryRacuni->Refresh();

	FDQueryCalculated->Connection = GlobalFDConnection;
	FDQueryCalculated->ParamByName("username")->AsString = _prijavljeniKorisnik;
	FDQueryCalculated->Active = true;
	//FDQueryCalculated->Open();
	//FDQueryCalculated->Refresh();

	FDQueryTrans->Connection = GlobalFDConnection;
	FDQueryTrans->Active = true;
	//FDQueryTrans->Open();
	//FDQueryTrans->Refresh();

}

//---------------------------------------------------------------------------

__fastcall TFormRacuni::TFormRacuni(TComponent* Owner)
	: TForm(Owner)
{
	DBImage1->DoubleBuffered = true; // Sprema prvo u memoriju pa onda iscrtava
}
//---------------------------------------------------------------------------


void __fastcall TFormRacuni::ButtonObrisiSlikuClick(TObject *Sender)
{
		FDQueryRacuni->Edit();
		FDQueryRacuni->FieldByName("Image")->Clear();
		FDQueryRacuni->Post();
}
//---------------------------------------------------------------------------

void __fastcall TFormRacuni::ButtonNewAccClick(TObject *Sender)
{
	//FormHome->FDConnectionX = new TFDConnection(this);
	// Dinamièko kreiranje dijaloga FormNewAcc
	//TFormNewAccount *newAccountForm = new TFormNewAccount(this);
	FormNewAccount->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFormRacuni::ButtonLoadCardClick(TObject *Sender)
{
	// static_cast - Converts between types using a combination of implicit and user-defined conversions
	// A Cast operator is a operator which forces one data type to be converted into another data type.
	//
	// C++ supports 4 types of casting:
	//
	// Static Cast
	// Dynamic Cast
	// Const Cast
	// Reinterpret Cast
	//
	//Static Cast
	//This is the simplest type of cast that can be used.
	//It is a compile-time cast.
	//It does things like implicit conversions between
	//types (such as int to float, or pointer to void*),
	//and it can also call explicit conversion functions.

	if(OpenDialog1->Execute()){
		FDQueryRacuni->Edit();
		FDQueryRacuni->FieldByName("Image")->Clear();
		static_cast<TBlobField*>(FDQueryRacuni->FieldByName("Image"))->LoadFromFile(OpenDialog1->FileName);
		FDQueryRacuni->Post();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormRacuni::ButtonNewTransClick(TObject *Sender)
{
	//FormHome->FDConnectionX = new TFDConnection(this);
	// Dinamièko kreiranje instance FormNewTrans
	//TFormNewTrans *newTransForm = new TFormNewTrans(this);
	FormNewTrans->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFormRacuni::FDQueryCalculatedCalcFields(TDataSet *DataSet)
{
	UnicodeString ime = DataSet->FieldByName("Ime")->AsString;
	UnicodeString prezime = DataSet->FieldByName("Prezime")->AsString;
	UnicodeString email = DataSet->FieldByName("Email")->AsString;
	UnicodeString user = DataSet->FieldByName("UserName")->AsString;

	// Spajanje vrijednosti u jedan string
	UnicodeString slozeniString = "Prijavljeni korisnik : "+ ime + " " + prezime + "        email : " + email + "        username : " + user;
	// Postavljanje vrijednosti u izraèunato polje
	DataSet->FieldByName("Calculated")->AsString = slozeniString;
}
//---------------------------------------------------------------------------

void __fastcall TFormRacuni::ButtonLoadBCodeClick(TObject *Sender)
{
	if(OpenDialog1->Execute()){
		FDQueryTrans->Edit();
		FDQueryTrans->FieldByName("Trans3Dcode")->Clear();
		static_cast<TBlobField*>(FDQueryTrans->FieldByName("Trans3Dcode"))->LoadFromFile(OpenDialog1->FileName);
		FDQueryTrans->Post();
	}

}
//---------------------------------------------------------------------------

void __fastcall TFormRacuni::ButtonObrisiBCodeClick(TObject *Sender)
{
	FDQueryTrans->Edit();
	FDQueryTrans->FieldByName("Trans3Dcode")->Clear();
	FDQueryTrans->Post();
}
//---------------------------------------------------------------------------

void __fastcall TFormRacuni::Button1Click(TObject *Sender)
{
	FDQueryRacuni->Refresh();
}
//---------------------------------------------------------------------------

void __fastcall TFormRacuni::FormActivate(TObject *Sender)
{
	FDQueryRacuni->Refresh();
	FDQueryTrans->Refresh();
    FDQueryTrans->First();
}
//---------------------------------------------------------------------------

void __fastcall TFormRacuni::DBGrid1TitleClick(TColumn *Column)
{
    // Dohvaæanje naziva polja na koje je korisnik kliknuo
    String fieldName = Column->FieldName;
    // Provjera trenutnog sortiranja - silazno ili uzlazno
	static bool sortAscending = true; // Varijabla koja prati redoslijed sortiranja
    String sortOrder = sortAscending ? "ASC" : "DESC";
    sortAscending = !sortAscending; // Prebacivanje reda nakon svakog klika
    // Postavljanje novog SQL upita s ORDER BY klauzulom
    FDQueryRacuni->Close();
	FDQueryRacuni->SQL->Text = "SELECT * FROM racun WHERE username = :username ORDER BY " + fieldName + " " + sortOrder;
    FDQueryRacuni->Open();
}
//---------------------------------------------------------------------------

void __fastcall TFormRacuni::DBGridTransTitleClick(TColumn *Column)
{
	// Dohvaæanje naziva polja na koje je korisnik kliknuo
	String fieldName = Column->FieldName;
	// Provjera trenutnog sortiranja - silazno ili uzlazno
	static bool sortAscending = true; // Varijabla koja prati redoslijed sortiranja
	String sortOrder = sortAscending ? "ASC" : "DESC";
	sortAscending = !sortAscending; // Prebacivanje reda nakon svakog klika
	// Postavljanje novog SQL upita s ORDER BY klauzulom
	FDQueryTrans->Close();
	FDQueryTrans->SQL->Text = "SELECT * FROM transakcija ORDER BY " + fieldName + " " + sortOrder;
	FDQueryTrans->Open();
}
//---------------------------------------------------------------------------

