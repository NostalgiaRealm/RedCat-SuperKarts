/*
 * FUN_00430ee0 at 00430ee0
 * undefined __register FUN_00430ee0(HWND param_1, int param_2)
 * Address ranges: 00430ee0-00430f0e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00430ee0(HWND param_1,int param_2)

{
  bool bVar1;
  
  bVar1 = FUN_00430e88();
  if (bVar1) {
    FUN_00430eb8('\0');
  }
  ShowWindow(param_1,param_2);
  if (bVar1) {
    FUN_00430eb8('\x01');
  }
  return;
}

