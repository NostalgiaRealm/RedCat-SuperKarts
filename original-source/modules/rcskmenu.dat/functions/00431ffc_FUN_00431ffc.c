/*
 * FUN_00431ffc at 00431ffc
 * undefined4 __register FUN_00431ffc(int param_1, int * param_2)
 * Address ranges: 00431ffc-004320b3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00431ffc(int param_1,int *param_2)

{
  int *piVar1;
  HWND pHVar2;
  HANDLE pvVar3;
  LRESULT LVar4;
  LONG LVar5;
  undefined4 uVar6;
  
  uVar6 = 0;
  if ((0xff < (uint)param_2[1]) && ((uint)param_2[1] < 0x109)) {
    pHVar2 = GetCapture();
    if (pHVar2 == (HWND)0x0) {
      pHVar2 = (HWND)*param_2;
      piVar1 = *(int **)(param_1 + 0x38);
      if ((piVar1 == (int *)0x0) || (pHVar2 != (HWND)piVar1[0x8f])) {
        while( true ) {
          pvVar3 = FUN_0043c864(pHVar2);
          if ((pvVar3 != (HANDLE)0x0) || (pHVar2 == (HWND)0x0)) break;
          pHVar2 = GetParent(pHVar2);
        }
        if (pHVar2 == (HWND)0x0) {
          pHVar2 = (HWND)*param_2;
        }
      }
      else {
        pHVar2 = (HWND)FUN_00445724(piVar1);
      }
      LVar4 = SendMessageA(pHVar2,param_2[1] + 0xbc00,param_2[2],param_2[3]);
      if (LVar4 != 0) {
        uVar6 = 1;
      }
    }
    else {
      LVar5 = GetWindowLongA(pHVar2,-6);
      if (LVar5 == DAT_0047d4dc) {
        LVar4 = SendMessageA(pHVar2,param_2[1] + 0xbc00,param_2[2],param_2[3]);
        if (LVar4 != 0) {
          uVar6 = 1;
        }
      }
    }
  }
  return uVar6;
}

