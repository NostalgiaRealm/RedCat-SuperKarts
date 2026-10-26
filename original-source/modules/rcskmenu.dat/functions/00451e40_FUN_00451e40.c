/*
 * FUN_00451e40 at 00451e40
 * undefined4 __register FUN_00451e40(int param_1, undefined4 param_2, undefined4 param_3)
 * Address ranges: 00451e40-00451e84
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00451e40(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  undefined4 extraout_ECX;
  
  if (*(int *)(param_1 + 0x20) == 0) {
    FUN_00451d50(param_1,param_2,param_3);
    piVar2 = FUN_00417ff0((int *)&PTR_FUN_0041631c,'\x01',extraout_ECX);
    *(int **)(param_1 + 0x20) = piVar2;
    FUN_00418a14(piVar2,*(int *)(*(int *)(param_1 + 0x24) + 0x420));
    iVar1 = *(int *)(param_1 + 0x20);
    *(int *)(iVar1 + 0x34) = param_1;
    *(code **)(iVar1 + 0x30) = FUN_00451cac;
  }
  return *(undefined4 *)(param_1 + 0x20);
}

