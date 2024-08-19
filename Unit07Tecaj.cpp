#include <vcl.h>
#include <System.JSON.hpp>
#include <System.SysUtils.hpp>
#include <System.Classes.hpp>
#include "Unit07Tecaj.h"
#include ".\\DLL\\KonverzijaDLL.h"


#pragma hdrstop
#pragma package(smart_init)
#pragma resource "*.dfm"


TFormTecaj *FormTecaj;

__fastcall TFormTecaj::TFormTecaj(TComponent* Owner)
    : TForm(Owner)
{
    String naziv = DataSource1->DataSet->FieldByName("valuta")->AsString;
	Label9->Caption = naziv;

	KonverzijaValute konverter; //Kreiranje novog objekta klase iz dll-a
}
//---------------------------------------------------------------------------

void __fastcall TFormTecaj::ButtonUcitajHnbClick(TObject *Sender)
{
    RESTRequest1->Execute();
}
//---------------------------------------------------------------------------

void __fastcall TFormTecaj::ButtonSpremiJsonClick(TObject *Sender)
{
    String jsonDoc;
    jsonDoc += "[";
    FDMemTable1->First();
    while (!FDMemTable1->Eof) {
        jsonDoc += "{";
        jsonDoc += "\"broj_tecajnice\":\"" + FDMemTable1->FieldByName("broj_tecajnice")->AsString + "\",";
        jsonDoc += "\"sifra_valute\":\"" + FDMemTable1->FieldByName("sifra_valute")->AsString + "\",";
        jsonDoc += "\"valuta\":\"" + FDMemTable1->FieldByName("valuta")->AsString + "\",";
        jsonDoc += "\"kupovni_tecaj\":\"" + FDMemTable1->FieldByName("kupovni_tecaj")->AsString + "\",";
        jsonDoc += "\"srednji_tecaj\":\"" + FDMemTable1->FieldByName("srednji_tecaj")->AsString + "\",";
        jsonDoc += "\"prodajni_tecaj\":\"" + FDMemTable1->FieldByName("prodajni_tecaj")->AsString + "\",";
        jsonDoc += "\"drzava\":\"" + FDMemTable1->FieldByName("drzava")->AsString + "\",";
        jsonDoc += "\"drzava_iso\":\"" + FDMemTable1->FieldByName("drzava_iso")->AsString + "\",";
        jsonDoc += "\"datum_primjene\":\"" + FDMemTable1->FieldByName("datum_primjene")->AsString + "\"";
        jsonDoc += "}";
        FDMemTable1->Next();
        if (!FDMemTable1->Eof) {
            jsonDoc += ",";
        }
    }
    jsonDoc += "]";
    TDateTime vrijeme = TDateTime::CurrentDate();
    String FileName = "./SpremljeniTecaj_" + vrijeme.FormatString("dd_mm_yyyy") + ".json";
    jsonDoc = ((TJSONObject*)TJSONObject::ParseJSONValue(jsonDoc))->Format(2);
    TStringStream* ss = new TStringStream();
    ss->WriteString(jsonDoc);
    ss->SaveToFile(FileName);
    delete ss;
	ShowMessage("Teèaj spremljen");
}
//---------------------------------------------------------------------------

void __fastcall TFormTecaj::ButtonUcitajJsonClick(TObject *Sender)
{
	// Definiranje naziva datoteke
	TDateTime vrijeme = TDateTime::CurrentDate();
	String FileName = "./SpremljeniTecaj_" + vrijeme.FormatString("dd_mm_yyyy") + ".json";
	// Provjera postoji li datoteka
	if (!FileExists(FileName)) {
		ShowMessage("Datoteka ne postoji");
		return;
	}
	// Uèitavanje sadržaja datoteke u string
	TStringStream *ss = new TStringStream();
	ss->LoadFromFile(FileName);
	String jsonDoc = ss->DataString;
	delete ss;
	// Parsiranje JSON dokumenata
	TJSONArray *jsonArray = (TJSONArray*)TJSONObject::ParseJSONValue(jsonDoc);
	if (jsonArray == nullptr) {
		ShowMessage("Greška pri èitanju JSON datoteke");
		return;
	}
	// Brisanje trenutnih podataka u FDMemTable1
	FDMemTable1->Close();
	FDMemTable1->Open();
	while (!FDMemTable1->IsEmpty()) {
		FDMemTable1->First();
		FDMemTable1->Delete();
	}
	// Uèitavanje podataka iz JSON-a u FDMemTable1
    for (int i = 0; i < jsonArray->Count; i++) {
        TJSONObject *jsonObject = (TJSONObject*)jsonArray->Items[i];
		FDMemTable1->Append();
		FDMemTable1->FieldByName("broj_tecajnice")->AsString = jsonObject->GetValue("broj_tecajnice")->Value();
        FDMemTable1->FieldByName("sifra_valute")->AsString = jsonObject->GetValue("sifra_valute")->Value();
		FDMemTable1->FieldByName("valuta")->AsString = jsonObject->GetValue("valuta")->Value();
        FDMemTable1->FieldByName("kupovni_tecaj")->AsString = jsonObject->GetValue("kupovni_tecaj")->Value();
		FDMemTable1->FieldByName("srednji_tecaj")->AsString = jsonObject->GetValue("srednji_tecaj")->Value();
		FDMemTable1->FieldByName("prodajni_tecaj")->AsString = jsonObject->GetValue("prodajni_tecaj")->Value();
		FDMemTable1->FieldByName("drzava")->AsString = jsonObject->GetValue("drzava")->Value();
		FDMemTable1->FieldByName("drzava_iso")->AsString = jsonObject->GetValue("drzava_iso")->Value();
		FDMemTable1->FieldByName("datum_primjene")->AsString = jsonObject->GetValue("datum_primjene")->Value();
		FDMemTable1->Post();
	}
	delete jsonArray;
	ShowMessage("Uèitan je teèaj iz JSON datoteke");

}
//---------------------------------------------------------------------------

void __fastcall TFormTecaj::DBGrid1CellClick(TColumn *Column)
{
	String naziv = DataSource1->DataSet->FieldByName("valuta")->AsString;
    Label9->Caption = naziv;
	Label8->Caption = naziv;
	Edit1->Text = "1";

    String tecaj = DataSource1->DataSet->FieldByName("srednji_tecaj")->AsString;
    Label6->Caption = tecaj;
}
//---------------------------------------------------------------------------

void __fastcall TFormTecaj::Edit1Change(TObject *Sender)
{
	// Korišteno statièko povezivanje dll-a;
	// Možemo direktno koristiti funkcije i klase iz DLL-a
	// bez potrebe za dinamièkim uèitavanjem i oslobaðanjem

	KonverzijaValute konverter; //Kreiranje novog objekta klase iz dll-a

	double tecajRazmjene = Label6->Caption.ToDouble();
	double iznosEur = Edit1->Text.ToDouble();
	konverter.postaviTecaj(tecajRazmjene);
	konverter.postaviIznosEur(iznosEur);
	double iznosKonverzije = konverter.izracunajIznosKonverzije();
	Label7->Caption = FormatFloat("0.00", iznosKonverzije);
}
//---------------------------------------------------------------------------


