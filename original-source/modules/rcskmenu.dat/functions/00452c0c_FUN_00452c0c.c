/*
 * FUN_00452c0c at 00452c0c
 * undefined __register FUN_00452c0c(int param_1, uint * param_2)
 * Address ranges: 00452c0c-00452cbd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00452c0c(int param_1,uint *param_2)

{
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  undefined4 *in_FS_OFFSET;
  undefined1 uVar1;
  undefined4 uStack_28;
  undefined1 *puStack_24;
  undefined1 *puStack_20;
  int local_18;
  int local_14;
  undefined4 *local_10;
  uint *local_c;
  uint *local_8;
  
  local_c = (uint *)0x0;
  local_10 = (undefined4 *)0x0;
  local_14 = 0;
  local_18 = 0;
  puStack_20 = (undefined1 *)0x452c24;
  local_8 = param_2;
  FUN_00403f84((int)param_2);
  uVar1 = 1;
  puStack_24 = &LAB_00452cbe;
  uStack_28 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_28;
  puStack_20 = &stack0xfffffffc;
  FUN_00452bf8(param_1,(int *)&local_c);
  FUN_00403ee0(local_8,local_c);
  if (!(bool)uVar1) {
    FUN_0044e6f8(local_8,(int *)&local_10);
    FUN_00403ba4((int *)(param_1 + 0xc),local_10);
    FUN_00452bf8(param_1,&local_14);
    if (local_14 == 0) {
      FUN_00451c90(*(int **)(param_1 + 0x10),extraout_EDX,extraout_ECX);
    }
    else {
      FUN_00452bf8(param_1,&local_18);
      (**(code **)(**(int **)(param_1 + 0x10) + 0x48))(*(int **)(param_1 + 0x10),local_18);
    }
  }
  *in_FS_OFFSET = uStack_28;
  puStack_20 = &LAB_00452cc5;
  puStack_24 = (undefined1 *)0x452ca8;
  FUN_00403b74(&local_18,2);
  puStack_24 = (undefined1 *)0x452cb0;
  FUN_00403b50((int *)&local_10);
  puStack_24 = (undefined1 *)0x452cbd;
  FUN_00403b74((int *)&local_c,2);
  return;
}

