/*
 * FUN_00419654 at 00419654
 * undefined __cdecl FUN_00419654(int * param_1, int * param_2, undefined1 param_3)
 * Address ranges: 00419654-00419757
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_00419654(int *param_1,int *param_2,undefined1 param_3)

{
  size_t sVar1;
  int local_8;
  
  sVar1 = _strlen((char *)((int)param_1 + param_1[0xc] * 0x65 + 0x50));
  if ((uint)param_1[0xb] < sVar1) {
    sVar1 = _strlen((char *)((int)param_1 + param_1[0xc] * 0x65 + 0x50));
    for (local_8 = sVar1 + 1; param_1[0xb] <= local_8; local_8 = local_8 + -1) {
      *(undefined1 *)((int)param_1 + local_8 + param_1[0xc] * 0x65 + 0x51) =
           *(undefined1 *)((int)param_1 + local_8 + param_1[0xc] * 0x65 + 0x50);
    }
  }
  *(undefined1 *)((int)param_1 + param_1[0xb] + param_1[0xc] * 0x65 + 0x50) = param_3;
  param_1[0xb] = param_1[0xb] + 1;
  sVar1 = _strlen((char *)((int)param_1 + param_1[0xc] * 0x65 + 0x50));
  if (sVar1 < (uint)param_1[0xb]) {
    *(undefined1 *)((int)param_1 + param_1[0xb] + param_1[0xc] * 0x65 + 0x50) = 0;
  }
  FUN_004195c9(param_1,param_2);
  return;
}

