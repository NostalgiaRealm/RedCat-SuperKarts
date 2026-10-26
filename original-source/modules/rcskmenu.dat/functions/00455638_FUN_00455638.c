/*
 * FUN_00455638 at 00455638
 * undefined __register FUN_00455638(int param_1)
 * Address ranges: 00455638-0045569b;004556a6-004556bb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00455638(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_30;
  undefined1 *puStack_2c;
  undefined1 *puStack_28;
  undefined4 uStack_24;
  undefined1 *puStack_20;
  undefined1 *puStack_1c;
  
  puStack_1c = &stack0xfffffffc;
  puStack_20 = &LAB_004556bc;
  uStack_24 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_24;
  puStack_28 = (undefined1 *)0x455665;
  piVar1 = FUN_0044f4ac((int *)&PTR_FUN_0044f450,'\x01',*(undefined4 **)(param_1 + 0xc));
  puStack_2c = &LAB_0045569c;
  uStack_30 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_30;
  puStack_28 = &stack0xfffffffc;
  uVar2 = (**(code **)(*piVar1 + 8))(piVar1,"transitiontable","lastrunok");
  *(undefined4 *)(param_1 + 0x18) = uVar2;
  *in_FS_OFFSET = 0;
  *in_FS_OFFSET = puStack_28;
  puStack_20 = &LAB_004556c3;
  uStack_24 = 0x4556bb;
  FUN_00402eac(piVar1);
  return;
}

