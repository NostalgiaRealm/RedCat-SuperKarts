/*
 * FUN_004bdac3 at 004bdac3
 * undefined FUN_004bdac3(void)
 * Address ranges: 004bdac3-004bdb84
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall
FUN_004bdac3(int param_1,undefined4 *param_2,int param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar2 = param_3;
  local_c = param_5;
  local_8 = param_6;
  if (*(int *)(param_1 + 0x50) != 0) {
    iVar1 = FUN_004c12b2(*(int *)(param_1 + 0x50),&local_c);
    if (iVar1 == 0) {
      if (iVar2 != 0) {
        iVar2 = FUN_004c0331(*(undefined4 *)(param_1 + 0x50),iVar2,1);
        if (iVar2 != 0) goto LAB_004bdb56;
      }
      iVar2 = FUN_004c1290(*(undefined4 *)(param_1 + 0x50),&local_c);
      if (iVar2 == 0) {
        if (*(int *)(param_1 + 0x44) != 0) {
          *(undefined4 *)(param_1 + 0x40) = param_7;
          FUN_004478a0(0,0xffffffff);
        }
        param_3 = 0;
        param_5 = local_c;
        param_6 = local_8;
        param_7 = *(undefined4 *)(param_1 + 0x40);
        goto LAB_004bdb78;
      }
    }
  }
LAB_004bdb56:
  param_3 = 0xffffffff;
  param_5 = 0;
  param_6 = 0;
  param_7 = DAT_006b6a54;
LAB_004bdb78:
  puVar3 = &param_3;
  for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
    *param_2 = *puVar3;
    puVar3 = puVar3 + 1;
    param_2 = param_2 + 1;
  }
  return;
}

