//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitHelp.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
THelp *Help;
//---------------------------------------------------------------------------
__fastcall THelp::THelp(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall THelp::FormCreate(TObject *Sender)
{
	//C:\Program Files (x86)\Embarcadero\Studio\22.0\Redist\win32\WebView2Loader.dll

	String url = "file:///" + ExtractFilePath(Application->ExeName) + "Help.htm";
	EdgeBrowser1->Navigate(url);
}
//---------------------------------------------------------------------------
