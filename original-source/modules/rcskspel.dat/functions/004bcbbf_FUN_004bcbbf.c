/*
 * FUN_004bcbbf at 004bcbbf
 * undefined FUN_004bcbbf(void)
 * Address ranges: 004bcbbf-004bccd3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint __fastcall FUN_004bcbbf(basic_streambuf<char,std::char_traits<char>_> *param_1)

{
  int iVar1;
  byte *pbVar2;
  uint uVar3;
  int iVar4;
  undefined1 local_14 [4];
  undefined1 local_10 [4];
  int local_c;
  byte local_5;
  
  uVar3 = **(uint **)(param_1 + 0x1c);
  if ((uVar3 != 0) && (uVar3 < **(int **)(param_1 + 0x2c) + uVar3)) {
    pbVar2 = (byte *)std::basic_streambuf<char,std::char_traits<char>_>::_Gninc(param_1);
    return (uint)*pbVar2;
  }
  if (*(int *)(param_1 + 0x50) != 0) {
    if (*(int *)(param_1 + 0x38) == 0) {
      uVar3 = FUN_004c09f0(*(int *)(param_1 + 0x50));
      if (uVar3 != 0xffffffff) {
        return uVar3 & 0xff;
      }
    }
    else {
      *(undefined4 *)(param_1 + 0x3c) = *(undefined4 *)(param_1 + 0x40);
      FUN_004478a0(0,0xffffffff);
      while (iVar4 = FUN_004c09f0(*(undefined4 *)(param_1 + 0x50)), iVar4 != -1) {
        FUN_0045b1e0(1,iVar4);
        iVar4 = *(int *)(param_1 + 0x44);
        *(undefined4 *)(param_1 + 0x40) = *(undefined4 *)(param_1 + 0x3c);
        FUN_0044da90();
        iVar1 = *(int *)(param_1 + 0x44);
        local_c = *(int *)(iVar4 + 4);
        FUN_0044da90();
        iVar4 = (**(code **)(**(int **)(param_1 + 0x38) + 0x10))
                          (param_1 + 0x40,*(undefined4 *)(iVar1 + 4),
                           -(uint)(local_c != 0) & *(int *)(iVar4 + 8) + local_c,local_14,&local_5,
                           &stack0xfffffffc,local_10);
        if (iVar4 == 0) goto LAB_004bcccb;
        if (iVar4 != 1) {
          if (iVar4 != 3) {
            return 0xffffffff;
          }
          iVar4 = *(int *)(param_1 + 0x44);
          if (*(int *)(iVar4 + 8) != 0) {
            FUN_0044da90();
            FUN_004c0e10(&local_5,*(undefined4 *)(iVar4 + 4),1);
LAB_004bcccb:
            return (uint)local_5;
          }
        }
      }
    }
  }
  return 0xffffffff;
}

