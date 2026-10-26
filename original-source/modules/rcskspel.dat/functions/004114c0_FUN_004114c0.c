/*
 * FUN_004114c0 at 004114c0
 * undefined FUN_004114c0(void)
 * Address ranges: 004114c0-0041151f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_004114c0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = 0;
  iVar1 = DAT_00680b28 + param_1 * 0x984;
  if (0 < *(int *)(iVar1 + 0xe4)) {
    piVar3 = (int *)(iVar1 + 0x124);
    do {
      if (param_2 == *piVar3) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
      piVar3 = piVar3 + 1;
    } while (iVar2 < *(int *)(iVar1 + 0xe4));
  }
  iVar2 = 0;
  if (0 < *(int *)(iVar1 + 0xe8)) {
    piVar3 = (int *)(iVar1 + 0x154);
    do {
      if (param_2 == *piVar3) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
      piVar3 = piVar3 + 1;
    } while (iVar2 < *(int *)(iVar1 + 0xe8));
  }
  return -1;
}

