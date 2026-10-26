/*
 * FUN_00405762 at 00405762
 * undefined __cdecl FUN_00405762(char * param_1)
 * Address ranges: 00405762-004057bd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_00405762(char *param_1)

{
  size_t sVar1;
  
  sVar1 = _strlen(param_1);
  if (sVar1 != 0) {
    sVar1 = _strlen(param_1);
    if (sVar1 < 0x12d) goto LAB_0040579c;
  }
  FUN_0040187a((byte *)s__set_ini_filename___s__d____file_0042eb94);
LAB_0040579c:
  _strncpy(&DAT_0043d2d0,param_1,299);
  DAT_0043d3fc = 1;
  return;
}

