//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "GlobalConnection.h"

#include "Unit09NewUser.h"
#include "Unit01Prijava.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormNewUser *FormNewUser;
//---------------------------------------------------------------------------
__fastcall TFormNewUser::TFormNewUser(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFormNewUser::ButtonNewUserCancelClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormNewUser::ButtonNewUserCreateClick(TObject *Sender)
{
    // Preuzimanje vrijednosti iz polja za unos
	String ime = EditNewName->Text;
	String prezime = EditNewSecName->Text;
	String email = EditNewEmail->Text;
	String city = EditNewCity->Text;
	String username = EditNewUsername->Text;
	String password = EditNewPass->Text;
	String passwordConfirm = EditNewPassConfirm->Text;

    // Provjera da li su sva polja popunjena
    if (ime.IsEmpty() || prezime.IsEmpty() || email.IsEmpty() || city.IsEmpty() || username.IsEmpty() || password.IsEmpty() || passwordConfirm.IsEmpty()) {
        ShowMessage("Molimo ispunite sva polja.");
        return;
    }

    // Provjera da li se lozinka i potvrda lozinke podudaraju
    if (password != passwordConfirm) {
        ShowMessage("Lozinka i potvrda lozinke se ne podudaraju.");
        return;
    }

	// Kreiranje objekta NewUser
	NewUser newUser(ime, prezime, email, city, username, password, passwordConfirm);

    // Provjera postoji li veæ korisnik s tim korisnièkim imenom
    if (newUser.TraziUsername()) {
        ShowMessage("Korisnièko ime veæ postoji. Molimo odaberite drugo korisnièko ime.");
    } else {
        // Upis novog korisnika u bazu podataka
		newUser.UpisiKorisnika(ime, prezime, email, city, username, password);
        ShowMessage("Novi korisnik uspješno dodan.");
        Close(); // Zatvaranje forme nakon uspješnog unosa korisnika
    }
}
//---------------------------------------------------------------------------

