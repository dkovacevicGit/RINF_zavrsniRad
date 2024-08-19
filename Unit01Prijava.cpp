//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit01Prijava.h"
#include "Unit02Home.h"
#include "Unit09NewUser.h"
#include "Unit12Language.h"
#include "GlobalConnection.h"
#include "Unit13Help.h"

#include ".\\DLL\\UnitHelp.h"
#include ".\\DLL\\UnitAbout.h"
#include "reinit.hpp"

AnsiString _prijavljeniKorisnik; // Definicija globalne var.
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormPrijava *FormPrijava;
//---------------------------------------------------------------------------
__fastcall TFormPrijava::TFormPrijava(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormPrijava::BtnZatvoriClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormPrijava::BtnPrijavaClick(TObject *Sender)
{
	AnsiString username = EditUsername->Text;
	AnsiString password = EditPassword->Text;

	if(username=="" || password==""){
	ShowMessage("Unesite i korisnièko ime i lozinku");
	} else {
		// Kreiranje objekta UserLogin sa FDConnection1 kao argumentom konstruktora
		UserLogin userLogin(username, password);

		// Poziv metode za prijavu iz UserLogin objekta
		bool loginSuccess = userLogin.TrazenjeKorisnika();

		// Provjera rezultata prijave
		if (loginSuccess) {
			_prijavljeniKorisnik = username;  // Sprema username u globalnu varijablu
			ModalResult = mrOk;  //vraæa mrOk u main funkciju radi zatvaranja
		} else {
			ShowMessage("Pogrešno korisnièko ime ili lozinka!");  // Ako prijava nije uspjela, prikaži poruku
			EditUsername->SetFocus();
			EditUsername->Text="";
			EditPassword->Text="";
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormPrijava::BtnNewUserClick(TObject *Sender)
{
	//FDConnection1 = new TFDConnection(this);
	// Dinamièko kreiranje instance FormNewUser
	TFormNewUser *newUserForm = new TFormNewUser(this);

	// Prikazivanje forme
	newUserForm->ShowModal();

	// !! Ne smije se uništavati formu odmah nakon Show() jer to može uzrokovati pad aplikacije
}
//---------------------------------------------------------------------------

void __fastcall TFormPrijava::EditUsernameKeyPress(TObject *Sender, System::WideChar &Key)

{
	if (Key == VK_RETURN) //VK_RETURN - konstantna vrijednost za tipku Enter
	{
		Key = 0; // poništava Enter tipku, ne dodaje novi red u edit
		EditPassword->SetFocus(); // prebacuje fokus na gumb
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormPrijava::EditPasswordKeyPress(TObject *Sender, System::WideChar &Key)

{
	if (Key == VK_RETURN)
	{
		Key = 0; // poništava Enter tipku, ne dodaje novi red u edit
		BtnPrijava->SetFocus();
	}
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

void __fastcall TFormPrijava::ButtonHelpClick(TObject *Sender)
{
	THelp* UnitHelp = new THelp(this);
	UnitHelp->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFormPrijava::ButtonAboutClick(TObject *Sender)
{
	TFormAbout* UnitAbout = new TFormAbout(this);
	UnitAbout->ShowModal();
}
//---------------------------------------------------------------------------


