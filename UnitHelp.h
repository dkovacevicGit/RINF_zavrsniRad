//---------------------------------------------------------------------------

#ifndef UnitHelpH
#define UnitHelpH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <SHDocVw.hpp>
#include <Vcl.OleCtrls.hpp>
#include <Vcl.Edge.hpp>
#include <Winapi.ActiveX.hpp>
#include <Winapi.WebView2.hpp>
//---------------------------------------------------------------------------

#ifdef EXPORTS
  #define DLL_EXPORT __declspec(dllexport)
#else
  #define DLL_EXPORT __declspec(dllimport)
#endif


class DLL_EXPORT THelp : public TForm
{
__published:	// IDE-managed Components
	TEdgeBrowser *EdgeBrowser1;
	void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall THelp(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern DLL_EXPORT THelp *Help;
//---------------------------------------------------------------------------
#endif
