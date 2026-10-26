/*
 * FUN_00467748 at 00467748
 * undefined FUN_00467748(void)
 * Address ranges: 00467748-0046777f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00467748(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  iVar1 = FUN_00466230(param_1);
  if (-1 < iVar1) {
    uVar2 = FUN_00466230(param_1);
    piVar3 = (int *)(**(code **)(*(int *)param_1[0x84] + 0x18))((int *)param_1[0x84],uVar2);
    FUN_00467660(param_1,piVar3);
    return;
  }
  FUN_00467660(param_1,(int *)0x0);
  return;
}

