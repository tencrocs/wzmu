Unit settingsui;

{$mode objfpc}{$H+}

Interface

Uses
  classes, sysutils, fileutil, forms, controls, graphics, dialogs, ExtCtrls,
  StdCtrls, wz_misc;

Type

  { TfrmSettings }

  TfrmSettings = Class(tform)
    cmbLanguage: tcombobox;
    edtid: tedit;
    imgcancel: timage;
    imgcancel1: timage;
    imgcancel2: timage;
    imgchecked: timage;
    imgconfig1: timage;
    imgconfig2: timage;
    imgconfig3: timage;
    imgconfig4: timage;
    imgconfig5: timage;
    imgconfig6: timage;
    imgconfig7: timage;
    imgsave: timage;
    imgsave1: timage;
    imgsave2: timage;
    imgsettingsbg: timage;
    imgunchecked: timage;
    Procedure edtidchange(sender: tobject);
    Procedure formclick(sender: tobject);
    Procedure formcreate(sender: tobject);
    Procedure imgcancelclick(sender: tobject);
    Procedure imgconfig1click(sender: tobject);
    Procedure imgconfig2click(sender: tobject);
    Procedure imgconfig3click(sender: tobject);
    Procedure imgconfig4click(sender: tobject);
    Procedure imgconfig5click(sender: tobject);
    Procedure imgconfig6click(sender: tobject);
    Procedure imgconfig7click(sender: tobject);
    Procedure imgsaveclick(sender: tobject);
    Procedure imgsettingsbgmousedown(sender: tobject; button: tmousebutton;
      shift: tshiftstate; x, y: integer);
    Procedure imgsettingsbgmousemove(sender: tobject; shift: tshiftstate; x,
      y: integer);
  Private
    { private declarations }
    Procedure GetReg;
  Public
    { public declarations }
  End;

Var
  frmSettings: TfrmSettings;
  xx,yy: integer;

Implementation

{$R *.lfm}

{ TfrmSettings }

Procedure tfrmsettings.imgsaveclick(sender: tobject);
Begin
  // resolution
  SetRegKey('Resolution', config.Resolution);
  // color depth
  SetRegKey('ColorDepth',config.ColorDepth);
  // sound effect
  SetRegKey('SoundOnOff',config.SoundEffect);
  // music
  SetRegKey('MusicOnOff',config.Music);
  // ID
  SetRegKey('ID',config.Username);

  //imgWindowMode.Enabled := true;
  //imgSettings.Enabled := true;
  //imgClose.Enabled := true;
  //imgStartGame.Enabled := true;

  Close;
end;

Procedure tfrmsettings.imgsettingsbgmousedown(sender: tobject;
  button: tmousebutton; shift: tshiftstate; x, y: integer);
Begin
  xx := x;
  yy := y;
end;

Procedure tfrmsettings.imgsettingsbgmousemove(sender: tobject;
  shift: tshiftstate; x, y: integer);
Begin
  if ssleft in Shift then
  begin
    top := top + y - yy;
    left := left + x - xx;
  end;
end;

Procedure tfrmsettings.imgcancelclick(sender: tobject);
Begin
  //pnlSettings.Hide;
  //imgWindowMode.Enabled := true;
  //imgSettings.Enabled := true;
  //imgStartGame.Enabled := true;
  //imgClose.Enabled := true;
  Close;
end;

Procedure tfrmsettings.formclick(sender: tobject);
Begin
  if config.Music = 0 then begin     // background music
    config.Music := 1;
    imgConfig7.Picture := imgChecked.Picture;
  end
  else begin
    config.Music := 0;
    imgConfig7.Picture := imgUnchecked.Picture;
  end;
end;

Procedure tfrmsettings.edtidchange(sender: tobject);
Begin
  config.Username := trim(edtID.Text);
end;

