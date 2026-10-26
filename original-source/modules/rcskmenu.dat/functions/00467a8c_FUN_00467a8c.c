/*
 * FUN_00467a8c at 00467a8c
 * int __register FUN_00467a8c(int * param_1, undefined4 * param_2)
 * Address ranges: 00467a8c-00467b1b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00467a8c(int *param_1,undefined4 *param_2)

{
  HWND hWnd;
  LRESULT LVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  UINT Msg;
  WPARAM wParam;
  undefined4 *lParam;
  undefined4 local_1c;
  undefined4 local_18;
  
  local_1c = *param_2;
  local_18 = param_2[1];
  iVar2 = 0;
  if ((char)param_1[0x51] != '\0') {
    lParam = &local_1c;
    wParam = 0;
    Msg = 0x130d;
    hWnd = (HWND)FUN_00445724(param_1);
    LVar1 = SendMessageA(hWnd,Msg,wParam,(LPARAM)lParam);
    if (-1 < LVar1) {
      iVar3 = 0;
      if (-1 < LVar1) {
        iVar4 = LVar1 + 1;
        do {
          iVar3 = FUN_00467318((int)param_1,iVar3,'\x01','\x01');
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
      if (iVar3 != 0) {
        iVar4 = FUN_0044268c(iVar3);
        if (0 < iVar4) {
          iVar2 = FUN_00442650(iVar3,0);
          if (param_1 != *(int **)(iVar2 + 0x90)) {
            iVar2 = 0;
          }
        }
      }
    }
  }
  return iVar2;
}

