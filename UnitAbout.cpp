//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitAbout.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "frxGIFGraphic"
#pragma resource "*.dfm"
TFormAbout *FormAbout;
//---------------------------------------------------------------------------
__fastcall TFormAbout::TFormAbout(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFormAbout::ButtonExitClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

