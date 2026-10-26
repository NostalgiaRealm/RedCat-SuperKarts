/*
 * FUN_004441a0 at 004441a0
 * undefined FUN_004441a0(void)
 * Address ranges: 004441a0-00444208
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004441a0(undefined1 *param_1)

{
  char cVar1;
  DWORD DVar2;
  
  if (DAT_0053f4ec == 0) {
    DVar2 = GetTickCount();
    if (999 < DVar2 - _DAT_0053f4f0) {
      DAT_0053f4ec = 1;
    }
  }
  else if (DAT_0053f4ec == 1) {
    cVar1 = FUN_00443f10(param_1);
    if (cVar1 != '\0') {
      DAT_0053f4ec = 2;
      return 0;
    }
  }
  else if (DAT_0053f4ec == 2) {
    cVar1 = FUN_00443ff0(0x3dcccccd);
    if (cVar1 != '\0') {
      *param_1 = 0;
      return 1;
    }
  }
  return 0;
}

