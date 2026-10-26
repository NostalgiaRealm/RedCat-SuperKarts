/*
 * FUN_004011f0 at 004011f0
 * uint __cdecl FUN_004011f0(int param_1, int param_2, int param_3)
 * Address ranges: 004011f0-00401245
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint __cdecl FUN_004011f0(int param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  piVar1 = DAT_00437da0;
  if (0 < (int)DAT_00437da0 + -1) {
    piVar1 = &DAT_00437dac;
    do {
      if (param_2 == *piVar1 && (param_1 == piVar1[-1] && param_3 == piVar1[1])) {
        return CONCAT31((int3)((uint)piVar1 >> 8),1);
      }
      iVar2 = iVar2 + 1;
      piVar1 = piVar1 + 3;
    } while (iVar2 < (int)DAT_00437da0 + -1);
  }
  return (uint)piVar1 & 0xffffff00;
}

