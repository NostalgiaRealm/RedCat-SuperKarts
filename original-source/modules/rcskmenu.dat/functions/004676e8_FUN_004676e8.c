/*
 * FUN_004676e8 at 004676e8
 * undefined __register FUN_004676e8(int param_1, int param_2)
 * Address ranges: 004676e8-00467739
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004676e8(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_1c;
  undefined1 *puStack_18;
  undefined1 *puStack_14;
  int local_8;
  
  puStack_14 = &stack0xfffffffc;
  local_8 = 0;
  puStack_18 = &LAB_0046773a;
  uStack_1c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_1c;
  FUN_0043f64c(param_2,&local_8);
  iVar1 = local_8;
  iVar2 = FUN_00466cc0(param_2);
  (**(code **)(**(int **)(param_1 + 0x210) + 0x20))(*(int **)(param_1 + 0x210),iVar2,iVar1);
  *in_FS_OFFSET = uStack_1c;
  puStack_14 = &LAB_00467741;
  puStack_18 = (undefined1 *)0x467739;
  FUN_00403b50(&local_8);
  return;
}

