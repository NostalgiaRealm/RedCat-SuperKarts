/*
 * _SmackToBufferRect@8 at 00402f40
 * undefined4 __fastcall _SmackToBufferRect@8(undefined4 param_1, undefined4 param_2, int param_3, int param_4)
 * Address ranges: 00402f40-004031c3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __fastcall
_SmackToBufferRect_8(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  uint *puVar1;
  undefined4 uVar2;
  DWORD DVar3;
  uint uVar4;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  uint uVar5;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined8 uVar10;
  int iStack_18;
  int iStack_14;
  
                    /* 0x2f40  28  _SmackToBufferRect@8 */
  if (param_3 == 0) {
    uVar2 = 0;
  }
  else {
    if (DAT_0040e83c != 0) {
      (*DAT_00410474)();
      param_1 = extraout_ECX;
      param_2 = extraout_EDX;
    }
    if ((*(int *)(param_3 + 0x3e4) == 0) || (param_4 == 2)) {
      return 0;
    }
    if (*(int *)(param_3 + 0x468) == 0) {
      DVar3 = timeGetTime();
      iVar6 = *(int *)(param_3 + 0x464);
      *(DWORD *)(param_3 + 0x468) = DVar3;
      param_1 = extraout_ECX_00;
      param_2 = extraout_EDX_00;
      if (iVar6 != 0) {
        *(undefined4 *)(param_3 + 0x464) = 0;
        *(DWORD *)(param_3 + 0x484) = *(int *)(param_3 + 0x484) + (DVar3 - iVar6);
      }
    }
    if (*(int *)(param_3 + 0x3e4) == 1) {
      uVar10 = FUN_0040d540(param_1,param_2,*(int *)(param_3 + 0x3a0),(uint *)(param_3 + 1000));
      if ((char)uVar10 == '\0') {
        *(undefined4 *)(param_3 + 0x3e4) = 0;
        if (*(int *)(param_3 + 0x68) == 0) {
          return 0;
        }
        *(undefined4 *)(param_3 + 0x374) = 0;
        *(undefined4 *)(param_3 + 0x378) = 0;
        *(undefined4 *)(param_3 + 0x37c) = 0;
        *(undefined4 *)(param_3 + 0x380) = 0;
        return 1;
      }
      *(undefined4 *)(param_3 + 0x3e4) = 2;
    }
    puVar1 = (uint *)(param_3 + 1000);
    uVar7 = *(uint *)(param_3 + 1000);
    iStack_18 = *(int *)(param_3 + 0x3ec);
    iVar6 = *(int *)(param_3 + 0x3f4);
    iStack_14 = iStack_18 + iVar6;
    uVar9 = *(int *)(param_3 + 0x3f0) + uVar7;
    if (param_4 == 1) {
      while( true ) {
        uVar10 = FUN_0040d540(*(undefined4 *)(param_3 + 0x3a0),iVar6,
                              *(undefined4 *)(param_3 + 0x3a0),puVar1);
        iVar6 = (int)((ulonglong)uVar10 >> 0x20);
        if ((char)uVar10 == '\0') break;
        if (*(uint *)(param_3 + 1000) < uVar7) {
          uVar7 = *(uint *)(param_3 + 1000);
        }
        uVar4 = *(int *)(param_3 + 1000) + *(int *)(param_3 + 0x3f0);
        if (uVar9 < uVar4) {
          uVar9 = uVar4;
        }
        iStack_14 = *(int *)(param_3 + 0x3ec) + *(int *)(param_3 + 0x3f4);
      }
LAB_00403155:
      *(undefined4 *)(param_3 + 0x3e4) = 0;
    }
    else {
      uVar8 = (uint)(*(int *)(param_3 + 0x3f0) * *(int *)(param_3 + 0x3f4) * 5) >> 2;
      uVar5 = uVar7;
      uVar4 = uVar9;
      iVar6 = iStack_14;
      do {
        iStack_14 = iVar6;
        uVar9 = uVar4;
        uVar7 = uVar5;
        uVar10 = FUN_0040d540(*(undefined4 *)(param_3 + 0x3a0),puVar1,
                              *(undefined4 *)(param_3 + 0x3a0),puVar1);
        if ((char)uVar10 == '\0') goto LAB_00403155;
        uVar8 = uVar8 + ((uint)(*(int *)(param_3 + 0x3f0) * *(int *)(param_3 + 0x3f4) * 5) >> 2);
        uVar5 = *(uint *)(param_3 + 1000);
        if (uVar7 <= *(uint *)(param_3 + 1000)) {
          uVar5 = uVar7;
        }
        uVar4 = *(int *)(param_3 + 1000) + *(int *)(param_3 + 0x3f0);
        if (uVar4 < uVar9) {
          uVar4 = uVar9;
        }
        iVar6 = *(int *)(param_3 + 0x3ec) + *(int *)(param_3 + 0x3f4);
      } while ((iVar6 - iStack_18) * (uVar4 - uVar5) <= uVar8);
    }
    if ((*(byte *)(param_3 + 0x386) & 0x30) != 0) {
      iStack_18 = iStack_18 * 2;
      iStack_14 = iStack_14 * 2;
    }
    *(uint *)(param_3 + 0x374) = uVar7 + *(int *)(param_3 + 0x388);
    *(int *)(param_3 + 0x378) = iStack_18 + *(int *)(param_3 + 0x38c);
    *(uint *)(param_3 + 0x37c) = uVar9 - uVar7;
    *(int *)(param_3 + 0x380) = iStack_14 - iStack_18;
    uVar2 = 1;
  }
  return uVar2;
}

