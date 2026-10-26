/*
 * FUN_0044685c at 0044685c
 * undefined __register FUN_0044685c(int * param_1, int param_2)
 * Address ranges: 0044685c-004468d3;004468fe-00446901
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044685c(int *param_1,int param_2)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_24;
  undefined1 *puStack_20;
  undefined1 *puStack_1c;
  undefined4 uStack_18;
  undefined1 *puStack_14;
  undefined1 *puStack_10;
  
  if (*(int *)(param_2 + 4) != 0) {
    puStack_10 = (undefined1 *)0x44687e;
    FUN_004185e8(param_1[0x48]);
    puStack_14 = &LAB_004468f7;
    uStack_18 = *in_FS_OFFSET;
    *in_FS_OFFSET = &uStack_18;
    puStack_1c = (undefined1 *)0x44689d;
    puStack_10 = &stack0xfffffffc;
    FUN_00418a14((int *)param_1[0x48],*(int *)(param_2 + 4));
    puStack_20 = &LAB_004468d4;
    uStack_24 = *in_FS_OFFSET;
    *in_FS_OFFSET = &uStack_24;
    puStack_1c = &stack0xfffffffc;
    (**(code **)(*param_1 + 0x84))();
    *in_FS_OFFSET = uStack_24;
    puStack_1c = &LAB_004468db;
    puStack_20 = (undefined1 *)0x4468d3;
    FUN_00418a14((int *)param_1[0x48],0);
    return;
  }
  return;
}

