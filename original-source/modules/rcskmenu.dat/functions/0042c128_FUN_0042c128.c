/*
 * FUN_0042c128 at 0042c128
 * undefined FUN_0042c128(void)
 * Address ranges: 0042c128-0042c1ec
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042c128(int *param_1,int *param_2)

{
  HBRUSH hbr;
  int iVar1;
  undefined4 uVar2;
  char cVar3;
  RECT RStack_1c;
  int *piStack_c;
  int *piStack_8;
  
  iVar1 = *param_2;
  piStack_c = param_2;
  piStack_8 = param_1;
  if (iVar1 == 0x14) {
    hbr = (HBRUSH)FUN_00417ed4(param_1[0x4c]);
    (**(code **)(*piStack_8 + 0x40))(piStack_8,&RStack_1c);
    FillRect((HDC)piStack_c[1],&RStack_1c,hbr);
    piStack_c[3] = 1;
    return;
  }
  if (iVar1 == 0x3f) {
    FUN_0042c09c();
    if (*(char *)((int)piStack_8 + 0x217) == '\x02') {
      iVar1 = FUN_0042c480((int)piStack_8);
      if ((iVar1 == 0) || (uVar2 = FUN_0042c0e8(), (char)uVar2 == '\0')) {
        cVar3 = '\x01';
      }
      else {
        cVar3 = '\0';
      }
      FUN_00429260((HWND)piStack_8[0x8f],cVar3);
      return;
    }
    return;
  }
  if (iVar1 != 0x84) {
    FUN_0042c09c();
    return;
  }
  FUN_0042c09c();
  if (piStack_c[3] != 1) {
    return;
  }
  piStack_c[3] = -1;
  return;
}

