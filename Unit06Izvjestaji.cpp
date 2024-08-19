//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit06Izvjestaji.h"
#include "Unit04Racuni.h"
#include "Unit02Home.h"
#include "Subjekti.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "frxClass"
#pragma link "frxDBSet"
#pragma link "frxExportBaseDialog"
#pragma link "frxExportPDF"
#pragma link "frxExportRTF"
#pragma link "frxClass"
#pragma link "frxDBSet"
#pragma link "frxExportBaseDialog"
#pragma link "frxExportPDF"
#pragma link "frxExportRTF"
#pragma resource "*.dfm"
TFormIzvjestaji *FormIzvjestaji;

bool duzinaOIB(const AnsiString& oibStr); //Prototip funkcije iz CheckOib.lib
bool provjeriOIB(const int oib[]); //Prototip funkcije iz CheckOib.lib

//---------------------------------------------------------------------------
__fastcall TFormIzvjestaji::TFormIzvjestaji(TComponent* Owner)
	: TForm(Owner)
{
	FDQueryTransakcije->Connection = GlobalFDConnection;
	FDQueryTransakcije->Active = true;
	FDQueryTransakcije->Open();

	FDQueryKlijent->Connection = GlobalFDConnection;
	FDQueryKlijent->Active = true;
	FDQueryKlijent->Open();

}
//---------------------------------------------------------------------------
//      SORTIRANJE I PRETRAŽIVANJE
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

