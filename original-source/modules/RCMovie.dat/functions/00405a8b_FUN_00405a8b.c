/*
 * FUN_00405a8b at 00405a8b
 * undefined __cdecl FUN_00405a8b(int param_1, char * param_2, size_t param_3)
 * Address ranges: 00405a8b-00405ae2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_00405a8b(int param_1,char *param_2,size_t param_3)

{
  if ((param_1 < 0) || (DAT_0043d400 < param_1)) {
    FUN_0040187a((byte *)s__get_ini_argument_value___s__d____0042ee4c);
  }
  _strncpy(param_2,&DAT_004384b0 + param_1 * 200,param_3);
  return;
}

