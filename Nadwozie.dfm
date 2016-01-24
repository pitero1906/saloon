object add_nadwozie: Tadd_nadwozie
  Left = 569
  Top = 242
  BorderStyle = bsToolWindow
  Caption = 'Dodaj nowe nadwozie'
  ClientHeight = 250
  ClientWidth = 430
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
    Left = 24
    Top = 16
    Width = 197
    Height = 24
    Caption = 'Wprowad'#378' parametry'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 64
    Top = 80
    Width = 52
    Height = 20
    Caption = 'Rodzaj'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 64
    Top = 112
    Width = 4
    Height = 20
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 64
    Top = 144
    Width = 39
    Height = 20
    Caption = 'Cena'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label5: TLabel
    Left = 64
    Top = 112
    Width = 79
    Height = 20
    Caption = 'Ilo'#347#263' drzwi'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object rodzaj: TEdit
    Left = 160
    Top = 80
    Width = 209
    Height = 21
    TabOrder = 0
  end
  object drzwi: TEdit
    Left = 160
    Top = 112
    Width = 209
    Height = 21
    TabOrder = 1
  end
  object cena: TEdit
    Left = 160
    Top = 144
    Width = 209
    Height = 21
    TabOrder = 2
  end
  object Button1: TButton
    Left = 272
    Top = 200
    Width = 97
    Height = 25
    Caption = 'Zapisz'
    TabOrder = 3
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 160
    Top = 200
    Width = 97
    Height = 25
    Caption = 'Anuluj'
    TabOrder = 4
    OnClick = Button2Click
  end
end
