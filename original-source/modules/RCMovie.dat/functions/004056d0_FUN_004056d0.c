/*
 * FUN_004056d0 at 004056d0
 * undefined __cdecl FUN_004056d0(uint * param_1)
 * Address ranges: 004056d0-00405761
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_004056d0(uint *param_1)

{
  size_t sVar1;
  
  sVar1 = _strlen((char *)param_1);
  if (sVar1 != 0) {
    sVar1 = _strlen((char *)param_1);
    if (sVar1 < 0x10) goto LAB_00405708;
  }
  FUN_0040187a((byte *)s__set_ini_filename___s__d____file_0042eb48);
LAB_00405708:
  FUN_00427ae4((uint *)&DAT_0043d2d0,0x118);
  sVar1 = _strlen(&DAT_0043d2d0);
  if ((&DAT_0043d2cf)[sVar1] != '\\') {
    FUN_0041f7b0((uint *)&DAT_0043d2d0,(uint *)&DAT_0042eb84);
  }
  FUN_0041f7b0((uint *)&DAT_0043d2d0,param_1);
  DAT_0043d3fc = 1;
  return;
}

