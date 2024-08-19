//---------------------------------------------------------------------------

#ifndef Unit08PostavkeH
#define Unit08PostavkeH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "Unit02Home.h"
#include <Vcl.ExtCtrls.hpp>
#include <Data.Bind.Components.hpp>
#include <Data.Bind.ObjectScope.hpp>
#include <REST.Client.hpp>
#include <REST.Types.hpp>
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
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <REST.Response.Adapter.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdHTTP.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include <Vcl.ComCtrls.hpp>
#include <IdIntercept.hpp>
#include <IdInterceptThrottler.hpp>
//---------------------------------------------------------------------------
class TFormPostavke : public TForm
{
__published:	// IDE-managed Components
	TPanel *PanelLozinka;
	TEdit *EditUsername;
	TButton *ButtonChangePass;
	TEdit *EditNewPass;
	TLabel *Label2;
	TLabel *Label4;
	TLabel *Label5;
	TEdit *EditPassConfirm;
	TButton *ButtonClear;
	TLabel *Label3;
	TPanel *PanelUI;
	TLabel *LabelDark;
	TCheckBox *CheckBoxDarkMode;
	TPanel *PanelLicenca;
	TEdit *Edit1;
	TButton *ButtonLicenca;
	TPanel *PanelUpdate;
	TButton *ButtonCheckNewVer;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TIdHTTP *HTTP1;
	TIdInterceptThrottler *InterceptThrottler1;
	TLabel *LabelUpdateDate;
	TLabel *LabelDatum;
	TLabel *Label1;
	void __fastcall CheckBoxDarkModeClick(TObject *Sender);
	void __fastcall ButtonChangePassClick(TObject *Sender);
	void __fastcall ButtonClearClick(TObject *Sender);
	void __fastcall ButtonLicencaClick(TObject *Sender);
	void __fastcall ButtonCheckNewVerClick(TObject *Sender);
	private:	// User declarations
public:		// User declarations
	__fastcall TFormPostavke(TComponent* Owner);
};

//---------------------------------------------------------------------------

extern AnsiString _prijavljeniKorisnik; // Definicija globalne varijable
extern TFDConnection *GlobalFDConnection;

//---------------------------------------------------------------------------

void SetDarkMode(){
	FormHome->Color = clNavy;
	FormHome->Font->Color = clWhite;
	FormHome->StatusBar1->Color = clBlack;
	FormHome->ListBox1->Color = clNavy;
	FormHome->ListBox1->Font->Color = clWhite;
};

void SetLightMode(){
	FormHome->Color = clBtnFace;
	FormHome->Font->Color = clBlack;
	FormHome->StatusBar1->Color = clBtnFace;
    FormHome->ListBox1->Color = clSkyBlue;
	FormHome->ListBox1->Font->Color = clBlack;
};



//---------------------------------------------------------------------------
extern PACKAGE TFormPostavke *FormPostavke;
//---------------------------------------------------------------------------
#endif
