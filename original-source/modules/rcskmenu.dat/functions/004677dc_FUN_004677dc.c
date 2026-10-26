/*
 * FUN_004677dc at 004677dc
 * undefined __register FUN_004677dc(int * param_1, int param_2, undefined4 param_3)
 * Address ranges: 004677dc-00467845
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004677dc(int *param_1,int param_2,undefined4 param_3)

{
  char cVar1;
  SHORT SVar2;
  HWND hWnd;
  HWND hWndParent;
  BOOL BVar3;
  
  cVar1 = FUN_00403088(param_1,param_2,param_3);
  if (cVar1 == '\0') {
    hWnd = GetFocus();
    hWndParent = (HWND)FUN_00445724(param_1);
    BVar3 = IsChild(hWndParent,hWnd);
    if (BVar3 == 0) goto LAB_00467839;
  }
  if ((*(short *)(param_2 + 4) == 9) && (SVar2 = GetKeyState(0x11), SVar2 < 0)) {
    SVar2 = GetKeyState(0x10);
    FUN_0046760c(param_1,-1 < SVar2);
    *(undefined4 *)(param_2 + 0xc) = 1;
    return;
  }
LAB_00467839:
  FUN_00444c44((int)param_1,param_2);
  return;
}

