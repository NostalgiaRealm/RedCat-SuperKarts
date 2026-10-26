/*
 * FUN_0044e898 at 0044e898
 * undefined __register FUN_0044e898(int * param_1, undefined4 * param_2, char param_3)
 * Address ranges: 0044e898-0044e8d9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044e898(int *param_1,undefined4 *param_2,char param_3)

{
  bool bVar1;
  HWND hWnd;
  int iVar2;
  RECT *pRVar3;
  byte bVar4;
  RECT *lpRect;
  RECT local_1c;
  
  bVar4 = 0;
  lpRect = &local_1c;
  bVar1 = FUN_00445a20((int)param_1);
  if (bVar1) {
    pRVar3 = &local_1c;
    for (iVar2 = 4; iVar2 != 0; iVar2 = iVar2 + -1) {
      pRVar3->left = *param_2;
      param_2 = param_2 + (uint)bVar4 * -2 + 1;
      pRVar3 = (RECT *)((int)pRVar3 + ((uint)bVar4 * -2 + 1) * 4);
    }
    iVar2 = -(uint)(param_3 != '\0');
    hWnd = (HWND)FUN_00445724(param_1);
    InvalidateRect(hWnd,lpRect,iVar2);
  }
  return;
}

