/*
 * FUN_0040b24c at 0040b24c
 * undefined4 __cdecl FUN_0040b24c(int param_1, undefined4 param_2)
 * Address ranges: 0040b24c-0040b296
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_0040b24c(int param_1,undefined4 param_2)

{
  if ((param_1 < 0) || (0x1a < param_1)) {
    FUN_0040187a((byte *)s__s__d_____set_message_funtion__t_004316e4);
  }
  else {
    (&DAT_0043d540)[param_1] = param_2;
  }
  return 1;
}

