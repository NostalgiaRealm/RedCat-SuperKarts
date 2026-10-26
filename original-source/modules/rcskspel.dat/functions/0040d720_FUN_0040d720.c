/*
 * FUN_0040d720 at 0040d720
 * undefined FUN_0040d720(void)
 * Address ranges: 0040d720-0040d744
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0040d720(int param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  piVar1 = &DAT_004d23a0;
  do {
    if (*piVar1 == param_1) {
      return *(undefined4 *)(&UNK_004d23a4 + iVar2 * 8);
    }
    piVar1 = piVar1 + 2;
    iVar2 = iVar2 + 1;
  } while ((int)piVar1 < 0x4d23c0);
  return 0;
}

