/*
 * FUN_0043d238 at 0043d238
 * undefined1 __register FUN_0043d238(int * param_1, undefined4 param_2, undefined4 param_3, int param_4)
 * Address ranges: 0043d238-0043d3cf
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined1 FUN_0043d238(int *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  HWND pHVar1;
  int *piVar2;
  DWORD dwThreadId;
  undefined4 uVar3;
  BOOL BVar4;
  int *piVar5;
  code *lpfn;
  RECT local_40;
  tagRECT local_30;
  int local_20;
  HWND local_1c;
  HWND local_18;
  undefined4 local_14;
  undefined4 local_10;
  char local_c;
  undefined1 local_5;
  
  local_5 = 1;
  local_18 = FUN_0043d63c((POINT *)(param_4 + -0xc));
  pHVar1 = GetWindow(local_18,4);
  if (pHVar1 != *(HWND *)(*(int *)PTR_DAT_0047c86c + 0x24)) {
    piVar2 = FUN_0043c864(local_18);
    if (piVar2 == (int *)0x0) {
      return local_5;
    }
    do {
      piVar5 = piVar2;
      piVar2 = (int *)piVar5[9];
    } while (piVar2 != (int *)0x0);
    local_18 = (HWND)FUN_00445724(piVar5);
  }
  piVar2 = param_1;
  if (local_18 != (HWND)0x0) {
    do {
      piVar5 = piVar2;
      piVar2 = (int *)piVar5[9];
    } while (piVar2 != (int *)0x0);
    local_1c = (HWND)FUN_00445724(piVar5);
    if (local_1c != local_18) {
      piVar2 = *(int **)(*(int *)(param_4 + -0x10) + 0x24);
      if (piVar2 == (int *)0x0) {
        uVar3 = FUN_00403024(*(int **)(param_4 + -0x10),(int)&PTR_FUN_0043be00);
        if ((char)uVar3 == '\0') {
          local_20 = 0;
        }
        else {
          local_20 = FUN_00445724(*(int **)(param_4 + -0x10));
        }
      }
      else {
        do {
          piVar5 = piVar2;
          piVar2 = (int *)piVar5[9];
        } while (piVar2 != (int *)0x0);
        local_20 = FUN_00445724(piVar5);
      }
      local_c = '\0';
      local_14 = *(undefined4 *)(param_4 + -0xc);
      local_10 = *(undefined4 *)(param_4 + -8);
      piVar2 = &local_20;
      lpfn = FUN_0043d1cc;
      dwThreadId = GetCurrentThreadId();
      EnumThreadWindows(dwThreadId,lpfn,(LPARAM)piVar2);
      if (local_c != '\0') {
        GetWindowRect(local_18,&local_30);
        FUN_00403088(param_1,*(undefined4 *)(param_4 + -0x10),&local_40);
        uVar3 = FUN_00403024(DAT_0047d7bc,(int)&PTR_FUN_0043ae18);
        if (((((char)uVar3 == '\0') || (*(int *)(DAT_0047d7bc[0xe] + 0x90) == 0)) ||
            (pHVar1 = (HWND)FUN_00445724(*(int **)(DAT_0047d7bc[0xe] + 0x90)), pHVar1 != local_18))
           && (BVar4 = IntersectRect(&local_30,&local_30,&local_40), BVar4 != 0)) {
          local_5 = 0;
        }
      }
    }
  }
  return local_5;
}

