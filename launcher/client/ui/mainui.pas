unit mainui;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, FileUtil, Forms, Controls, Graphics, Dialogs, ExtCtrls,
  StdCtrls, wz_misc, settingsui, debugui, fpJSON, JSONParser,
  // To run executable
  ShellApi, typinfo,
  // For download routine (synapse)
  blcksock, httpsend;

type

  { THTTPDownload }

  THTTPDownload = class(TThread)
    private
      fURL: string;
      fFileName: string;
      UseStream : boolean;
      procedure OnStatus(Sender: TObject; Reason: THookSocketReason; const  Value: string);
    public
      //StringData : string;
      StreamData : TStringStream;
      //TotalBytes : integer;
      Success : boolean;
      constructor Create(const URL, FileName: string; const IsStream : boolean);
      procedure Execute; override;
  end;

  { THTGetSize }

  THTGetSize = class(TTHread)
    private
      fURL: string;
      procedure OnStatus(Sender: TObject; Reason: THookSocketReason; const  Value: string);
    public
      TotalBytesX : integer;
      constructor Create(const URL: string);
      procedure Execute; override;
  end;

  { TfrmMain }

  TfrmMain = class(TForm)
    imgpbbg: timage;
    imgSettingsON: TImage;
    imgSettingsOFF: TImage;
    imgpb: timage;
    imgAds: TImage;
    imgBG: TImage;
    imgCloseOff: TImage;
    imgCloseOn: TImage;
    imgStartGameCyan: TImage;
    imgStartGameGray: TImage;
    imgStartGameYellow: TImage;
    imgSettings: TImage;
    imgStartGame: TImage;
    imgWindowMode: TImage;
    imgClose: TImage;
    imgWindowModeOFF: TImage;
    imgWindowModeON: TImage;
    lblpbstatusstring: tlabel;
    lblpbpercentstring: TLabel;
    updater: ttimer;
    procedure FormCreate(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure imgAdsMouseDown(Sender: TObject; Button: TMouseButton;
      Shift: TShiftState; X, Y: Integer);
    procedure imgAdsMouseMove(Sender: TObject; Shift: TShiftState; X, Y: Integer
      );

    procedure imgBGMouseDown(Sender: TObject; Button: TMouseButton;
      Shift: TShiftState; X, Y: Integer);
    procedure imgBGMouseMove(Sender: TObject; Shift: TShiftState; X, Y: Integer
      );

    procedure imgCloseMouseEnter(Sender: TObject);
    procedure imgCloseMouseLeave(Sender: TObject);
    procedure imgSettingsMouseEnter(Sender: TObject);
    procedure imgSettingsMouseLeave(Sender: TObject);
    procedure imgStartGameClick(Sender: TObject);
    procedure imgCloseClick(Sender: TObject);
    procedure imgSettingsClick(Sender: TObject);
    procedure imgStartGameMouseDown(Sender: TObject; Button: TMouseButton;
      Shift: TShiftState; X, Y: Integer);
    procedure imgStartGameMouseUp(Sender: TObject; Button: TMouseButton;
      Shift: TShiftState; X, Y: Integer);
    procedure imgWindowModeClick(Sender: TObject);
    procedure imgWindowModeMouseEnter(Sender: TObject);
    procedure imgWindowModeMouseLeave(Sender: TObject);
    procedure lblpbstatusstringDblClick(Sender: TObject);
    Procedure updatertimer(sender: tobject);
  private
    procedure LoadSkin;
    procedure LoadRegistrySettings;
    //procedure StatusUpdate(const msg: string; const delay: integer);
    procedure SelfCheck;
    Procedure CheckForUpdates();
    procedure DownloadTerminated(Sender: TObject);
    procedure StartGameEx(const msg: string);
    procedure InitUpdateIndicators(const v : boolean);
  public
    { public declarations }
  end;

procedure AddLog(const msg : string);
procedure StatusUpdate(const msg: string);
procedure StatusUpdate(const msg: string; const delay: integer);

var
  update_enabled : boolean = false;
  frmMain: TfrmMain;
  frmDebugLog: TfrmDebug;
  xx,yy: integer;
  config : TWZConfig;
  bmpbg: TBitmap;
  updatecurrent, updatecount, TotalBytes, CurrentBytes : integer;

implementation

var
   mainbga, mainbgb, // main form background
   startgameyellow, startgamecyan, startgamegray, // start game button images
   adsimage, // adverts image
   CloseOn, CloseOff,
   SettingsOn, SettingsOff,
   WindowModeOn, WindowModeOff : string;
   pbwidth: integer;

   ThreadDone, percentstringvisible : boolean;

{$R *.lfm}

procedure StatusUpdate(const msg: string);
begin
  frmMain.lblpbstatusstring.Caption := msg;
  //application.ProcessMessages;
  //sleep(1);
end;

procedure StatusUpdate(const msg: string; const delay: integer);
begin
  frmMain.lblpbstatusstring.Caption := msg;
  //application.ProcessMessages;
  sleep(delay);
end;

{ TODO : THTTPDownload Create }
constructor THTTPDownload.Create(const URL, FileName: string; const IsStream : boolean);
begin
  inherited Create(true);
  fURL := URL;
  fFileName := FileName;
  UseStream := IsStream;
end;

{ TODO : THTTPDownload Execute }
procedure THTTPDownload.Execute;
begin

  AddLog('Download.Execute: Downloading data ' + fURL);


  with THTTPSend.Create do begin
    try
    Sock.OnStatus := @OnStatus;

      if HTTPMethod('GET', fURL) then begin
        case Resultcode of
          100..299:
          begin
            if UseStream then begin
              AddLog('Download.Execute: Saving downloaded data to stream . . .');
              StreamData := TStringStream.Create('');
              Document.SaveToStream(StreamData);
              //StringData := StreamData.DataString;
              //JSONStream := StreamData.DataString;
              //FreeAndNil(StreamData);
            end else begin
              AddLog('Download.Execute: Saving downloaded data to ' + fFileName);
              Document.SaveToFile(fFileName);
            end;
            success := True;
          end; //informational, success
          300..599: success := False; // internal server error
          else success := False; // unknown code
        end;
      end else begin
        success := false;
      End;
     Except
    end;
  end;
  if success then begin
    AddLog('Download.Execute: Downloaded!');
  End else begin
    AddLog('Download.Execute: Download failed!');
  End;
  Exit;
end;


{ DONE : THTTPDownload OnStatus}
procedure THTTPDownload.OnStatus(Sender: TObject; Reason: THookSocketReason; const  Value: string);
var
 dlprogress : integer = 0;
 msg : string = 'Initiating download . . .';
begin
 try
 AddLog('Download.OnStatus: ' + GetEnumName(TypeInfo(THookSocketReason), Integer(Reason)) + ', ' +
        Value);

 if (TotalBytes = 0) then exit;

 case Reason of
 	HR_CanWrite, HR_CanRead, HR_ReadCount: begin
     Inc(CurrentBytes, StrToIntDef(Value, 0));
     dlprogress := Round(100 * (CurrentBytes / TotalBytes));
     frmMain.imgpb.Visible := true;
     frmMain.imgpb.Width := round(dlprogress * (pbwidth / 100));
     frmMain.lblpbpercentstring.Visible := true;
     frmMain.lblpbpercentstring.Caption := inttostr(dlprogress) + '%';
     msg := 'Downloading update ' + inttostr(updatecurrent) + '/' + inttostr(updatecount) + ' [' + FormatByteSize(CurrentBytes) + ']';
     AddLog(msg + ' (' + frmMain.lblpbpercentstring.Caption + ')');
 	end;
 	HR_Connect: CurrentBytes := 0;
  HR_Error: msg := value;
 end;
 Except
 End;
 StatusUpdate(msg);
end;

{ TODO : THTGet Size Create }
constructor THTGetSize.Create(const URL : string);
begin
  inherited Create(true);
  fURL := URL;
  TotalBytesX := 0;
end;

{ DONE : GetDownloadSize }
procedure THTGetSize.Execute;
var
  i: integer;
begin

  AddLog('GetSize.Execute: Reading download size of ' + fURL);

  with THTTPSend.Create do begin
    try
    Sock.OnStatus := @OnStatus;
    //Timeout := 60;

    if HTTPMethod('HEAD', fURL) then begin
      for i := 0 to Headers.Count - 1 do begin
        if pos('CONTENT-LENGTH:', UpperCase(Headers[i])) > 0 then begin
          TotalBytesX := StrToIntDef(copy(Headers[i],pos(':',Headers[i])+1,length(Headers[i])),0);
          //showmessage('GetSize: ' + inttostr(TotalBytesX));
          AddLog('GetSize.Execute: Download size is ' + inttostr(TotalBytesX));//FormatByteSize(TotalBytesX));
          break;
        end;
      end;
    end;

   if TotalBytesX < 1 then AddLog('GetSize.Execute: Failed to read download size!');

  Except

  end;
  end;
  Exit;
End;

{ DONE : THTGetSize OnStatus}
procedure THTGetSize.OnStatus(Sender: TObject; Reason: THookSocketReason; const  Value: string);
var
   msg : string = 'Contacting update server . . .';

begin
  try
 AddLog('GetSize.OnStatus: ' + GetEnumName(TypeInfo(THookSocketReason), Integer(Reason)) + ', ' +
        Value);
 Case Reason of
    HR_Error: msg := value;
//      case Integer(Reason) of
//         11001: msg := 'Host not found!';
//      End;
  end;
	Except
	End;
  StatusUpdate(msg);
end;

{ AddLog }
procedure AddLog(const msg : string);
var
   File1: TextFile;
   dbgfile: string = 'debug.log';
begin
  //if not fileExists(dbgfile) then FileCreate (dbgfile);
  AssignFile(File1, dbgfile);
  if not fileExists(dbgfile) then
    Rewrite(File1)
  else
    Append(File1);
  Writeln(File1,msg);
  CloseFile(File1);
  frmDebugLog.AddLog(msg);
end;

{ TfrmMain }

procedure TfrmMain.imgStartGameClick(Sender: TObject);
begin

  if (FileExists(wzexe)) then begin
     Cursor := crHourGlass; // busy mouse pointer
     //WindowState := wsMinimized;
     ShellExecute(0,nil, PChar(wzexe),PChar(''),PChar(''),1); // run main.exe
     //WindowState := wsMinimized;
     application.Minimize;
     //Close;
  end
  else
      //ShowMessage('Unable to find file - ' + wzexe);
      MessageDlg('WarZone MU Launcher', 'Unable to find file - ' + wzexe, mtError, [mbOK], 0);

end;

procedure TfrmMain.imgCloseMouseEnter(Sender: TObject);
begin
  imgClose.Picture := imgCloseOn.Picture;
end;

procedure TfrmMain.FormCreate(Sender: TObject);
begin
  // debug form
  frmDebugLog := TfrmDebug.Create(nil);
  if GetConfig('GENERAL','debug',0) = 1 then frmDebugLog.Show;
  // ----------
  LoadSkin();
  LoadRegistrySettings;
end;

procedure TfrmMain.FormShow(Sender: TObject);
begin

  if (not FileExists(mainbga)) then exit;
  bmpbg := TBitmap.Create;
  bmpbg.LoadFromFile(mainbga);
  bmpbg.Monochrome := True;

  //Visible := false;
  Width := bmpbg.Width; // set form width
  Height := bmpbg.Height; // set form height
  //Position := poScreenCenter;
  //BorderStyle := bsNone; // hide form border

  SetShape(bmpbg); // draw the new form shape

  bmpbg.Free; // free resources

  // This is a workaround to center a form
  // after setting its custom shape
  Left := (Screen.Width - Width) div 2;
  Top := (Screen.Height - Height) div 2;

  // Self check
  SelfCheck;

  updater.Enabled := true;   // start updater

end;

procedure TfrmMain.SelfCheck;
begin
  AddLog('Performing self check...');
  // Check for new launcher (self-update)
  if FileExists('mu.old') then begin
     AddLog('Deleting mu.old . . .');
     DeleteFile('mu.old');
  end;

  If FileExists('mu.new') then
  begin
     RenameFile('mu.exe', 'mu.old');
     RenameFile('mu.new', 'mu.exe');
     ShellExecute(Handle, nil, PChar(Application.ExeName), nil, nil, 1);
     Application.Terminate; // or, if this is the main form, simply Close;
  end;
end;

procedure TfrmMain.imgAdsMouseDown(Sender: TObject; Button: TMouseButton;
  Shift: TShiftState; X, Y: Integer);
begin
  xx := x;
  yy := y;
end;

procedure TfrmMain.imgAdsMouseMove(Sender: TObject; Shift: TShiftState; X,
  Y: Integer);
begin
  if ssleft in Shift then
  begin
    top := top + y - yy;
    left := left + x - xx;
  end;
end;

procedure TfrmMain.imgBGMouseDown(Sender: TObject; Button: TMouseButton;
  Shift: TShiftState; X, Y: Integer);
begin
  xx := x;
  yy := y;
end;

procedure TfrmMain.imgBGMouseMove(Sender: TObject; Shift: TShiftState; X,
  Y: Integer);
begin
  if ssleft in Shift then
  begin
    top := top + y - yy;
    left := left + x - xx;
  end;
end;


procedure TfrmMain.imgCloseMouseLeave(Sender: TObject);
begin
    imgClose.Picture := imgCloseOff.Picture;
end;

procedure TfrmMain.imgSettingsMouseEnter(Sender: TObject);
begin
  imgSettings.Picture := imgSettingsON.Picture;
end;

procedure TfrmMain.imgSettingsMouseLeave(Sender: TObject);
begin
  imgSettings.Picture := imgSettingsOFF.Picture;
end;

procedure TfrmMain.imgCloseClick(Sender: TObject);
begin
  application.Terminate;
  //Exit;
end;

procedure TfrmMain.imgSettingsClick(Sender: TObject);
begin
  TfrmSettings.Create(nil).ShowModal;
end;

procedure TfrmMain.imgStartGameMouseDown(Sender: TObject; Button: TMouseButton;
  Shift: TShiftState; X, Y: Integer);
begin
    imgStartGame.Picture := imgStartGameCyan.Picture;
end;

procedure TfrmMain.imgStartGameMouseUp(Sender: TObject; Button: TMouseButton;
  Shift: TShiftState; X, Y: Integer);
begin
  imgStartGame.Picture := imgStartGameYellow.Picture;
end;

procedure TfrmMain.imgWindowModeClick(Sender: TObject);
begin
  if config.WindowMode = 0 then begin  // window mode
    config.WindowMode := 1;
    imgWindowMode.Picture := imgWindowModeON.Picture;
    imgWindowMode.Hint := imgWindowModeON.Hint;
  end
  else begin
    config.WindowMode := 0;
    imgWindowMode.Picture := imgWindowModeOFF.Picture;
    imgWindowMode.Hint := imgWindowModeOFF.Hint;
  end;
  SetRegKey('WindowMode', config.WindowMode);
end;

procedure TfrmMain.imgWindowModeMouseEnter(Sender: TObject);
begin
  if config.WindowMode = 0 then imgWindowMode.Picture := imgWindowModeON.Picture;
end;

procedure TfrmMain.imgWindowModeMouseLeave(Sender: TObject);
begin
  if config.WindowMode = 0 then imgWindowMode.Picture := imgWindowModeOFF.Picture;
end;

procedure TfrmMain.lblpbstatusstringDblClick(Sender: TObject);
begin
  frmDebugLog.Show;
end;

Procedure Tfrmmain.updatertimer(sender: tobject);
Begin
  updater.Enabled := false;
  CheckForUpdates();
end;

procedure TfrmMain.DownloadTerminated(Sender: TObject);
begin
  ThreadDone := true;
end;

{ DONE : Check for updates }
Procedure TfrmMain.CheckForUpdates();
var
  status : boolean;
  msg, fn, wzurl : string;
  jd : TJSONData;
  i, wzlast : integer;
  htdl : THTTPDownload;
  htgs : THTGetSize;

Begin
  try
	   InitUpdateIndicators(false);

	   wzlast := GetConfig('GENERAL', 'last', 0);
	   //showmessage('wzlast ' + inttostr(wzlast));
	   if wzlast < 1 then
	      wzlast := 1 // if our last update counter is less than 1 then set it to 1
	   else
	     wzlast := wzlast + 1; // else add +1

	   if GetConfig('GENERAL','debug',false) then wzlast := 1; // testing mode

	   //showmessage('wzlast ' + inttostr(wzlast));
	   wzurl := wz_update_server + inttostr(wzlast);

      //msg := 'Downloading update list . . .';
      //StatusUpdate(msg);
      //AddLog(msg);


      htdl := THTTPDownload.Create(wzurl, '', true);
      Application.ProcessMessages;

      htdl.OnTerminate:= @DownloadTerminated;
      htdl.Start;

     // download update list
     while(not ThreadDone) do begin
       Application.ProcessMessages;
     end;

     if assigned(htdl.StreamData) then begin
       jd := GetJSON(htdl.StreamData.DataString);
       AddLog('Update List: ' + htdl.StreamData.DataString);
     End;
     status := htdl.Success;

     //htdl.Free;

      if (not assigned(jd)) or (not status) then begin
        InitUpdateIndicators(false);
        msg := 'Unable to get json data!';
        AddLog(msg);
      end else begin

        if (jd.JSONType = jtArray) OR (jd.JSONType = jtObject) then  begin

          for i := 0 to jd.Count - 1 do begin

            updatecount := wzlast + jd.Count - 1;
            updatecurrent := wzlast + i;
            // Error message received from server
            if UpperCase(TJSONObject(jd).Names[0]) = 'ERROR' then begin
              InitUpdateIndicators(false);
              msg := TJSONString(jd.Items[0]).Value;
              break;
            end;

            // we need to check if the header is equal to our wzlast (last update + 1)
            if not (TJSONObject(jd).Names[0] = inttostr(wzlast)) then begin
              InitUpdateIndicators(false);
              msg := 'Invalid download header!';
              break;
            end;

            status := false; // reset checker

            InitUpdateIndicators(true);

            wzurl := TJSONString(jd.Items[i]).Value; // remote url

            fn := inttostr(wzlast+i) + '.wz'; // local file name

            //msg := 'Reading download size of update ' + inttostr(wzlast+i);
            //StatusUpdate(msg);
            //AddLog(msg);
            // Get the download size for progress bar
            ThreadDone := false;
            htgs := THTGetSize.Create(wzurl);
            Application.ProcessMessages;
              htgs.OnTerminate := @DownloadTerminated;
              htgs.Start;

              while(not ThreadDone) do begin
                application.ProcessMessages;
              End;

              TotalBytes := htgs.TotalBytesX;

              //htgs.Free;

            //End;

            if TotalBytes < 1 then begin
              //msg := 'Failed to get download size.';
              break;
            end;

            //msg := 'Downloading update ';
            //msg := msg + inttostr(wzlast + i);
            //msg := msg + ' of ';
            //msg := msg + inttostr(wzlast + jd.Count - 1);
            //msg := msg + ' . . .';
            //StatusUpdate(msg);
            //AddLog(msg);

            ThreadDone := false;

            htdl := THTTPDownload.Create(wzurl,fn,false);// do begin
            Application.ProcessMessages;
              htdl.OnTerminate := @DownloadTerminated;
              htdl.Start;

              while(not ThreadDone) do begin
                Application.ProcessMessages;
              end;

              status := htdl.Success;

              //Terminate;
              //htdl.Free;
            //End;

            if status then begin
              msg := 'Applying update ';
              msg := msg + inttostr(wzlast + i);
              msg := msg + ' of ';
              msg := msg + inttostr(wzlast + jd.Count - 1);
              msg := msg + ' . . .';
              StatusUpdate(msg);
              AddLog(msg);

              //htdl.Free;

              // This is where the patch gets decompressed
              if PatchClient(fn,GetConfig('GENERAL','debug',false)) then begin
                deletefile(fn);
                SetConfig('GENERAL','last', wzlast + i);
                msg := 'Done.';
                StatusUpdate(msg);
                AddLog(msg);
              end else begin
                msg := 'Failed to apply update ' + inttostr(wzlast + i) + '!';
                AddLog(msg);
                break;
              end;
              adsimage := GetImagePath('GENERAL','adsimage','ads.png');
              if FileExists(adsimage) then imgAds.Picture.LoadFromFile(adsimage);
            end else begin
              //msg := 'Failed to download upate.';
              break;
            end;
          end;
          End;
        End;
    Except
    end;
  if assigned(jd) then FreeAndNil(jd);
  if assigned(htdl) then begin
    //htdl.FreeOnTerminate := true;
    //htdl.Terminate;
    //FreeAndNil(htdl);
	End;
	if assigned(htgs) then begin
    //htgs.FreeOnTerminate := true;
    //htgs.Terminate;
    //FreeAndNil(htgs);
  end;
  selfcheck; // checks if mu.new exists then reload launcher
  if not status then InitUpdateIndicators(false);
  StartGameEx(msg); // let's do it!
end;

{TODO: Init update indicators}
procedure TfrmMain.InitUpdateIndicators(const v : boolean);
begin
  imgStartGame.Enabled := false;
  imgpb.AutoSize := false;
  imgpb.Width := 0;
  imgpb.Visible := false;
  lblpbpercentstring.Caption := '0%';
  lblpbpercentstring.Visible := percentstringvisible or v;
  updater.Enabled := false;
  TotalBytes := 0;
  CurrentBytes := 0;
  ThreadDone := false;
  AddLog('Update indicators has been set.');
End;


{ DONE : Starts the Game }
procedure TfrmMain.StartGameEx(const msg: string);
begin
  if Length(msg) > 0 then StatusUpdate(msg);
  imgStartGame.Picture := imgStartGameYellow.Picture;
  imgStartGame.Enabled := True;
  lblpbpercentstring.Visible := false;
  AddLog('Play button enabled.');
end;

{ DONE : Load skin }
procedure TfrmMain.LoadSkin;
var
  imgpath : string;

begin
  Addlog('Initializing skin...');
  // main form background images
  mainbga := GetImagePath('GENERAL', 'mainbga', 'bg.bmp');
  if not FileExists(mainbga) then exit;
  mainbgb := GetImagePath('GENERAL', 'mainbgb', 'bg.png');
  if not FileExists(mainbgb) then exit;
  imgBG.AutoSize := true;
  imgBG.Picture.LoadFromFile(mainbgb);
  imgBG.Left := 0;
  imgBG.Top := 0;

  // form window buttons
  CloseOff := GetImagePath('GENERAL', 'btnclosea', 'closeoff.png');
  CloseOn := GetImagePath('GENERAL', 'btncloseb', 'closeon.png');
  if FileExists(CloseOn) then imgCloseOn.Picture.LoadFromFile(CloseOn);
  if FileExists(CloseOff) then imgCloseOff.Picture.LoadFromFile(CloseOff);
  imgClose.Picture := imgCloseOff.Picture;
  imgClose.Left := GetSkinPos('GENERAL', 'btncloseposx', 0);
  imgClose.Top := GetSkinPos('GENERAL', 'btncloseposy', 0);

  SettingsOff := GetImagePath('GENERAL', 'btnsettingsa', 'settingsoff.png');
  SettingsOn := GetImagePath('GENERAL', 'btnsettingsb', 'settingson.png');
  if FileExists(SettingsOn) then imgSettingsOn.Picture.LoadFromFile(SettingsOn);
  if FileExists(SettingsOff) then imgSettingsOff.Picture.LoadFromFile(SettingsOff);
  imgSettings.Picture := imgSettingsOff.Picture;
  imgSettings.Left := GetSkinPos('GENERAL', 'btnsettingsposx', 0);
  imgSettings.Top := GetSkinPos('GENERAL', 'btnsettingsposy', 0);

  WindowModeOff := GetImagePath('GENERAL', 'btnwma', 'wmoff.png');
  WindowModeOn := GetImagePath('GENERAL', 'btnwmb', 'wmon.png');
  if FileExists(WindowModeOn) then imgWindowModeOn.Picture.LoadFromFile(WindowModeOn);
  if FileExists(WindowModeOff) then imgWindowModeOff.Picture.LoadFromFile(WindowModeOff);
  imgWindowMode.Picture := imgWindowModeOff.Picture;
  imgWindowMode.Left := GetSkinPos('GENERAL', 'btnwmposx', 0);
  imgWindowMode.Top := GetSkinPos('GENERAL', 'btnwmposy', 0);

  lblpbstatusstring.Visible := GetSkinInfo('UPDATER', 'pbstatusstringvisible', false);
  lblpbstatusstring.Left := GetSkinPos('UPDATER', 'pbstatusstringposx', 0);
  lblpbstatusstring.Top := GetSkinPos('UPDATER', 'pbstatusstringposy', 0);

  percentstringvisible := GetSkinInfo('UPDATER', 'pbstatusstringvisible', false);
  lblpbpercentstring.Left := GetSkinPos('UPDATER', 'pbpercentstringposx', 0);
  lblpbpercentstring.Top := GetSkinPos('UPDATER', 'pbpercentstringposy', 0);

  // ads
  adsimage := GetImagePath('ADVERTS', 'adsimage', 'ads.png');
  imgAds.AutoSize := true;
  imgAds.Top := 0;
  imgAds.Left := 0;
  if FileExists(adsimage) then imgAds.Picture.LoadFromFile(adsimage);

  // start button
  startgameyellow := GetImagePath('BTNSTARTGAME', 'startgameyellow', 'startgameyellow.png');
  startgamecyan := GetImagePath('BTNSTARTGAME', 'startgamecyan', 'startgamecyan.png');
  startgamegray := GetImagePath('BTNSTARTGAME', 'startgamegray', 'startgamegray.png');

  if FileExists(startgameyellow) then imgStartGameYellow.Picture.LoadFromFile(startgameyellow);
  if FileExists(startgamecyan) then imgStartGameCyan.Picture.LoadFromFile(startgamecyan);
  if FileExists(startgamegray) then imgStartGameGray.Picture.LoadFromFile(startgamegray);

  imgStartGame.Picture := imgStartGameGray.Picture;
  imgStartGame.Left := GetSkinPos('BTNSTARTGAME', 'posx', 0);
  imgStartGame.Top := GetSkinPos('BTNSTARTGAME', 'posy', 0);

  imgpath := GetImagePath('UPDATER','pbimagebg','pbbg.png');
  if FileExists(imgpath) then imgpbbg.Picture.LoadFromFile(imgpath);
  imgpbbg.Visible := GetSkinInfo('UPDATER', 'usepbimage', false);
  imgpbbg.Width := GetSkinInfo('UPDATER', 'pbwidth', 0);
  imgpbbg.Left := GetSkinPos('UPDATER', 'pbposx', 0);
  imgpbbg.Top := GetSkinPos('UPDATER', 'pbposy', 0);

  imgpath := GetImagePath('UPDATER','pbimage','pbyellow.png');
  if FileExists(imgpath) then imgpb.Picture.LoadFromFile(imgpath);
  //imgpb.Visible := GetSkinInfo('UPDATER', 'usepbimage', false);
  imgpb.Width := GetSkinInfo('UPDATER', 'pbwidth', 0);
  pbwidth := imgpb.Width;
  imgpb.Left := GetSkinPos('UPDATER', 'pbposx', 0);
  imgpb.Top := GetSkinPos('UPDATER', 'pbposy', 0);
  imgpb.Visible := false;
End;

{ DONE : Get and set registry entries }
procedure TfrmMain.LoadRegistrySettings;
begin
  CreateDefaultMuRegEntry; // creates default mu settings in registry if it did not exist yet
  config.WindowMode := GetRegKeyInt('WindowMode');
  if config.WindowMode = 1 then begin
    imgWindowMode.Picture := imgWindowModeON.Picture;
    imgWindowMode.Hint := imgWindowModeON.Hint;
  end else begin
    imgWindowMode.Picture := imgWindowModeOFF.Picture;
    imgWindowMode.Hint := imgWindowModeOFF.Hint;
  End;
end;

end.

