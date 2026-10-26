/*
 * FUN_004176e4 at 004176e4
 * undefined __register FUN_004176e4(int param_1)
 * Address ranges: 004176e4-00417844;0041784c-0041786c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004176e4(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  HFONT pHVar3;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_6c;
  undefined1 *puStack_68;
  undefined1 *puStack_64;
  undefined4 uStack_60;
  undefined1 *puStack_5c;
  undefined1 *puStack_58;
  undefined *local_50;
  undefined *local_4c;
  undefined *local_48;
  LOGFONTA local_44;
  int local_8;
  
  puStack_58 = &stack0xfffffffc;
  local_50 = (undefined *)0x0;
  local_4c = (undefined *)0x0;
  local_48 = (undefined *)0x0;
  puStack_5c = &LAB_0041786d;
  uStack_60 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_60;
  local_8 = *(int *)(param_1 + 0x10);
  if (*(int *)(local_8 + 8) == 0) {
    puStack_64 = (undefined1 *)0x417723;
    FUN_00416b10(DAT_0047d6c8);
    puStack_68 = &LAB_00417845;
    uStack_6c = *in_FS_OFFSET;
    *in_FS_OFFSET = &uStack_6c;
    if (*(int *)(local_8 + 8) == 0) {
      local_44.lfHeight = *(LONG *)(local_8 + 0x14);
      local_44.lfWidth = 0;
      local_44.lfEscapement = 0;
      local_44.lfOrientation = 0;
      if ((*(byte *)(local_8 + 0x19) & 1) == 0) {
        local_44.lfWeight = 400;
      }
      else {
        local_44.lfWeight = 700;
      }
      local_44.lfItalic = (*(byte *)(local_8 + 0x19) & 2) != 0;
      local_44.lfUnderline = (*(byte *)(local_8 + 0x19) & 4) != 0;
      local_44.lfStrikeOut = (*(byte *)(local_8 + 0x19) & 8) != 0;
      local_44.lfCharSet = *(BYTE *)(local_8 + 0x1a);
      puStack_64 = &stack0xfffffffc;
      FUN_00403d74((int *)&local_48,(byte *)(local_8 + 0x1b));
      iVar1 = FUN_00407db0(local_48,"Default");
      if (iVar1 == 0) {
        FUN_00403d74((int *)&local_4c,(byte *)s_MS_Sans_Serif_0047b37f);
        FUN_00408404(local_44.lfFaceName,local_4c);
      }
      else {
        FUN_00403d74((int *)&local_50,(byte *)(local_8 + 0x1b));
        FUN_00408404(local_44.lfFaceName,local_50);
      }
      local_44.lfQuality = '\0';
      local_44.lfOutPrecision = '\0';
      local_44.lfClipPrecision = '\0';
      uVar2 = FUN_004179c8(param_1);
      if ((char)uVar2 == '\x01') {
        local_44.lfPitchAndFamily = '\x02';
      }
      else if ((char)uVar2 == '\x02') {
        local_44.lfPitchAndFamily = '\x01';
      }
      else {
        local_44.lfPitchAndFamily = '\0';
      }
      pHVar3 = CreateFontIndirectA(&local_44);
      *(HFONT *)(local_8 + 8) = pHVar3;
    }
    *in_FS_OFFSET = uStack_6c;
    puStack_64 = (undefined1 *)0x41784c;
    puStack_68 = (undefined1 *)0x417844;
    FUN_00416b1c(DAT_0047d6c8);
    return;
  }
  *in_FS_OFFSET = uStack_60;
  puStack_58 = &LAB_00417874;
  puStack_5c = (undefined1 *)0x41786c;
  FUN_00403b74((int *)&local_50,3);
  return;
}

