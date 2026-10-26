/*
 * FUN_004310b8 at 004310b8
 * undefined FUN_004310b8(void)
 * Address ranges: 004310b8-00431194
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004310b8(int *param_1,char param_2)

{
  int *piVar1;
  undefined4 extraout_ECX;
  byte extraout_DL;
  undefined4 extraout_EDX;
  
  piVar1 = FUN_0040320c(param_1,param_2);
  if ((HMODULE)0x20 < (HMODULE)piVar1[0x24]) {
    FreeLibrary((HMODULE)piVar1[0x24]);
  }
  if (((piVar1[9] != 0) && ((char)piVar1[0x25] != '\0')) && (piVar1[0x10] != 0)) {
    FUN_00432854();
  }
  *(undefined1 *)((int)piVar1 + 0x8d) = 0;
  FUN_00432e8c((int)piVar1);
  FUN_0043286c((int)piVar1,'\0');
  FUN_004147c4(piVar1,extraout_DL & 0xfc);
  FUN_00432280((int)piVar1,extraout_EDX,extraout_ECX,0x43155c,(int)piVar1);
  if (((HWND)piVar1[9] != (HWND)0x0) && ((char)piVar1[0x25] != '\0')) {
    if (*PTR_DAT_0047c7a0 != '\0') {
      SendMessageA((HWND)piVar1[9],0x80,1,0);
    }
    DestroyWindow((HWND)piVar1[9]);
  }
  if (piVar1[0xd] != 0) {
    FUN_00429670(piVar1[0xd]);
  }
  FUN_00402eac((int *)piVar1[0x26]);
  FUN_00402eac((int *)piVar1[0x20]);
  FUN_00402eac((int *)piVar1[0x22]);
  if ('\0' < (char)extraout_DL) {
    FUN_004031fc(piVar1);
  }
  return;
}

