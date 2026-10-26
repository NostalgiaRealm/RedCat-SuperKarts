/*
 * FUN_0043a590 at 0043a590
 * undefined __register FUN_0043a590(int * param_1, int param_2)
 * Address ranges: 0043a590-0043a5b5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043a590(int *param_1,int param_2)

{
  HWND pHVar1;
  
  if (param_1[2] == 0) {
    pHVar1 = FUN_00429694();
    param_1[4] = (int)pHVar1;
  }
  FUN_0040f504(param_1,param_2);
  return;
}

