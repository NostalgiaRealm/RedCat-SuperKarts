/*
 * FUN_00466ca0 at 00466ca0
 * undefined FUN_00466ca0(void)
 * Address ranges: 00466ca0-00466e09
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00466ca0(int param_1)

{
  int iVar1;
  float *pfVar2;
  float *pfVar3;
  
  pfVar3 = (float *)(param_1 + 0x30);
  FUN_004b1850(1,0x50,0x78,s_ax____f__<F1>_<F2>__004f4a00,(double)*(float *)(param_1 + 0x30));
  FUN_004b1850(1,0x50,0x8c,s_bx____f__<F3>_<F4>__004f4a14,(double)*(float *)(param_1 + 0x34));
  FUN_004b1850(1,0x50,0xa0,s_ay____f__<F5>_<F6>__004f4a28,(double)*(float *)(param_1 + 0x38));
  FUN_004b1850(1,0x50,0xb4,s_by____f__<F9>_<F10>__004f4a3c,(double)*(float *)(param_1 + 0x3c));
  iVar1 = FUN_004b3830(0x70);
  if (iVar1 != 0) {
    *pfVar3 = *pfVar3 * 1.01;
  }
  iVar1 = FUN_004b3830();
  if (iVar1 != 0) {
    *pfVar3 = *pfVar3 * 0.990099;
  }
  iVar1 = FUN_004b3830();
  if (iVar1 != 0) {
    *(float *)(param_1 + 0x38) = *(float *)(param_1 + 0x38) * 1.01;
  }
  iVar1 = FUN_004b3830();
  if (iVar1 != 0) {
    *(float *)(param_1 + 0x38) = *(float *)(param_1 + 0x38) * 0.990099;
  }
  iVar1 = FUN_004b3830();
  if (iVar1 != 0) {
    *(float *)(param_1 + 0x34) = *(float *)(param_1 + 0x34) + 0.001;
  }
  iVar1 = FUN_004b3830();
  if (iVar1 != 0) {
    *(float *)(param_1 + 0x34) = *(float *)(param_1 + 0x34) - 0.001;
  }
  iVar1 = FUN_004b3830();
  if (iVar1 != 0) {
    *(float *)(param_1 + 0x3c) = *(float *)(param_1 + 0x3c) + 0.001;
  }
  iVar1 = FUN_004b3830();
  if (iVar1 != 0) {
    *(float *)(param_1 + 0x3c) = *(float *)(param_1 + 0x3c) - 0.001;
  }
  iVar1 = FUN_004b3830();
  if (iVar1 != 0) {
    pfVar2 = (float *)(&DAT_004f4620 + DAT_0053b9b4 * 0x14);
    for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
      *pfVar3 = *pfVar2;
      pfVar2 = pfVar2 + 1;
      pfVar3 = pfVar3 + 1;
    }
  }
  return;
}

