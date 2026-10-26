/*
 * FUN_00404180 at 00404180
 * undefined4 * __register FUN_00404180(undefined4 * param_1)
 * Address ranges: 00404180-00404194
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 * FUN_00404180(undefined4 *param_1)

{
  BSTR bstrString;
  
  bstrString = (BSTR)*param_1;
  if (bstrString != (BSTR)0x0) {
    *param_1 = 0;
    SysFreeString(bstrString);
  }
  return param_1;
}

