//---------------------------------------------------------------------------

#ifndef Unit05PlanH
#define Unit05PlanH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TFormPlan : public TForm
{
__published:	// IDE-managed Components
	TButton *ButtonClose;
	TLabel *Label1;
	void __fastcall ButtonCloseClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormPlan(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormPlan *FormPlan;
//---------------------------------------------------------------------------
#endif
