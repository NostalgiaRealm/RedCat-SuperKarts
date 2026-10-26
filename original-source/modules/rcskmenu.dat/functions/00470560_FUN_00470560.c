/*
 * FUN_00470560 at 00470560
 * undefined __register FUN_00470560(int param_1, uint * param_2)
 * Address ranges: 00470560-004705d8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00470560(int param_1,uint *param_2)

{
  int iVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_1c;
  undefined1 *puStack_18;
  undefined1 *puStack_14;
  int local_c;
  uint *local_8;
  
  local_c = 0;
  puStack_14 = (undefined1 *)0x470579;
  local_8 = param_2;
  FUN_00403f84((int)param_2);
  puStack_18 = &LAB_004705d9;
  uStack_1c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_1c;
  puStack_14 = &stack0xfffffffc;
  FUN_0043f67c(*(int *)(param_1 + 0x2e4),local_8);
  FUN_0043f64c(*(int *)(param_1 + 0x2e4),&local_c);
  iVar1 = FUN_00403dd0(local_c);
  (**(code **)(**(int **)(param_1 + 0x2dc) + 0x5c))(*(int **)(param_1 + 0x2dc),0 < iVar1);
  *in_FS_OFFSET = uStack_1c;
  puStack_14 = &LAB_004705e0;
  puStack_18 = (undefined1 *)0x4705d0;
  FUN_00403b50(&local_c);
  puStack_18 = (undefined1 *)0x4705d8;
  FUN_00403b50((int *)&local_8);
  return;
}

