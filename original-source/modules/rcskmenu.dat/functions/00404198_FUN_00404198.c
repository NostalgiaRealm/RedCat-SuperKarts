/*
 * FUN_00404198 at 00404198
 * undefined __register FUN_00404198(undefined4 * param_1, int param_2)
 * Address ranges: 00404198-004041b8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00404198(undefined4 *param_1,int param_2)

{
  BSTR bstrString;
  
  do {
    bstrString = (BSTR)*param_1;
    if (bstrString != (BSTR)0x0) {
      *param_1 = 0;
      SysFreeString(bstrString);
    }
    param_1 = param_1 + 1;
    param_2 = param_2 + -1;
  } while (param_2 != 0);
  return;
}

