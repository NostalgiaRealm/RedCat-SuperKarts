/*
 * FUN_0041b790 at 0041b790
 * undefined FUN_0041b790(void)
 * Address ranges: 0041b790-0041b908
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041b790(int param_1)

{
  int iVar1;
  int iVar2;
  float10 fVar3;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar1 = param_1;
  FUN_0041c0b0(param_1);
  FUN_0041cae0(iVar1);
  param_1 = 0;
  iVar2 = DAT_006a5c38 + *(int *)(DAT_0053be28 * 0xd0 + DAT_0067ee20 + 0xc) * 0xa9;
  FUN_00495fe0(*(undefined4 *)(iVar2 + 0x50),*(undefined4 *)(iVar2 + 0x54),
               *(undefined4 *)(iVar2 + 0x58),&param_1,&local_4,&local_8);
  iVar2 = DAT_006a5c38 + *(int *)(DAT_0053be28 * 0xd0 + 0xc + DAT_0067ee20) * 0xa9;
  fVar3 = (float10)FUN_00496290(*(undefined4 *)(iVar2 + 0x50),*(undefined4 *)(iVar2 + 0x54),
                                *(undefined4 *)(iVar2 + 0x58),local_4,local_8);
  if ((((DAT_0053bec4 != '\0') ||
       (*(int *)(*(int *)(iVar1 * 0xd0 + 0x24 + DAT_0067ee20) * 0x50 + 4 + DAT_00680ae0) == 0x44))
      && ((float10)*(float *)(iVar2 + 0x54) - fVar3 < (float10)2.5)) &&
     (4.0 < ABS(*(float *)(DAT_0053be28 * 0xd0 + 0xa4 + DAT_0067ee20)))) {
    FUN_0041cb80(iVar1);
  }
  if (DAT_0053bec5 != '\0') {
    FUN_0041cba0(iVar1);
  }
  return;
}

