/*
 * FUN_00425bcc at 00425bcc
 * undefined __register FUN_00425bcc(int * param_1, int * param_2)
 * Address ranges: 00425bcc-00425c1c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00425bcc(int *param_1,int *param_2)

{
  uint uVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  
  FUN_004427e8(param_1,param_2);
  FUN_00442714(param_1,(int)param_2,"BUTTON");
  uVar1 = FUN_00403088(param_1,extraout_EDX,extraout_ECX);
  param_2[1] = *(uint *)(&DAT_0047b6a0 + (uint)*(byte *)(param_1 + 0x7e) * 4 + (uVar1 & 0x7f) * 8) |
               param_2[1] | 5U;
  param_2[9] = param_2[9] & 0xfffffffc;
  return;
}

