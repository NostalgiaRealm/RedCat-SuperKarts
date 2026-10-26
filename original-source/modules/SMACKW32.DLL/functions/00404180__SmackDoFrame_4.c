/*
 * _SmackDoFrame@4 at 00404180
 * char __stdcall _SmackDoFrame@4(int param_1)
 * Address ranges: 00404180-00404257
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

char _SmackDoFrame_4(int param_1)

{
  char cVar1;
  DWORD DVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  undefined8 uVar3;
  
                    /* 0x4180  19  _SmackDoFrame@4 */
  if (param_1 == 0) {
    cVar1 = '\0';
  }
  else {
    DVar2 = timeGetTime();
    *(DWORD *)(param_1 + 0x464) = DVar2;
    *(DWORD *)(param_1 + 0x460) = DVar2;
    if (*(int *)(param_1 + 0x46c) == 0) {
      *(DWORD *)(param_1 + 0x46c) = DVar2;
    }
    if (*(int *)(param_1 + 0x68) != 0) {
      *(undefined4 *)(param_1 + 0x3b4) = *(undefined4 *)(param_1 + 0x370);
    }
    *(int *)(param_1 + 0x478) = *(int *)(param_1 + 0x478) + 1;
    FUN_004042d0();
    if (((*(byte *)(param_1 + 0x385) & 4) == 0) && (*(int *)(param_1 + 0x400) != 0)) {
      uVar3 = FUN_00404260(extraout_ECX,extraout_EDX);
      cVar1 = (char)uVar3;
    }
    else {
      cVar1 = '\0';
    }
    if (*(int *)(param_1 + 0x3a0) != 0) {
      if (cVar1 == '\0') {
        *(undefined4 *)(param_1 + 0x3e4) = 1;
        FUN_0040c920(*(undefined4 *)(param_1 + 0x3e0),*(undefined4 *)(param_1 + 0x39c),
                     (uint *)*(undefined4 *)(param_1 + 0x3e0),*(undefined4 *)(param_1 + 0x39c),
                     *(byte **)(param_1 + 0x3a0));
      }
      else {
        *(int *)(param_1 + 0x47c) = *(int *)(param_1 + 0x47c) + 1;
      }
    }
    if (DAT_0040e83c != 0) {
      (*DAT_00410474)();
    }
  }
  return cVar1;
}

