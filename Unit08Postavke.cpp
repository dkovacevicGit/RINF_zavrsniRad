//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit08Postavke.h"
#include "Unit01Prijava.h"
#include "Unit02Home.h"
#include "Unit03Pregled.h"
#include "Unit04Racuni.h"
#include "Unit05Plan.h"
#include "Unit06Izvjestaji.h"
#include "Unit07Tecaj.h"
#include "Unit09NewUser.h"
#include "Unit10NewAccount.h"
#include "Unit11NewTrans.h"
#include <System.JSON.hpp>
#include <windows.h> // za funkcije CreateProcess i WaitForSingleObject
#include <string> // za std::wstring i std::to_wstring

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormPostavke *FormPostavke;
bool _darkModeEnabled;
//---------------------------------------------------------------------------
__fastcall TFormPostavke::TFormPostavke(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFormPostavke::CheckBoxDarkModeClick(TObject *Sender)
{
    // Promjena globalne varijable na temelju stanja CheckBox-a
	_darkModeEnabled = CheckBoxDarkMode->Checked;
    // Primjena promjena na izgled forme
	if (_darkModeEnabled) {
		SetDarkMode();
	} else {
		SetLightMode();
	}
}

//---------------------------------------------------------------------------

void __fastcall TFormPostavke::ButtonChangePassClick(TObject *Sender)
{
	// Dohva�anje korisni�kog imena i nove lozinke iz edit polja
	String username = EditUsername->Text;
	String newPassword = EditNewPass->Text;
	String passwordConfirm = EditPassConfirm->Text;

	// Provjera jesu li polja popunjena
	if(username=="" || newPassword==""){
	ShowMessage("Unesite i korisni�ko ime i lozinku");
	}

	// Provjera je li username odgovara prijavljenom useru
	if (username != _prijavljeniKorisnik) {
	ShowMessage("Uneseno korisni�ko ime ne odgovara prijavljenom korisniku. Mijenjati mo�ete samo svoju lozinku.");
	return;
	}

		// Provjera je li nova lozinka potvr�ena
	if (newPassword != passwordConfirm) {
	ShowMessage("Lozinka i potvrda lozinke nisu iste.");
	return;
	}else {
		TFDQuery *query = new TFDQuery(NULL); // Stvaranje objekta upita
         try {
        query->Connection = GlobalFDConnection; // Postavljanje veze na objekt upita
        query->SQL->Text = "UPDATE korisnik SET password = :password WHERE username = :username";
        query->ParamByName("username")->AsString = username;
        query->ParamByName("password")->AsString = newPassword;
        query->ExecSQL(); // Izvr�avanje upita

        // Provjera je li upit uspje�no izvr�en
        if (query->RowsAffected > 0) {
            ShowMessage("Lozinka je uspje�no promijenjena.");
        } else {
            ShowMessage("Lozinka nije promijenjena. Provjerite unesene podatke.");
        }
    } catch (Exception &e) {
        ShowMessage("Do�lo je do pogre�ke: " + e.Message);
    }
	delete query; // Osloba�anje memorije

	EditUsername ->Text = "";
	EditNewPass ->Text = "";
	EditPassConfirm ->Text = "";
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormPostavke::ButtonClearClick(TObject *Sender)
{
	EditUsername ->Text = "";
	EditNewPass ->Text = "";
	EditPassConfirm ->Text = "";
}
//---------------------------------------------------------------------------


void __fastcall TFormPostavke::ButtonLicencaClick(TObject *Sender)
{
	Licenciranje licenca;

	TDateTime datum = Date();

	licenca.SpremiDatumUnosaKljuca(datum);
}
//---------------------------------------------------------------------------
//              PROCESI
//---------------------------------------------------------------------------

void __fastcall TFormPostavke::ButtonCheckNewVerClick(TObject *Sender)
{
//	STARTUPINFO startInfo;
//	PROCESS_INFORMATION processInfo;
//	wchar_t CommandLine[255] = L"Update.exe";
//	unsigned long exitcode;
//	ZeroMemory(&startInfo, sizeof(startInfo));
//	startInfo.cb = sizeof(startInfo);
//	ZeroMemory(&processInfo, sizeof(processInfo));
//	if (!CreateProcessW(NULL, CommandLine, NULL, NULL, FALSE, 0, NULL, NULL,
//        &startInfo, &processInfo))
//    {
//		ShowMessage(L"Gre�ka u aplikaciji!");
//		return;
//	}
//    WaitForSingleObject(processInfo.hProcess, INFINITE);
//	GetExitCodeProcess(processInfo.hProcess, &exitcode);
//	CloseHandle(processInfo.hProcess);
//	CloseHandle(processInfo.hThread);
//
//	if (exitcode == 0)
//	{
//		ShowMessage(L"Preuzeli ste najnoviju verziju datoteke  D:\\NewCashFlow.zip");
//	}
//    else if (exitcode == 1)
//	{
		ShowMessage(L"Ve� koristite najnoviju verziju datoteke!");
//    }
//	else
//	{
//		ShowMessage(L"Do�lo je do gre�ke pri provjeri verzije.");
//	}

	LabelDatum->Caption = DateToStr(Now());
}
//---------------------------------------------------------------------------

