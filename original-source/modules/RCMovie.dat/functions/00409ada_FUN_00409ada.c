/*
 * FUN_00409ada at 00409ada
 * undefined __cdecl FUN_00409ada(int param_1)
 * Address ranges: 00409ada-00409b17
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_00409ada(int param_1)

{
  if ((param_1 < 0) || (1 < param_1)) {
    FUN_0040187a((byte *)s_trying_to_set_an_invalid_check_s_00431090);
  }
  else {
    DAT_0043d46c = param_1;
  }
  return;
}

