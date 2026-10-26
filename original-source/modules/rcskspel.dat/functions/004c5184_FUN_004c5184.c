/*
 * FUN_004c5184 at 004c5184
 * undefined FUN_004c5184(void)
 * Address ranges: 004c5184-004c51c9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004c5184(int *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  piVar1 = (int *)*param_1;
  if (((*piVar1 == -0x1f928c9d) && (piVar1[4] == 3)) && (piVar1[5] == 0x19930520)) {
    uVar2 = FUN_004c2b7c();
    return uVar2;
  }
  if ((DAT_006b67ac != (code *)0x0) && (iVar3 = FUN_004c9764(DAT_006b67ac), iVar3 != 0)) {
    uVar2 = (*DAT_006b67ac)(param_1);
    return uVar2;
  }
  return 0;
}

