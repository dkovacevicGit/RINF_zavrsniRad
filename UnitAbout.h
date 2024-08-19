//---------------------------------------------------------------------------

#ifndef UnitAboutH
#define UnitAboutH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "frxGIFGraphic.hpp"
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------

#ifdef EXPORTS
  #define DLL_EXPORT __declspec(dllexport)
#else
  #define DLL_EXPORT __declspec(dllimport)
#endif


class DLL_EXPORT TFormAbout : public TForm
{
__published:	// IDE-managed Components
	TMemo *MemoAbout;
	TButton *ButtonExit;
	void __fastcall ButtonExitClick(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TFormAbout(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern DLL_EXPORT TFormAbout *FormAbout;
//---------------------------------------------------------------------------
#endif
