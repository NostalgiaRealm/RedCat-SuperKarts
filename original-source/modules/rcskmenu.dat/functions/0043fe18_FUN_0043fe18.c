/*
 * FUN_0043fe18 at 0043fe18
 * undefined FUN_0043fe18(void)
 * Address ranges: 0043fe18-0043fee7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043fe18(undefined4 param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  HWND hWnd;
  LPRECT lpRect;
  double dVar4;
  double dVar5;
  
  if ((param_2[1] == 0) || (*(char *)(param_2[1] + 0x17c) == '\0')) {
    iVar1 = FUN_0043f5f0(param_2[0xe]);
    iVar2 = FUN_0043f5dc(param_2[0xe]);
    dVar4 = (double)param_2[3] - (double)iVar1 * *(double *)(param_2 + 8);
    dVar5 = (double)param_2[4] - (double)iVar2 * *(double *)(param_2 + 10);
    iVar3 = FUN_004029bc();
    param_2[0x11] = iVar3;
    iVar3 = FUN_004029bc();
    param_2[0x12] = iVar3;
    param_2[0x13] = iVar1 + param_2[0x11];
    param_2[0x14] = iVar2 + param_2[0x12];
    (**(code **)(*param_2 + 0x28))(param_2,param_2 + 0x11,*param_2,dVar4,dVar5);
  }
  else {
    lpRect = (LPRECT)(param_2 + 0x11);
    hWnd = (HWND)FUN_00445724((int *)param_2[1]);
    GetWindowRect(hWnd,lpRect);
    iVar1 = param_2[1];
    if ((*(char *)(iVar1 + 0x17c) != '\0') && (*(int *)(iVar1 + 0x148) != 0)) {
      (**(code **)(**(int **)(iVar1 + 0x148) + 0x24))
                (*(int **)(iVar1 + 0x148),param_2[0xe],param_2[0x16],param_2 + 0x11,
                 (char)param_2[0x15]);
    }
  }
  return;
}