Procedure tfrmsettings.formcreate(sender: tobject);
Begin
  Width := imgSettingsBG.Width;
  Height := imgSettingsBG.Height;
  cmbLanguage.Items.Add('English');
  cmbLanguage.ItemIndex := 1;
  cmbLanguage.Text := 'English';
  GetReg;
end;

Procedure tfrmsettings.imgconfig1click(sender: tobject);
Begin
  config.Resolution := 1;  // 800x800 resolution
  imgConfig1.Picture := imgChecked.Picture;
  imgConfig2.Picture := imgunchecked.Picture;
  imgConfig3.Picture := imgunchecked.Picture;
end;

Procedure tfrmsettings.imgconfig2click(sender: tobject);
Begin
  config.Resolution := 2; //1024x768
  imgConfig1.Picture := imgunchecked.Picture;
  imgConfig2.Picture := imgChecked.Picture;
  imgConfig3.Picture := imgunchecked.Picture;
end;

Procedure tfrmsettings.imgconfig3click(sender: tobject);
Begin
  config.Resolution := 3;  //1280x1024
  imgConfig1.Picture := imgunchecked.Picture;
  imgConfig2.Picture := imgunchecked.Picture;
  imgConfig3.Picture := imgChecked.Picture;
end;

Procedure tfrmsettings.imgconfig4click(sender: tobject);
Begin
  config.ColorDepth := 0; //min color 16bit
  imgConfig4.Picture := imgChecked.Picture;
  imgConfig5.Picture := imgUnchecked.Picture;
end;

Procedure tfrmsettings.imgconfig5click(sender: tobject);
Begin
  config.ColorDepth := 1; //max color 32bit
  imgConfig4.Picture := imgUnchecked.Picture;
  imgConfig5.Picture := imgChecked.Picture;
end;

Procedure tfrmsettings.imgconfig6click(sender: tobject);
Begin
  if config.SoundEffect = 0 then begin  //sound effect
    config.SoundEffect := 1;
    imgConfig6.Picture := imgChecked.Picture;
  end
  else begin
    config.SoundEffect := 0;
    imgConfig6.Picture := imgUnchecked.Picture;
  end;
end;

Procedure tfrmsettings.imgconfig7click(sender: tobject);
Begin
  if config.Music = 0 then begin  //music
    config.Music := 1;
    imgConfig7.Picture := imgChecked.Picture;
  end
  else begin
    config.Music := 0;
    imgConfig7.Picture := imgUnchecked.Picture;
  end;
end;

{-----------------------------------
 Get registry entries
------------------------------------}
procedure TfrmSettings.GetReg;
begin
  config.Resolution := GetRegKeyInt('Resolution');
  config.ColorDepth := GetRegKeyInt('ColorDepth');
  config.SoundEffect := GetRegKeyInt('SoundOnOff');
  config.Music := GetRegKeyInt('MusicOnOff');
  config.Username := GetRegKeyStr('ID');

  imgConfig1.Picture := imgUnchecked.Picture;
  imgConfig2.Picture := imgUnchecked.Picture;
  imgConfig3.Picture := imgUnchecked.Picture;
  imgConfig4.Picture := imgUnchecked.Picture;
  imgConfig5.Picture := imgUnchecked.Picture;
  imgConfig6.Picture := imgUnchecked.Picture;
  imgConfig7.Picture := imgUnchecked.Picture;

  case config.Resolution  of  // resolution
     1: imgConfig1.Picture := imgChecked.Picture;
     2: imgConfig2.Picture := imgChecked.Picture;
     3: imgConfig3.Picture := imgChecked.Picture;
  else
    imgConfig1.Picture := imgChecked.Picture;
  End;

  if config.ColorDepth = 0 then
     imgConfig4.Picture := imgChecked.Picture
  else
    imgConfig5.Picture := imgChecked.Picture;

  if config.SoundEffect = 1 then imgConfig6.Picture := imgChecked.Picture;

  if config.Music = 1 then imgConfig7.Picture := imgChecked.Picture;

  edtID.Text := config.Username;

end;

End.

