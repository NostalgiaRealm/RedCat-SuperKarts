/*
 * FUN_0042bcdc at 0042bcdc
 * undefined FUN_0042bcdc(void)
 * Address ranges: 0042bcdc-0042bf31;0042bf56-0042c035;0042c081-0042c091
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042bcdc(int *param_1,uint *param_2,undefined4 param_3)

{
  uint uVar1;
  HANDLE pvVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  HWND pHVar6;
  HDC hdc;
  int *piVar7;
  int iVar8;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 extraout_ECX_03;
  undefined4 extraout_ECX_04;
  undefined4 extraout_ECX_05;
  undefined4 extraout_ECX_06;
  undefined4 *in_FS_OFFSET;
  undefined4 uVar9;
  undefined4 uStack_30;
  undefined1 *puStack_2c;
  
  uVar1 = *param_2;
  if ((int)uVar1 < 0x47) {
    if (uVar1 == 0x46) {
      if ((*(ushort *)(param_1 + 8) & 0x11) == 1) {
        if (((byte)((char)param_1[0x86] - 1U) < 2) && (*(char *)((int)param_1 + 0x213) != '\x02')) {
          *(uint *)(param_2[2] + 0x18) = *(uint *)(param_2[2] + 0x18) | 2;
        }
        if ((((char)param_1[0x86] == '\x01') || ((char)param_1[0x86] == '\x03')) &&
           ((*(char *)((int)param_1 + 0x211) == '\x02' ||
            (*(char *)((int)param_1 + 0x211) == '\x05')))) {
          *(uint *)(param_2[2] + 0x18) = *(uint *)(param_2[2] + 0x18) | 1;
        }
      }
    }
    else if (uVar1 - 6 < 3) {
      if (DAT_0047b6b4 == '\0') {
        return;
      }
      if ((*param_2 == 7) && ((*(byte *)(param_1 + 8) & 0x10) == 0)) {
        pHVar6 = (HWND)0x0;
        if (*(char *)((int)param_1 + 0x217) == '\x02') {
          pvVar2 = FUN_0042c44c((int)param_1);
          param_3 = extraout_ECX;
          if (pvVar2 != (HANDLE)0x0) {
            piVar3 = FUN_0042c44c((int)param_1);
            pHVar6 = (HWND)FUN_00445724(piVar3);
            param_3 = extraout_ECX_00;
          }
        }
        else {
          piVar3 = (int *)param_1[0x82];
          if ((piVar3 != (int *)0x0) && (piVar3 != param_1)) {
            pHVar6 = (HWND)FUN_00445724(piVar3);
            param_3 = extraout_ECX_01;
          }
        }
        if (pHVar6 != (HWND)0x0) {
          puStack_2c = (undefined1 *)0x42bd9c;
          SetFocus(pHVar6);
          return;
        }
      }
    }
    else if (uVar1 == 0x2b) {
      piVar3 = (int *)param_2[2];
      if (((*piVar3 == 1) && (param_1[0x8c] != 0)) &&
         (piVar5 = (int *)FUN_004393f8(param_1[0x8c]), param_3 = extraout_ECX_04,
         piVar5 != (int *)0x0)) {
        piVar4 = FUN_00417ff0((int *)&PTR_FUN_0043aeac,'\x01',extraout_ECX_04);
        puStack_2c = &LAB_0042bf4f;
        uStack_30 = *in_FS_OFFSET;
        *in_FS_OFFSET = &uStack_30;
        iVar8 = SaveDC((HDC)piVar3[6]);
        uVar9 = *in_FS_OFFSET;
        *in_FS_OFFSET = &stack0xffffffc4;
        FUN_00418a14(piVar4,piVar3[6]);
        FUN_004188b4((int)piVar4);
        FUN_0043a824(piVar5,(int)piVar4,piVar3 + 7,
                     CONCAT22((short)((uint)piVar3 >> 0x10),(short)piVar3[4]));
        *in_FS_OFFSET = uVar9;
        FUN_00418a14(piVar4,0);
        RestoreDC((HDC)piVar3[6],iVar8);
        return;
      }
    }
    else if (((uVar1 == 0x2c) && (piVar3 = (int *)param_2[2], *piVar3 == 1)) &&
            ((param_1[0x8c] != 0 &&
             (piVar5 = (int *)FUN_004393f8(param_1[0x8c]), param_3 = extraout_ECX_05,
             piVar5 != (int *)0x0)))) {
      pHVar6 = (HWND)FUN_00445724(param_1);
      puStack_2c = (undefined1 *)0x42bf9d;
      hdc = GetWindowDC(pHVar6);
      puStack_2c = &LAB_0042c07a;
      uStack_30 = *in_FS_OFFSET;
      *in_FS_OFFSET = &uStack_30;
      piVar7 = FUN_00417ff0((int *)&PTR_FUN_0043aeac,'\x01',extraout_ECX_06);
      *in_FS_OFFSET = &stack0xffffffc4;
      iVar8 = SaveDC(hdc);
      *in_FS_OFFSET = &stack0xffffffb8;
      FUN_00418a14(piVar7,(int)hdc);
      FUN_004188b4((int)piVar7);
      piVar4 = piVar3 + 4;
      FUN_00437cd8(piVar5,piVar7,piVar3 + 3,piVar4);
      *in_FS_OFFSET = piVar4;
      FUN_00418a14(piVar7,0);
      RestoreDC(hdc,iVar8);
      return;
    }
  }
  else if (uVar1 == 0xb01a) {
    if (param_1[0x24] != 0) {
      FUN_00403088(param_1,param_2,param_3);
      param_3 = extraout_ECX_03;
    }
  }
  else if ((uVar1 == 0xb01b) && (param_1[0x24] != 0)) {
    FUN_00403088(param_1,param_2,param_3);
    param_3 = extraout_ECX_02;
  }
  FUN_004430bc(param_1,param_2,param_3);
  return;
}

