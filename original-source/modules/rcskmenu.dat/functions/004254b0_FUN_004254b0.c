/*
 * FUN_004254b0 at 004254b0
 * undefined __register FUN_004254b0(int * param_1, int param_2)
 * Address ranges: 004254b0-004254dd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004254b0(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_2 + 8);
  *(int *)(iVar1 + 0x10) = param_1[0x7f];
  if (*(char *)((int)param_1 + 0x1fa) == '\x04') {
    (**(code **)(*param_1 + 0xc0))(param_1,*(undefined4 *)(iVar1 + 8),iVar1 + 0x10);
  }
  return;
}

