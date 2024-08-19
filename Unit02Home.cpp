//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "GlobalConnection.h"

#include "Unit01Prijava.h"
#include "Unit02Home.h"
#include "Unit03Pregled.h"
#include "Unit04Racuni.h"
#include "Unit05Plan.h"
#include "Unit06Izvjestaji.h"
#include "Unit07Tecaj.h"
#include "Unit08Postavke.h"
#include <registry.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormHome *FormHome;
//---------------------------------------------------------------------------
__fastcall TFormHome::TFormHome(TComponent* Owner)
    : TForm(Owner)
{
	//ShowMessage(_prijavljeniKorisnik);

    TFormPregled *FormPregled = new TFormPregled(this);
    FormPregled->Parent = PageControl1;
	FormPregled->Align = alClient;
	FormPregled->BorderStyle = bsNone;
	FormPregled->Visible = false;

    TFormRacuni *FormRacuni = new TFormRacuni(this);
    FormRacuni->Parent = PageControl1;
    FormRacuni->Align = alClient;
    FormRacuni->BorderStyle = bsNone;
	FormRacuni->Visible = true; //Odreðuje koja je forma prva vidljiva

    TFormPlan *FormPlan = new TFormPlan(this);
    FormPlan->Parent = PageControl1;
    FormPlan->Align = alClient;
    FormPlan->BorderStyle = bsNone;
    FormPlan->Visible = false;

    TFormIzvjestaji *FormIzvjestaji = new TFormIzvjestaji(this);
    FormIzvjestaji->Parent = PageControl1;
    FormIzvjestaji->Align = alClient;
    FormIzvjestaji->BorderStyle = bsNone;
    FormIzvjestaji->Visible = false;

    TFormTecaj *FormTecaj = new TFormTecaj(this);
    FormTecaj->Parent = PageControl1;
    FormTecaj->Align = alClient;
    FormTecaj->BorderStyle = bsNone;
    FormTecaj->Visible = false;

    TFormPostavke *FormPostavke = new TFormPostavke(this);
    FormPostavke->Parent = PageControl1;
    FormPostavke->Align = alClient;
    FormPostavke->BorderStyle = bsNone;
	FormPostavke->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TFormHome::PrikaziFormu(TForm* Form) // Definicija metode za prikaz formi
{
	// Postavljanje parametara za prikaz
    Form->Parent = PageControl1;
	Form->Align = alClient;
    Form->BorderStyle = bsNone;
    Form->Visible = true;
    Form->BringToFront();
}
//---------------------------------------------------------------------------

void __fastcall TFormHome::ButtonChooseLangClick(TObject *Sender)
{
	FormLanguage->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TFormHome::ButtonHomeClick(TObject *Sender)
{
	PrikaziFormu(FormPregled);
	FormRacuni->FDQueryRacuni->Open();
	FormRacuni->FDQueryRacuni->Refresh(); //Osvježavanje radi korištenja u DBChart
    FormPregled->DBChart1->RefreshData();
}
//---------------------------------------------------------------------------

void __fastcall TFormHome::ButtonRacuniClick(TObject *Sender)
{
	PrikaziFormu(FormRacuni);
}
//---------------------------------------------------------------------------

void __fastcall TFormHome::ButtonIzvjestajiClick(TObject *Sender)
{
	PrikaziFormu(FormIzvjestaji);
}
//---------------------------------------------------------------------------

void __fastcall TFormHome::ButtonTecajnaClick(TObject *Sender)
{
	PrikaziFormu(FormTecaj);
}
//---------------------------------------------------------------------------

void __fastcall TFormHome::ButtonPostavkeClick(TObject *Sender)
{
	PrikaziFormu(FormPostavke);
}

//---------------------------------------------------------------------------

void __fastcall TFormHome::ButtonExitClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormHome::FormClose(TObject *Sender, TCloseAction &Action)
{
	String ime = FormRacuni->FDQueryCalculated->FieldByName("Ime")->AsString;
	String prezime = FormRacuni->FDQueryCalculated->FieldByName("Prezime")->AsString;
	String email = FormRacuni->FDQueryCalculated->FieldByName("Email")->AsString;
	String user = FormRacuni->FDQueryCalculated->FieldByName("UserName")->AsString;
	String currentDateTime = DateTimeToStr(Now());
	bool darkMode = _darkModeEnabled;

	TIniFile* ini = new TIniFile(GetCurrentDir() + "\\Postavke.ini");
	ini->WriteString("LASTLOGED", "Name", ime);
	ini->WriteString("LASTLOGED", "SecondName", prezime);
	ini->WriteString("LASTLOGED", "Email", email);
	ini->WriteString("LASTLOGED", "Username", user);
	ini->WriteString("LASTLOGED", "LastLoginDateTime", currentDateTime);
	delete ini;

	TRegistry* winreg = new TRegistry;
	winreg->RootKey = HKEY_CURRENT_USER;  //HKEY_CURRENT_USER\SOFTWARE\CashFlow
	UnicodeString appkey = "Software\\CashFlow";

	winreg->CreateKey(appkey);
	if(winreg->OpenKey(appkey, true)){
		winreg->WriteInteger("WindowState", (int)WindowState);
			// WindowState je tip TWindowState, koji predstavlja stanje prozora.
			// Ako želimo saèuvati WindowState u registry ili ini datoteku,
			// moramo ga prvo konvertirati u string ili integer vrijednost.
			// Isto tako kod uèitavanja treba ga konvertirati natrag u TWindowState.
		winreg->WriteBool("DarkMode", darkMode);
		winreg->CloseKey();
	}
	delete winreg;
}

//---------------------------------------------------------------------------

void __fastcall TFormHome::FormCreate(TObject *Sender)
{
	// Èitanje vrijednosti iz INI datoteke
	TIniFile* ini = new TIniFile(GetCurrentDir() + "\\Postavke.ini");
	String ime = ini->ReadString("LASTLOGED", "Name", "");
	String prezime = ini->ReadString("LASTLOGED", "SecondName", "");
	String email = ini->ReadString("LASTLOGED", "Email", "");
	String user = ini->ReadString("LASTLOGED", "Username", "");
	String lastLoginDateTime = ini->ReadString("LASTLOGED", "LastLoginDateTime", "");
	bool darkMode;
	delete ini;
	// Prikaz vrijednosti u ListBoxu
	ListBox1->Items->Add("  Zadnji prijavljeni korisnik:");
	ListBox1->Items->Add("  " + ime + " " + prezime);
	ListBox1->Items->Add("");
	ListBox1->Items->Add("  Email: " + email);
	ListBox1->Items->Add("  Username: " + user);
	ListBox1->Items->Add("");
	ListBox1->Items->Add("  Datum i vrijeme prijave:");
	ListBox1->Items->Add("  " + lastLoginDateTime);

    Licenciranje licenciranje; // Instanca klase Licenciranje
	licenciranje.ProvjeriIstekLicence();


	TRegistry* winreg = new TRegistry;
	winreg->RootKey = HKEY_CURRENT_USER; //HKEY_CURRENT_USER\SOFTWARE\CashFlow
	UnicodeString appkey = "Software\\CashFlow";

	if(winreg->KeyExists(appkey)){
		if(winreg->OpenKey(appkey, true)){
			WindowState = (TWindowState)winreg->ReadInteger("WindowState");
			darkMode = winreg->ReadBool("DarkMode");
			_darkModeEnabled = darkMode;
			winreg->CloseKey();
		}
	}
	delete winreg;

	// Primjena promjena na izgled forme
	if (_darkModeEnabled) {
		SetDarkMode(); //08-70
	} else {
		SetLightMode(); //08-80
	}
}

//---------------------------------------------------------------------------

