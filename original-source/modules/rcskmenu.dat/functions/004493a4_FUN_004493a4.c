/*
 * FUN_004493a4 at 004493a4
 * undefined FUN_004493a4(void)
 * Address ranges: 004493a4-00449774
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004493a4(int *param_1,int *param_2)

{
  int iVar1;
  HWND hWnd;
  BOOL BVar2;
  undefined4 uVar3;
  HCURSOR hCursor;
  int extraout_ECX;
  undefined4 extraout_EDX;
  int *piVar4;
  int *piVar5;
  undefined4 *in_FS_OFFSET;
  byte bVar6;
  UINT wMsgFilterMin;
  UINT wMsgFilterMax;
  UINT wRemoveMsg;
  undefined4 uStack_64;
  undefined1 *puStack_60;
  undefined1 *puStack_5c;
  undefined4 *puStack_4c;
  int iStack_48;
  int iStack_44;
  tagMSG tStack_40;
  int iStack_24;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  tagPOINT tStack_10;
  int *piStack_8;
  
  bVar6 = 0;
  puStack_5c = &stack0xfffffffc;
  puStack_4c = (undefined4 *)0x0;
  puStack_60 = &LAB_00449775;
  uStack_64 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_64;
  iVar1 = *param_2;
  piStack_8 = param_1;
  if (iVar1 < 0x203) {
    if (iVar1 == 0x202) {
      if (param_1[0x18] == 0) {
        puStack_5c = &stack0xfffffffc;
        FUN_00406c20(param_2[2],&tStack_10.x);
        iVar1 = FUN_00448070((int)piStack_8,&tStack_10.x,&iStack_14);
        if ((iVar1 != 0) && (iStack_14 == 0x14)) {
          piVar4 = *(int **)(iVar1 + 4);
          uVar3 = FUN_00403024(piVar4,(int)&PTR_FUN_00427e2c);
          if ((char)uVar3 == '\0') {
            FUN_0043f564(piVar4,0,extraout_ECX);
          }
          else {
            FUN_0042eb18(piVar4,extraout_EDX,extraout_ECX);
          }
        }
      }
      else {
        puStack_5c = &stack0xfffffffc;
        FUN_00448fc4((int)param_1);
      }
    }
    else if (iVar1 == 0x20) {
      puStack_5c = &stack0xfffffffc;
      GetCursorPos(&tStack_10);
      FUN_0043f1f0((int *)piStack_8[5],&tStack_10.x,&iStack_48);
      tStack_10.x = iStack_48;
      tStack_10.y = iStack_44;
      if (((((short)param_2[2] == 1) &&
           (iVar1 = FUN_00445724((int *)piStack_8[5]), iVar1 == param_2[1])) &&
          (iVar1 = FUN_004440b0(piStack_8[5]), 0 < iVar1)) &&
         ((iVar1 = FUN_00448070((int)piStack_8,&tStack_10.x,&iStack_14), iVar1 != 0 &&
          (iStack_14 == 0x12)))) {
        hCursor = (HCURSOR)FUN_00430608(*(int *)PTR_DAT_0047c9bc,
                                        (int)*(short *)(&DAT_0047ba10 +
                                                       (uint)*(byte *)(*(int *)(iVar1 + 0x14) + 0x10
                                                                      ) * 2));
        SetCursor(hCursor);
        param_2[3] = 1;
        goto LAB_0044975f;
      }
    }
    else if (iVar1 == 0x200) {
      puStack_5c = &stack0xfffffffc;
      if (param_1[0x18] != 0) {
        puStack_5c = &stack0xfffffffc;
        FUN_00449074((int)param_1);
        FUN_00406c20(param_2[2],&iStack_48);
        piStack_8[0x14] = iStack_48;
        piStack_8[0x15] = iStack_44;
        FUN_00449310();
        FUN_00449074((int)piStack_8);
      }
    }
    else {
      puStack_5c = &stack0xfffffffc;
      if (iVar1 == 0x201) {
        puStack_5c = &stack0xfffffffc;
        FUN_00406c20(param_2[2],&tStack_10.x);
        iVar1 = FUN_00448070((int)piStack_8,&tStack_10.x,&iStack_14);
        if (iVar1 != 0) {
          if (iStack_14 == 0x12) {
            FUN_00448f64((int)piStack_8,iVar1,&tStack_10.x);
          }
          else if (iStack_14 == 2) {
            wRemoveMsg = 0;
            wMsgFilterMax = 0x203;
            wMsgFilterMin = 0x203;
            hWnd = (HWND)FUN_00445724((int *)piStack_8[5]);
            BVar2 = PeekMessageA(&tStack_40,hWnd,wMsgFilterMin,wMsgFilterMax,wRemoveMsg);
            if ((BVar2 == 0) &&
               (uVar3 = FUN_00403024(*(int **)(iVar1 + 4),(int)&PTR_FUN_0043be00),
               (char)uVar3 != '\0')) {
              (**(code **)(**(int **)(iVar1 + 4) + 0xb0))();
            }
            piVar4 = *(int **)(iVar1 + 4);
            if ((*(char *)((int)piVar4 + 0x8b) == '\x01') &&
               (*(char *)((int)piVar4 + 0x4d) == '\x01')) {
              FUN_0043fc90(piVar4,'\0',-1);
            }
            goto LAB_0044975f;
          }
        }
      }
    }
  }
  else if (iVar1 == 0x203) {
    FUN_00406c20(param_2[2],&iStack_48);
    iVar1 = FUN_00448070((int)piStack_8,&iStack_48,&iStack_14);
    if (((iVar1 != 0) && (*(int *)(iVar1 + 4) != 0)) && (iStack_14 == 2)) {
      FUN_0043e064();
      FUN_00440188(*(int **)(iVar1 + 4),(int *)0x0,0,1);
    }
  }
  else {
    if (iVar1 == 0xb030) {
      puStack_5c = &stack0xfffffffc;
      (*(code *)param_1[0xc])(param_1[0xd],param_2);
      if (param_2[3] == 0) {
        iVar1 = (**(code **)(*piStack_8 + 4))(piStack_8,param_2[2] + 0x28,&iStack_14);
        if (iStack_14 == 0x12) {
          FUN_00403b50((int *)(param_2[2] + 0x38));
        }
        else if ((iVar1 != 0) && ((iStack_14 == 2 || (iStack_14 == 0x14)))) {
          FUN_0043f054(iVar1,&iStack_24);
          (**(code **)*piStack_8)(piStack_8,iVar1,&iStack_24);
          iStack_24 = *(int *)(iVar1 + 0x30) * 2 - iStack_24;
          iStack_20 = *(int *)(iVar1 + 0x34) * 2 - iStack_20;
          iStack_1c = *(int *)(iVar1 + 0x38) * -2 + iStack_1c * 3 + iStack_24 * -2;
          iStack_18 = *(int *)(iVar1 + 0x3c) * -2 + iStack_18 * 3 + iStack_20 * -2;
          FUN_0043f64c(iVar1,(int *)&puStack_4c);
          FUN_00403ba4((int *)(param_2[2] + 0x38),puStack_4c);
          piVar4 = &iStack_24;
          piVar5 = (int *)(param_2[2] + 0x18);
          for (iVar1 = 4; iVar1 != 0; iVar1 = iVar1 + -1) {
            *piVar5 = *piVar4;
            piVar4 = piVar4 + (uint)bVar6 * -2 + 1;
            piVar5 = piVar5 + (uint)bVar6 * -2 + 1;
          }
        }
      }
      goto LAB_0044975f;
    }
    puStack_5c = &stack0xfffffffc;
    if ((iVar1 == 0xb042) && (puStack_5c = &stack0xfffffffc, *(int *)param_2[2] == 0xb00b)) {
      puStack_5c = &stack0xfffffffc;
      FUN_004492a4(param_1,param_2[1],((int *)param_2[2])[1]);
    }
  }
  (*(code *)piStack_8[0xc])(piStack_8[0xd],param_2);
LAB_0044975f:
  *in_FS_OFFSET = uStack_64;
  puStack_5c = &LAB_0044977c;
  puStack_60 = (undefined1 *)0x449774;
  FUN_00403b50((int *)&puStack_4c);
  return;
}

