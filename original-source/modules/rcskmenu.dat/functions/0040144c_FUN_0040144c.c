/*
 * FUN_0040144c at 0040144c
 * undefined4 __register FUN_0040144c(int * param_1, int * param_2)
 * Address ranges: 0040144c-0040147b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0040144c(int *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = FUN_004013f4();
  if (piVar2 == (int *)0x0) {
    return 0;
  }
  piVar2[2] = *param_2;
  piVar2[3] = param_2[1];
  iVar1 = *param_1;
  *piVar2 = iVar1;
  piVar2[1] = (int)param_1;
  *(int **)(iVar1 + 4) = piVar2;
  *param_1 = (int)piVar2;
  return CONCAT31((int3)((uint)piVar2 >> 8),1);
}

