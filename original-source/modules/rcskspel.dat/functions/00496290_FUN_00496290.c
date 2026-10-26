/*
 * FUN_00496290 at 00496290
 * undefined FUN_00496290(void)
 * Address ranges: 00496290-0049635d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

float10 __thiscall
FUN_00496290(int param_1,float param_2,undefined4 param_3,float param_4,int param_5,int param_6)

{
  int iVar1;
  
  if (param_5 == 0) {
    iVar1 = param_1 + param_6 * 0xc;
    return (((float10)*(float *)(param_1 + 0x5c4 + param_6 * 4) -
            (float10)param_2 * (float10)*(float *)(param_1 + (param_6 * 3 + 0xe1) * 4)) -
           (float10)param_4 * (float10)*(float *)(iVar1 + 0x38c)) /
           (float10)*(float *)(iVar1 + 0x388);
  }
  if (param_5 != 1) {
    if (param_5 != 2) {
      return (((float10)*(float *)(param_1 + 0xdc) -
              (float10)param_2 * (float10)*(float *)(param_1 + 0x3c)) -
             (float10)param_4 * (float10)*(float *)(param_1 + 0x44)) /
             (float10)*(float *)(param_1 + 0x40);
    }
    iVar1 = param_1 + param_6 * 0xc;
    return (((float10)*(float *)(param_1 + 0x924 + param_6 * 4) -
            (float10)param_2 * (float10)*(float *)(param_1 + (param_6 * 3 + 0x201) * 4)) -
           (float10)param_4 * (float10)*(float *)(iVar1 + 0x80c)) /
           (float10)*(float *)(iVar1 + 0x808);
  }
  return (((float10)*(float *)(param_1 + 0x304 + param_6 * 4) -
          (float10)param_2 * (float10)*(float *)(param_1 + 0x184 + param_6 * 0xc)) -
         (float10)param_4 * (float10)*(float *)(param_1 + (param_6 * 3 + 99) * 4)) /
         (float10)*(float *)(param_1 + param_6 * 0xc + 0x188);
}

