/*
 * FUN_00443bbc at 00443bbc
 * undefined __register FUN_00443bbc(int * param_1, int param_2)
 * Address ranges: 00443bbc-00443cba
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00443bbc(int *param_1,int param_2)

{
  int iVar1;
  HCURSOR hCursor;
  HWND pHVar2;
  HWND pHVar3;
  short sVar4;
  char cVar5;
  tagPOINT local_1c;
  int local_14 [2];
  
  if (*(int *)(param_2 + 4) == param_1[0x53]) {
    if (*(short *)(param_2 + 8) == -2) {
      if ((*(short *)(param_2 + 10) == 0x201) && (*(int *)(*(int *)PTR_DAT_0047c86c + 0x24) != 0)) {
        pHVar2 = GetLastActivePopup(*(HWND *)(*(int *)PTR_DAT_0047c86c + 0x24));
        pHVar3 = GetForegroundWindow();
        if (pHVar2 != pHVar3) {
          FUN_00431e7c(*(int *)PTR_DAT_0047c86c);
          return;
        }
      }
    }
    else if (*(short *)(param_2 + 8) == 1) {
      sVar4 = *(short *)(*(int *)PTR_DAT_0047c9bc + 0x38);
      if (sVar4 == 0) {
        GetCursorPos(&local_1c);
        cVar5 = '\0';
        FUN_0043f1f0(param_1,&local_1c.x,local_14);
        iVar1 = FUN_00442f94((int)param_1,local_14,0,cVar5);
        if (iVar1 != 0) {
          if ((*(byte *)(iVar1 + 0x20) & 0x10) == 0) {
            sVar4 = *(short *)(iVar1 + 0x68);
          }
          else {
            sVar4 = -2;
          }
        }
        if (sVar4 == 0) {
          if ((*(byte *)(param_1 + 8) & 0x10) == 0) {
            sVar4 = (short)param_1[0x1a];
          }
          else {
            sVar4 = -2;
          }
        }
      }
      if (sVar4 != 0) {
        hCursor = (HCURSOR)FUN_00430608(*(int *)PTR_DAT_0047c9bc,(int)sVar4);
        SetCursor(hCursor);
        *(undefined4 *)(param_2 + 0xc) = 1;
        return;
      }
    }
  }
  (**(code **)(*param_1 + -0x10))(param_1,param_2);
  return;
}

