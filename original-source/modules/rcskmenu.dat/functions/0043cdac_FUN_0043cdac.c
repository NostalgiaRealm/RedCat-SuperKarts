/*
 * FUN_0043cdac at 0043cdac
 * undefined FUN_0043cdac(void)
 * Address ranges: 0043cdac-0043ce72;0043ce92-0043ce98
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043cdac(undefined4 param_1,int *param_2)

{
  int iVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_24;
  undefined *puStack_20;
  undefined1 *puStack_1c;
  tagPOINT tStack_c;
  
  puStack_1c = &stack0xfffffffc;
  puStack_20 = &DAT_0043ce73;
  uStack_24 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_24;
  iVar1 = *param_2;
  if (iVar1 < 0x216) {
    if (iVar1 == 0x215) {
      puStack_1c = &stack0xfffffffc;
      FUN_0043de04('\0');
    }
    else if (iVar1 == 0x200) {
      puStack_1c = &stack0xfffffffc;
      FUN_00406c20(param_2[2],&tStack_c.x);
      ClientToScreen(DAT_0047d7c4,&tStack_c);
      FUN_0043d788(&tStack_c);
    }
    else if ((iVar1 == 0x202) || (iVar1 == 0x205)) {
      puStack_1c = &stack0xfffffffc;
      FUN_0043de04('\x01');
    }
  }
  else if (iVar1 == 0xbd00) {
    if (param_2[1] == 0x11) {
      FUN_0043d788((POINT *)(DAT_0047d7bc + 0xc));
    }
    else if (param_2[1] == 0x1b) {
      param_2[3] = 1;
      puStack_1c = &stack0xfffffffc;
      FUN_0043de04('\0');
    }
  }
  else if ((iVar1 == 0xbd01) && (param_2[1] == 0x11)) {
    puStack_1c = &stack0xfffffffc;
    FUN_0043d788((POINT *)(DAT_0047d7bc + 0xc));
  }
  *in_FS_OFFSET = uStack_24;
  return;
}

