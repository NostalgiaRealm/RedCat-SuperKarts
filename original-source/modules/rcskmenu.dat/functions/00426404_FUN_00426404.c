/*
 * FUN_00426404 at 00426404
 * undefined __register FUN_00426404(int param_1, int param_2)
 * Address ranges: 00426404-0042642b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00426404(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x4c);
  if (param_2 != iVar1) {
    if (iVar1 != 0) {
      FUN_004266e0(iVar1,param_1);
    }
    if (param_2 != 0) {
      FUN_004266c0(param_2,param_1);
    }
  }
  return;
}

