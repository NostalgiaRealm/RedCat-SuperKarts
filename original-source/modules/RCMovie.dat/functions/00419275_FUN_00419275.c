/*
 * FUN_00419275 at 00419275
 * undefined4 __cdecl FUN_00419275(int param_1, int * param_2)
 * Address ranges: 00419275-004194cc
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_00419275(int param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  
  iVar3 = *param_2;
  if (*(int *)(*(int *)(param_1 + 0xc) + 0x90) == 0) {
    FUN_0040187a((byte *)s__s__d_____show_cursor__trying_to_00435f38);
  }
  if (*(int *)(param_1 + 0x4c) == 0) {
    uVar1 = 0;
  }
  else {
    FUN_00415dd1(*(uint *)(param_1 + 0x1c));
    FUN_00415e01(*(uint *)(param_1 + 0x18));
    if (((*(int *)(param_1 + 0x3c) != -1) && (*(int *)(param_1 + 0x40) != -1)) &&
       ((*(int *)(param_1 + 0x40) != *(int *)(param_1 + 0x30) ||
        (*(int *)(param_1 + 0x3c) != *(int *)(param_1 + 0x2c))))) {
      iVar2 = FUN_00417005((char *)(param_1 + 0x50 + *(int *)(param_1 + 0x30) * 0x65),
                           *(size_t *)(param_1 + 0x3c));
      iVar3 = iVar3 + iVar2;
      if (*(char *)(param_1 + 0x50 + *(int *)(param_1 + 0x40) * 0x65 + *(int *)(param_1 + 0x3c)) ==
          '\0') {
        pbVar5 = &DAT_00435f88;
        iVar4 = param_2[1] + *(int *)(param_1 + 0x40) * *(int *)(param_1 + 0x44);
        iVar2 = FUN_00412061();
        FUN_0041635e(iVar2,iVar3,iVar4,pbVar5);
      }
      else {
        pbVar5 = &DAT_00435f8c;
        iVar2 = param_2[1] + *(int *)(param_1 + 0x40) * *(int *)(param_1 + 0x44);
        iVar4 = FUN_00412061();
        FUN_0041635e(iVar4,iVar3,iVar2,pbVar5);
      }
    }
    *(undefined4 *)(param_1 + 0x40) = *(undefined4 *)(param_1 + 0x30);
    *(undefined4 *)(param_1 + 0x3c) = *(undefined4 *)(param_1 + 0x2c);
    iVar3 = *param_2;
    FUN_00415dd1(*(uint *)(param_1 + 0x24));
    FUN_00415e01(*(uint *)(param_1 + 0x20));
    iVar2 = FUN_00417005((char *)(param_1 + 0x50 + *(int *)(param_1 + 0x30) * 0x65),
                         *(size_t *)(param_1 + 0x2c));
    iVar3 = iVar3 + iVar2;
    if (*(char *)(param_1 + 0x50 + *(int *)(param_1 + 0x30) * 0x65 + *(int *)(param_1 + 0x2c)) ==
        '\0') {
      pbVar5 = &DAT_00435f90;
      iVar4 = param_2[1] + *(int *)(param_1 + 0x30) * *(int *)(param_1 + 0x44);
      iVar2 = FUN_00412061();
      FUN_0041635e(iVar2,iVar3,iVar4,pbVar5);
    }
    else {
      pbVar5 = &DAT_00435f94;
      iVar2 = param_2[1] + *(int *)(param_1 + 0x30) * *(int *)(param_1 + 0x44);
      iVar4 = FUN_00412061();
      FUN_0041635e(iVar4,iVar3,iVar2,pbVar5);
    }
    uVar1 = 1;
  }
  return uVar1;
}

