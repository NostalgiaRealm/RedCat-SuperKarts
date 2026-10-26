/*
 * FUN_00431634 at 00431634
 * undefined FUN_00431634(void)
 * Address ranges: 00431634-004316dc;00431715-00431c87;00431c9d-00431ca3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Heritage AFTER dead removal. Example location: EAX : 0x00431a37 */
/* WARNING: Restarted to delay deadcode elimination for space: register */
/* WARNING: Exceeded maximum restarts with more pending */

void FUN_00431634(int param_1,int *param_2)

{
  int *piVar1;
  byte bVar2;
  undefined4 *puVar3;
  LRESULT LVar4;
  FARPROC pFVar5;
  DWORD DVar6;
  undefined4 uVar7;
  HWND pHVar8;
  BOOL BVar9;
  HWND hWnd;
  uint extraout_ECX;
  undefined4 extraout_EDX;
  int iVar10;
  int iVar11;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_24;
  undefined1 *puStack_20;
  undefined1 *puStack_1c;
  
  puStack_1c = &stack0xfffffffc;
  puStack_20 = &LAB_00431c88;
  uStack_24 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_24;
  param_2[3] = 0;
  iVar10 = *(int *)(*(int *)(param_1 + 0x98) + 8);
  if (-1 < iVar10 + -1) {
    iVar11 = 0;
    puStack_1c = &stack0xfffffffc;
    do {
      puVar3 = (undefined4 *)FUN_0040f6b0(*(undefined4 **)(param_1 + 0x98),iVar11);
      (*(code *)*puVar3)(puVar3[1],param_2);
      if ((char)puVar3 != '\0') {
        *in_FS_OFFSET = uStack_24;
        return;
      }
      iVar11 = iVar11 + 1;
      iVar10 = iVar10 + -1;
    } while (iVar10 != 0);
  }
  FUN_0043155c(param_1,param_2);
  iVar10 = *param_2;
  if (iVar10 < 0x113) {
    if (iVar10 == 0x112) {
      if ((param_2[1] & 0xfff0U) == 0xf020) {
        FUN_00431cec(param_1);
      }
      else if ((param_2[1] & 0xfff0U) == 0xf120) {
        FUN_00431d8c(param_1);
      }
      else {
        FUN_004315ac();
      }
      goto LAB_00431c7e;
    }
    if (iVar10 < 0x17) {
      if (iVar10 == 0x16) {
        if (param_2[1] != 0) {
          *(undefined1 *)(param_1 + 0x8c) = 1;
        }
        goto LAB_00431c7e;
      }
      switch(iVar10) {
      case 7:
        PostMessageA(*(HWND *)(param_1 + 0x24),0xb01a,0,0);
        FUN_004315ac();
        break;
      default:
        goto switchD_004316d6_caseD_1;
      case 10:
        if (param_2[1] == 0) {
          FUN_004315ac();
          if (*(int *)(param_1 + 0x9c) == 0) {
            uVar7 = FUN_00429334(*(undefined4 *)(param_1 + 0x24));
            *(undefined4 *)(param_1 + 0x9c) = uVar7;
          }
          FUN_004314b8(param_1);
        }
        else {
          FUN_004314c0(param_1);
          if (*(undefined4 **)(param_1 + 0x9c) != (undefined4 *)0x0) {
            FUN_004293e8(*(undefined4 **)(param_1 + 0x9c));
            *(undefined4 *)(param_1 + 0x9c) = 0;
          }
          FUN_004315ac();
        }
        break;
      case 0xf:
        BVar9 = IsIconic(*(HWND *)(param_1 + 0x24));
        if (BVar9 == 0) {
          FUN_004315ac();
        }
        else {
          FUN_004315e8();
        }
        break;
      case 0x10:
        if (*(int **)(param_1 + 0x38) != (int *)0x0) {
          FUN_0042eb18(*(int **)(param_1 + 0x38),extraout_EDX,extraout_ECX);
        }
        break;
      case 0x14:
        *param_2 = 0x27;
        FUN_004315ac();
      }
      goto LAB_00431c7e;
    }
    if (iVar10 < 0x1e) {
      if (iVar10 == 0x1d) {
        FUN_00430c68(DAT_0047d774);
        FUN_004315ac();
        goto LAB_00431c7e;
      }
      if (iVar10 == 0x1a) {
        FUN_004498e8(*(int *)PTR_DAT_0047c990,param_2[1]);
        FUN_004315ac();
        goto LAB_00431c7e;
      }
      if (iVar10 == 0x1c) {
        FUN_004315ac();
        *(bool *)(param_1 + 0x8d) = param_2[1] != 0;
        if (param_2[1] == 0) {
          FUN_004314b0(param_1);
          PostMessageA(*(HWND *)(param_1 + 0x24),0xb001,0,0);
        }
        else {
          FUN_004314c0(param_1);
          PostMessageA(*(HWND *)(param_1 + 0x24),0xb000,0,0);
        }
        goto LAB_00431c7e;
      }
    }
    else {
      if (iVar10 == 0x37) {
        iVar10 = FUN_00431cd0(param_1);
        param_2[3] = iVar10;
        goto LAB_00431c7e;
      }
      if (iVar10 == 0x4a) {
        if ((*(int *)param_2[2] == -0x21acbbac) && (*(char *)(param_1 + 0x8e) != '\0')) {
          if (*(int *)(param_1 + 0x90) == 0) {
            iVar10 = FUN_0040bffc("vcltest3.dll",0x8000);
            *(int *)(param_1 + 0x90) = iVar10;
            if (iVar10 == 0) {
              DVar6 = GetLastError();
              param_2[3] = DVar6;
              *(undefined4 *)(param_1 + 0x90) = 0;
            }
            else {
              param_2[3] = 0;
              pFVar5 = GetProcAddress(*(HMODULE *)(param_1 + 0x90),"RegisterAutomation");
              if (pFVar5 != (FARPROC)0x0) {
                (*pFVar5)(pFVar5,param_2);
              }
            }
          }
          else {
            param_2[3] = 0;
          }
        }
        goto LAB_00431c7e;
      }
    }
  }
  else if (iVar10 < 0xb01b) {
    if (iVar10 == 0xb01a) {
      BVar9 = IsIconic(*(HWND *)(param_1 + 0x24));
      if (((BVar9 == 0) && (pHVar8 = GetFocus(), pHVar8 == *(HWND *)(param_1 + 0x24))) &&
         (pHVar8 = (HWND)FUN_00429484(0), pHVar8 != (HWND)0x0)) {
        SetFocus(pHVar8);
      }
      goto LAB_00431c7e;
    }
    if (iVar10 < 0xb002) {
      if (iVar10 == 0xb001) {
        if (*(short *)(param_1 + 0xe2) != 0) {
          (**(code **)(param_1 + 0xe0))(*(undefined4 *)(param_1 + 0xe4),param_1);
        }
        goto LAB_00431c7e;
      }
      if (iVar10 - 0x132U < 7) {
        LVar4 = SendMessageA((HWND)param_2[2],iVar10 + 0xbc00,param_2[1],(LPARAM)param_2[2]);
        param_2[3] = LVar4;
        goto LAB_00431c7e;
      }
      if (iVar10 - 0x132U == 0xaece) {
        if (*(short *)(param_1 + 0xea) != 0) {
          (**(code **)(param_1 + 0xe8))(*(undefined4 *)(param_1 + 0xec),param_1);
        }
        goto LAB_00431c7e;
      }
    }
    else {
      if (iVar10 == 0xb016) {
        uVar7 = FUN_004320e4(param_1,param_2,extraout_ECX);
        if ((char)uVar7 != '\0') {
          param_2[3] = 1;
        }
        goto LAB_00431c7e;
      }
      if (iVar10 == 0xb017) {
        piVar1 = *(int **)(param_1 + 0x38);
        if ((piVar1 != (int *)0x0) && (iVar10 = FUN_00445724(piVar1), iVar10 != 0)) {
          pHVar8 = (HWND)FUN_00445724(piVar1);
          BVar9 = IsWindowEnabled(pHVar8);
          if (BVar9 != 0) {
            pHVar8 = (HWND)FUN_00445724(piVar1);
            BVar9 = IsWindowVisible(pHVar8);
            if (BVar9 != 0) {
              DAT_0047b6b4 = 0;
              pHVar8 = GetFocus();
              hWnd = (HWND)FUN_00445724(piVar1);
              SetFocus(hWnd);
              FUN_004405f0((int)piVar1,0x112,param_2[1],param_2[2]);
              SetFocus(pHVar8);
              DAT_0047b6b4 = 1;
              param_2[3] = 1;
            }
          }
        }
        goto LAB_00431c7e;
      }
    }
  }
  else {
    if (iVar10 == 0xb01f) {
      FUN_0043271c(param_1,(short)param_2[1],param_2[2]);
      goto LAB_00431c7e;
    }
    if (iVar10 == 0xb020) {
      if (param_2[1] == 0) {
        FUN_00432224(param_1,extraout_EDX,extraout_ECX,*(undefined4 *)param_2[2],
                     ((undefined4 *)param_2[2])[1]);
      }
      else {
        FUN_00432280(param_1,extraout_EDX,extraout_ECX,*(int *)param_2[2],((int *)param_2[2])[1]);
      }
      goto LAB_00431c7e;
    }
    if (iVar10 == 0xb031) {
      if (param_2[1] == 1) {
        param_2[3] = *(int *)(param_1 + 0xa0);
      }
      else {
        *(int *)(param_1 + 0xa0) = param_2[2];
      }
      goto LAB_00431c7e;
    }
    if (iVar10 - 0xb03fU < 2) {
      bVar2 = FUN_00433414(param_1,iVar10,(int *)param_2[2]);
      param_2[3] = bVar2 & 0x7f;
      goto LAB_00431c7e;
    }
  }
switchD_004316d6_caseD_1:
  FUN_004315ac();
LAB_00431c7e:
  *in_FS_OFFSET = uStack_24;
  return;
}

