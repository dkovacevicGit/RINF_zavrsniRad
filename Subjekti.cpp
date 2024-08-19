
// ************************************************** //
//                                                  
//                 XML Data Binding                 
//                                                  
//         Generated on: 19.06.2024 19:46:21        
//       Generated from: C:\CashFlow\Subjekti.xml   
//   Settings stored in: C:\CashFlow\Subjekti.xdb   
//                                                  
// ************************************************** //

#include <System.hpp>
#pragma hdrstop

#include "Subjekti.h"


// Global Functions 

_di_IXMLCompanyInfoType __fastcall GetCompanyInfo(Xml::Xmlintf::_di_IXMLDocument Doc)
{
  return (_di_IXMLCompanyInfoType) Doc->GetDocBinding("CompanyInfo", __classid(TXMLCompanyInfoType), TargetNamespace);
};

_di_IXMLCompanyInfoType __fastcall GetCompanyInfo(Xml::Xmldoc::TXMLDocument *Doc)
{
  Xml::Xmlintf::_di_IXMLDocument DocIntf;
  Doc->GetInterface(DocIntf);
  return GetCompanyInfo(DocIntf);
};

_di_IXMLCompanyInfoType __fastcall LoadCompanyInfo(const System::UnicodeString& FileName)
{
  return (_di_IXMLCompanyInfoType) Xml::Xmldoc::LoadXMLDocument(FileName)->GetDocBinding("CompanyInfo", __classid(TXMLCompanyInfoType), TargetNamespace);
};

_di_IXMLCompanyInfoType __fastcall  NewCompanyInfo()
{
  return (_di_IXMLCompanyInfoType) Xml::Xmldoc::NewXMLDocument()->GetDocBinding("CompanyInfo", __classid(TXMLCompanyInfoType), TargetNamespace);
};

// TXMLCompanyInfoType 

void __fastcall TXMLCompanyInfoType::AfterConstruction(void)
{
  RegisterChildNode(System::UnicodeString("Tvrtka"), __classid(TXMLTvrtkaType));
  ItemTag = "Tvrtka";
  ItemInterface = __uuidof(IXMLTvrtkaType);
  Xml::Xmldoc::TXMLNodeCollection::AfterConstruction();
};

_di_IXMLTvrtkaType __fastcall TXMLCompanyInfoType::Get_Tvrtka(const int Index)
{
  return (_di_IXMLTvrtkaType) List->Nodes[Index];
};

_di_IXMLTvrtkaType __fastcall TXMLCompanyInfoType::Add()
{
  return (_di_IXMLTvrtkaType) AddItem(-1);
};

_di_IXMLTvrtkaType __fastcall TXMLCompanyInfoType::Insert(const int Index)
{
  return (_di_IXMLTvrtkaType) AddItem(Index);
};

// TXMLTvrtkaType 

System::UnicodeString __fastcall TXMLTvrtkaType::Get_Naziv()
{
  return GetChildNodes()->Nodes[System::UnicodeString("Naziv")]->Text;
};

void __fastcall TXMLTvrtkaType::Set_Naziv(const System::UnicodeString Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("Naziv")]->NodeValue = Value;
};

System::UnicodeString __fastcall TXMLTvrtkaType::Get_UlicaBroj()
{
  return GetChildNodes()->Nodes[System::UnicodeString("UlicaBroj")]->Text;
};

void __fastcall TXMLTvrtkaType::Set_UlicaBroj(const System::UnicodeString Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("UlicaBroj")]->NodeValue = Value;
};

System::UnicodeString __fastcall TXMLTvrtkaType::Get_Grad()
{
  return GetChildNodes()->Nodes[System::UnicodeString("Grad")]->Text;
};

void __fastcall TXMLTvrtkaType::Set_Grad(const System::UnicodeString Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("Grad")]->NodeValue = Value;
};
