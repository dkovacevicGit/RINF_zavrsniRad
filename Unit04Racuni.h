//---------------------------------------------------------------------------

#ifndef Unit04RacuniH
#define Unit04RacuniH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
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
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Mask.hpp>
#include <Vcl.Dialogs.hpp>
#include <Datasnap.DBClient.hpp>
#include <Datasnap.Provider.hpp>


//---------------------------------------------------------------------------
class TFormRacuni : public TForm
{
__published:	// IDE-managed Components
	TFDQuery *FDQueryKorisnik;
	TDataSource *DataSourceKorisnik;
	TDBImage *DBImage1;
	TButton *ButtonObrisiSliku;
	TButton *ButtonNewAcc;
	TFDQuery *FDQueryRacuni;
	TDataSource *DataSourceRacuni;
	TDBGrid *DBGrid1;
	TButton *ButtonLoadCard;
	TOpenDialog *OpenDialog1;
	TDBNavigator *DBNavigator1;
	TFDQuery *FDQueryTrans;
	TDBGrid *DBGridTrans;
	TDataSource *DataSourceTrans;
	TButton *ButtonNewTrans;
	TDBNavigator *DBNavigator2;
	TFDQuery *FDQueryCalculated;
	TDataSource *DataSourceCalculated;
	TDBImage *DBImage2;
	TButton *ButtonLoadBCode;
	TButton *ButtonObrisiBCode;
	TLabel *Label2;
	TLabel *Label3;
	TStringField *FDQueryCalculatedCalculated;
	TStringField *FDQueryCalculatedime;
	TStringField *FDQueryCalculatedprezime;
	TStringField *FDQueryCalculatedusername;
	TStringField *FDQueryCalculatedemail;
	void __fastcall ButtonObrisiSlikuClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ButtonNewAccClick(TObject *Sender);
	void __fastcall ButtonLoadCardClick(TObject *Sender);
	void __fastcall ButtonNewTransClick(TObject *Sender);
	void __fastcall FDQueryCalculatedCalcFields(TDataSet *DataSet);
	void __fastcall ButtonLoadBCodeClick(TObject *Sender);
	void __fastcall ButtonObrisiBCodeClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall DBGrid1TitleClick(TColumn *Column);
	void __fastcall DBGridTransTitleClick(TColumn *Column);

private:	// User declarations
public:		// User declarations
	__fastcall TFormRacuni(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern AnsiString _prijavljeniKorisnik; // Definicija globalne varijable
extern TFDConnection *GlobalFDConnection;
//---------------------------------------------------------------------------

extern PACKAGE TFormRacuni *FormRacuni;
//---------------------------------------------------------------------------
#endif
