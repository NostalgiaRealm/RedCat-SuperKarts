/*
 * FUN_00432314 at 00432314
 * undefined __register FUN_00432314(int param_1, int param_2, undefined4 * param_3)
 * Address ranges: 00432314-00432351;00432368-00432390
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00432314(int param_1,int param_2,undefined4 *param_3)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_20;
  undefined1 *puStack_1c;
  undefined1 *puStack_18;
  
  puStack_18 = (undefined1 *)0x432327;
  piVar1 = (int *)(**(code **)(param_2 + -0xc))();
  *param_3 = piVar1;
  puStack_1c = &LAB_00432352;
  uStack_20 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_20;
  puStack_18 = &stack0xfffffffc;
  (**(code **)(*piVar1 + 0x2c))(piVar1,0xffffffff,param_1);
  *in_FS_OFFSET = uStack_20;
  if (*(int *)(param_1 + 0x38) == 0) {
    puStack_18 = (undefined1 *)0x43237b;
    uVar2 = FUN_00403024(piVar1,(int)&PTR_FUN_00428110);
    if ((char)uVar2 != '\0') {
      puStack_18 = (undefined1 *)0x432388;
      FUN_00445700(piVar1);
      *(int **)(param_1 + 0x38) = piVar1;
    }
  }
  return;
}

