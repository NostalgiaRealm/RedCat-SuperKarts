/*
 * FUN_00451cb4 at 00451cb4
 * undefined __register FUN_00451cb4(int * param_1, byte param_2, undefined4 param_3)
 * Address ranges: 00451cb4-00451d1c;00451d34-00451d4c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00451cb4(int *param_1,byte param_2,undefined4 param_3)

{
  int *piVar1;
  undefined4 extraout_ECX;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_20;
  undefined1 *puStack_1c;
  undefined1 *puStack_18;
  
  if (((1 < *(int *)(param_1[9] + 4)) || (*(char *)(param_1[9] + 0x41c) != '\0')) ||
     ((param_2 == 0 && (*(char *)(param_1[9] + 0x42c) != '\0')))) {
    puStack_18 = (undefined1 *)0x451ced;
    piVar1 = FUN_004507f8((int *)&PTR_FUN_004501d8,'\x01',param_3);
    puStack_1c = &LAB_00451d1d;
    uStack_20 = *in_FS_OFFSET;
    *in_FS_OFFSET = &uStack_20;
    puStack_18 = &stack0xfffffffc;
    FUN_004510c0(piVar1,param_1[9],
                 CONCAT31((int3)((uint)extraout_ECX >> 8),*(byte *)(param_1[9] + 0x42c) & param_2));
    *in_FS_OFFSET = uStack_20;
    puStack_18 = (undefined1 *)0x451d3e;
    FUN_004524e4((int)param_1,(int)piVar1);
    puStack_18 = (undefined1 *)0x451d47;
    (**(code **)(*param_1 + 0x10))(param_1,param_1);
  }
  return;
}

