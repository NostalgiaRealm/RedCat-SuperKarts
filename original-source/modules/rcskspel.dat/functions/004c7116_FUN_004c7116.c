/*
 * FUN_004c7116 at 004c7116
 * undefined FUN_004c7116(void)
 * Address ranges: 004c7116-004c713e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004c7116(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_006b6c80;
  for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined1 *)puVar2 = 0;
  DAT_006b6b64 = 0;
  DAT_006b6b7c = 0;
  DAT_006b6d84 = 0;
  DAT_006b6b70 = 0;
  DAT_006b6b74 = 0;
  DAT_006b6b78 = 0;
  return;
}

