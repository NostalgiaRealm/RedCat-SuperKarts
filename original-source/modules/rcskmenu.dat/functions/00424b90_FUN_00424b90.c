/*
 * FUN_00424b90 at 00424b90
 * undefined FUN_00424b90(void)
 * Address ranges: 00424b90-00424c65
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00424b90(void)

{
  uint uVar1;
  char cVar2;
  int *piVar3;
  LPARAM lParam;
  int *unaff_ESI;
  uint *unaff_EDI;
  LONG in_stack_00000004;
  undefined4 in_stack_00000008;
  int iStack_4;
  
  if ((0xff < *unaff_EDI) && (*unaff_EDI < 0x109)) {
    iStack_4 = 0x424ba7;
    piVar3 = FUN_004298bc(unaff_ESI);
    if (piVar3 != (int *)0x0) {
      iStack_4 = 0x424bbb;
      cVar2 = (**(code **)(*piVar3 + 0xdc))();
      if (cVar2 != '\0') {
        return;
      }
    }
  }
  iStack_4 = unaff_ESI[0x86];
  (**(code **)(*unaff_ESI + 0xb4))();
  uVar1 = *unaff_EDI;
  if (uVar1 == 0x30) {
    if (*PTR_DAT_0047c7a0 != '\0') {
      SendMessageA((HWND)unaff_ESI[0x82],0xd3,3,0);
    }
  }
  else if (((uVar1 == 0x201) || (uVar1 == 0x203)) && (*(char *)((int)unaff_ESI + 0x4d) == '\x01')) {
    GetCursorPos((LPPOINT)&iStack_4);
    FUN_0043f1f0(unaff_ESI,&iStack_4,&stack0x00000004);
    iStack_4 = in_stack_00000004;
    lParam = FUN_00406c34((undefined2 *)&iStack_4);
    SendMessageA((HWND)unaff_ESI[0x82],0x202,0,lParam);
    FUN_0043fc90(unaff_ESI,'\0',-1);
  }
  return;
}

