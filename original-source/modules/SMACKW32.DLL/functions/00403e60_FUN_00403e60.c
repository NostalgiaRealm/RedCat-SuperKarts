/*
 * FUN_00403e60 at 00403e60
 * undefined __fastcall FUN_00403e60(short param_1, short param_2, short param_3)
 * Address ranges: 00403e60-00403e9a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00403e60(short param_1,short param_2,short param_3)

{
  short *in_EAX;
  uint unaff_EBX;
  
  *in_EAX = param_2;
  in_EAX[1] = (short)(unaff_EBX >> 2);
  in_EAX[2] = param_1 * param_2 + -4;
  in_EAX[3] = param_1 * param_2;
  in_EAX[4] = param_2 * param_3 - (short)unaff_EBX;
  return;
}

