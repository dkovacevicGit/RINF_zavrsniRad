object FormNewTrans: TFormNewTrans
  Left = 0
  Top = 0
  Caption = 'Nova transakcija'
  ClientHeight = 584
  ClientWidth = 297
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poScreenCenter
  OnCreate = FormCreate
  TextHeight = 15
  object Label1: TLabel
    Left = 48
    Top = 44
    Width = 39
    Height = 15
    Caption = 'Datum:'
  end
  object Label2: TLabel
    Left = 48
    Top = 227
    Width = 30
    Height = 15
    Caption = 'Iznos:'
  end
  object Label3: TLabel
    Left = 48
    Top = 273
    Width = 36
    Height = 15
    Caption = 'Ra'#269'un:'
  end
  object Label4: TLabel
    Left = 41
    Top = 312
    Width = 50
    Height = 15
    Caption = 'Primatelj:'
  end
  object Label5: TLabel
    Left = 48
    Top = 360
    Width = 86
    Height = 15
    Caption = 'Opis transakcije:'
  end
  object DBLookupKlijent: TDBLookupComboBox
    Left = 112
    Top = 304
    Width = 137
    Height = 23
    KeyField = 'Naziv'
    ListField = 'Naziv'
    ListSource = DataSourceKlijent
    TabOrder = 5
  end
  object DateTimePicker1: TDateTimePicker
    Left = 104
    Top = 40
    Width = 145
    Height = 23
    Date = 45475.000000000000000000
    Time = 0.429927870369283500
    TabOrder = 0
  end
  object GroupBox1: TGroupBox
    Left = 48
    Top = 88
    Width = 201
    Height = 105
    Caption = 'Vrsta transakcije'
    TabOrder = 1
    object RadioButtonPlacanje: TRadioButton
      Left = 32
      Top = 40
      Width = 113
      Height = 17
      Caption = 'Pla'#263'anje ra'#269'una'
      Checked = True
      TabOrder = 0
      TabStop = True
      OnClick = RadioButtonPlacanjeClick
    end
    object RadioButtonUplata: TRadioButton
      Left = 32
      Top = 63
      Width = 113
      Height = 17
      Caption = 'Uplata na ra'#269'un'
      TabOrder = 1
      OnClick = RadioButtonUplataClick
    end
  end
  object EditTransIznos: TEdit
    Left = 112
    Top = 224
    Width = 137
    Height = 23
    Alignment = taRightJustify
    TabOrder = 2
    Text = '0,00'
  end
  object Memo1: TMemo
    Left = 48
    Top = 381
    Width = 201
    Height = 108
    TabOrder = 3
  end
  object ButtonTransSpremi: TButton
    Left = 48
    Top = 536
    Width = 86
    Height = 25
    Caption = 'Spremi'
    TabOrder = 4
    OnClick = ButtonTransSpremiClick
  end
  object ButtonTransOdbaci: TButton
    Left = 163
    Top = 536
    Width = 86
    Height = 25
    Caption = 'Odbaci'
    TabOrder = 6
    OnClick = ButtonTransOdbaciClick
  end
  object DBLookupAcc: TDBLookupComboBox
    Left = 112
    Top = 265
    Width = 137
    Height = 23
    KeyField = 'RacNaziv'
    ListField = 'RacNaziv'
    ListSource = FormRacuni.DataSourceRacuni
    TabOrder = 7
  end
  object DataSourceKlijent: TDataSource
    DataSet = FDQueryKlijent
    Left = 40
    Top = 440
  end
  object FDQueryKlijent: TFDQuery
    SQL.Strings = (
      'SELECT * FROM klijent')
    Left = 40
    Top = 496
    object FDQueryKlijentNaziv: TStringField
      FieldName = 'Naziv'
      Size = 100
    end
  end
end
