/*
 * FUN_0044e850 at 0044e850
 * undefined FUN_0044e850(void)
 * Address ranges: 0044e850-0044e952
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_0044e850(int param_1,int param_2)

{
  char cVar1;
  DWORD DVar2;
  int iVar3;
  int iVar4;
  
  FUN_004afce0(s___s__d_handle_Meshanim___________004f0b3c,
               s_D__work_rcsk_Code_game_msh_MshAn_004f0b14,0xa0);
  DVar2 = GetTickCount();
  if ((uint)(((param_2 * 1000) / *(int *)(param_1 + 8)) / 100) < DVar2 - *(int *)(param_1 + 0x18)) {
    DVar2 = GetTickCount();
    cVar1 = *(char *)(param_1 + 0x1c);
    *(DWORD *)(param_1 + 0x18) = DVar2;
    if (cVar1 == '\0') {
      iVar3 = *(int *)(param_1 + 0x10) + -1;
    }
    else {
      iVar3 = *(int *)(param_1 + 0x10) + 1;
    }
    *(int *)(param_1 + 0x10) = iVar3;
    if (*(int *)(param_1 + 0x54) == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(param_1 + 0x58) - *(int *)(param_1 + 0x54) >> 2;
    }
    if ((*(int *)(param_1 + 0x10) == iVar3) ||
       ((*(int *)(param_1 + 0x54) != 0 &&
        ((*(int *)(param_1 + 0x58) - *(int *)(param_1 + 0x54) & 0xfffffffcU) == 4)))) {
      *(undefined4 *)(param_1 + 0x10) = 0;
      *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
    }
    if (*(int *)(param_1 + 0xc) == -2) {
      iVar3 = *(int *)(param_1 + 0x10);
      if (iVar3 != -1) {
        if (*(int *)(param_1 + 0x54) == 0) {
          iVar4 = 0;
        }
        else {
          iVar4 = *(int *)(param_1 + 0x58) - *(int *)(param_1 + 0x54) >> 2;
        }
        if (iVar3 != iVar4 + -1) {
          return;
        }
      }
      *(bool *)(param_1 + 0x1c) = cVar1 == '\0';
      if (cVar1 == '\0') {
        *(undefined4 *)(param_1 + 0x10) = 1;
        *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
        return;
      }
      *(int *)(param_1 + 0x10) = iVar3 + -2;
      *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
    }
  }
  return;
}

