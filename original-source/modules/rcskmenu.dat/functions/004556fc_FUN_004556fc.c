/*
 * FUN_004556fc at 004556fc
 * undefined __register FUN_004556fc(int param_1, undefined4 param_2)
 * Address ranges: 004556fc-00455756;00455761-00455776
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004556fc(int param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_2c;
  undefined1 *puStack_28;
  undefined1 *puStack_24;
  undefined4 uStack_20;
  undefined1 *puStack_1c;
  undefined1 *puStack_18;
  
  puStack_18 = &stack0xfffffffc;
  puStack_1c = &LAB_00455777;
  uStack_20 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_20;
  puStack_24 = (undefined1 *)0x455724;
  piVar1 = FUN_0044f4ac((int *)&PTR_FUN_0044f450,'\x01',*(undefined4 **)(param_1 + 0xc));
  puStack_28 = &LAB_00455757;
  uStack_2c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_2c;
  *(undefined4 *)(param_1 + 0x18) = param_2;
  puStack_24 = &stack0xfffffffc;
  (**(code **)(*piVar1 + 0xc))(piVar1,"transitiontable","lastrunok");
  *in_FS_OFFSET = param_2;
  *in_FS_OFFSET = puStack_24;
  puStack_1c = &LAB_0045577e;
  uStack_20 = 0x455776;
  FUN_00402eac(piVar1);
  return;
}

