/*
 * FUN_00424c94 at 00424c94
 * undefined FUN_00424c94(void)
 * Address ranges: 00424c94-00424f4a;00424f64-00424f6c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00424c94(int *param_1,UINT *param_2,HWND param_3,WNDPROC param_4)

{
  undefined1 *puVar1;
  char cVar2;
  bool bVar3;
  int *piVar4;
  uint uVar5;
  undefined4 uVar6;
  HWND hWndTo;
  UINT UVar7;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  undefined4 *in_FS_OFFSET;
  tagPOINT *lpPoints;
  undefined4 uStack_28;
  undefined1 *puStack_24;
  undefined1 *puStack_20;
  tagPOINT tStack_10;
  int *piStack_8;
  
  puStack_20 = &stack0xfffffffc;
  puStack_24 = &LAB_00424f4b;
  uStack_28 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_28;
  UVar7 = *param_2;
  piStack_8 = param_1;
  if ((int)UVar7 < 0x105) {
    if (UVar7 != 0x104) {
      if ((int)UVar7 < 0x88) {
        if (UVar7 == 0x87) {
          puStack_20 = &stack0xfffffffc;
          bVar3 = FUN_004246bc(param_1);
          puVar1 = puStack_20;
          if (bVar3) {
            param_2[3] = 4;
            *in_FS_OFFSET = uStack_28;
            return;
          }
        }
        else if (UVar7 == 7) {
          puStack_20 = &stack0xfffffffc;
          piVar4 = FUN_004298bc(param_1);
          puVar1 = puStack_20;
          if ((piVar4 != (int *)0x0) &&
             (cVar2 = (**(code **)(*piVar4 + 0xd4))(piVar4,piStack_8), puVar1 = puStack_20,
             cVar2 == '\0')) {
            *in_FS_OFFSET = uStack_28;
            return;
          }
        }
        else if (UVar7 == 8) {
          puVar1 = &stack0xfffffffc;
          if ((*(byte *)(param_1 + 0x11) & 0x20) != 0) {
            *in_FS_OFFSET = uStack_28;
            return;
          }
        }
        else {
          puVar1 = &stack0xfffffffc;
          if ((UVar7 == 0x84) && (puVar1 = &stack0xfffffffc, (*(byte *)(param_1 + 8) & 0x10) != 0))
          {
            param_2[3] = 0xffffffff;
            *in_FS_OFFSET = uStack_28;
            return;
          }
        }
        goto LAB_00424f0c;
      }
      if (UVar7 != 0x100) {
        if (UVar7 != 0x101) {
          puVar1 = &stack0xfffffffc;
          if (UVar7 == 0x102) {
            puStack_20 = &stack0xfffffffc;
            uVar5 = FUN_00444568(param_1,(int)param_2,param_3);
            if ((char)uVar5 != '\0') {
              *in_FS_OFFSET = uStack_28;
              return;
            }
            if ((((short)param_2[1] == 0xd) || (puVar1 = puStack_20, (short)param_2[1] == 0x1b)) &&
               (bVar3 = FUN_004246bc(piStack_8), puVar1 = puStack_20, bVar3)) {
              FUN_004246e0(piStack_8,0);
              *in_FS_OFFSET = uStack_28;
              return;
            }
          }
          goto LAB_00424f0c;
        }
        goto LAB_00424e2f;
      }
    }
    puVar1 = &stack0xfffffffc;
    if ((param_3 != (HWND)param_1[0x83]) &&
       (puStack_20 = &stack0xfffffffc, cVar2 = FUN_004443d0(param_1,(int)param_2),
       puVar1 = puStack_20, cVar2 != '\0')) {
      *in_FS_OFFSET = uStack_28;
      return;
    }
  }
  else {
    if (0xbd00 < (int)UVar7) {
      if (((UVar7 != 0xbd02) && (UVar7 != 0xbd04)) && (puVar1 = &stack0xfffffffc, UVar7 != 0xbd06))
      goto LAB_00424f0c;
LAB_00424ef8:
      (**(code **)(*param_1 + 0x6c))(param_1,param_2);
      *in_FS_OFFSET = uStack_28;
      return;
    }
    if (UVar7 == 0xbd00) goto LAB_00424ef8;
    if (UVar7 != 0x105) {
      if (UVar7 == 0x200) {
        puStack_20 = &stack0xfffffffc;
        FUN_00432d10(*(int *)PTR_DAT_0047c86c,param_1,(int)param_2);
        puVar1 = puStack_20;
      }
      else {
        puVar1 = &stack0xfffffffc;
        if ((UVar7 == 0x205) &&
           (puStack_20 = &stack0xfffffffc, uVar6 = FUN_00422eb4((int)param_1), puVar1 = puStack_20,
           (char)uVar6 != '\0')) {
          tStack_10.x = (LONG)(short)param_2[2];
          tStack_10.y = (LONG)*(short *)((int)param_2 + 10);
          UVar7 = 1;
          lpPoints = &tStack_10;
          hWndTo = (HWND)FUN_00445724(piStack_8);
          MapWindowPoints(param_3,hWndTo,lpPoints,UVar7);
          *(undefined2 *)(param_2 + 2) = (undefined2)tStack_10.x;
          *(undefined2 *)((int)param_2 + 10) = (undefined2)tStack_10.y;
          (**(code **)(*piStack_8 + 0x6c))(piStack_8,param_2);
          *in_FS_OFFSET = uStack_28;
          return;
        }
      }
      goto LAB_00424f0c;
    }
LAB_00424e2f:
    puStack_20 = &stack0xfffffffc;
    cVar2 = FUN_004444a0(param_1,(int)param_2);
    puVar1 = puStack_20;
    if (cVar2 != '\0') {
      *in_FS_OFFSET = uStack_28;
      return;
    }
  }
LAB_00424f0c:
  puStack_20 = puVar1;
  UVar7 = CallWindowProcA(param_4,param_3,*param_2,param_2[1],param_2[2]);
  param_2[3] = UVar7;
  if ((*param_2 == 0x203) && ((*(byte *)(piStack_8 + 0x10) & 0x80) != 0)) {
    FUN_00403088(piStack_8,extraout_EDX,extraout_ECX);
  }
  *in_FS_OFFSET = uStack_28;
  return;
}

