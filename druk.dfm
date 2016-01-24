object faktura: Tfaktura
  Left = 451
  Top = 119
  BorderStyle = bsToolWindow
  Caption = 'Faktura'
  ClientHeight = 553
  ClientWidth = 501
  Color = clCaptionText
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Mem: TMemo
    Left = 8
    Top = 16
    Width = 481
    Height = 481
    Alignment = taCenter
    TabOrder = 0
  end
  object Button1: TButton
    Left = 352
    Top = 512
    Width = 113
    Height = 33
    Caption = 'Drukuj'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Print: TPrintDialog
    Left = 24
    Top = 512
  end
end
