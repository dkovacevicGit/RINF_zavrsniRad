
// ************************************************** //
//                                                  
//                 XML Data Binding                 
//                                                  
//         Generated on: 19.06.2024 19:46:21        
//       Generated from: C:\CashFlow\Subjekti.xml   
//   Settings stored in: C:\CashFlow\Subjekti.xdb   
//                                                  
// ************************************************** //

#ifndef   SubjektiH
#define   SubjektiH

#include <System.hpp>
#include <System.Variants.hpp>
#include <System.SysUtils.hpp>
#include <Xml.Xmldom.hpp>
#include <Xml.XMLIntf.hpp>
#include <Xml.XMLDoc.hpp>
#include <XMLNodeImp.h>
#include <Xml.xmlutil.hpp>


// Forward Decls 

__interface IXMLCompanyInfoType;
typedef System::DelphiInterface<IXMLCompanyInfoType> _di_IXMLCompanyInfoType;
__interface IXMLTvrtkaType;
typedef System::DelphiInterface<IXMLTvrtkaType> _di_IXMLTvrtkaType;

// IXMLCompanyInfoType 

__interface INTERFACE_UUID("{846689E6-2DBB-4B9A-8F74-CEFBBD56CCD6}") IXMLCompanyInfoType : public Xml::Xmlintf::IXMLNodeCollection
{
public:
public:
  // Property Accessors 
  virtual _di_IXMLTvrtkaType __fastcall Get_Tvrtka(const int Index) = 0;
  // Methods & Properties 
  virtual _di_IXMLTvrtkaType __fastcall Add() = 0;
  virtual _di_IXMLTvrtkaType __fastcall Insert(const int Index) = 0;
  __property _di_IXMLTvrtkaType Tvrtka[const int Index] = { read=Get_Tvrtka };/* default */
};

// IXMLTvrtkaType 

__interface INTERFACE_UUID("{24717AB4-6C5D-473C-9C70-248624DDA94E}") IXMLTvrtkaType : public Xml::Xmlintf::IXMLNode
{
public:
  // Property Accessors 
  virtual System::UnicodeString __fastcall Get_Naziv() = 0;
  virtual System::UnicodeString __fastcall Get_UlicaBroj() = 0;
  virtual System::UnicodeString __fastcall Get_Grad() = 0;
  virtual void __fastcall Set_Naziv(const System::UnicodeString Value) = 0;
  virtual void __fastcall Set_UlicaBroj(const System::UnicodeString Value) = 0;
  virtual void __fastcall Set_Grad(const System::UnicodeString Value) = 0;
  // Methods & Properties 
  __property System::UnicodeString Naziv = { read=Get_Naziv, write=Set_Naziv };
  __property System::UnicodeString UlicaBroj = { read=Get_UlicaBroj, write=Set_UlicaBroj };
  __property System::UnicodeString Grad = { read=Get_Grad, write=Set_Grad };
};

// Forward Decls 

class TXMLCompanyInfoType;
class TXMLTvrtkaType;

// TXMLCompanyInfoType 

class TXMLCompanyInfoType : public Xml::Xmldoc::TXMLNodeCollection, public IXMLCompanyInfoType
{
  __IXMLNODECOLLECTION_IMPL__
protected:
  // IXMLCompanyInfoType 
  virtual _di_IXMLTvrtkaType __fastcall Get_Tvrtka(const int Index);
  virtual _di_IXMLTvrtkaType __fastcall Add();
  virtual _di_IXMLTvrtkaType __fastcall Insert(const int Index);
public:
  virtual void __fastcall AfterConstruction(void);
};

// TXMLTvrtkaType 

class TXMLTvrtkaType : public Xml::Xmldoc::TXMLNode, public IXMLTvrtkaType
{
  __IXMLNODE_IMPL__
protected:
  // IXMLTvrtkaType 
  virtual System::UnicodeString __fastcall Get_Naziv();
  virtual System::UnicodeString __fastcall Get_UlicaBroj();
  virtual System::UnicodeString __fastcall Get_Grad();
  virtual void __fastcall Set_Naziv(const System::UnicodeString Value);
  virtual void __fastcall Set_UlicaBroj(const System::UnicodeString Value);
  virtual void __fastcall Set_Grad(const System::UnicodeString Value);
};

// Global Functions 

_di_IXMLCompanyInfoType __fastcall GetCompanyInfo(Xml::Xmlintf::_di_IXMLDocument Doc);
_di_IXMLCompanyInfoType __fastcall GetCompanyInfo(Xml::Xmldoc::TXMLDocument *Doc);
_di_IXMLCompanyInfoType __fastcall LoadCompanyInfo(const System::UnicodeString& FileName);
_di_IXMLCompanyInfoType __fastcall  NewCompanyInfo();

#define TargetNamespace ""

#endif