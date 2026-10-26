/*
 * FUN_004047ac at 004047ac
 * undefined __register FUN_004047ac(LPCWSTR param_1, int * param_2)
 * Address ranges: 004047ac-004047ce
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004047ac(LPCWSTR param_1,int *param_2)

{
  UINT UVar1;
  
  UVar1 = SysStringLen(param_1);
  FUN_00404720(param_1,UVar1,param_2);
  return;
}

