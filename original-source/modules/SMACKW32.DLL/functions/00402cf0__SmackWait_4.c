/*
 * _SmackWait@4 at 00402cf0
 * longlong __fastcall _SmackWait@4(undefined4 param_1, uint param_2, int param_3)
 * Address ranges: 00402cf0-00402e09
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

longlong __fastcall _SmackWait_4(undefined4 param_1,uint param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  uint extraout_EDX;
  DWORD DVar5;
  undefined8 uVar6;
  
                    /* 0x2cf0  32  _SmackWait@4 */
  if (param_3 == 0) {
    uVar2 = 0;
  }
  else {
    if (DAT_0040e83c != 0) {
      (*DAT_00410474)();
      param_2 = extraout_EDX;
    }
    if (*(int *)(param_3 + 0x420) == -1) {
      if (*(int *)(param_3 + 0x3f8) != 0) {
        return (ulonglong)param_2 << 0x20;
      }
      DVar5 = timeGetTime();
      uVar3 = *(uint *)(param_3 + 0x3fc);
      uVar4 = DVar5 * 100;
      uVar2 = extraout_ECX_00;
      if (uVar3 == 0xffffffff) {
        DVar5 = *(DWORD *)(param_3 + 0x400);
        *(uint *)(param_3 + 0x3fc) = uVar4 + DVar5;
      }
      else if (uVar3 <= uVar4) {
        iVar1 = uVar3 + *(int *)(param_3 + 0x400);
        uVar3 = uVar4 - iVar1;
        *(int *)(param_3 + 0x3fc) = iVar1;
        if (*(uint *)(param_3 + 0x400) < uVar3) {
          *(uint *)(param_3 + 0x3fc) = uVar4 + *(uint *)(param_3 + 0x400);
        }
        if (*(int *)(param_3 + 0x400) != 0) {
          *(undefined4 *)(param_3 + 0x3f8) = 1;
        }
        return (ulonglong)uVar3 << 0x20;
      }
    }
    else {
      if ((*(int *)(param_3 + 0x424) == 0) || (*(int *)(param_3 + 0x428) != 0)) {
        return (ulonglong)param_2 << 0x20;
      }
      uVar3 = (*DAT_00410478)(*(undefined4 *)(param_3 + 0x404 + *(int *)(param_3 + 0x420) * 4));
      DVar5 = *(uint *)(*(int *)(param_3 + 0x404 + *(int *)(param_3 + 0x420) * 4) + 0x20) >> 7;
      uVar2 = extraout_ECX;
      if (DVar5 <= uVar3) {
        *(undefined4 *)(param_3 + 0x424) = 0;
        return (ulonglong)DVar5 << 0x20;
      }
    }
    uVar6 = FUN_00405c60(uVar2,DVar5);
    param_2 = (uint)((ulonglong)uVar6 >> 0x20);
    uVar2 = 1;
  }
  return CONCAT44(param_2,uVar2);
}

