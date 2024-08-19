//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
#include <memory>
//---------------------------------------------------------------------------
USEFORM("Unit04Racuni.cpp", FormRacuni);
USEFORM("Unit05Plan.cpp", FormPlan);
USEFORM("Unit06Izvjestaji.cpp", FormIzvjestaji);
USEFORM("Unit01Prijava.cpp", FormPrijava);
USEFORM("Unit02Home.cpp", FormHome);
USEFORM("Unit03Pregled.cpp", FormPregled);
USEFORM("Unit10NewAccount.cpp", FormNewAccount);
USEFORM("Unit11NewTrans.cpp", FormNewTrans);
USEFORM("Unit12Language.cpp", FormLanguage);
USEFORM("Unit07Tecaj.cpp", FormTecaj);
USEFORM("Unit08Postavke.cpp", FormPostavke);
USEFORM("Unit09NewUser.cpp", FormNewUser);
USEFORM("Unit13Help.cpp", FormHelp);
//---------------------------------------------------------------------------
#include "Unit01Prijava.h"
#include "Unit02Home.h"
#include "GlobalConnection.h"

//---------------------------------------------------------------------------

int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;

		InitializeGlobalConnection();

		//Kreiranje forme preko pointera u alociranoj memoriji
		std::unique_ptr<TFormPrijava> FormPrijava(new TFormPrijava(NULL));
		if(FormPrijava->ShowModal() == mrOk){  //Ako je login uspješan, zatvara FormPrijava

		Application->CreateForm(__classid(TFormHome), &FormHome);
		Application->CreateForm(__classid(TFormPregled), &FormPregled);
		Application->CreateForm(__classid(TFormRacuni), &FormRacuni);
		Application->CreateForm(__classid(TFormPlan), &FormPlan);
		Application->CreateForm(__classid(TFormIzvjestaji), &FormIzvjestaji);
		Application->CreateForm(__classid(TFormTecaj), &FormTecaj);
		Application->CreateForm(__classid(TFormPostavke), &FormPostavke);
		Application->CreateForm(__classid(TFormNewUser), &FormNewUser);
		Application->CreateForm(__classid(TFormNewAccount), &FormNewAccount);
		Application->CreateForm(__classid(TFormNewTrans), &FormNewTrans);
		Application->CreateForm(__classid(TFormLanguage), &FormLanguage);
		Application->CreateForm(__classid(TFormHelp), &FormHelp);
		Application->Run();
		}
		else;

	FinalizeGlobalConnection();

	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
