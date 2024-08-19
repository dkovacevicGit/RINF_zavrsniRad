//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit03Pregled.h"
#include "Unit04Racuni.h"
#include "Unit02Home.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormPregled *FormPregled;
//---------------------------------------------------------------------------
__fastcall TFormPregled::TFormPregled(TComponent* Owner)
	: TForm(Owner)
{
	//FormRacuni->FDQueryRacuni->Refresh();
	DBChart1->RefreshData();
}
//---------------------------------------------------------------------------

