/*
 * FUN_00424a0b at 00424a0b
 * undefined __stdcall FUN_00424a0b(void)
 * Address ranges: 00424a0b-00424a33
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00424a0b(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_0043e6e0;
  for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined1 *)puVar2 = 0;
  DAT_0043e5bc = 0;
  DAT_0043e5cc = 0;
  DAT_0043e7e4 = 0;
  DAT_0043e5c0 = 0;
  DAT_0043e5c4 = 0;
  DAT_0043e5c8 = 0;
  return;
}

