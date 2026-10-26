/*
 * FUN_00475674 at 00475674
 * undefined __register FUN_00475674(int param_1, undefined4 param_2, undefined4 param_3)
 * Address ranges: 00475674-004756e5;004756f0-004756f5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00475674(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_20;
  undefined1 *puStack_1c;
  undefined1 *puStack_18;
  undefined4 uStack_8;
  
  puStack_18 = &stack0xfffffffc;
  puStack_1c = &LAB_004756e6;
  uStack_20 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_20;
  uStack_8 = param_3;
  FUN_00458480(*(int *)(*(int *)PTR_DAT_0047c670 + 0x90),*(int *)(*(int *)(param_1 + 0x3a8) + 0x14))
  ;
  FUN_00458490(*(int *)(*(int *)PTR_DAT_0047c670 + 0x90),(undefined2 *)((int)&uStack_8 + 2),
               *(int *)(*(int *)(param_1 + 0x3a8) + 0x14));
  FUN_0045a030(*(int *)(*(int *)PTR_DAT_0047c670 + 0x80),*(int *)(param_1 + 0x3a8));
  *in_FS_OFFSET = uStack_20;
  return;
}

