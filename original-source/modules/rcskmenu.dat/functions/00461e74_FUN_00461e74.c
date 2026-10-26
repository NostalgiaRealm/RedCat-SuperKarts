/*
 * FUN_00461e74 at 00461e74
 * undefined __register FUN_00461e74(undefined4 param_1, int param_2, int * param_3)
 * Address ranges: 00461e74-00461ea5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00461e74(undefined4 param_1,int param_2,int *param_3)

{
  int iVar1;
  int *piVar2;
  
  FUN_00403b50(param_3);
  iVar1 = 9;
  piVar2 = &DAT_0047c33c;
  do {
    if (param_2 == *piVar2) {
      FUN_00403ba4(param_3,(undefined4 *)piVar2[1]);
      return;
    }
    piVar2 = piVar2 + 2;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}

