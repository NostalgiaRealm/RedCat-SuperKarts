/*
 * FUN_0048ffc0 at 0048ffc0
 * undefined FUN_0048ffc0(void)
 * Address ranges: 0048ffc0-00490120
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall
FUN_0048ffc0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,
            undefined4 param_10,undefined4 param_11,undefined4 param_12,int param_13,
            undefined4 param_14)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  *(undefined4 *)(param_1 + 0x18) = param_14;
  *(undefined4 *)(param_1 + 0x54) = param_11;
  *(int *)(param_1 + 0x14) = param_13;
  *(undefined4 *)(param_1 + 0x5c) = param_12;
  *(undefined4 *)(param_1 + 4) = 0;
  iVar2 = FUN_0049fc60(param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,FUN_004a0610
                      );
  *(int *)(param_1 + 0xc) = iVar2;
  *(undefined4 *)(DAT_006a5c38 + iVar2 * 0xa9 + 0xc) = param_2;
  *(undefined4 *)(DAT_006a5c38 + *(int *)(param_1 + 0xc) * 0xa9 + 0xa1) = 2;
  *(undefined1 *)(DAT_006a5c38 + *(int *)(param_1 + 0xc) * 0xa9 + 0x90) = 1;
  FUN_004a09e0();
  iVar2 = *(int *)(param_1 + 0xc);
  iVar1 = *(int *)(DAT_006a5c38 + iVar2 + iVar2 * 0xa8);
  iVar2 = DAT_006a5c38 + iVar2 + iVar2 * 0xa8;
  if (iVar1 == 1) {
    param_13 = *(int *)(iVar2 + 0x99);
  }
  else if (iVar1 == 2) {
    param_13 = *(int *)(*(int *)(*(int *)(*(int *)(iVar2 + 4) * 9 + 4 + DAT_006a5f78) +
                                *(int *)(iVar2 + 8) * 4) * 0x10 + DAT_006a5f30);
  }
  if (*(int *)(DAT_006847d0 + param_13 * 4) != 0) {
    *(int *)(param_1 + 200) = param_13;
    uVar3 = FUN_004a77d0(param_13);
    *(undefined4 *)(param_1 + 0xcc) = uVar3;
  }
  return;
}

