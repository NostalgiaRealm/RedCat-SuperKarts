/*
 * FUN_004502d4 at 004502d4
 * undefined __register FUN_004502d4(int param_1, int param_2, int param_3, int * param_4)
 * Address ranges: 004502d4-00450362
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004502d4(int param_1,int param_2,int param_3,int *param_4)

{
  byte bVar1;
  
  bVar1 = (byte)param_3;
  *param_4 = (1 << ((byte)param_1 & 0x1f)) + -1 << (bVar1 + (byte)param_2 & 0x1f);
  param_4[1] = (1 << ((byte)param_2 & 0x1f)) + -1 << (bVar1 & 0x1f);
  param_4[2] = (1 << (bVar1 & 0x1f)) + -1;
  param_4[3] = param_1;
  param_4[4] = param_2;
  param_4[5] = param_3;
  param_4[9] = 8 - param_1;
  param_4[10] = 8 - param_2;
  param_4[0xb] = 8 - param_3;
  param_4[6] = (param_3 + param_2) - (8 - param_1);
  param_4[7] = param_3 - (8 - param_2);
  param_4[8] = 8 - param_3;
  return;
}

