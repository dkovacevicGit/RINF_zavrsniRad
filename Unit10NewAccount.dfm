object FormNewAccount: TFormNewAccount
  Left = 0
  Top = 0
  Caption = 'New account'
  ClientHeight = 239
  ClientWidth = 335
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poScreenCenter
  TextHeight = 15
  object Label1: TLabel
    Left = 37
    Top = 59
    Width = 71
    Height = 15
    Caption = 'Naziv ra'#269'una:'
  end
  object Label2: TLabel
    Left = 45
    Top = 106
    Width = 63
    Height = 15
    Caption = 'Broj ra'#269'una:'
  end
  object EditNewAccName: TEdit
    Left = 136
    Top = 56
    Width = 180
    Height = 23
    TabOrder = 0
  end
  object EditNewAccNumber: TEdit
    Left = 136
    Top = 103
    Width = 180
    Height = 23
    TabOrder = 1
  end
  object ButtonNewAccCreate: TButton
    Left = 27
    Top = 176
    Width = 126
    Height = 25
    Caption = 'Kreiraj ra'#269'un'
    TabOrder = 2
    OnClick = ButtonNewAccCreateClick
  end
  object ButtonNewAccCancel: TButton
    Left = 184
    Top = 176
    Width = 132
    Height = 25
    Caption = 'Odbaci'
    TabOrder = 3
    OnClick = ButtonNewAccCancelClick
  end
end
