/*
 * FUN_004599c0 at 004599c0
 * undefined FUN_004599c0(void)
 * Address ranges: 004599c0-004599e9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004599c0(int param_1)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  
  puVar1 = *(undefined1 **)(param_1 + 4);
  if (puVar1 == (undefined1 *)0x0) {
    puVar1 = &DAT_004d2404;
  }
  uVar2 = FUN_004a6200(puVar1);
  FUN_004599f0(uVar2);
  return;
}

