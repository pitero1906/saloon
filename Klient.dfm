object new_egzemplarz: Tnew_egzemplarz
  Left = 459
  Top = 197
  BorderStyle = bsToolWindow
  Caption = 'Egzemplarz na zam'#243'wienie'
  ClientHeight = 300
  ClientWidth = 400
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 16
    Top = 16
    Width = 218
    Height = 24
    Caption = 'Wprowad'#378' dane klienta'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 48
    Top = 72
    Width = 35
    Height = 24
    Caption = 'Imi'#281
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 48
    Top = 112
    Width = 80
    Height = 24
    Caption = 'Nazwisko'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 48
    Top = 152
    Width = 60
    Height = 24
    Caption = 'PESEL'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object ID: TLabel
    Left = 144
    Top = 192
    Width = 5
    Height = 24
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label6: TLabel
    Left = 48
    Top = 192
    Width = 80
    Height = 24
    Caption = 'Numer ID'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object imie: TEdit
    Left = 144
    Top = 72
    Width = 225
    Height = 21
    TabOrder = 0
  end
  object nazwisko: TEdit
    Left = 144
    Top = 112
    Width = 225
    Height = 21
    TabOrder = 1
  end
  object pesel: TEdit
    Left = 144
    Top = 152
    Width = 225
    Height = 21
    TabOrder = 2
  end
  object Button2: TButton
    Left = 263
    Top = 251
    Width = 97
    Height = 33
    Caption = 'Dalej'
    TabOrder = 3
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 151
    Top = 251
    Width = 97
    Height = 33
    Caption = 'Anuluj'
    TabOrder = 4
    OnClick = Button3Click
  end
end
