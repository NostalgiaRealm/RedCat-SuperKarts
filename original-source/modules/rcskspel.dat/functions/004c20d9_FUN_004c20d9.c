/*
 * FUN_004c20d9 at 004c20d9
 * undefined FUN_004c20d9(void)
 * Address ranges: 004c20d9-004c217b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_004c20d9(undefined4 param_1,int param_2)

{
  ushort in_FPUStatusWord;
  float10 in_ST0;
  ushort unaff_retaddr;
  uint uStack_4;
  
  uStack_4 = (uint)((ulonglong)(double)in_ST0 >> 0x20);
  if (((ulonglong)(double)in_ST0 & 0x7ff0000000000000) == 0) {
    fscale(in_ST0,(float10)1536.0);
  }
  else if ((uStack_4 & 0x7ff00000) == 0x7ff00000) {
    fscale(in_ST0,(float10)-1536.0);
  }
  else if (((unaff_retaddr == 0x27f) || ((unaff_retaddr & 0x20) != 0)) ||
          ((in_FPUStatusWord & 0x20) == 0)) {
    return;
  }
  if (param_2 == 0x1d) {
    FUN_004c1f90();
    return;
  }
  __startOneArgErrorHandling();
  return;
}

