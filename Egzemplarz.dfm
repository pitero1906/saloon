object add_egzemplarz: Tadd_egzemplarz
  Left = 279
  Top = 79
  BorderStyle = bsToolWindow
  Caption = 'Dodaj nowy egzemplarz'
  ClientHeight = 480
  ClientWidth = 800
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
    Width = 232
    Height = 24
    Caption = 'Stw'#243'rz nowy egzemplarz'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Button2: TButton
    Left = 675
    Top = 432
    Width = 97
    Height = 33
    Caption = 'Zapisz'
    TabOrder = 0
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 563
    Top = 432
    Width = 97
    Height = 33
    Caption = 'Anuluj'
    TabOrder = 1
    OnClick = Button3Click
  end
  object GroupBox1: TGroupBox
    Left = 24
    Top = 72
    Width = 745
    Height = 177
    Caption = 'Wybierz samoch'#243'd'
    TabOrder = 2
    object foto: TImage
      Left = 520
      Top = 16
      Width = 209
      Height = 145
      Proportional = True
    end
    object info: TComboBox
      Left = 16
      Top = 72
      Width = 473
      Height = 28
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ItemHeight = 20
      ParentFont = False
      TabOrder = 0
      OnChange = infoChange
    end
  end
  object GroupBox2: TGroupBox
    Left = 24
    Top = 264
    Width = 321
    Height = 169
    Caption = 'Dodatki'
    TabOrder = 3
    object klima: TCheckBox
      Left = 16
      Top = 24
      Width = 249
      Height = 25
      Caption = 'Klimatyzacja'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
    end
    object alusy: TCheckBox
      Left = 16
      Top = 56
      Width = 249
      Height = 25
      Caption = 'Aluminiowe felgi'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
    end
    object komp: TCheckBox
      Left = 16
      Top = 88
      Width = 249
      Height = 25
      Caption = 'Komputer '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
    end
    object skora: TCheckBox
      Left = 16
      Top = 120
      Width = 249
      Height = 25
      Caption = 'Sk'#243'rzane fotele'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 3
    end
  end
  object GroupBox3: TGroupBox
    Left = 368
    Top = 328
    Width = 401
    Height = 73
    Caption = 'Cena zestawu'
    TabOrder = 4
    object cena: TLabel
      Left = 208
      Top = 16
      Width = 18
      Height = 39
      Alignment = taCenter
      Caption = '?'
      Font.Charset = EASTEUROPE_CHARSET
      Font.Color = clNavy
      Font.Height = -32
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Button1: TButton
      Left = 16
      Top = 24
      Width = 105
      Height = 33
      Caption = 'Oblicz'
      TabOrder = 0
      OnClick = Button1Click
    end
  end
  object GroupBox5: TGroupBox
    Left = 648
    Top = 16
    Width = 121
    Height = 49
    Caption = 'ID Egzemplarza'
    TabOrder = 5
    object id: TLabel
      Left = 56
      Top = 16
      Width = 5
      Height = 24
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
  end
end
