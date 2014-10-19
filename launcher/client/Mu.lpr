program Mu;

{$mode objfpc}{$H+}

uses
  {$IFDEF UNIX}{$IFDEF UseCThreads}
  cthreads,
  {$ENDIF}{$ENDIF}
  Interfaces, // this includes the LCL widgetset
  Forms, mainui, settingsui, wz_misc, debugui, Dialogs, sysutils;

{$R *.res}

begin
  RequireDerivedFormResource := True;
  Application.Initialize;

  if LowerCase(extractfilename(Application.ExeName)) <> 'mu.exe' then begin
     if not GetConfig('GENERAL','debug',false) then begin
	      MessageDlg('WarZone MU', 'ERROR : CRC check failed! Unable to continue.', mtError, [mbOK], 0);
	      Exit;
		 End;
	End;

  Application.CreateForm(TfrmMain, frmMain);
  application.createform(tfrmsettings, frmsettings);
  application.createform(tfrmdebug, frmdebug);
  Application.Run;
end.

