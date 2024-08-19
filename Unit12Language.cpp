//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit01Prijava.h"
#include "Unit02Home.h"
#include "Unit03Pregled.h"
#include "Unit04Racuni.h"
#include "Unit05Plan.h"
#include "Unit06Izvjestaji.h"
#include "Unit07Tecaj.h"
#include "Unit08Postavke.h"
#include "Unit09NewUser.h"
#include "Unit10NewAccount.h"
#include "Unit11NewTrans.h"
#include "Unit12Language.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "frxGIFGraphic"
#pragma resource "*.dfm"
TFormLanguage *FormLanguage;
//---------------------------------------------------------------------------
__fastcall TFormLanguage::TFormLanguage(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
	void __fastcall TFormLanguage::ImageCROClick(TObject *Sender)
{
	//ShowMessage("Odabrali ste hrvatski jezik");
	prevoditelj.Hrvatski();
	Close();
}
//---------------------------------------------------------------------------
	void __fastcall TFormLanguage::ImageENGClick(TObject *Sender)
{
	//ShowMessage("English language selected!");
	prevoditelj.Engleski();
	Close();
}
//---------------------------------------------------------------------------
	void __fastcall TFormLanguage::ImageGERClick(TObject *Sender)
{
	//ShowMessage("Sie haben die deutsche Sprache ausgew�hlt!");
	prevoditelj.Njemacki();
	Close();
}
//---------------------------------------------------------------------------


void Prevoditelj::Hrvatski()
{
//	FormPrijava->Caption = "CashFlow";
//	FormPrijava->GroupBox1->Caption = "Prijava u aplikaciju";
//	FormPrijava->Label1->Caption = "Korisni�ko ime:";
//	FormPrijava->Label2->Caption = "Lozinka:";
//	FormPrijava->BtnPrijava->Caption = "Prijava";
//	FormPrijava->BtnNewUser->Caption = "Novi  korisnik";
//	FormPrijava->ButtonLang->Caption = "Jezik korisni�kog su�elja";
//	FormPrijava->ButtonHelp->Caption = "Korisni�ki priru�nik";
//	FormPrijava->BtnZatvori->Caption = "Zatvori";

	FormHome->Caption = "CashFlow";
	FormHome->ButtonHome->Caption = "Pregled";
	FormHome->ButtonRacuni->Caption = "Ra�uni i transakcije";
	FormHome->ButtonIzvjestaji->Caption = "Izvje�taji i poslovni subjekti";
	FormHome->ButtonTecajna->Caption = "Te�ajna lista";
	FormHome->ButtonPostavke->Caption = "Postavke";
	FormHome->ButtonExit->Caption = "I Z L A Z";

	FormPregled->Caption = "Pregled";
	FormPregled->Label1->Caption = "Pregled";

	FormRacuni->Caption = "Ra�uni i transakcije";
	FormRacuni->ButtonNewAcc->Caption = "Novi ra�un";
	FormRacuni->ButtonLoadCard->Caption = "U�itaj karticu";
	FormRacuni->ButtonObrisiSliku->Caption = "Obri�i karticu";
	FormRacuni->ButtonNewTrans->Caption = "Nova transakcija";
	FormRacuni->ButtonLoadBCode->Caption = "U�itaj barcode";
	FormRacuni->ButtonObrisiBCode->Caption = "Obri�i barcode";
	FormRacuni->Label2->Caption = "Ra�uni";
	FormRacuni->Label3->Caption = "Transakcije";

	FormPlan->Caption = "Planirane transakcije";
	FormPlan->ButtonClose->Caption = "Zatvori";
	FormPlan->Label1->Caption = "Planirane transakcije";

	FormIzvjestaji->Caption = "Izvje�taji i pregled";
	//FormIzvjestaji->Label1->Caption = "Sortiranje";
	FormIzvjestaji->Label2->Caption = "Izvje�taji";
	FormIzvjestaji->Label3->Caption = "Poslovni subjekti";
	FormIzvjestaji->Label5->Caption = "Provjeri OIB:";
//	FormIzvjestaji->RadioButton1->Caption = "po datumu transakcije";
//	FormIzvjestaji->RadioButton2->Caption = "po iznosu pla�anja";
//	FormIzvjestaji->RadioButton3->Caption = "po nazivu ra�una";
//	FormIzvjestaji->RadioButton4->Caption = "po primatelju";
//	FormIzvjestaji->CheckBoxUzlazno->Caption = "sortiraj uzlazno";
	FormIzvjestaji->ButtonEditXml->Caption = "Spremi promjene";
	FormIzvjestaji->ButtonClear->Caption = "O�isti polja";
	FormIzvjestaji->ButtonPretrazi->Caption = "Pretra�i";
	FormIzvjestaji->ButtonIzvjestaj->Caption = "Kreiraj izvje�taj";
	FormIzvjestaji->ButtonSavePdf->Caption = "Spremi u PDF";
	FormIzvjestaji->ButtonSaveRtf->Caption = "Spremi u RTF";
	FormIzvjestaji->ButtonUcitajXml->Caption = "U�itaj u tablicu";
	FormIzvjestaji->ButtonIzbrisiUXml->Caption = "Obri�i poslovni subjekt";
	FormIzvjestaji->ButtonDodajUxml->Caption = "Dodaj novi";
	FormIzvjestaji->ButtonOib->Caption = "Provjeri OIB";

	FormTecaj->Caption = "Te�ajna lista";
	FormTecaj->Label1->Caption = ">> odabrana valuta";
	FormTecaj->Label2->Caption = "Te�ajna lista";
	FormTecaj->Label3->Caption = "Te�aj valute:";
	FormTecaj->Label4->Caption = "Iznos u EUR:";
	FormTecaj->Label5->Caption = "Iznos konverzije:";
	FormTecaj->Label6->Caption = "1,00";
	FormTecaj->Label7->Caption = "0,00";
	FormTecaj->ButtonSpremiJson->Caption = "Spremi u JSON datoteku";
	FormTecaj->ButtonUcitajHnb->Caption = "U�itaj te�aj HNB";
	FormTecaj->ButtonUcitajJson->Caption = "U�itaj iz JSON datoteke";

	FormPostavke->Caption = "Postavke";
	//FormPostavke->ButtonGetUsers->Caption = "U�itaj sve korisnike aplikacije";
	FormPostavke->ButtonChangePass->Caption = "Promijeni lozinku";
	FormPostavke->ButtonClear->Caption = "O�isti polja";
	FormPostavke->ButtonLicenca->Caption = "Aktiviraj licencu";
	FormPostavke->ButtonCheckNewVer->Caption = "Potra�i noviju verziju";
	FormPostavke->LabelUpdateDate->Caption = "Datum zadnje provjere:";
	FormPostavke->Label1->Caption = "Promjena lozinke korisnika";
	FormPostavke->Label2->Caption = "Korisnik:";
	FormPostavke->Label3->Caption = "Postavke";
	FormPostavke->Label4->Caption = "Nova lozinka:";
	FormPostavke->Label5->Caption = "Potvrdi lozinku:";
	FormPostavke->Label6->Caption = "Kod za aktivaciju:";
	FormPostavke->Label7->Caption = "Aktivacija aplikacije";
	FormPostavke->Label8->Caption = "Nadogradnja aplikacije";
	FormPostavke->LabelDark->Caption = "Tamni na�in:";
	FormPostavke->CheckBoxDarkMode->Caption = "Uklju�i";

	FormNewUser->Caption = "Novi korisnik";
	FormNewUser->Label1->Caption = "Ime:";
	FormNewUser->Label2->Caption = "Prezime:";
	FormNewUser->Label3->Caption = "Email:";
	FormNewUser->Label4->Caption = "Grad:";
	FormNewUser->Label5->Caption = "Korisni�ko ime:";
	FormNewUser->Label6->Caption = "Lozinka:";
	FormNewUser->Label7->Caption = "Ponovi lozinku:";
	FormNewUser->ButtonNewUserCreate->Caption = "Kreiraj";
	FormNewUser->ButtonNewUserCancel->Caption = "Odbaci";

	FormNewAccount->Caption = "Novi ra�un";
	FormNewAccount->Label1->Caption = "Naziv ra�una:";
	FormNewAccount->Label2->Caption = "Broj ra�una:";
	FormNewAccount->ButtonNewAccCreate->Caption = "Kreiraj ra�un";
	FormNewAccount->ButtonNewAccCancel->Caption = "Odbaci";

	FormNewTrans->Caption = "Novi ra�un";
	FormNewTrans->Label1->Caption = "Datum:";
	FormNewTrans->Label2->Caption = "Iznos:";
	FormNewTrans->Label3->Caption = "Ra�un:";
	FormNewTrans->Label4->Caption = "Primatelj:";
	FormNewTrans->Label5->Caption = "Opis transakcije:";
	FormNewTrans->GroupBox1->Caption = "Vrsta transakcije";
	FormNewTrans->RadioButtonPlacanje->Caption = "Pla�anje ra�una";
	FormNewTrans->RadioButtonUplata->Caption = "Uplata na ra�un";
	FormNewTrans->ButtonTransSpremi->Caption = "Spremi";
	FormNewTrans->ButtonTransOdbaci->Caption = "Odbaci";
}

void Prevoditelj::Engleski()
{
//	FormPrijava->Caption = "CashFlow";
//	FormPrijava->GroupBox1->Caption = "Login to the application";
//	FormPrijava->Label1->Caption = "Username:";
//	FormPrijava->Label2->Caption = "Password:";
//	FormPrijava->BtnPrijava->Caption = "Login";
//	FormPrijava->BtnNewUser->Caption = "New user";
//	FormPrijava->ButtonLang->Caption = "User interface language";
//	FormPrijava->ButtonHelp->Caption = "User manual";
//	FormPrijava->BtnZatvori->Caption = "Close";
//
	FormHome->Caption = "CashFlow";
	FormHome->ButtonHome->Caption = "Overview";
	FormHome->ButtonRacuni->Caption = "Accounts and transactions";
	FormHome->ButtonIzvjestaji->Caption = "Reports and business entities";
	FormHome->ButtonTecajna->Caption = "Exchange rate list";
	FormHome->ButtonPostavke->Caption = "Settings";
	FormHome->ButtonExit->Caption = "E X I T";

	FormPregled->Caption = "Overview";
	FormPregled->Label1->Caption = "Overview";

	FormRacuni->Caption = "Accounts and transactions";
	FormRacuni->ButtonNewAcc->Caption = "New account";
	FormRacuni->ButtonLoadCard->Caption = "Load card";
	FormRacuni->ButtonObrisiSliku->Caption = "Delete card";
	FormRacuni->ButtonNewTrans->Caption = "New transaction";
	FormRacuni->ButtonLoadBCode->Caption = "Load barcode";
	FormRacuni->ButtonObrisiBCode->Caption = "Delete barcode";
	FormRacuni->Label2->Caption = "Accounts";
	FormRacuni->Label3->Caption = "Transactions";

	FormPlan->Caption = "Planned transactions";
	FormPlan->ButtonClose->Caption = "Close";
	FormPlan->Label1->Caption = "Planned transactions";

	FormIzvjestaji->Caption = "Reports and overview";
	//FormIzvjestaji->Label1->Caption = "Sorting";
	FormIzvjestaji->Label2->Caption = "Reports";
	FormIzvjestaji->Label3->Caption = "Business entities";
	FormIzvjestaji->Label5->Caption = "Check OIB number:";
//	FormIzvjestaji->RadioButton1->Caption = "by transaction date";
//	FormIzvjestaji->RadioButton2->Caption = "by payment amount";
//	FormIzvjestaji->RadioButton3->Caption = "by account name";
//	FormIzvjestaji->RadioButton4->Caption = "by recipient";
//	FormIzvjestaji->CheckBoxUzlazno->Caption = "sort ascending";
	FormIzvjestaji->ButtonEditXml->Caption = "Save changes";
	FormIzvjestaji->ButtonClear->Caption = "Clear fields";
	FormIzvjestaji->ButtonPretrazi->Caption = "Search";
	FormIzvjestaji->ButtonIzvjestaj->Caption = "Create report";
	FormIzvjestaji->ButtonSavePdf->Caption = "Save as PDF";
	FormIzvjestaji->ButtonSaveRtf->Caption = "Save as RTF";
	FormIzvjestaji->ButtonUcitajXml->Caption = "Load into table";
	FormIzvjestaji->ButtonIzbrisiUXml->Caption = "Delete business entity";
	FormIzvjestaji->ButtonDodajUxml->Caption = "Add new";
	FormIzvjestaji->ButtonOib->Caption = "Check OIB:";

	FormTecaj->Caption = "Exchange rate list";
	FormTecaj->Label1->Caption = ">> selected currency:";
	FormTecaj->Label2->Caption = "Exchange rate list";
	FormTecaj->Label3->Caption = "Currency rate:";
	FormTecaj->Label4->Caption = "Amount in EUR:";
	FormTecaj->Label5->Caption = "Conversion amount:";
	FormTecaj->Label6->Caption = "1.00";
	FormTecaj->Label7->Caption = "0.00";
	FormTecaj->ButtonSpremiJson->Caption = "Save as JSON file";
	FormTecaj->ButtonUcitajHnb->Caption = "Load HNB exchange rate";
	FormTecaj->ButtonUcitajJson->Caption = "Load from JSON file";

	FormPostavke->Caption = "Settings";
	//FormPostavke->ButtonGetUsers->Caption = "Load all application users";
	FormPostavke->ButtonChangePass->Caption = "Change password";
	FormPostavke->ButtonClear->Caption = "Clear fields";
	FormPostavke->ButtonLicenca->Caption = "Activate license";
	FormPostavke->ButtonCheckNewVer->Caption = "Check for new version";
	FormPostavke->LabelUpdateDate->Caption = "Last checked:";
	FormPostavke->Label1->Caption = "Change user password";
	FormPostavke->Label2->Caption = "User:";
	FormPostavke->Label3->Caption = "Settings";
	FormPostavke->Label4->Caption = "New password:";
	FormPostavke->Label5->Caption = "Confirm password:";
	FormPostavke->Label6->Caption = "Activation code:";
	FormPostavke->Label7->Caption = "Application activation";
	FormPostavke->Label8->Caption = "Application upgrade";
	FormPostavke->LabelDark->Caption = "Dark mode:";
	FormPostavke->CheckBoxDarkMode->Caption = "Enable";

	FormNewUser->Caption = "New user";
	FormNewUser->Label1->Caption = "First name:";
	FormNewUser->Label2->Caption = "Last name:";
	FormNewUser->Label3->Caption = "Email:";
	FormNewUser->Label4->Caption = "City:";
	FormNewUser->Label5->Caption = "Username:";
	FormNewUser->Label6->Caption = "Password:";
	FormNewUser->Label7->Caption = "Repeat password:";
	FormNewUser->ButtonNewUserCreate->Caption = "Create";
	FormNewUser->ButtonNewUserCancel->Caption = "Cancel";

	FormNewAccount->Caption = "New account";
	FormNewAccount->Label1->Caption = "Account name:";
	FormNewAccount->Label2->Caption = "Account number:";
	FormNewAccount->ButtonNewAccCreate->Caption = "Create account";
	FormNewAccount->ButtonNewAccCancel->Caption = "Cancel";

	FormNewTrans->Caption = "New transaction";
	FormNewTrans->Label1->Caption = "Date:";
	FormNewTrans->Label2->Caption = "Amount:";
	FormNewTrans->Label3->Caption = "Account:";
	FormNewTrans->Label4->Caption = "Recipient:";
	FormNewTrans->Label5->Caption = "Transaction description:";
	FormNewTrans->GroupBox1->Caption = "Transaction type";
	FormNewTrans->RadioButtonPlacanje->Caption = "Bill payment";
	FormNewTrans->RadioButtonUplata->Caption = "Deposit to account";
	FormNewTrans->ButtonTransSpremi->Caption = "Save";
	FormNewTrans->ButtonTransOdbaci->Caption = "Cancel";
}


void Prevoditelj::Njemacki()
{
//	FormPrijava->Caption = "CashFlow";
//	FormPrijava->GroupBox1->Caption = "Anmeldung zur Anwendung";
//	FormPrijava->Label1->Caption = "Benutzername:";
//	FormPrijava->Label2->Caption = "Passwort:";
//	FormPrijava->BtnPrijava->Caption = "Anmelden";
//	FormPrijava->BtnNewUser->Caption = "Neuer Benutzer";
//	FormPrijava->ButtonLang->Caption = "Benutzeroberfl�chensprache";
//	FormPrijava->ButtonHelp->Caption = "Benutzerhandbuch";
//	FormPrijava->BtnZatvori->Caption = "Schlie�en";
//
	FormHome->Caption = "CashFlow";
	FormHome->ButtonHome->Caption = "�berblick";
	FormHome->ButtonRacuni->Caption = "Konten und Transaktionen";
	FormHome->ButtonIzvjestaji->Caption = "Berichte und Gesch�ftspartner";
	FormHome->ButtonTecajna->Caption = "Wechselkursliste";
	FormHome->ButtonPostavke->Caption = "Einstellungen";
	FormHome->ButtonExit->Caption = "A U S G A N G";

	FormPregled->Caption = "�berblick";
	FormPregled->Label1->Caption = "�berblick";

	FormRacuni->Caption = "Konten und Transaktionen";
	FormRacuni->ButtonNewAcc->Caption = "Neues Konto";
	FormRacuni->ButtonLoadCard->Caption = "Karte laden";
	FormRacuni->ButtonObrisiSliku->Caption = "Karte l�schen";
	FormRacuni->ButtonNewTrans->Caption = "Neue Transaktion";
	FormRacuni->ButtonLoadBCode->Caption = "Barcode laden";
	FormRacuni->ButtonObrisiBCode->Caption = "Barcode l�schen";
	FormRacuni->Label2->Caption = "Konten";
	FormRacuni->Label3->Caption = "Transaktionen";

	FormPlan->Caption = "Geplante Transaktionen";
	FormPlan->ButtonClose->Caption = "Schlie�en";
	FormPlan->Label1->Caption = "Geplante Transaktionen";

	FormIzvjestaji->Caption = "Berichte und �bersicht";
	//FormIzvjestaji->Label1->Caption = "Sortierung";
	FormIzvjestaji->Label2->Caption = "Berichte";
	FormIzvjestaji->Label3->Caption = "Gesch�ftspartner";
	FormIzvjestaji->Label5->Caption = "OIB numer:";
//	FormIzvjestaji->RadioButton1->Caption = "nach Transaktionsdatum";
//	FormIzvjestaji->RadioButton2->Caption = "nach Zahlungsbetrag";
//	FormIzvjestaji->RadioButton3->Caption = "nach Kontoname";
//	FormIzvjestaji->RadioButton4->Caption = "nach Empf�nger";
//	FormIzvjestaji->CheckBoxUzlazno->Caption = "aufsteigend sortieren";
	FormIzvjestaji->ButtonEditXml->Caption = "�nderungen speichern";
	FormIzvjestaji->ButtonClear->Caption = "Text l�schen";
	FormIzvjestaji->ButtonPretrazi->Caption = "Suchen";
	FormIzvjestaji->ButtonIzvjestaj->Caption = "Bericht erstellen";
	FormIzvjestaji->ButtonSavePdf->Caption = "Als PDF speichern";
	FormIzvjestaji->ButtonSaveRtf->Caption = "Als RTF speichern";
	FormIzvjestaji->ButtonUcitajXml->Caption = "In Tabelle laden";
	FormIzvjestaji->ButtonIzbrisiUXml->Caption = "Gesch�ftspartner l�schen";
	FormIzvjestaji->ButtonDodajUxml->Caption = "Neue Partner";
	FormIzvjestaji->ButtonOib->Caption = "OIB numer �berpr�fen";

	FormTecaj->Caption = "Wechselkursliste";
	FormTecaj->Label1->Caption = ">> ausgew�hlte W�hrung";
	FormTecaj->Label2->Caption = "Wechselkursliste";
	FormTecaj->Label3->Caption = "Wechselkurs:";
	FormTecaj->Label4->Caption = "Betrag in EUR:";
	FormTecaj->Label5->Caption = "Umrechnungsbetrag:";
	FormTecaj->Label6->Caption = "1,00";
	FormTecaj->Label7->Caption = "0,00";
	FormTecaj->ButtonSpremiJson->Caption = "Als JSON Datei speichern";
	FormTecaj->ButtonUcitajHnb->Caption = "HNB-Wechselkurs laden";
	FormTecaj->ButtonUcitajJson->Caption = "Von JSON einladen";

	FormPostavke->Caption = "Einstellungen";
	//FormPostavke->ButtonGetUsers->Caption = "Alle Anwendung Benutzer laden";
	FormPostavke->ButtonChangePass->Caption = "Passwort �ndern";
	FormPostavke->ButtonClear->Caption = "Felder l�schen";
	FormPostavke->ButtonLicenca->Caption = "Lizenz aktivieren";
	FormPostavke->ButtonCheckNewVer->Caption = "Nach neuer Version suchen";
	FormPostavke->LabelUpdateDate->Caption = "Das letzte �berpr�fung:";
	FormPostavke->Label1->Caption = "Benutzerpasswort �ndern";
	FormPostavke->Label2->Caption = "Benutzer:";
	FormPostavke->Label3->Caption = "Einstellungen";
	FormPostavke->Label4->Caption = "Neues Passwort:";
	FormPostavke->Label5->Caption = "Passwort best�tigen:";
	FormPostavke->Label6->Caption = "Aktivierungscode:";
	FormPostavke->Label7->Caption = "Anwendungsaktivierung";
	FormPostavke->Label8->Caption = "Anwendungsupgrade";
	FormPostavke->LabelDark->Caption = "Dunkelmodus:";
	FormPostavke->CheckBoxDarkMode->Caption = "Aktivieren";

	FormNewUser->Caption = "Neuer Benutzer";
	FormNewUser->Label1->Caption = "Vorname:";
	FormNewUser->Label2->Caption = "Nachname:";
	FormNewUser->Label3->Caption = "E-Mail:";
	FormNewUser->Label4->Caption = "Stadt:";
	FormNewUser->Label5->Caption = "Benutzername:";
	FormNewUser->Label6->Caption = "Passwort:";
	FormNewUser->Label7->Caption = "Passwort wiederholen:";
	FormNewUser->ButtonNewUserCreate->Caption = "Erstellen";
	FormNewUser->ButtonNewUserCancel->Caption = "Abbrechen";

	FormNewAccount->Caption = "Neues Konto";
	FormNewAccount->Label1->Caption = "Kontoname:";
	FormNewAccount->Label2->Caption = "Kontonummer:";
	FormNewAccount->ButtonNewAccCreate->Caption = "Konto erstellen";
	FormNewAccount->ButtonNewAccCancel->Caption = "Abbrechen";

	FormNewTrans->Caption = "Neue Transaktion";
	FormNewTrans->Label1->Caption = "Datum:";
	FormNewTrans->Label2->Caption = "Betrag:";
	FormNewTrans->Label3->Caption = "Konto:";
	FormNewTrans->Label4->Caption = "Empf�nger:";
	FormNewTrans->Label5->Caption = "Transaktionsbeschreibung:";
	FormNewTrans->GroupBox1->Caption = "Transaktionsart";
	FormNewTrans->RadioButtonPlacanje->Caption = "Rechnungszahlung";
	FormNewTrans->RadioButtonUplata->Caption = "Einzahlung auf Konto";
	FormNewTrans->ButtonTransSpremi->Caption = "Speichern";
	FormNewTrans->ButtonTransOdbaci->Caption = "Abbrechen";
}



