object FormNewUser: TFormNewUser
  Left = 0
  Top = 0
  Caption = 'New user'
  ClientHeight = 459
  ClientWidth = 351
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poScreenCenter
  TextHeight = 15
  object Label1: TLabel
    Left = 93
    Top = 64
    Width = 23
    Height = 15
    Caption = 'Ime:'
  end
  object Label2: TLabel
    Left = 71
    Top = 109
    Width = 45
    Height = 15
    Caption = 'Prezime:'
  end
  object Label3: TLabel
    Left = 84
    Top = 154
    Width = 32
    Height = 15
    Caption = 'Email:'
  end
  object Label4: TLabel
    Left = 88
    Top = 200
    Width = 28
    Height = 15
    Caption = 'Grad:'
  end
  object Label5: TLabel
    Left = 32
    Top = 245
    Width = 81
    Height = 15
    Caption = 'Korisni'#269'ko ime:'
  end
  object Label6: TLabel
    Left = 73
    Top = 290
    Width = 43
    Height = 15
    Caption = 'Lozinka:'
  end
  object Label7: TLabel
    Left = 35
    Top = 336
    Width = 81
    Height = 15
    Caption = 'Ponovi lozinku:'
  end
  object EditNewName: TEdit
    Left = 144
    Top = 56
    Width = 180
    Height = 23
    TabOrder = 0
  end
  object EditNewSecName: TEdit
    Left = 144
    Top = 106
    Width = 180
    Height = 23
    TabOrder = 1
  end
  object EditNewEmail: TEdit
    Left = 144
    Top = 151
    Width = 180
    Height = 23
    TabOrder = 2
  end
  object EditNewCity: TEdit
    Left = 144
    Top = 192
    Width = 180
    Height = 23
    TabOrder = 3
  end
  object EditNewUsername: TEdit
    Left = 144
    Top = 237
    Width = 180
    Height = 23
    TabOrder = 4
  end
  object EditNewPass: TEdit
    Left = 144
    Top = 282
    Width = 180
    Height = 23
    PasswordChar = '*'
    TabOrder = 5
  end
  object EditNewPassConfirm: TEdit
    Left = 144
    Top = 328
    Width = 180
    Height = 23
    PasswordChar = '*'
    TabOrder = 6
  end
  object ButtonNewUserCreate: TButton
    Left = 144
    Top = 400
    Width = 85
    Height = 25
    Caption = 'Kreiraj'
    TabOrder = 7
    OnClick = ButtonNewUserCreateClick
  end
  object ButtonNewUserCancel: TButton
    Left = 239
    Top = 400
    Width = 85
    Height = 25
    Caption = 'Odbaci'
    TabOrder = 8
    OnClick = ButtonNewUserCancelClick
  end
end