void __fastcall TFormIzvjestaji::ButtonPretraziClick(TObject *Sender)
{
	String uvijetPretrage = EditPretrazi->Text.Trim();  //Trim() uklanja sve vodeæe i zaostale praznine (whitespace) iz stringa
	if (!uvijetPretrage.IsEmpty()) {
		FDQueryTransakcije->Close();
		FDQueryTransakcije->SQL->Text = "SELECT * FROM transakcija WHERE "
							  "TereceniRacun LIKE :uvijetPretrage OR "
							  "KlijentIme LIKE :uvijetPretrage OR "
							  "Username LIKE :uvijetPretrage";
		FDQueryTransakcije->ParamByName("uvijetPretrage")->AsString = "%" + uvijetPretrage + "%";
		//LIKE sa % omoguæavate pretraživanje ne samo toènih podudaranja, veæ i svih zapisa koji sadrže navedeni pojam
		FDQueryTransakcije->Open();
		EditPretrazi->Text = "";
    } else {
		FDQueryTransakcije->Close();
		FDQueryTransakcije->SQL->Text = "SELECT * FROM transakcija";
		FDQueryTransakcije->Open();
        EditPretrazi->Text = "";
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormIzvjestaji::ButtonIzvjestajClick(TObject *Sender)
{
	frxReport1->ShowReport();
}
//---------------------------------------------------------------------------


void __fastcall TFormIzvjestaji::ButtonSavePdfClick(TObject *Sender)
{
	//frxPDFExport1->FileName = "Detalji_transakcije.pdf"; // Definirano u vizualnoj komponenti
	frxReport1->PrepareReport(true);
	frxReport1->Export(frxPDFExport1);
}
//---------------------------------------------------------------------------

void __fastcall TFormIzvjestaji::ButtonSaveRtfClick(TObject *Sender)
{
	frxReport1->PrepareReport(true);
	frxReport1->Export(frxRTFExport1);

}
//---------------------------------------------------------------------------

//************   Rad sa XML-om    *************
//---------------------------------------------------------------------------

void __fastcall TFormIzvjestaji::ButtonUcitajXmlClick(TObject *Sender)
{
	_di_IXMLCompanyInfoType PopisTvrtki = GetCompanyInfo(XMLDocument1);

	ListView1->Items->Clear();
	for (int i = 0; i < PopisTvrtki->Count; i++) {
		ListView1->Items->Add();
		ListView1->Items->Item[i]->Caption = PopisTvrtki->Tvrtka[i]->Naziv;
		ListView1->Items->Item[i]->SubItems->Add(PopisTvrtki->Tvrtka[i]->UlicaBroj);
		ListView1->Items->Item[i]->SubItems->Add(PopisTvrtki->Tvrtka[i]->Grad);
	}
}

//---------------------------------------------------------------------------

void __fastcall TFormIzvjestaji::Button1Click(TObject *Sender)
{
	if(EditNaziv->Text == ""){
		ShowMessage("Popunite podatke o poslovnom subjektu.");
	} else {
	_di_IXMLCompanyInfoType PopisTvrtki = GetCompanyInfo(XMLDocument1);
	_di_IXMLTvrtkaType Tvrtka = PopisTvrtki->Add();

	Tvrtka->Naziv = EditNaziv->Text;
	Tvrtka->UlicaBroj = EditUlicaBroj->Text;
	Tvrtka->Grad = EditGrad->Text;

	XMLDocument1->SaveToFile(XMLDocument1->FileName);

	EditNaziv->Text = "";
	EditUlicaBroj->Text = "";
	EditGrad->Text = "";
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormIzvjestaji::ListView1Click(TObject *Sender)
{
	if (ListView1->Selected){
		int selectedIndex = ListView1->Selected->Index;
		_di_IXMLCompanyInfoType PopisTvrtki = GetCompanyInfo(XMLDocument1);
		_di_IXMLTvrtkaType Tvrtka = PopisTvrtki->Tvrtka[selectedIndex];
		EditNaziv->Text = Tvrtka->Naziv;
		EditUlicaBroj->Text = Tvrtka->UlicaBroj;
		EditGrad->Text = Tvrtka->Grad;
	}

}
//---------------------------------------------------------------------------

void __fastcall TFormIzvjestaji::ButtonEditXmlClick(TObject *Sender)
{
	if (!ListView1->Selected){
		ShowMessage("Odaberite red iz tablice");
	} else {
		int odabraniRed = ListView1->Selected->Index;
		_di_IXMLCompanyInfoType PopisTvrtki = GetCompanyInfo(XMLDocument1);
		_di_IXMLTvrtkaType Tvrtka = PopisTvrtki->Tvrtka[odabraniRed];
		Tvrtka->Naziv = EditNaziv->Text;
		Tvrtka->UlicaBroj = EditUlicaBroj->Text;
		Tvrtka->Grad = EditGrad->Text;
		XMLDocument1->SaveToFile(XMLDocument1->FileName);
		//ShowMessage("Promjene su spremljene.");
		// Ažuriraj ListView stavku
		ListView1->Selected->Caption = Tvrtka->Naziv;
		ListView1->Selected->SubItems->Strings[0] = Tvrtka->UlicaBroj;
		ListView1->Selected->SubItems->Strings[1] = Tvrtka->Grad;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormIzvjestaji::ButtonIzbrisiUXmlClick(TObject *Sender)
{
	_di_IXMLCompanyInfoType PopisTvrtki = GetCompanyInfo(XMLDocument1);

	PopisTvrtki->Delete(ListView1->ItemIndex);
	XMLDocument1->SaveToFile(XMLDocument1->FileName);
	ShowMessage("Obrisano!");
}
//---------------------------------------------------------------------------
void __fastcall TFormIzvjestaji::ButtonClearClick(TObject *Sender)
{
	EditNaziv->Text = "";
	EditUlicaBroj->Text = "";
	EditGrad->Text = "";
	ListView1->Selected = NULL;
}
//---------------------------------------------------------------------------

// METODA PROVJERE OIB-a (Kod je u StaticLibrary)
// Kontrolna znamenka prema meðunarodnoj normi ISO 7064 (MOD 11, 10). dobiva se slijedeæim postupkom :
// 1. prva znamenka zbroji se s brojem 10
// 2. dobiveni zbroj cjelobrojno (s ostatkom) podijeli se brojem 10;
// ako je dobiveni ostatak 0 zamijeni se brojem 10 (ovaj broj je tzv. meðuostatak)
// 3. dobiveni meðuostatak pomnoži se brojem 2
// 4. dobiveni umnožak cjelobrojno (s ostatkom) podijeli se brojem 11;
// ovaj ostatak matematièki nikako ne može biti 0 jer je rezultat
// prethodnog koraka uvijek paran broj
// 5. slijedeæa znamenka zbroji se s ostatkom u prethodnom koraku
// 6. ponavljaju se koraci 2, 3, 4 i 5 dok se ne potroše sve znamenke
// 7. razlika izmeðu broja 11 i ostatka u zadnjem koraku je kontrolna znamenka; ako je
// ostatak 1 kontrolna znamenka je 0 (11-1=10, a 10 ima dvije znamenke)

void __fastcall TFormIzvjestaji::ButtonOibClick(TObject *Sender)
{
	String oibStr = EditOib->Text;

	// Provjera dužine OIB-a (metoda iz static lib)
	if(!duzinaOIB(oibStr)) {
		ShowMessage("OIB mora sadržavati 11 znamenki!");
	} else {
		int oib[11];
		// Pretvaranje stringa u niz integera
		for (int i = 0; i < 11; ++i) {
			oib[i] = StrToIntDef(oibStr.SubString(i + 1, 1), 0);  //AnsiStringT SubString(int index, int count)
		}
		if (provjeriOIB(oib)) {
			ShowMessage("OIB je ispravan.");
		} else {
			ShowMessage("OIB nije ispravan.");
		}
    }

}
//---------------------------------------------------------------------------

void __fastcall TFormIzvjestaji::DBGridIzvjestajiTitleClick(TColumn *Column)
{
	// Dohvaæanje naziva polja na koje je korisnik kliknuo
	String fieldName = Column->FieldName;
	// Provjera trenutnog sortiranja - silazno ili uzlazno
	static bool sortAscending = true; // Varijabla koja prati redoslijed sortiranja
	String sortOrder = sortAscending ? "ASC" : "DESC";
	sortAscending = !sortAscending; // Prebacivanje reda nakon svakog klika
	// Postavljanje novog SQL upita s ORDER BY klauzulom
	FDQueryTransakcije->Close();
	FDQueryTransakcije->SQL->Text = "SELECT * FROM transakcija ORDER BY " + fieldName + " " + sortOrder;
	FDQueryTransakcije->Open();
}
//---------------------------------------------------------------------------

