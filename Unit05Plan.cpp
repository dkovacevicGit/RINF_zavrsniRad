//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit05Plan.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormPlan *FormPlan;
//---------------------------------------------------------------------------
__fastcall TFormPlan::TFormPlan(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormPlan::ButtonCloseClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

