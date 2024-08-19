//---------------------------------------------------------------------------

#ifndef Unit06IzvjestajiH
#define Unit06IzvjestajiH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Comp.DataSet.hpp>
#include <FireDAC.DApt.hpp>
#include <FireDAC.DApt.Intf.hpp>
#include <FireDAC.DatS.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Param.hpp>
#include <Vcl.ExtCtrls.hpp>

#include <Vcl.ComCtrls.hpp>
#include <Xml.XMLDoc.hpp>
#include <Xml.xmldom.hpp>
#include <Xml.XMLIntf.hpp>
#include "frxClass.hpp"
#include "frxDBSet.hpp"
#include "frxExportBaseDialog.hpp"
#include "frxExportPDF.hpp"
#include "frxExportRTF.hpp"

//---------------------------------------------------------------------------
class TFormIzvjestaji : public TForm
{
__published:	// IDE-managed Components
	TDBGrid *DBGridIzvjestaji;
	TPanel *PanelPretraživanje;
	TButton *ButtonPretrazi;
	TEdit *EditPretrazi;
    TfrxReport *frxReport1;
	TfrxDBDataset *frxDBDatasetTransakcije;
	TfrxDBDataset *frxDBDatasetKlijent;
	TButton *ButtonIzvjestaj;
	TFDQuery *FDQueryTransakcije;
	TFDQuery *FDQueryKlijent;
	TDataSource *DataSourceTransakcija;
	TDataSource *DataSourceKlijent;
	TfrxPDFExport *frxPDFExport1;
	TButton *ButtonSavePdf;
	TButton *ButtonSaveRtf;
	TfrxRTFExport *frxRTFExport1;
	TLabel *Label2;
	TLabel *Label3;
	TPanel *PanelPrimatelji;
	TListView *ListView1;
	TXMLDocument *XMLDocument1;
	TButton *ButtonDodajUxml;
	TEdit *EditNaziv;
	TEdit *EditUlicaBroj;
	TEdit *EditGrad;
	TEdit *EditOib;
	TLabel *Label5;
	TButton *ButtonOib;
	TButton *ButtonEditXml;
	TButton *ButtonIzbrisiUXml;
	TButton *ButtonUcitajXml;
	TButton *ButtonClear;

	void __fastcall ButtonPretraziClick(TObject *Sender);
	void __fastcall ButtonIzvjestajClick(TObject *Sender);
	void __fastcall ButtonSavePdfClick(TObject *Sender);
	void __fastcall ButtonSaveRtfClick(TObject *Sender);
	void __fastcall ButtonUcitajXmlClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall ButtonIzbrisiUXmlClick(TObject *Sender);
	void __fastcall ButtonOibClick(TObject *Sender);
	void __fastcall ListView1Click(TObject *Sender);
	void __fastcall ButtonEditXmlClick(TObject *Sender);
	void __fastcall ButtonClearClick(TObject *Sender);
	void __fastcall DBGridIzvjestajiTitleClick(TColumn *Column);

private:	// User declarations
public:		// User declarations
	__fastcall TFormIzvjestaji(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormIzvjestaji *FormIzvjestaji;
extern TFDConnection *GlobalFDConnection;
//---------------------------------------------------------------------------
#endif
