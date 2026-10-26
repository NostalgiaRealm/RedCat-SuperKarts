/*
 * FUN_0044f7a4 at 0044f7a4
 * undefined __register FUN_0044f7a4(undefined4 * param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5)
 * Address ranges: 0044f7a4-0044f80d;0044f833-0044f848
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044f7a4(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  int *in_FS_OFFSET;
  float10 in_ST0;
  int iStack_44;
  undefined1 *puStack_40;
  undefined1 *puStack_3c;
  undefined **ppuStack_38;
  undefined4 uStack_34;
  undefined1 *puStack_30;
  undefined1 *puStack_2c;
  undefined1 *puStack_28;
  undefined *local_18;
  undefined8 local_14;
  undefined4 local_8;
  
  puStack_28 = &stack0xfffffffc;
  local_18 = (undefined *)0x0;
  puStack_2c = &LAB_0044f849;
  puStack_30 = (undefined1 *)*in_FS_OFFSET;
  *in_FS_OFFSET = (int)&puStack_30;
  uStack_34 = 0;
  ppuStack_38 = &local_18;
  puStack_3c = (undefined1 *)0x44f7d8;
  local_8 = param_3;
  (**(code **)*param_1)(param_1,param_2,param_3);
  local_14 = (double)CONCAT44(param_5,param_4);
  if (local_18 != (undefined *)0x0) {
    puStack_40 = &LAB_0044f80e;
    iStack_44 = *in_FS_OFFSET;
    *in_FS_OFFSET = (int)&iStack_44;
    puStack_3c = &stack0xfffffffc;
    FUN_00408b68(local_18);
    local_14 = (double)in_ST0;
    *in_FS_OFFSET = iStack_44;
  }
  *in_FS_OFFSET = (int)ppuStack_38;
  puStack_30 = &LAB_0044f850;
  uStack_34 = 0x44f848;
  FUN_00403b50((int *)&local_18);
  return;
}

