/*
 * FUN_0044df24 at 0044df24
 * undefined __register FUN_0044df24(undefined4 * param_1)
 * Address ranges: 0044df24-0044df56
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044df24(undefined4 *param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar1 = FUN_0044df58((int)param_1);
  if (-1 < iVar1 + -1) {
    iVar3 = 0;
    do {
      piVar2 = (int *)(**(code **)*param_1)(param_1,iVar3);
      FUN_00402eac(piVar2);
      iVar3 = iVar3 + 1;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  (**(code **)(*(int *)param_1[1] + 8))();
  return;
}

