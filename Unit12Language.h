#ifndef Unit12LanguageH
#define Unit12LanguageH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include "frxGIFGraphic.hpp"
//---------------------------------------------------------------------------

class Prevoditelj {
public:
	void Hrvatski();
	void Engleski();
    void Njemacki();
	void Talijanski();
	void Slovenski();
};

class TFormLanguage : public TForm
{
__published:    // IDE-managed Components
    TImage *ImageCRO;
	TImage *ImageENG;
    TImage *ImageGER;
    void __fastcall ImageCROClick(TObject *Sender);
	void __fastcall ImageENGClick(TObject *Sender);
    void __fastcall ImageGERClick(TObject *Sender);
private:    // User declarations
    Prevoditelj prevoditelj;  // Deklaracija objekta prevoditelj
public:     // User declarations
    __fastcall TFormLanguage(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormLanguage *FormLanguage;
//---------------------------------------------------------------------------
#endif

