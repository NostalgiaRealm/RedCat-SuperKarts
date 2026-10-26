/*
 * FUN_004ca2ca at 004ca2ca
 * undefined FUN_004ca2ca(void)
 * Address ranges: 004ca2ca-004ca2fa
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004ca2ca(byte param_1,uint param_2,byte param_3)

{
  if ((*(byte *)((int)&DAT_006b6c80 + param_1 + 1) & param_3) == 0) {
    if (param_2 == 0) {
      param_2 = 0;
    }
    else {
      param_2 = *(ushort *)(&DAT_00502d8a + (uint)param_1 * 2) & param_2;
    }
    if (param_2 == 0) {
      return 0;
    }
  }
  return 1;
}

