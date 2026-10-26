/*
 * FUN_0040505b at 0040505b
 * undefined __stdcall FUN_0040505b(void)
 * Address ranges: 0040505b-00405083
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040505b(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_00408ee0;
  for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined1 *)puVar2 = 0;
  DAT_00408db8 = 0;
  DAT_00408dcc = 0;
  DAT_00408fe4 = 0;
  DAT_00408dc0 = 0;
  DAT_00408dc4 = 0;
  DAT_00408dc8 = 0;
  return;
}

