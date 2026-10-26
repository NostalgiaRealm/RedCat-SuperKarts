/*
 * FUN_00405dd4 at 00405dd4
 * int __register FUN_00405dd4(int param_1, uint param_2, undefined4 param_3, uint param_4, uint param_5)
 * Address ranges: 00405dd4-00405e1c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00405dd4(int param_1,uint param_2,undefined4 param_3,uint param_4,uint param_5)

{
  ulonglong uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  
  if ((param_5 == 0) && ((param_2 == 0 || (param_4 == 0)))) {
    param_1 = (int)(CONCAT44(param_2,param_1) / (ulonglong)param_4);
  }
  else {
    iVar2 = 0x40;
    uVar4 = 0;
    uVar3 = 0;
    do {
      bVar5 = param_1 < 0;
      param_1 = param_1 * 2;
      uVar1 = (ulonglong)CONCAT14(bVar5,param_2) << 1;
      param_2 = (uint)uVar1 | (uint)bVar5;
      bVar5 = (uVar1 & 0x100000000) != 0;
      uVar1 = (ulonglong)CONCAT14(bVar5,uVar3) << 1;
      uVar3 = (uint)uVar1 | (uint)bVar5;
      uVar4 = uVar4 << 1 | (uint)((uVar1 & 0x100000000) != 0);
      if ((param_5 <= uVar4) && ((param_5 < uVar4 || (param_4 <= uVar3)))) {
        bVar5 = uVar3 < param_4;
        uVar3 = uVar3 - param_4;
        uVar4 = (uVar4 - param_5) - (uint)bVar5;
        param_1 = param_1 + 1;
      }
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return param_1;
}

