/*
 * FUN_004069b0 at 004069b0
 * undefined FUN_004069b0(void)
 * Address ranges: 004069b0-00406a1f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __fastcall
FUN_004069b0(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 extraout_ECX;
  ulonglong uVar4;
  
  uVar1 = (*(uint *)(param_4 + 0x14) >> 2) + 0xfff >> 8 & 0xfffff0;
  *(uint *)(param_4 + 0x3c) = uVar1 * 0x100;
  iVar3 = FUN_00402c30(param_1,param_2,uVar1 * 0x200 + 0x40);
  *(int *)(param_4 + 0x54) = iVar3;
  if (iVar3 == 0) {
    return 0;
  }
  *(int *)(param_4 + 0x58) = iVar3 + 0x20 + *(int *)(param_4 + 0x3c);
  *(undefined4 *)(param_4 + 0x68) = param_3;
  uVar4 = FUN_00406a20(extraout_ECX,*(int *)(param_4 + 0x3c));
  uVar2 = DAT_0040e890;
  if ((char)uVar4 == '\0') {
    FUN_00402c10();
    return 0;
  }
  DAT_0040e890 = param_4;
  *(undefined4 *)(param_4 + 0x34) = uVar2;
  return 1;
}

