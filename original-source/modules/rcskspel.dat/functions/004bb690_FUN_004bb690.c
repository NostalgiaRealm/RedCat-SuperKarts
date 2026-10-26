/*
 * FUN_004bb690 at 004bb690
 * undefined FUN_004bb690(void)
 * Address ranges: 004bb690-004bb6b2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004bb690(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_006abb58;
  for (iVar1 = 10000; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xffffffff;
    puVar2 = puVar2 + 1;
  }
  DAT_006b5798 = 0;
  DAT_006b579c = 1;
  return;
}

