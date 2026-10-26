/*
 * FUN_00424a10 at 00424a10
 * undefined __register FUN_00424a10(int * param_1)
 * Address ranges: 00424a10-00424a5a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00424a10(int *param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 extraout_ECX;
  
  iVar1 = (**(code **)(*(int *)param_1[0x7c] + 0x14))();
  if (0 < iVar1) {
    iVar1 = FUN_00424728(param_1);
    param_1[0x8a] = iVar1;
    piVar2 = (int *)FUN_00402e7c((int *)&PTR_FUN_0040e2e8,'\x01',extraout_ECX);
    param_1[0x89] = (int)piVar2;
    (**(code **)(*piVar2 + 8))(piVar2,param_1[0x7c]);
  }
  FUN_00442af0(param_1);
  return;
}

