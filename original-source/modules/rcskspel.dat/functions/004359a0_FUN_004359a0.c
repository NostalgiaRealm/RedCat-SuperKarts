/*
 * FUN_004359a0 at 004359a0
 * undefined FUN_004359a0(void)
 * Address ranges: 004359a0-00435a04
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_004359a0(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  
  uVar2 = FUN_0040c970();
  switch(uVar2) {
  default:
    cVar1 = FUN_00412390(DAT_00508610,param_1);
    break;
  case 2:
    cVar1 = FUN_004358c0();
    break;
  case 4:
    cVar1 = FUN_00412280(DAT_00508610,param_1);
    break;
  case 5:
    cVar1 = FUN_004358d0();
    break;
  case 6:
    cVar1 = FUN_00412560(DAT_00508610,param_1);
  }
  if (cVar1 == '\0') {
    *(undefined1 *)(param_1 + 0x11c) = 0;
  }
  return;
}

