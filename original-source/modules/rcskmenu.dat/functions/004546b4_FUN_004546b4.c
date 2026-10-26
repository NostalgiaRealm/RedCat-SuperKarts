/*
 * FUN_004546b4 at 004546b4
 * undefined __register FUN_004546b4(int param_1, int param_2)
 * Address ranges: 004546b4-0045470d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004546b4(int param_1,int param_2)

{
  int iVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_1c;
  undefined1 *puStack_18;
  undefined1 *puStack_14;
  byte *local_8;
  
  puStack_14 = &stack0xfffffffc;
  local_8 = (byte *)0x0;
  puStack_18 = &LAB_0045470e;
  uStack_1c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_1c;
  if ((-1 < param_2) && (iVar1 = (**(code **)(**(int **)(param_1 + 4) + 0x14))(), param_2 <= iVar1))
  {
    (**(code **)(**(int **)(param_1 + 4) + 0xc))(*(int **)(param_1 + 4),param_2,&local_8);
    FUN_00407f90(local_8);
  }
  *in_FS_OFFSET = uStack_1c;
  puStack_14 = &LAB_00454715;
  puStack_18 = (undefined1 *)0x45470d;
  FUN_00403b50((int *)&local_8);
  return;
}

