Unit wz_misc;

{$mode objfpc}{$H+}
{$DEFINE DEBUG_OFF}

Interface

Uses
  classes, sysutils, dialogs, Forms,
  // For opening ini files
  INIFiles,
  // For decompression routine
  Zipper,
  // For windows registry access
  Registry;

type

  TWZConfig = record
    // integers
    ColorDepth, // Options: 0 - 16bit, 1 - 32bit
    Resolution, // Options: 0 - 640 x 480 / 1 - 800 x 600 / 2 - 1024 x 768 / 3 - 1280 x 1024
    SoundEffect, // Options: 0 - off, 1 - on
    Music, // Options: 0 - off, 1 - on
    WindowMode // Options: 0 - off, 1 - on
    : integer;

    // strings
    Username, // Account ID of player
    Language, // Default language
    MuExe // Mu.exe executable path
    : string;
  end;

const
  wzkey = '\Software\Webzen\Mu\Config';
  default_path = 'data\launcher\';
  wz_settings_ini = 'settings.ini';
  wz_update_server = 'http://updates.warzonemu.com/?id=';
  wzexe = 'Main.exe';

var
  config : TWZConfig;

procedure CreateDefaultMuRegEntry();
function PatchClient(const fn : string; const debug : boolean): Boolean;
function PatchClient(const fnpath, fn : string; const debug : boolean): Boolean;
function SetRegKey(const cfg: string; const value: string): Boolean;
function SetRegKey(const cfg: string; const value: integer): Boolean;
function GetRegKeyStr(const skey : string): String;
function GetRegKeyInt(const skey : string): Integer;
function GetIni(const fn, section, key : string; const default : Boolean) : Boolean;
function GetIni(const fn, section, key : string; const default : integer) : Integer;
function GetIni(const fn, section, key, default : string) : String;
procedure SetIni(const fn, section, key : string; const value : integer);
procedure SetIni(const fn, section, key, value : string);
procedure SetIni(const fn, section, key : string; const value : boolean);
function GetSkinInfo(const section, key : string; const default : integer) : Integer;
function GetSkinInfo(const section, key : string; const default : boolean) : Boolean;
function GetSkinInfo(const section, key, default : string) : String;
function GetImagePath(const section, key, default : string) : String;
function GetSkinPos(const section, key : string; const default : integer) : integer;
function GetSkinPath : string;
function GetSkinINI : string;
function GetConfig(const section, key, default : string) : string;
function GetConfig(const section, key : string; const default : integer) : integer;
function GetConfig(const section, key : string; const default : boolean) : boolean;
procedure SetConfig(const section, key : string; const value : boolean);
procedure SetConfig(const section, key : string; const value : integer);
procedure SetConfig(const section, key, value : string);
function FormatByteSize(const bytes: Longword): string;

Implementation

function FormatByteSize(const bytes: Longword): string;
var
  B: byte;
  KB: word;
  MB: Longword;
  GB: Longword;
  TB: UInt64;
begin

  B  := 1; //byte
  KB := 1024 * B; //kilobyte
  MB := 1000 * KB; //megabyte
  GB := 1000 * MB; //gigabyte
  ///TB := 1000 * GB; //terabyte

  //if bytes > TB then
  //  result := FormatFloat('#.## TB', bytes / TB)
 // else
    if bytes > GB then
      result := FormatFloat('#.## GB', bytes / GB)
    else
      if bytes > MB then
        result := FormatFloat('#.## MB', bytes / MB)
      else
        if bytes > KB then
          result := FormatFloat('#.## KB', bytes / KB)
        else
          result := FormatFloat('#.## bytes', bytes) ;
end;

