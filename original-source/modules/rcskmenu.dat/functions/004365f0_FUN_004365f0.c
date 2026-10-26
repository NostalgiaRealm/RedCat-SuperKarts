/*
 * FUN_004365f0 at 004365f0
 * undefined __register FUN_004365f0(int * param_1, int param_2)
 * Address ranges: 004365f0-00436613
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004365f0(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = param_1[0x17];
  if (param_2 != iVar1) {
    if (iVar1 != 0) {
      *(undefined4 *)(iVar1 + 0x60) = 0;
    }
    param_1[0x17] = param_2;
    if (param_2 != 0) {
      *(int **)(param_2 + 0x60) = param_1;
    }
    FUN_00436650(param_1);
  }
  return;
}

