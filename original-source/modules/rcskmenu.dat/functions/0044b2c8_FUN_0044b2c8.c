/*
 * FUN_0044b2c8 at 0044b2c8
 * undefined4 __register FUN_0044b2c8(int * param_1)
 * Address ranges: 0044b2c8-0044b35e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0044b2c8(int *param_1)

{
  int *piVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  HWND hWnd;
  undefined4 uVar5;
  UINT Msg;
  WPARAM wParam;
  LPARAM lParam;
  
  uVar5 = 0;
  piVar1 = *(int **)(param_1[0x4a] + 4);
  if ((((*(char *)((int)param_1 + 0x47) != '\0') && ((*(byte *)(param_1 + 8) & 1) == 0)) &&
      (piVar1 != (int *)0x0)) && (*(char *)((int)piVar1 + 0x1a) != '\0')) {
    iVar3 = (**(code **)(*piVar1 + 0x24))();
    if (iVar3 == 0) {
      *(undefined1 *)((int)piVar1 + 0x1a) = 0;
    }
    else {
      piVar4 = FUN_004298bc(param_1);
      if ((piVar4 != (int *)0x0) && (*(char *)((int)piVar4 + 0x216) != '\0')) {
        bVar2 = FUN_00445a20((int)piVar4);
        if (bVar2) {
          if ((char)param_1[0x4f] == '\0') {
            lParam = 0;
            wParam = 0;
            Msg = 0x30f;
            hWnd = (HWND)FUN_00445724(piVar4);
            PostMessageA(hWnd,Msg,wParam,lParam);
          }
          else {
            FUN_004405f0((int)piVar4,0x30f,0,0);
          }
          uVar5 = 1;
          *(undefined1 *)((int)piVar1 + 0x1a) = 0;
        }
      }
    }
  }
  return uVar5;
}

