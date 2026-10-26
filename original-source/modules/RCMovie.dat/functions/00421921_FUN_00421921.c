/*
 * FUN_00421921 at 00421921
 * undefined __cdecl FUN_00421921(int param_1, int * param_2)
 * Address ranges: 00421921-0042195d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_00421921(int param_1,int *param_2)

{
  if (param_1 == 0) {
    if ((*(byte *)((int)param_2 + 0xd) & 0x10) != 0) {
      FUN_0042056d(param_2);
    }
  }
  else if ((*(byte *)((int)param_2 + 0xd) & 0x10) != 0) {
    FUN_0042056d(param_2);
    *(byte *)((int)param_2 + 0xd) = *(byte *)((int)param_2 + 0xd) & 0xee;
    param_2[6] = 0;
    *param_2 = 0;
    param_2[2] = 0;
    return;
  }
  return;
}