function GetConfig(const section, key, default : string) : string;
begin
  result := GetIni(default_path + '\' + wz_settings_ini, section, key, default);
End;

function GetConfig(const section, key : string; const default : integer) : integer;
begin
  result := GetIni(default_path + '\' + wz_settings_ini, section, key, default);
End;

function GetConfig(const section, key : string; const default : boolean) : boolean;
begin
  result := GetIni(default_path + '\' + wz_settings_ini, section, key, default);
End;

procedure SetConfig(const section, key, value : string);
begin
  SetIni(default_path + '\' + wz_settings_ini, section, key, value);
End;

procedure SetConfig(const section, key : string; const value : integer);
begin
  SetIni(default_path + '\' + wz_settings_ini, section, key, value);
End;

procedure SetConfig(const section, key : string; const value : boolean);
begin
  SetIni(default_path + '\' + wz_settings_ini, section, key, value);
End;

function GetIni(const fn, section, key : string; const default : Boolean) : Boolean;
begin
  with TINIFile.Create(fn) do begin
       result := ReadBool(section, key, default);
  End;
End;

function GetIni(const fn, section, key : string; const default : integer) : Integer;
begin
  with TINIFile.Create(fn) do begin
       result := ReadInteger(section, key, default);
  End;
End;

function GetIni(const fn, section, key, default : string) : String;
begin
  with TINIFile.Create(fn) do begin
       result := ReadString(section, key, default);
  End;
End;

procedure SetIni(const fn, section, key : string; const value : boolean);
begin
  with TINIFile.Create(fn) do begin
       WriteBool(section, key, value);
       Free;
  End;
End;

procedure SetIni(const fn, section, key : string; const value : integer);
begin
  with TINIFile.Create(fn) do begin
       WriteInteger(section, key, value);
       Free;
  End;
End;

procedure SetIni(const fn, section, key, value : string);
begin
  with TINIFile.Create(fn) do begin
       WriteString(section, key, value);
       Free;
  End;
End;

function GetSkinInfo(const section, key : string; const default : boolean) : Boolean;
begin
  result := GetIni(GetSkinINI, section, key, default);
  {$ifdef DEBUG_ON}showmessage('GetSkinInfo('+section+','+key+','+booltostr(default)+') => ' + booltostr(result));{$ENDIF}
End;

function GetSkinInfo(const section, key : string; const default : integer) : Integer;
begin
  result := GetIni(GetSkinINI, section, key, default);
  {$ifdef DEBUG_ON}showmessage('GetSkinInfo('+section+','+key+','+inttostr(default)+') => ' + inttostr(result));{$ENDIF}
End;

function GetSkinInfo(const section, key, default : string) : String;
begin
  result := GetIni(GetSkinINI, section, key, default);
  {$ifdef DEBUG_ON}showmessage('GetSkinInfo('+section+','+key+','+default+') => ' + result);{$ENDIF}
End;

function GetImagePath(const section, key, default : string) : String;
begin
  result := GetSkinPath + GetIni(GetSkinINI, section, key, default);
  {$ifdef DEBUG_ON}showmessage('GetImagePath('+section+','+key+','+default+') => ' + result);{$ENDIF}
End;

function GetSkinPos(const section, key : string; const default : integer) : integer;
begin
  result := GetSkinInfo(section, key, default);
  {$ifdef DEBUG_ON}showmessage('GetSkinPos('+section+','+key+','+inttostr(default)+') => ' + inttostr(result));{$ENDIF}
End;

function GetSkinPath : string;
begin
  result := default_path + '\' + GetIni(default_path + '\' + wz_settings_ini, 'GENERAL', 'skinpath', 'skins') + '\';
  result := result + GetIni(default_path + '\' + wz_settings_ini, 'GENERAL', 'defaultskin', 'default') + '\';
  {$ifdef DEBUG_ON}showmessage('GetSkinPath => ' + result);{$ENDIF}
End;

function GetSkinINI : string;
begin
  result := default_path + '\' + GetIni(default_path + '\' + wz_settings_ini, 'GENERAL', 'skinpath', 'skins') + '\';
  result := result + GetIni(default_path + '\' + wz_settings_ini, 'GENERAL', 'defaultskin', 'default') + '\';
  result := result + wz_settings_ini;
  {$ifdef DEBUG_ON}showmessage('GetSkinINI => ' + result);{$ENDIF}
End;

{-----------------------------------
 Client Updater (decompress files)
------------------------------------}
function PatchClient(const fn : string; const debug : boolean): Boolean;
begin
  result := PatchClient('', fn, debug);
End;

function PatchClient(const fnpath, fn : string; const debug : boolean): Boolean;
var
  actualpath : string;

begin
  if debug then
    actualpath := application.Location + '\debug\'
  else
    actualpath := fnpath;

  with TUnZipper.Create do
  try
    FileName := fn;
    OutputPath := actualpath;
    Examine;
    UnZipAllFiles;
    result := true;
    Free;
  Except
    result := false;
    Free;
  end;
end;

{-----------------------------------
 Save registry entries
------------------------------------}
// Save string value
function SetRegKey(const cfg: string; const value: string): Boolean;
begin
  with TRegistry.Create do
  try
    RootKey := HKEY_CURRENT_USER;
    if not OpenKey(wzkey, true) then CreateKey(wzkey);
    WriteString(cfg, value);
    result := true;
    free;
  except
    result := false;
    free;
  end;
end;

// Save Integer value
function SetRegKey(const cfg: string; const value: integer): Boolean;
begin
  with TRegistry.Create do
  try
    RootKey := HKEY_CURRENT_USER;
    if not OpenKey(wzkey, true) then CreateKey(wzkey);
    WriteInteger( cfg, value);
    result := true;
    free;
  except
    result := false;
    free;
  end;
end;

{-----------------------------------
 Get registry entries
------------------------------------}
function GetRegKeyStr(const skey : string) : String;
begin
  with TRegistry.Create do
  try
    RootKey := HKEY_CURRENT_USER;
    OpenKey(wzkey, true);
    result := ReadString(skey);
    Free;
  except
    result := '';
    Free;
  end;
end;

function GetRegKeyInt(const skey : string) : Integer;
begin
  with TRegistry.Create do
  try
    RootKey := HKEY_CURRENT_USER;
    OpenKey(wzkey, true);
    result := ReadInteger(skey);
    Free;
  except
    result := 0;
    Free;
  end;
end;

procedure CreateDefaultMuRegEntry();
begin
  // default settings
  config.Resolution := 1; // 800x600
  config.ColorDepth := 1; // 32bit
  config.SoundEffect := 1; // On
  config.Music := 1; // On
  config.WindowMode := 1; // Window mode
  config.Username := '';
  config.Language := 'ENG';

  with TRegistry.Create do begin
    RootKey := HKEY_CURRENT_USER;
    if not OpenKey(wzkey, true) then begin
      // no configuration exists, set default settings
      SetRegKey('Resolution', config.Resolution);
      SetRegKey('ColorDepth', config.ColorDepth);
      SetRegKey('SoundOnOff', config.SoundEffect);
      SetRegKey('MusicOnOff', config.Music);
      SetRegKey('WindowMode', config.WindowMode);
      SetRegKey('ID', config.Username);
      SetRegKey('Lang', config.Language);

    end else begin
      if not ValueExists('Resolution') then SetRegKey('Resolution', config.Resolution);
      if not ValueExists('ColorDepth') then SetRegKey('ColorDepth', config.ColorDepth);
      if not ValueExists('SoundOnOff') then SetRegKey('SoundOnOff', config.SoundEffect);
      if not ValueExists('MusicOnOff') then SetRegKey('MusicOnOff', config.Music);
      if not ValueExists('WindowMode') then SetRegKey('WindowMode', config.WindowMode);
      if not ValueExists('ID') then SetRegKey('ID', config.Username);
      if not ValueExists('Lang') then SetRegKey('Lang', config.Language);
    End;
  End;
End;

End.

