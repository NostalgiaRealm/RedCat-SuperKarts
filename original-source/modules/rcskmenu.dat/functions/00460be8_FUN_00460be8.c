/*
 * FUN_00460be8 at 00460be8
 * undefined __register FUN_00460be8(int param_1, byte param_2, undefined4 param_3)
 * Address ranges: 00460be8-00460ca8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00460be8(int param_1,byte param_2,undefined4 param_3)

{
  undefined1 *puVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_20;
  undefined1 *puStack_1c;
  undefined1 *puStack_18;
  uint *local_10;
  uint *local_c;
  int iStack_8;
  
  puStack_18 = &stack0xfffffffc;
  local_c = (uint *)0x0;
  local_10 = (uint *)0x0;
  iStack_8 = (uint)param_2 << 0x18;
  puStack_1c = &LAB_00460ca9;
  uStack_20 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_20;
  *(byte *)(param_1 + 0x2f0) = param_2;
  if ((((*(byte *)(param_1 + 0x2f0) & 4) != 0) ||
      (puVar1 = &stack0xfffffffc, (*(byte *)(param_1 + 0x2f0) & 1) != 0)) &&
     (puVar1 = &stack0xfffffffc, (*(byte *)(param_1 + 0x2f0) & 8) == 0)) {
    FUN_0043f564(*(int **)(param_1 + 0x2e0),0,param_3);
    FUN_0043f564(*(int **)(param_1 + 0x2dc),CONCAT31((int3)((uint)extraout_EDX >> 8),1),extraout_ECX
                );
    FUN_0043ee6c(*(int **)(param_1 + 0x2dc),0x148);
    puVar1 = puStack_18;
  }
  puStack_18 = puVar1;
  if ((*(byte *)(param_1 + 0x2f0) & 4) == 0) {
    FUN_0045c4c8(0x2a,(int *)&local_10);
    FUN_0043f67c(*(int *)(param_1 + 0x2dc),local_10);
  }
  else {
    FUN_0045c4c8(0xe,(int *)&local_c);
    FUN_0043f67c(*(int *)(param_1 + 0x2dc),local_c);
  }
  *in_FS_OFFSET = uStack_20;
  puStack_18 = &LAB_00460cb0;
  puStack_1c = (undefined1 *)0x460ca8;
  FUN_00403b74((int *)&local_10,2);
  return;
}

