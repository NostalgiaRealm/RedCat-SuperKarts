/*
 * FUN_0041016c at 0041016c
 * undefined __register FUN_0041016c(int * param_1)
 * Address ranges: 0041016c-004101c5;004101cd-004101d0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041016c(int *param_1)

{
  undefined1 *puVar1;
  int *piVar2;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_18;
  undefined1 *puStack_14;
  undefined1 *puStack_10;
  
  if (0 < *(int *)(param_1[2] + 8)) {
    puStack_10 = (undefined1 *)0x410188;
    (**(code **)(*param_1 + 0x14))();
    puStack_14 = &LAB_004101c6;
    uStack_18 = *in_FS_OFFSET;
    *in_FS_OFFSET = &uStack_18;
    puStack_10 = &stack0xfffffffc;
    while (puVar1 = puStack_10, 0 < (int)((undefined4 *)param_1[2])[2]) {
      piVar2 = (int *)FUN_0040f798((undefined4 *)param_1[2]);
      FUN_00402eac(piVar2);
    }
    *in_FS_OFFSET = uStack_18;
    puStack_10 = (undefined1 *)0x4101cd;
    puStack_14 = (undefined1 *)0x4101c5;
    (**(code **)(*param_1 + 0x18))(param_1,*param_1,puVar1);
    return;
  }
  return;
}

