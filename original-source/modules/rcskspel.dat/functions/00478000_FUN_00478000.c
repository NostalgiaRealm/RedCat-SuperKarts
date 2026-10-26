/*
 * FUN_00478000 at 00478000
 * undefined FUN_00478000(void)
 * Address ranges: 00478000-0047806c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00478000(int *param_1)

{
  int iVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  
  iVar1 = param_1[1];
  if (iVar1 != *param_1) {
    if (iVar1 == 3) {
      FUN_00473460();
      FUN_004736b0();
      return;
    }
    if ((iVar1 == 1) || (iVar1 == 0)) {
      puVar2 = DAT_00544e2c;
      if (DAT_00544e2c == (undefined1 *)0x0) {
        puVar2 = &DAT_004d2404;
      }
      FUN_004b1d60(puVar2);
      puVar2 = &DAT_004d2404;
      if (DAT_00544e0c != (undefined1 *)0x0) {
        puVar2 = DAT_00544e0c;
      }
      puVar3 = DAT_00544e1c;
      if (DAT_00544e1c == (undefined1 *)0x0) {
        puVar3 = &DAT_004d2404;
      }
      FUN_004b1e70(puVar3,puVar2,param_1[1]);
    }
  }
  return;
}

