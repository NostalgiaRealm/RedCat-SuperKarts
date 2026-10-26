/*
 * FUN_004c850a at 004c850a
 * undefined FUN_004c850a(void)
 * Address ranges: 004c850a-004c852e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004c850a(int param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  piVar1 = &DAT_00503568;
  do {
    if (*piVar1 == param_1) {
      return *(undefined4 *)(iVar2 * 8 + 0x50356c);
    }
    piVar1 = piVar1 + 2;
    iVar2 = iVar2 + 1;
  } while ((int)piVar1 < 0x503640);
  return 0;
}

