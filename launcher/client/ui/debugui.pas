Unit debugui;

{$mode objfpc}{$H+}

Interface

Uses
  classes, sysutils, fileutil, forms, controls, graphics, dialogs, StdCtrls;

Type

  { TfrmDebug }

  TfrmDebug = Class(tform)
    MemoLog: tmemo;
    Procedure formshow(sender: tobject);
  Private
    { private declarations }
  Public
    { public declarations }
    procedure AddLog(const msg : string);
  End;

Var
  frmDebug: TfrmDebug;

Implementation

{$R *.lfm}

{ TfrmDebug }

procedure TfrmDebug.AddLog(const msg : string);
begin
  MemoLog.Lines.Add(formatdatetime('hh:mm:ss',Now,[]) + ': ' + msg);
End;


Procedure tfrmdebug.formshow(sender: tobject);
Begin
  Top := 0;
  Left := 0;
end;

End.

