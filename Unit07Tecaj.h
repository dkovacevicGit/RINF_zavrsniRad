#ifndef Unit07TecajH
#define Unit07TecajH

#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.Bind.Components.hpp>
#include <Data.Bind.EngExt.hpp>
#include <Data.Bind.ObjectScope.hpp>
#include <REST.Client.hpp>
#include <REST.Types.hpp>
#include <System.Bindings.Outputs.hpp>
#include <System.Rtti.hpp>
#include <Vcl.Bind.DBEngExt.hpp>
#include <Vcl.Bind.Editors.hpp>
#include <Data.DB.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Comp.DataSet.hpp>
#include <FireDAC.DApt.Intf.hpp>
#include <FireDAC.DatS.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Param.hpp>
#include <REST.Response.Adapter.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>

class TFormTecaj : public TForm
{
__published:
    TButton *ButtonUcitajHnb;
    TDataSource *DataSource1;
    TDBGrid *DBGrid1;
    TRESTClient *RESTClient1;
    TRESTRequest *RESTRequest1;
    TRESTResponse *RESTResponse1;
    TRESTResponseDataSetAdapter *RESTRespAdapt1;
    TFDMemTable *FDMemTable1;
    TDBNavigator *DBNavigator1;
    TButton *ButtonSpremiJson;
    TPanel *PanelKonverzija;
    TWideStringField *FDMemTable1broj_tecajnice;
    TWideStringField *FDMemTable1datum_primjene;
    TWideStringField *FDMemTable1drzava;
    TWideStringField *FDMemTable1drzava_iso;
    TWideStringField *FDMemTable1kupovni_tecaj;
    TWideStringField *FDMemTable1prodajni_tecaj;
    TWideStringField *FDMemTable1sifra_valute;
    TWideStringField *FDMemTable1srednji_tecaj;
    TWideStringField *FDMemTable1valuta;
    TLabel *Label3;
    TLabel *Label4;
    TLabel *Label5;
    TLabel *Label1;
    TLabel *Label6;
    TEdit *Edit1;
    TLabel *Label7;
    TLabel *Label8;
    TLabel *Label9;
	TLabel *Label2;
	TButton *ButtonUcitajJson;

    void __fastcall ButtonUcitajHnbClick(TObject *Sender);
    void __fastcall ButtonSpremiJsonClick(TObject *Sender);
    void __fastcall DBGrid1CellClick(TColumn *Column);
	void __fastcall Edit1Change(TObject *Sender);
	void __fastcall ButtonUcitajJsonClick(TObject *Sender);

private:


public:
	__fastcall TFormTecaj(TComponent* Owner);
};

extern PACKAGE TFormTecaj *FormTecaj;

#endif

