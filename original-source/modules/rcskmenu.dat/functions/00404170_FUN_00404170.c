/*
 * FUN_00404170 at 00404170
 * undefined __register FUN_00404170(undefined4 * param_1, undefined4 param_2)
 * Address ranges: 00404170-0040417e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00404170(undefined4 *param_1,undefined4 param_2)

{
  BSTR bstrString;
  
  bstrString = (BSTR)*param_1;
  *param_1 = param_2;
  if (bstrString != (BSTR)0x0) {
    SysFreeString(bstrString);
  }
  return;
}

